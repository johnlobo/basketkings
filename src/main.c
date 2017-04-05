//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <cpctelera.h>
#include <stdlib.h>
#include "sprites/player04.h"
#include "sprites/tileset02.h"
#include "sprites/bball.h"
#include "levels/map.h"

// Pointers to the hardware backbuffer, placed in bank 1
// of the memory (0x8000-0xBFFF)
#define SCR_BUFF  (u8*)0x8000

// Program Stack locations
#define NEW_STACK_LOCATION       (void*)0x1000

#define YES 1
#define NO 0

#define WIDTH  80
#define HEIGHT  160

#define PLAYER_WIDTH   SP_PLAYER04_0_W
#define PLAYER_HEIGHT   SP_PLAYER04_0_H

#define VERTICAL_STEP 2

#define MAP_ORIGIN_Y   40

typedef struct {
        u8 look;
        u8* sprite;
} TFrame;

typedef struct {
        u8 x, y;
        u8 px, py;
        u8 move;
        u8 state;
        TFrame* frame;
        u8 nframe;
        u8 look;
        u8 jump;
} TPlayer;

// Looking to
enum {
        M_right   = 0
        ,  M_left
} ELook;

// Player Events
enum {
        EV_stop = 0
        ,  EV_move
        ,  EV_jump
        ,  EV_numEvents
} EEvents;

// Player States
enum {
        ST_stopped  = 0
        ,  ST_walking
        ,  ST_jumpPrep
        ,  ST_jumping
        ,  ST_falling
        ,  ST_landing
        ,  ST_numStates
} EStates;

// Maps
#define NUM_MAPS 1
u8* const maps[NUM_MAPS] = { map01 };

// Sprites States
#define HERO_FRAMES  5
const TFrame g_frames[HERO_FRAMES] = {
           { M_right, sp_player04_0 },  { M_right, sp_player04_1 }
        ,  { M_right, sp_player04_2 },  { M_right, sp_player04_3 }
        ,  { M_right, sp_player04_4 }
};

// Animaciones
#define ANIM_PAUSE        4
#define WALKING_FRAMES    4
#define JUMPING_FRAMES    4
#define FALLING_FRAMES    2
TFrame* const anim_walking[WALKING_FRAMES] = {
        &g_frames[1], &g_frames[2], &g_frames[3], &g_frames[4]
};
TFrame* const anim_jumping[JUMPING_FRAMES] = {
        &g_frames[0], &g_frames[0], &g_frames[0], &g_frames[0]
};
TFrame* const anim_falling[FALLING_FRAMES] = {
        &g_frames[0], &g_frames[0]
};

// Control de salto
#define JUMP_STEPS  20
const CPCT_2BITARRAY(g_tablaSalto, JUMP_STEPS) = {
        CPCT_ENCODE2BITS(3, 3, 3, 3)
        , CPCT_ENCODE2BITS(3, 3, 2, 2)
        , CPCT_ENCODE2BITS(2, 2, 2, 1)
        , CPCT_ENCODE2BITS(1, 1, 1, 1)
        , CPCT_ENCODE2BITS(1, 0, 0, 0)
};

// Máscara de transparencia
cpctm_createTransparentMaskTable(g_tablatrans, 0x100, M0, 0);

u8* map;
u8 map_num;
TPlayer player;
u8 page;
u8 *map_origins[2];
u8 *screen_origin[2];
u8 screen_page[2];
u8 distx;
u8 topx;
u8 topy;
u8 disty;
u8 stepx;
u8 stepy;

void erasePlayer(u8 screen);
void drawPlayer(u8 screen);
void stopped_enter();

void changeVideoMemoryPage() {
        cpct_setVideoMemoryPage(screen_page[page]);
        page = !page;
}

void interrupcion() {
        static u8 kk;

        if (++kk == 5) {
                //playmusic();
                cpct_scanKeyboard_if();
                kk = 0;
        }
}

void drawMap(u8 screen) {
        cpct_etm_drawTilemap2x4(MAP_WIDTH, MAP_HEIGHT, (u8*) map_origins[screen], map);
}

void assignFrame(TFrame **animation) {
        player.frame = animation[player.nframe / ANIM_PAUSE];
}

void turnFrame() {
        TFrame* f = player.frame;
        if (f->look != player.look) {
                cpct_hflipSpriteM0(SP_PLAYER04_0_W, SP_PLAYER04_0_H, f->sprite);
                f->look = player.look;
        }
}

