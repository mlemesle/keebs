// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.

#include <stdio.h>
#include QMK_KEYBOARD_H

static const uint8_t PROGMEM BASE_FRAME[1024] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 192, 192, 192, 192, 252,
252, 248, 240, 240, 240, 254, 254, 248, 248, 248, 248, 254, 254, 254, 248,
248, 240, 252, 254, 252, 240, 224, 248, 240, 248, 224, 192, 128, 128, 192,
128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 224, 224, 224, 224, 254, 254, 254, 254, 255, 127, 63, 63,
31, 15, 7, 7, 7, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 7,
7, 15, 15, 31, 63, 127, 127, 255, 255, 248, 248, 248, 252, 192, 128, 128, 128,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 140, 252, 252, 255,
255, 255, 255, 127, 31, 127, 127, 127, 127, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 127, 127, 127, 127, 127, 127, 127, 127, 127, 255, 255,
255, 255, 255, 255, 255, 254, 254, 252, 248, 240, 192, 0, 1, 3, 7, 31, 63,
255, 255, 255, 255, 243, 248, 56, 96, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128,
128, 128, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 0, 0, 0, 0, 0, 0,
0, 0, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 0, 0, 0, 0, 128,
128, 128, 128, 252, 252, 252, 252, 252, 252, 128, 128, 128, 128, 128, 128, 0,
194, 199, 247, 255, 255, 255, 255, 255, 7, 1, 0, 0, 0, 0, 0, 0, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 240, 240, 240, 240, 240, 240, 240,
240, 248, 248, 252, 255, 255, 255, 255, 255, 255, 191, 31, 15, 7, 1, 0, 0, 0,
0, 0, 0, 143, 255, 255, 255, 255, 255, 254, 156, 28, 0, 0, 0, 0, 0, 255, 255,
255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0,
0, 0, 16, 254, 255, 255, 255, 255, 199, 199, 199, 199, 199, 199, 135, 135,
143, 15, 0, 0, 0, 7, 7, 7, 7, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7,
0, 48, 57, 127, 255, 255, 255, 255, 255, 240, 192, 192, 192, 192, 192, 192,
192, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 195, 195, 195,
195, 195, 195, 3, 3, 7, 15, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254,
240, 192, 192, 192, 192, 224, 254, 254, 255, 255, 255, 255, 255, 255, 255,
207, 199, 6, 0, 0, 0, 0, 63, 255, 255, 255, 255, 255, 224, 224, 192, 224, 224,
240, 124, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 224, 225, 225, 195,
195, 195, 195, 195, 195, 199, 231, 255, 255, 255, 255, 126, 0, 0, 0, 0, 0, 0,
127, 255, 255, 255, 255, 255, 224, 224, 224, 224, 224, 0, 0, 0, 0, 12, 14, 31,
255, 255, 255, 255, 255, 255, 247, 255, 223, 159, 31, 31, 31, 31, 31, 31, 31,
31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 0, 0, 7, 15, 31, 31, 31,
31, 31, 31, 31, 31, 31, 31, 159, 223, 255, 255, 255, 255, 255, 255, 63, 63,
63, 49, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 1, 1, 0, 0, 1, 1, 1,
1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 63,
63, 31, 63, 63, 255, 255, 255, 254, 252, 248, 240, 240, 224, 224, 224, 192,
192, 192, 192, 128, 128, 128, 128, 128, 128, 128, 128, 192, 192, 192, 192,
192, 224, 224, 224, 240, 248, 248, 252, 254, 255, 127, 127, 127, 127, 199, 7,
7, 7, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 1, 15, 31, 31, 15, 7, 63, 127, 127, 127, 63,
31, 63, 127, 127, 127, 63, 31, 31, 127, 63, 127, 15, 15, 15, 31, 63, 31, 3, 3,
3, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0
};
static const uint8_t PROGMEM BASE_TO_RUST1[303] = {
15, 0, 129, 32, 4, 0, 137, 196, 0, 4, 8, 0, 248, 242, 255, 2, 2, 0, 150, 188,
185, 191, 192, 6, 0, 252, 242, 253, 0, 12, 0, 232, 0, 244, 8, 32, 0, 192, 160,
224, 128, 81, 0, 129, 64, 3, 32, 129, 226, 2, 0, 129, 2, 4, 0, 130, 32, 16, 3,
0, 131, 4, 0, 2, 4, 0, 130, 254, 250, 3, 243, 130, 250, 254, 2, 0, 2, 2, 2, 0,
131, 4, 0, 8, 2, 0, 130, 32, 64, 2, 0, 129, 3, 3, 250, 130, 54, 0, 2, 192,
129, 64, 71, 0, 130, 84, 4, 2, 0, 3, 128, 131, 0, 32, 128, 37, 0, 130, 1, 128,
2, 32, 129, 192, 2, 128, 131, 0, 2, 251, 2, 0, 129, 88, 67, 0, 129, 8, 4, 0,
135, 3, 235, 245, 244, 241, 249, 254, 37, 0, 134, 249, 241, 242, 244, 115, 3,
4, 0, 132, 255, 205, 86, 128, 63, 0, 131, 15, 200, 4, 52, 0, 129, 1, 5, 0,
132, 128, 92, 86, 6, 68, 0, 129, 96, 5, 0, 129, 248, 4, 0, 5, 128, 23, 0, 4,
128, 3, 0, 129, 224, 6, 0, 129, 96, 2, 32, 130, 37, 249, 71, 0, 2, 254, 131,
60, 0, 224, 2, 0, 129, 192, 2, 0, 2, 27, 132, 23, 249, 241, 228, 6, 0, 129,
192, 11, 0, 139, 224, 0, 232, 225, 241, 21, 23, 25, 7, 0, 128, 3, 64, 130,
136, 212, 2, 4, 130, 3, 255, 80, 0, 130, 1, 3, 4, 0, 129, 14, 3, 0, 131, 248,
56, 96, 4, 0, 130, 48, 64, 4, 0, 130, 16, 96, 2, 0, 129, 208, 2, 8, 132, 16,
32, 0, 252, 2, 2, 2, 4, 129, 253, 76, 0
};
static const uint8_t PROGMEM BASE_TO_RUST2[256] = {
15, 0, 129, 32, 4, 0, 135, 200, 0, 4, 8, 0, 248, 242, 4, 0, 146, 252, 250,
255, 0, 6, 128, 188, 178, 126, 0, 12, 0, 240, 0, 248, 0, 96, 0, 2, 192, 130,
0, 128, 81, 0, 129, 64, 3, 32, 129, 242, 2, 0, 129, 2, 4, 0, 130, 32, 16, 3,
0, 129, 4, 6, 0, 4, 1, 134, 254, 250, 227, 229, 245, 247, 2, 252, 8, 0, 131,
128, 0, 3, 2, 252, 131, 250, 48, 0, 2, 192, 72, 0, 129, 84, 2, 4, 3, 0, 131,
56, 188, 72, 2, 128, 40, 0, 129, 64, 3, 0, 130, 4, 251, 2, 0, 129, 80, 64, 0,
129, 128, 2, 0, 129, 248, 48, 0, 135, 160, 16, 8, 98, 0, 240, 112, 4, 0, 130,
14, 142, 64, 0, 130, 207, 198, 6, 0, 130, 16, 128, 43, 0, 2, 255, 7, 0, 131,
236, 132, 5, 64, 0, 133, 248, 240, 239, 0, 32, 4, 0, 132, 2, 0, 128, 160, 4,
32, 41, 0, 132, 32, 35, 25, 1, 69, 0, 130, 255, 0, 2, 254, 132, 12, 192, 224,
0, 3, 3, 131, 1, 255, 253, 5, 0, 129, 32, 2, 0, 2, 64, 8, 0, 133, 64, 0, 208,
196, 162, 2, 212, 130, 72, 248, 9, 0, 129, 80, 3, 4, 129, 255, 81, 0, 129, 1,
3, 0, 129, 254, 5, 0, 130, 248, 48, 5, 0, 131, 32, 0, 128, 5, 0, 131, 192, 0,
240, 87, 0
};
static const uint8_t PROGMEM BASE_TO_RUST3[248] = {
17, 0, 129, 224, 3, 0, 129, 4, 4, 0, 129, 248, 2, 0, 129, 252, 2, 0, 131, 252,
0, 255, 3, 0, 129, 248, 3, 0, 132, 16, 0, 8, 248, 2, 0, 129, 64, 3, 0, 129,
192, 88, 0, 132, 128, 192, 193, 0, 2, 64, 2, 0, 129, 248, 4, 0, 129, 254, 13,
0, 131, 228, 196, 203, 2, 215, 130, 242, 240, 2, 0, 129, 64, 4, 0, 2, 252,
130, 0, 56, 73, 0, 130, 16, 116, 2, 0, 129, 3, 5, 0, 2, 1, 36, 0, 129, 1, 2,
0, 129, 16, 6, 0, 131, 8, 72, 48, 65, 0, 131, 2, 0, 8, 5, 0, 129, 200, 45, 0,
131, 128, 206, 32, 5, 0, 131, 254, 144, 244, 64, 0, 131, 8, 6, 128, 4, 0, 129,
244, 43, 0, 129, 242, 2, 255, 132, 0, 30, 14, 4, 3, 0, 131, 232, 228, 3, 67,
0, 130, 16, 112, 3, 0, 134, 24, 60, 48, 0, 224, 160, 37, 0, 131, 16, 4, 1, 6,
0, 130, 248, 241, 73, 0, 131, 28, 0, 224, 8, 0, 129, 248, 7, 0, 129, 64, 5, 0,
131, 192, 160, 16, 2, 136, 131, 144, 208, 224, 4, 0, 129, 8, 8, 0, 129, 72, 3,
0, 129, 255, 81, 0, 129, 1, 5, 0, 129, 8, 4, 0, 137, 56, 64, 0, 64, 32, 0, 32,
0, 128, 4, 0, 132, 65, 193, 1, 240, 87, 0
};
static const uint8_t PROGMEM BASE_TO_RUST4[261] = {
15, 0, 129, 64, 3, 0, 130, 64, 0, 2, 4, 3, 0, 129, 248, 2, 0, 131, 252, 0, 8,
3, 0, 132, 2, 0, 8, 248, 2, 0, 132, 4, 16, 0, 8, 3, 0, 129, 192, 85, 0, 129,
160, 3, 0, 129, 254, 3, 0, 131, 2, 0, 128, 2, 184, 132, 144, 16, 8, 232, 3, 0,
2, 254, 14, 0, 137, 252, 0, 8, 16, 72, 88, 120, 144, 128, 6, 0, 129, 64, 73,
0, 130, 140, 208, 6, 0, 129, 64, 33, 0, 129, 255, 7, 0, 131, 248, 0, 192, 5,
0, 131, 8, 200, 64, 64, 0, 132, 64, 255, 224, 248, 6, 0, 129, 1, 45, 0, 129,
140, 78, 0, 133, 128, 192, 184, 80, 208, 2, 224, 38, 0, 130, 224, 240, 2, 0,
130, 193, 192, 5, 0, 131, 232, 0, 3, 64, 0, 132, 252, 254, 255, 80, 2, 0, 3,
1, 2, 0, 131, 32, 64, 128, 39, 0, 3, 1, 3, 0, 131, 2, 0, 1, 69, 0, 130, 255,
2, 3, 0, 132, 32, 0, 32, 64, 2, 0, 130, 1, 2, 11, 0, 131, 160, 144, 80, 2, 72,
131, 16, 160, 192, 7, 0, 129, 240, 2, 0, 129, 252, 3, 0, 129, 64, 3, 0, 129,
128, 87, 0, 2, 2, 131, 1, 250, 240, 2, 16, 135, 8, 0, 32, 0, 64, 96, 48, 2, 0,
137, 1, 3, 65, 33, 0, 224, 0, 192, 96, 2, 0, 132, 240, 0, 32, 28, 4, 0, 129,
4, 77, 0
};
static const uint8_t PROGMEM BASE_TO_RUST5[269] = {
17, 0, 2, 224, 2, 0, 132, 12, 0, 252, 248, 2, 0, 132, 6, 0, 250, 252, 2, 0,
132, 2, 0, 255, 252, 2, 0, 138, 4, 2, 254, 244, 0, 24, 0, 8, 232, 64, 2, 0,
131, 64, 192, 128, 81, 0, 129, 128, 3, 0, 129, 23, 2, 255, 132, 0, 1, 0, 192,
2, 0, 136, 240, 204, 214, 150, 146, 132, 226, 250, 11, 0, 129, 2, 8, 0, 131,
64, 128, 0, 3, 192, 2, 0, 2, 4, 73, 0, 129, 152, 3, 0, 129, 1, 40, 0, 2, 249,
133, 242, 243, 247, 249, 16, 5, 0, 131, 252, 7, 88, 66, 0, 130, 98, 228, 6, 0,
130, 8, 128, 45, 0, 130, 142, 224, 4, 0, 132, 255, 224, 0, 248, 63, 0, 132,
32, 1, 66, 128, 2, 0, 2, 14, 133, 255, 197, 193, 241, 250, 42, 0, 130, 97, 3,
73, 0, 132, 6, 255, 144, 16, 5, 0, 129, 248, 38, 0, 131, 160, 224, 48, 2, 60,
3, 0, 129, 192, 4, 0, 129, 255, 68, 0, 130, 255, 2, 2, 0, 129, 2, 2, 0, 129,
32, 7, 0, 129, 248, 4, 0, 130, 208, 144, 2, 136, 131, 72, 144, 160, 5, 0, 2,
64, 3, 0, 129, 32, 3, 0, 129, 8, 3, 0, 129, 1, 2, 0, 2, 128, 88, 0, 2, 2, 2,
0, 132, 240, 0, 16, 8, 3, 0, 140, 64, 65, 33, 1, 0, 128, 0, 64, 32, 0, 224, 0,
2, 64, 2, 0, 133, 240, 224, 0, 16, 0, 2, 252, 79, 0
};
static const uint8_t PROGMEM BASE_TO_RUST6[297] = {
17, 0, 2, 224, 2, 0, 129, 12, 2, 0, 129, 248, 2, 0, 132, 130, 128, 250, 252,
2, 0, 129, 2, 2, 0, 141, 252, 8, 0, 4, 2, 0, 248, 0, 24, 0, 8, 240, 192, 2,
128, 129, 64, 83, 0, 129, 128, 3, 0, 2, 255, 2, 0, 129, 1, 5, 0, 129, 248, 2,
0, 2, 244, 129, 233, 2, 201, 131, 229, 242, 250, 10, 0, 133, 252, 0, 248, 0,
240, 3, 0, 129, 128, 5, 0, 130, 4, 168, 3, 128, 69, 0, 131, 128, 148, 0, 2,
254, 129, 1, 3, 0, 129, 64, 38, 0, 134, 144, 130, 132, 64, 92, 124, 4, 0, 131,
12, 23, 88, 65, 0, 131, 160, 97, 212, 3, 0, 129, 32, 2, 112, 132, 120, 5, 8,
144, 43, 0, 129, 136, 5, 0, 131, 2, 100, 4, 64, 0, 131, 24, 253, 64, 5, 0,
130, 253, 127, 45, 0, 129, 1, 5, 0, 131, 16, 0, 65, 65, 0, 132, 250, 5, 135,
56, 5, 0, 129, 2, 2, 0, 130, 64, 128, 31, 0, 2, 32, 2, 224, 2, 96, 130, 0, 4,
3, 0, 129, 128, 2, 192, 130, 12, 16, 71, 0, 131, 3, 1, 233, 2, 32, 131, 0, 32,
64, 2, 0, 130, 1, 2, 2, 0, 135, 244, 100, 84, 82, 2, 196, 208, 17, 0, 129,
240, 2, 0, 134, 249, 253, 0, 129, 3, 1, 2, 128, 129, 192, 2, 0, 130, 1, 6, 82,
0, 129, 2, 2, 3, 148, 1, 242, 0, 16, 24, 8, 232, 0, 64, 96, 112, 48, 224, 192,
0, 64, 96, 32, 224, 160, 2, 0, 136, 112, 0, 240, 208, 224, 48, 28, 0, 2, 252,
130, 0, 7, 77, 0
};

