#include <types.h>
#include "map.h"

const u8 map01[MAP_WIDTH * MAP_HEIGHT] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,6,7,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,9,10,11,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,9,13,14,15,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,17,18,9,19,20,21,22,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,24,25,26,27,28,29,30,31,0,0,0,0,
  32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,33,34,35,36,37,38,39,40,0,0,0,0,
  41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,42,43,44,41,207,0,45,46,0,0,0,0,
  47,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,49,41,41,41,210,50,51,52,0,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,55,41,41,41,205,56,57,58,59,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,60,61,62,63,63,63,64,65,63,63,63,66,67,41,41,216,68,69,70,71,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,60,72,73,54,54,54,54,54,54,54,54,54,54,54,74,41,41,207,0,75,76,77,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,78,79,54,54,54,54,54,54,54,54,54,54,54,54,54,80,41,41,41,210,82,83,84,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,78,85,54,54,54,54,54,54,54,54,54,54,54,54,54,54,55,41,41,41,81,82,86,87,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,88,85,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,89,67,41,41,0,82,90,91,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,92,54,54,54,54,93,94,94,94,94,94,94,94,94,94,94,94,94,95,41,41,96,82,97,98,0,0,
  99,100,101,102,54,54,54,54,54,54,54,54,93,85,54,54,54,103,104,105,106,107,106,108,106,106,106,106,106,106,106,109,41,41,110,111,112,113,0,0,
  114,115,116,117,118,54,54,54,54,54,54,54,53,54,54,54,119,54,54,120,121,121,122,121,121,121,121,121,121,121,121,123,41,41,124,125,126,127,0,0,
  128,129,130,131,132,54,54,54,54,54,54,54,53,54,54,133,54,54,54,134,121,121,121,135,121,121,121,121,121,121,121,136,137,41,138,139,126,140,0,0,
  53,60,141,142,143,54,54,54,54,54,54,54,53,54,54,144,54,54,54,145,121,121,121,146,121,121,121,121,121,121,121,121,147,41,148,149,150,151,152,0,
  153,154,155,156,157,54,54,54,54,54,54,54,53,54,54,158,102,54,54,159,121,121,160,161,121,121,121,121,121,121,121,121,162,41,41,163,164,165,166,0,
  167,168,169,170,54,54,54,54,54,54,54,54,171,172,54,54,173,174,54,175,121,176,177,121,121,121,121,121,121,121,121,121,178,41,41,179,0,180,180,0,
  181,182,73,54,54,54,54,54,54,54,54,54,54,183,54,54,54,184,185,186,187,188,189,189,189,189,190,189,189,189,189,189,191,192,41,41,207,0,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,158,54,54,54,54,54,54,193,194,195,196,197,196,197,195,195,195,195,195,195,198,41,41,41,210,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,199,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,80,41,41,41,205,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,200,102,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,55,41,41,41,216,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,201,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,89,67,41,41,207,0,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,202,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,74,41,41,41,210,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,171,203,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,80,41,41,41,205,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,171,204,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,55,41,41,41,216,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,206,174,54,54,54,54,54,54,54,54,54,54,54,54,54,89,67,41,41,207,0,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,208,209,102,54,54,54,54,54,54,54,54,54,54,54,54,74,41,41,41,210,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,211,212,213,214,214,214,214,214,214,214,214,214,214,215,41,41,41,205,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,55,41,41,41,216,
  53,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,89,67,41,41,41,
  217,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,218,41,41,41,
  41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,
  41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41
};