void selectSpritePlayer() {
        switch(player.state) {
        case ST_stopped:      { player.frame = &g_frames[0];  break; }
        case ST_walking:      { assignFrame(anim_walking);    break; }
        case ST_jumpPrep:     { assignFrame(anim_jumping);   break; }
        case ST_jumping:      { player.frame = &g_frames[0]; break; }
        case ST_falling:      { player.frame = &g_frames[0]; break; }
        case ST_landing:      { assignFrame(anim_falling);     break; }
        }
        turnFrame();
}

void moveRight() {
        if (player.x + PLAYER_WIDTH < WIDTH) {
                player.x++;
                player.look  = M_right;
        }
}

void moveLeft() {
        if (player.x > 0) {
                player.x--;
                player.look  = M_left;
        }
}

void moveUp() {
        if (player.y - VERTICAL_STEP > 0) {
                player.y -= VERTICAL_STEP;
                //player.look  = M_right;
        }
}

void moveDown() {
        if (player.y + VERTICAL_STEP < HEIGHT) {
                player.y += VERTICAL_STEP;
                //player.look  = M_right;
        }
}

void redrawPlayer(u8 screen) {
        erasePlayer(screen);
        drawPlayer(screen);
}

u8 checkKeys(const cpct_keyID* k, u8 numk) {
        u8 i;
//   cpct_scanKeyboard_if();
        if (cpct_isAnyKeyPressed()) {
                for(i=1; i <= numk; i++, k++) {
                        if (cpct_isKeyPressed(*k))
                                return i;
                }
        }
        return 0;
}

void drawPlayer(u8 page) {
        u8* pvmem = cpct_getScreenPtr((u8*) screen_origin[page], player.x, player.y);
        cpct_drawSpriteMaskedAlignedTable(player.frame->sprite, pvmem, SP_PLAYER04_0_W, SP_PLAYER04_0_H, g_tablatrans);
}

void erasePlayer(u8 page) {
        u8 w = PLAYER_WIDTH / 2 + (player.px & 1);
        u8 h = PLAYER_HEIGHT / 4 + (player.py & 3 ? 1 : 0);
        cpct_etm_drawTileBox2x4(player.px / 2, (player.py-MAP_ORIGIN_Y) / 4, w, h, MAP_WIDTH, (u8*) map_origins[page], map);
}

u8* getTilePtr(u8 x, u8 y) {
        return map + (y-MAP_ORIGIN_Y)/4*MAP_WIDTH + x/2;
        //return 0;
}

void adjustToTheFloor() {
        player.y = (player.y & 0b11111100) + 1;
}

void landing_enter() {
        player.nframe = 0;
        player.state = ST_landing;
        player.move  = YES;
}

void landing() {
        player.move = YES;
        if(++player.nframe == FALLING_FRAMES*ANIM_PAUSE)
                stopped_enter();
}

void falling_enter() {
        player.state = ST_falling;
        player.move  = YES;
        player.jump  = JUMP_STEPS - 3;
}

void go_down() {
        player.y += cpct_get2Bits(g_tablaSalto, player.jump);
        if (player.jump > 1)
                player.jump--;
}

void falling() {
        static const cpct_keyID keys[2] = {Key_CursorRight, Key_CursorLeft};
        u8 k = checkKeys(keys, 2);
        switch(k) {
        case 0: break; // Nada que hacer
        case 1: moveRight();   break;
        case 2: moveLeft(); break;
        }
        go_down();
//        if (overTheFloor()) {
//                adjustToTheFloor();
//                landing_enter();
//        }
        player.move=YES;
}


void walking_enter(u8 look) {
        player.nframe = 0;
        player.state = ST_walking;
        player.look   = look;
        player.move  = YES;
}

void stopped_enter() {
        player.state = ST_stopped;
        player.move  = YES;
}

void jumpingPrep_enter() {
        player.nframe = 0;
        player.state = ST_jumpPrep;
        player.move  = YES;
}

void shoot(){
  u8* pvmem = cpct_getScreenPtr((u8*) screen_origin[page], player.x, player.y);
  u8 n = 0;
  distx = abs(136 - player.x);
  topx = player.x + (distx / 2);
  topy = 20;
  disty = abs(topy - player.y);
  stepx = 3;
  stepy = disty / stepx;

  cpct_drawSpriteMaskedAlignedTable(sp_bball, pvmem, SP_BBALL_W, SP_BBALL_H, g_tablatrans);

  pvmem = cpct_getScreenPtr((u8*) screen_origin[page], 136, 50);
  cpct_drawSpriteMaskedAlignedTable(sp_bball, pvmem, SP_BBALL_W, SP_BBALL_H, g_tablatrans);

  for (n=0;n<((distx/2)/stepx);n++){
    pvmem = cpct_getScreenPtr((u8*) screen_origin[page], player.x + (stepx*n), player.y - (stepy*n));
    cpct_drawSpriteMaskedAlignedTable(sp_bball, pvmem, SP_BBALL_W, SP_BBALL_H, g_tablatrans);
  }
}

