#include "player01.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2015
// Tile sp_player01_0: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_0[6 * 24] = {
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0xaa, 0xff, 0x00, 0x00,
	0x00, 0x55, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x55, 0xaa, 0x55, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x41, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x41, 0x41, 0x41, 0x00, 0x00,
	0x00, 0x55, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x41, 0x55, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0x82, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xeb, 0x82, 0x00
};

// Tile sp_player01_1: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_1[6 * 24] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0xff, 0x55, 0x00, 0x00,
	0x00, 0x55, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x55, 0xff, 0x55, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0x55, 0x41, 0x00, 0x00,
	0x00, 0xaa, 0x41, 0x41, 0x00, 0x00,
	0x00, 0xaa, 0x55, 0x00, 0x82, 0x00,
	0x00, 0xaa, 0x41, 0x00, 0x82, 0x00,
	0x55, 0x00, 0x55, 0x00, 0x41, 0x00,
	0x55, 0x00, 0x41, 0x00, 0x41, 0x00,
	0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xd7, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x82, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x82, 0x55, 0x00, 0x00,
	0x00, 0x41, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x41, 0x00, 0x55, 0x00, 0x00,
	0x00, 0xc3, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x82, 0x00, 0x00, 0xaa, 0x00,
	0x41, 0x82, 0x00, 0x00, 0xaa, 0x00,
	0x00, 0xc3, 0x00, 0x00, 0xff, 0xaa
};

// Tile sp_player01_2: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_2[6 * 24] = {
	0x00, 0x00, 0x55, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0x55, 0xaa, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xaa, 0x00,
	0x00, 0x00, 0xff, 0x00, 0xaa, 0x00,
	0x00, 0x00, 0x55, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x55, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0xaa, 0xaa, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0xaa, 0x00,
	0x00, 0x00, 0xaa, 0xaa, 0xaa, 0x00,
	0x00, 0x00, 0x82, 0x82, 0x82, 0x00,
	0x00, 0x00, 0xaa, 0xaa, 0xaa, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0xaa, 0x00,
	0x00, 0x00, 0x55, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x41, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x41, 0x00, 0x00,
	0x00, 0x00, 0x55, 0xff, 0xc3, 0x00
};

// Tile sp_player01_3: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_3[6 * 24] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x55, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x41, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x82, 0x41, 0x55, 0x00, 0x00,
	0x00, 0x82, 0x55, 0x00, 0xaa, 0x00,
	0x00, 0x82, 0x41, 0x00, 0xaa, 0x00,
	0x41, 0x00, 0x55, 0x00, 0x55, 0x00,
	0x41, 0x00, 0x41, 0x00, 0x55, 0x00,
	0x00, 0x00, 0xff, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x82, 0x00, 0x00,
	0x00, 0x00, 0xaa, 0x41, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x41, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x41, 0x00, 0x00,
	0x00, 0xff, 0x00, 0x41, 0x00, 0x00,
	0x00, 0xaa, 0x00, 0x00, 0x82, 0x00,
	0x55, 0xaa, 0x00, 0x00, 0x82, 0x00,
	0x00, 0xff, 0x00, 0x00, 0xc3, 0x82
};

// Tile sp_player01_4: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_4[6 * 24] = {
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x55, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x00, 0x55, 0x00, 0x00, 0x00,
	0x00, 0x55, 0xff, 0xff, 0x00, 0x00,
	0x00, 0xaa, 0x55, 0x00, 0xaa, 0x00,
	0x00, 0xaa, 0x41, 0x00, 0xaa, 0x00,
	0x00, 0xaa, 0x55, 0x00, 0xaa, 0x00,
	0x00, 0x82, 0x41, 0x00, 0x82, 0x00,
	0x00, 0xaa, 0x55, 0x00, 0xaa, 0x00,
	0x00, 0xaa, 0x41, 0x00, 0xaa, 0x00,
	0x00, 0x00, 0xff, 0xaa, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x41, 0x00, 0x41, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0x00, 0x55, 0x00, 0x00,
	0x00, 0x55, 0xff, 0x55, 0xff, 0x00
};

// Tile sp_player01_5: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_5[6 * 24] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Tile sp_player01_6: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_6[6 * 24] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Tile sp_player01_7: 12x24 pixels, 6x24 bytes.
const u8 sp_player01_7[6 * 24] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