typedef struct sized_ptr_s {
	const uint8_t *ptr;
	const size_t  size;
} sized_ptr_t;

#define RUST_FRAMES  6

static const sized_ptr_t RUST[6] = {
	{ BASE_TO_RUST1, sizeof(BASE_TO_RUST1) },
	{ BASE_TO_RUST2, sizeof(BASE_TO_RUST2) },
	{ BASE_TO_RUST3, sizeof(BASE_TO_RUST3) },
	{ BASE_TO_RUST4, sizeof(BASE_TO_RUST4) },
	{ BASE_TO_RUST5, sizeof(BASE_TO_RUST5) },
	{ BASE_TO_RUST6, sizeof(BASE_TO_RUST6) }
};

/// in this function we'll uncompress the frame to the OLED buffer and undiff it with the base frame
static void render_compressed_frame(const sized_ptr_t ptr) {
	const uint8_t *data = ptr.ptr;
	const size_t len = ptr.size;

	uint32_t current_pos_in_output = 0;

	uint32_t i = 0;
	while (i < len) {
		uint8_t byte = pgm_read_byte(&data[i]);
		uint8_t mode = byte >> 7;
		uint8_t n = byte & 0b01111111;

		if (mode != 0) {
			for (uint8_t tmp = 0; tmp < n; tmp++) {
				i += 1;
				uint8_t pixel = pgm_read_byte(&BASE_FRAME[current_pos_in_output]) - pgm_read_byte(&data[i]);
				oled_write_raw_byte(pixel, current_pos_in_output);
				current_pos_in_output += 1;
			}
		}
		else {
			i += 1;
			uint8_t next = pgm_read_byte(&data[i]);

			for (uint8_t tmp = 0; tmp < n; tmp++) {
				uint8_t pixel = pgm_read_byte(&BASE_FRAME[current_pos_in_output]) - next;
				oled_write_raw_byte(pixel, current_pos_in_output);
				current_pos_in_output += 1;
			}
		}

		i += 1;
	}
}

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms

void rust_render_anim(void) {
	static uint32_t anim_timer = 0;
	static uint32_t current_frame = 0;

	if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
		anim_timer = timer_read32();
		render_compressed_frame(RUST[current_frame]);
		current_frame = (current_frame + 1) % RUST_FRAMES;
	}
}