void stopped() {
        static const cpct_keyID keys[5] = {Key_CursorUp, Key_CursorDown, Key_CursorRight, Key_CursorLeft, Key_A};
        u8 k = checkKeys(keys, 5);
        switch(k) {
        case 0: break; // Nada que hacer
        case 1: walking_enter(player.look); break;
        case 2: walking_enter(player.look); break;
        case 3: walking_enter(M_right); break;
        case 4: walking_enter(M_left); break;
        case 5: shoot(); break;
        }
}

void raise() {
        player.y -= cpct_get2Bits(g_tablaSalto, player.jump);
        //if (player.y < MAP_ORIGIN_Y)
        //    player.y = MAP_ORIGIN_Y;
        if (++player.jump == JUMP_STEPS)
                falling_enter();
}

void jumping_enter() {
        player.state = ST_jumping;
        player.move  = YES;
        player.jump  = 0;
}

void jumping() {
        if (!cpct_isKeyPressed(Key_CursorUp)) {
                falling_enter();
        } else {
                static const cpct_keyID keys[2] = {Key_CursorRight, Key_CursorLeft};
                u8 k = checkKeys(keys, 2);
                switch(k) {
                case 0: break;
                case 1: moveRight();   break;
                case 2: moveLeft(); break;
                }
                raise();
                player.move = YES;
        }
}


void jumpPrep_animate() {
        if (++player.nframe == JUMPING_FRAMES*ANIM_PAUSE)
                jumping_enter();
}

void jumpPrep() {
        static const cpct_keyID keys[1] = {Key_CursorUp};
        u8 k = checkKeys(keys, 1);
        switch(k) {
        case 0: stopped_enter(); break;
        case 1: jumpPrep_animate(); break;
        }
        player.move = YES;
}

void walking_animate(u8 look) {
        player.look  = look;
        if(++player.nframe == WALKING_FRAMES*ANIM_PAUSE)
                player.nframe = 0;
}

void walking() {
        static const cpct_keyID keys[4] = {Key_CursorUp, Key_CursorDown, Key_CursorRight, Key_CursorLeft};
        u8 k = checkKeys(keys, 4);
        switch(k) {
        case 0: stopped_enter();    break;
        case 1: moveUp(); break;
        case 2: moveDown(); break;
        case 3: moveRight();   walking_animate(M_right);   break;
        case 4: moveLeft(); walking_animate(M_left); break;
        }
        player.move = YES;
}

void executeState() {
        switch(player.state) {
        case ST_stopped:     stopped();     break;
        case ST_walking:     walking();     break;
        case ST_jumpPrep:    jumpPrep();    break;
        case ST_jumping:     jumping();     break;
        case ST_falling:     falling();     break;
        case ST_landing:     landing();     break;
        }
}

void init() {
        cpct_setVideoMode(0);
        // Clean up Screen and BackBuffer filling them up with 0's
        cpct_memset(CPCT_VMEM_START, 0x00, 0x4000);
        cpct_memset(       SCR_BUFF, 0x00, 0x4000);
        cpct_setPalette(sp_palette, 16);
        cpct_setBorder(HW_BLACK);
        cpct_etm_setTileset2x4(tl_tileset);
        map_origins[0] = cpctm_screenPtr(CPCT_VMEM_START, 0, MAP_ORIGIN_Y);
        map_origins[1] = cpctm_screenPtr(SCR_BUFF, 0, MAP_ORIGIN_Y);
        screen_origin[0] = CPCT_VMEM_START;
        screen_origin[1] = SCR_BUFF;
        screen_page[0] = cpct_pageC0;
        screen_page[1] = cpct_page80;
        page = 0;
        map = map01;
        map_num = 0;
        player.x = player.px = 0;
        player.y = player.py = 100;
        player.state = ST_stopped;
        player.look   = M_right;
        player.nframe = 0;
        player.move  = NO;
        player.frame  = &g_frames[0];
        drawMap(0);
        drawMap(1);
        drawPlayer(0);
        //cpct_akp_musicInit(G_song);
        cpct_setInterruptHandler(interrupcion);
}

void main(void) {
        cpct_disableFirmware();
        cpct_setStackLocation(NEW_STACK_LOCATION);
        init();
        // Loop forever
        while (1) {
                executeState();
                //  if (player.move) {
                selectSpritePlayer();
                redrawPlayer(page);
                cpct_waitVSYNC();
                changeVideoMemoryPage();
                redrawPlayer(page);
                player.px = player.x;
                player.py = player.y;
                //        player.move = NO;
                //}
        }
}
