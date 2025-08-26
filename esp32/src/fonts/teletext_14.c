/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --stride 1 --align 1 --font EuropeanTeletextNuevo.ttf --range 33-176 --format lvgl -o teletext_14.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef TELETEXT_14
#define TELETEXT_14 1
#endif

#if TELETEXT_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0xff, 0xc0, 0xc0,

    /* U+0022 "\"" */
    0xee, 0xcd, 0x9e, 0x60,

    /* U+0023 "#" */
    0x33, 0x19, 0x8c, 0xdf, 0xf3, 0x31, 0x98, 0xcc,
    0x66, 0xff, 0x99, 0x8c, 0xc0,

    /* U+0024 "$" */
    0x18, 0x7e, 0xdb, 0xd8, 0xd8, 0x7f, 0x1b, 0x1b,
    0xdb, 0x7e, 0x18, 0x18,

    /* U+0025 "%" */
    0x60, 0xcc, 0x13, 0xc6, 0x33, 0x80, 0x80, 0x73,
    0x88, 0x51, 0x1b, 0x41, 0xc0,

    /* U+0026 "&" */
    0x3c, 0xb, 0x6, 0xc0, 0xe3, 0x28, 0x91, 0x4c,
    0x31, 0x14, 0x7c, 0xc0,

    /* U+0027 "'" */
    0xed, 0xe0,

    /* U+0028 "(" */
    0x3b, 0x11, 0x8c, 0x63, 0xc, 0x38,

    /* U+0029 ")" */
    0xe1, 0x84, 0x31, 0x8c, 0x66, 0xe0,

    /* U+002A "*" */
    0xcc, 0xdb, 0x62, 0xe0, 0x78, 0x6d, 0xb3, 0x30,
    0xc0,

    /* U+002B "+" */
    0x30, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x0,

    /* U+002C "," */
    0xed, 0xe0,

    /* U+002D "-" */
    0xfe,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x1, 0x80, 0x80, 0x81, 0x80, 0x80, 0xc0, 0x80,
    0x80, 0xc0, 0x0,

    /* U+0030 "0" */
    0x7e, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+0031 "1" */
    0x37, 0xf3, 0x33, 0x33, 0x30,

    /* U+0032 "2" */
    0x7c, 0x8b, 0x18, 0x20, 0x43, 0x8c, 0x3f, 0xfe,

    /* U+0033 "3" */
    0xfe, 0xc, 0x10, 0x61, 0x40, 0x81, 0x63, 0x7c,

    /* U+0034 "4" */
    0x6, 0x8, 0x31, 0x82, 0xc, 0xf9, 0xff, 0x6,

    /* U+0035 "5" */
    0xff, 0xc0, 0xc0, 0xc0, 0xff, 0x3, 0x3, 0xc3,
    0x7e,

    /* U+0036 "6" */
    0x1c, 0x38, 0x70, 0x60, 0xff, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+0037 "7" */
    0xff, 0x7, 0x6, 0xe, 0x30, 0x30, 0x30, 0x30,
    0x60,

    /* U+0038 "8" */
    0x7e, 0x42, 0xc3, 0x42, 0x7e, 0x42, 0xc3, 0x42,
    0x7e,

    /* U+0039 "9" */
    0x7e, 0xc3, 0xc3, 0xc3, 0xff, 0x6, 0xe, 0x1c,
    0x38,

    /* U+003A ":" */
    0xc0, 0x30,

    /* U+003B ";" */
    0x60, 0x35, 0x0,

    /* U+003C "<" */
    0x7, 0x1e, 0x60, 0x40, 0xc0, 0x60, 0x1e, 0x7,

    /* U+003D "=" */
    0xfe, 0x0, 0x0, 0xf, 0xe0,

    /* U+003E ">" */
    0xe0, 0x70, 0xc, 0x4, 0x7, 0xc, 0x70, 0xe0,

    /* U+003F "?" */
    0x79, 0x2c, 0xc2, 0x18, 0xc0, 0x0, 0x30,

    /* U+0040 "@" */
    0x7f, 0xf0, 0xf3, 0xfb, 0x3d, 0x9e, 0xcf, 0x3d,
    0xc0, 0x7f, 0x0,

    /* U+0041 "A" */
    0x1c, 0xa, 0x18, 0xd8, 0x3c, 0x1f, 0xff, 0x7,
    0x83, 0xc1, 0x80,

    /* U+0042 "B" */
    0xfe, 0xc2, 0xc3, 0xc2, 0xfe, 0xc2, 0xc3, 0xc2,
    0xfe,

    /* U+0043 "C" */
    0x3c, 0x66, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0x66,
    0x3c,

    /* U+0044 "D" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc6,
    0xfc,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0,
    0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0,
    0xc0,

    /* U+0047 "G" */
    0x7e, 0xc3, 0xc0, 0xc0, 0xc0, 0xdf, 0xc3, 0xc3,
    0x7e,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3f, 0xfe, 0xf, 0x7,
    0x83, 0xc1, 0x80,

    /* U+0049 "I" */
    0xfe, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0xfe,

    /* U+004A "J" */
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0xc3, 0x66,
    0x3c,

    /* U+004B "K" */
    0xc7, 0xc6, 0xcc, 0xd8, 0xf8, 0xd8, 0xd8, 0xc6,
    0xc7,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xff,

    /* U+004D "M" */
    0xc1, 0xe0, 0xf8, 0xfb, 0xbc, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0x80,

    /* U+004E "N" */
    0xe1, 0xf0, 0xf4, 0x79, 0x3c, 0x9e, 0x3f, 0x7,
    0x83, 0xc1, 0x80,

    /* U+004F "O" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0050 "P" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xff, 0xc0, 0xc0, 0xc0,
    0xc0,

    /* U+0051 "Q" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c, 0xe,

    /* U+0052 "R" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xff, 0xc7, 0xc3, 0xc3,
    0xc3,

    /* U+0053 "S" */
    0x7e, 0xc0, 0xc0, 0xc0, 0x7f, 0x3, 0x3, 0x3,
    0x7e,

    /* U+0054 "T" */
    0xff, 0x8c, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0x0,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+0056 "V" */
    0xc1, 0xa0, 0x98, 0xcc, 0x63, 0x61, 0xb0, 0x50,
    0x28, 0x8, 0x0,

    /* U+0057 "W" */
    0xc1, 0xe0, 0xf0, 0x7b, 0x3d, 0x9e, 0xcf, 0xf6,
    0xca, 0x63, 0x0,

    /* U+0058 "X" */
    0xc3, 0x42, 0x3c, 0x18, 0x18, 0x18, 0x3c, 0x42,
    0xc3,

    /* U+0059 "Y" */
    0xc0, 0xd0, 0x22, 0x10, 0x78, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x0,

    /* U+005A "Z" */
    0xfe, 0x18, 0x21, 0xc3, 0x6, 0xc, 0x38, 0xfe,

    /* U+005B "[" */
    0xfe, 0x31, 0x8c, 0x63, 0x18, 0xf8,

    /* U+005C "\\" */
    0xc0, 0x20, 0x8, 0x3, 0x0, 0x80, 0x60, 0x8,
    0x2, 0x1, 0x80,

    /* U+005D "]" */
    0xf8, 0xc6, 0x31, 0x8c, 0x63, 0xf8,

    /* U+005E "^" */
    0x18, 0x13, 0x18, 0xdc, 0x70,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0xcc,

    /* U+0061 "a" */
    0x7e, 0x73, 0x9f, 0xc8, 0x6e, 0x7b, 0xfc,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xdc, 0xe6, 0xc3, 0xc2, 0xe6,
    0xdc,

    /* U+0063 "c" */
    0x3c, 0x62, 0xe3, 0xe3, 0x62, 0x3c,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x3b, 0x67, 0xc3, 0x43, 0x67,
    0x3b,

    /* U+0065 "e" */
    0x7e, 0xe7, 0xff, 0xc0, 0xe3, 0x7e,

    /* U+0066 "f" */
    0xe, 0x30, 0xc1, 0x8f, 0xc6, 0xc, 0x18, 0x30,

    /* U+0067 "g" */
    0x7b, 0x6b, 0xef, 0x7b, 0x3, 0xc7, 0x7e,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xde, 0xe3, 0xc3, 0xc3, 0xc3,
    0xc3,

    /* U+0069 "i" */
    0x60, 0x0, 0xc6, 0x31, 0x8c, 0xf8,

    /* U+006A "j" */
    0xe, 0x0, 0x0, 0x70, 0x60, 0xc1, 0x83, 0x7,
    0x8d, 0xf0,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc7, 0xc6, 0xcc, 0xfc, 0xc6,
    0xc7,

    /* U+006C "l" */
    0x70, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0xfe,

    /* U+006D "m" */
    0xf6, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,

    /* U+006E "n" */
    0xde, 0xe3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+006F "o" */
    0x7e, 0xc3, 0xc3, 0xc3, 0xc3, 0x7e,

    /* U+0070 "p" */
    0xde, 0xe3, 0xe3, 0xe3, 0xff, 0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x7b, 0xc7, 0xc7, 0xc7, 0xff, 0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0xcf, 0xa3, 0x86, 0xc, 0x18, 0x0,

    /* U+0073 "s" */
    0x7c, 0xee, 0x7e, 0x2, 0xe7, 0x7e,

    /* U+0074 "t" */
    0x30, 0x60, 0xc7, 0xe3, 0x6, 0xc, 0xc, 0xe,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0x7b,

    /* U+0076 "v" */
    0xc1, 0xa0, 0x88, 0x82, 0x81, 0x80, 0x40,

    /* U+0077 "w" */
    0xc1, 0xec, 0xf6, 0x7b, 0x37, 0xd3, 0x38,

    /* U+0078 "x" */
    0xe3, 0xb3, 0x8f, 0x4, 0xc6, 0x77, 0x1c,

    /* U+0079 "y" */
    0x61, 0x90, 0x87, 0x81, 0x0, 0x81, 0xc1, 0x81,
    0xc0,

    /* U+007A "z" */
    0xff, 0xfe, 0xc, 0x30, 0x7f, 0xff,

    /* U+007B "{" */
    0x3c, 0xc3, 0xc, 0xc0, 0xc3, 0xc, 0x3c,

    /* U+007C "|" */
    0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xe1, 0x8c, 0x61, 0x98, 0xc6, 0xe0,

    /* U+007E "~" */
    0x73, 0x38,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xc3, 0xff, 0xc0,

    /* U+00A2 "¢" */
    0xc, 0xc, 0x7f, 0x4c, 0xcc, 0x4c, 0x7f, 0xc,
    0xc,

    /* U+00A3 "£" */
    0x3e, 0x22, 0x63, 0x60, 0xf8, 0x30, 0x30, 0x33,
    0xee,

    /* U+00A4 "¤" */
    0xc3, 0x42, 0x7e, 0x42, 0xc3, 0x42, 0x7e, 0x42,
    0xc3,

    /* U+00A5 "¥" */
    0xc1, 0xa0, 0x88, 0x83, 0x80, 0x83, 0xf8, 0x20,
    0xfe, 0x8, 0x0,

    /* U+00A6 "¦" */
    0xff, 0x3f, 0xc0,

    /* U+00A7 "§" */
    0xfe, 0xd1, 0x3, 0xe4, 0x58, 0xd1, 0x3e, 0x7,
    0xdd, 0xf0,

    /* U+00A8 "¨" */
    0xd8,

    /* U+00A9 "©" */
    0x3e, 0x61, 0xf6, 0x7e, 0xbf, 0x1f, 0x8f, 0xf7,
    0x83, 0x43, 0x1f, 0x0,

    /* U+00AA "ª" */
    0x7e, 0x7f, 0x31, 0x9f, 0xff, 0xf8, 0x3, 0xff,
    0xff,

    /* U+00AB "«" */
    0x3d, 0xde, 0xe7, 0x33, 0x18, 0x73, 0x1e, 0xe3,
    0xdc,

    /* U+00AC "¬" */
    0xfe, 0xc, 0x18, 0x30,

    /* U+00AE "®" */
    0x3e, 0x61, 0xfe, 0x7e, 0xbf, 0x1f, 0xcf, 0xd7,
    0x83, 0x43, 0x1f, 0x0,

    /* U+00B0 "°" */
    0x72, 0xb6, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 168, .box_w = 7, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 7, .adv_w = 168, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 20, .adv_w = 168, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 32, .adv_w = 168, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 168, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 168, .box_w = 3, .box_h = 4, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 59, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 168, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 168, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 87, .adv_w = 168, .box_w = 3, .box_h = 4, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 89, .adv_w = 168, .box_w = 7, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 90, .adv_w = 168, .box_w = 2, .box_h = 1, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 168, .box_w = 4, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 168, .box_w = 2, .box_h = 6, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 168, .box_w = 3, .box_h = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 168, .box_w = 7, .box_h = 5, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 203, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 168, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 390, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 168, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 168, .box_w = 9, .box_h = 4, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 507, .adv_w = 168, .box_w = 9, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 509, .adv_w = 168, .box_w = 3, .box_h = 2, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 510, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 168, .box_w = 8, .box_h = 7, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 562, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 168, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 587, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 630, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 638, .adv_w = 168, .box_w = 7, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 644, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 658, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 671, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 678, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 685, .adv_w = 168, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 694, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 168, .box_w = 6, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 707, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 710, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 168, .box_w = 7, .box_h = 2, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 718, .adv_w = 168, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 722, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 731, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 740, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 749, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 168, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 773, .adv_w = 168, .box_w = 5, .box_h = 1, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 774, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 168, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 795, .adv_w = 168, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 804, .adv_w = 168, .box_w = 7, .box_h = 4, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 808, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 168, .box_w = 5, .box_h = 4, .ofs_x = 3, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 0, 13, 0,
    14
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 33, .range_length = 94, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 17, .glyph_id_start = 95,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_1, .list_length = 17, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t teletext_14 = {
#else
lv_font_t teletext_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if TELETEXT_14*/
