/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --stride 1 --align 1 --font EuropeanTeletextNuevo.ttf --range 32-382 --format lvgl -o teletext_14.c
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
    /* U+0020 " " */
    0x0,

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
    0x72, 0xb6, 0xe0,

    /* U+00B1 "±" */
    0x30, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x0, 0x1,
    0xfc,

    /* U+00B2 "²" */
    0xfb, 0xf7, 0xb0, 0xff, 0xf0,

    /* U+00B3 "³" */
    0xff, 0xcc, 0x3f, 0xf8,

    /* U+00B4 "´" */
    0x78,

    /* U+00B5 "µ" */
    0x63, 0x63, 0x63, 0x63, 0x7e, 0x60, 0x60, 0xc0,

    /* U+00B6 "¶" */
    0x7f, 0x7b, 0xfb, 0x7b, 0x1b, 0x1b, 0x1b, 0x1b,
    0x1b,

    /* U+00B7 "·" */
    0xc0,

    /* U+00B8 "¸" */
    0x3f,

    /* U+00B9 "¹" */
    0x37, 0xf3, 0x30,

    /* U+00BA "º" */
    0x7e, 0xff, 0xc3, 0xff, 0xff, 0x0, 0xff, 0xff,

    /* U+00BB "»" */
    0xef, 0x1d, 0xe3, 0x38, 0x63, 0x33, 0x9d, 0xee,
    0xf0,

    /* U+00BC "¼" */
    0xe3, 0xb6, 0x82, 0x3, 0x66, 0xdf, 0x7f, 0x6,

    /* U+00BD "½" */
    0x61, 0xf1, 0xdb, 0x4d, 0x81, 0xf3, 0xff, 0x31,
    0x9f,

    /* U+00BE "¾" */
    0xf8, 0xde, 0xe1, 0x60, 0x58, 0xff, 0x8d, 0xb7,
    0x7d, 0x83,

    /* U+00BF "¿" */
    0x30, 0x0, 0xc, 0x61, 0xc, 0xd2, 0x78,

    /* U+00C0 "À" */
    0x38, 0x0, 0x0, 0xf, 0xee, 0x3e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+00C1 "Á" */
    0xe, 0x0, 0x0, 0xf, 0xee, 0x3e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+00C2 "Â" */
    0x3e, 0x0, 0x0, 0xf, 0xee, 0x3e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+00C3 "Ã" */
    0x3f, 0x0, 0x0, 0xf, 0xee, 0x3e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+00C4 "Ä" */
    0x63, 0xe, 0x5, 0xc, 0x6c, 0x1e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+00C5 "Å" */
    0x1c, 0x1b, 0x5, 0xf, 0xec, 0x1e, 0xf, 0xff,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+00C6 "Æ" */
    0x3f, 0xb6, 0x33, 0x19, 0x8c, 0xff, 0xe3, 0x31,
    0x98, 0xcf, 0x80,

    /* U+00C7 "Ç" */
    0x3c, 0x24, 0x42, 0xc3, 0xc0, 0xc0, 0xc3, 0x42,
    0x7e, 0x18, 0x30,

    /* U+00C8 "È" */
    0x38, 0x0, 0x0, 0xff, 0xc0, 0xc0, 0xfc, 0xc0,
    0xc0, 0xff,

    /* U+00C9 "É" */
    0x1c, 0x0, 0x0, 0xff, 0xc0, 0xc0, 0xfc, 0xc0,
    0xc0, 0xff,

    /* U+00CA "Ê" */
    0x3c, 0x0, 0x0, 0xff, 0xc0, 0xc0, 0xfc, 0xc0,
    0xc0, 0xff,

    /* U+00CB "Ë" */
    0x66, 0x0, 0x0, 0xff, 0xc0, 0xc0, 0xfc, 0xc0,
    0xc0, 0xff,

    /* U+00CC "Ì" */
    0x78, 0x0, 0x7, 0xf3, 0x6, 0xc, 0x18, 0x31,
    0xfc,

    /* U+00CD "Í" */
    0x78, 0x0, 0x7, 0xf3, 0x6, 0xc, 0x18, 0x31,
    0xfc,

    /* U+00CE "Î" */
    0x7c, 0x0, 0x7, 0xf3, 0x6, 0xc, 0x18, 0x31,
    0xfc,

    /* U+00CF "Ï" */
    0x6c, 0x0, 0x7, 0xf1, 0x2, 0x4, 0x8, 0x11,
    0xfc,

    /* U+00D0 "Ð" */
    0x7e, 0x31, 0x98, 0x6c, 0x3f, 0x1b, 0xd, 0x86,
    0xc6, 0x7e, 0x0,

    /* U+00D1 "Ñ" */
    0x3f, 0x0, 0x0, 0x1c, 0x3d, 0x9e, 0x4f, 0x37,
    0x87, 0xc1, 0xe0, 0xc0,

    /* U+00D2 "Ò" */
    0x38, 0x0, 0x0, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+00D3 "Ó" */
    0x1c, 0x0, 0x0, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+00D4 "Ô" */
    0x3c, 0x0, 0x0, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+00D5 "Õ" */
    0x7e, 0x0, 0x0, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+00D6 "Ö" */
    0x66, 0x0, 0x0, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+00D7 "×" */
    0xc3, 0x7e, 0x3c, 0x3c, 0x7e, 0xe7,

    /* U+00D8 "Ø" */
    0x3, 0x7e, 0x4e, 0xcf, 0xdb, 0xdb, 0xf3, 0xf7,
    0x66, 0x7e, 0x40, 0xc0,

    /* U+00D9 "Ù" */
    0x30, 0x8, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x7e,

    /* U+00DA "Ú" */
    0xc, 0x10, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x7e,

    /* U+00DB "Û" */
    0x18, 0x3c, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x7e,

    /* U+00DC "Ü" */
    0x66, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x7e,

    /* U+00DD "Ý" */
    0x7, 0x3, 0x0, 0x3, 0x3, 0x73, 0x83, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0,

    /* U+00DE "Þ" */
    0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0xc3, 0xff, 0xc0,
    0xc0,

    /* U+00DF "ß" */
    0x3c, 0x24, 0x46, 0xde, 0xc2, 0xc3, 0xc3, 0xc3,
    0xdf, 0xc0, 0xc0,

    /* U+00E0 "à" */
    0x10, 0x4, 0x0, 0xf, 0xce, 0x73, 0xf9, 0xd,
    0xcf, 0x7f, 0x80,

    /* U+00E1 "á" */
    0x8, 0x8, 0x0, 0xf, 0xce, 0x73, 0xf9, 0xd,
    0xcf, 0x7f, 0x80,

    /* U+00E2 "â" */
    0x18, 0x1e, 0x0, 0xf, 0xce, 0x73, 0xf9, 0xd,
    0xcf, 0x7f, 0x80,

    /* U+00E3 "ã" */
    0x7f, 0x0, 0x0, 0xf, 0xce, 0x73, 0xf9, 0xd,
    0xcf, 0x7f, 0x80,

    /* U+00E4 "ä" */
    0x36, 0x0, 0x0, 0xf, 0xce, 0x73, 0xf9, 0xd,
    0xcf, 0x7f, 0x80,

    /* U+00E5 "å" */
    0x18, 0x1e, 0x6, 0x0, 0x7, 0xe7, 0x39, 0xfc,
    0x86, 0xe7, 0xbf, 0xc0,

    /* U+00E6 "æ" */
    0x7f, 0x4, 0xdf, 0xe9, 0xc, 0x83, 0xf8,

    /* U+00E7 "ç" */
    0x3c, 0x62, 0xe3, 0xc0, 0xe3, 0x3c, 0x10, 0x30,

    /* U+00E8 "è" */
    0x10, 0x8, 0x0, 0x7e, 0xe7, 0xff, 0xc0, 0xe3,
    0x7e,

    /* U+00E9 "é" */
    0x8, 0x10, 0x0, 0x7e, 0xe7, 0xff, 0xc0, 0xe3,
    0x7e,

    /* U+00EA "ê" */
    0x18, 0x3c, 0x0, 0x7e, 0xe7, 0xff, 0xc0, 0xe3,
    0x7e,

    /* U+00EB "ë" */
    0x33, 0x0, 0x0, 0x7f, 0xe3, 0xff, 0xc0, 0xe1,
    0x7f,

    /* U+00EC "ì" */
    0x61, 0x4, 0x7, 0x18, 0xc6, 0xf8,

    /* U+00ED "í" */
    0x19, 0x8, 0x7, 0x18, 0xc6, 0xf8,

    /* U+00EE "î" */
    0x22, 0xb6, 0x7, 0x18, 0xc6, 0xf8,

    /* U+00EF "ï" */
    0xf0, 0x1c, 0x63, 0x1b, 0xe0,

    /* U+00F0 "ð" */
    0x3, 0x3, 0x3, 0xf, 0x3, 0xff, 0xc3, 0xc3,
    0xc3, 0x7f,

    /* U+00F1 "ñ" */
    0xff, 0x0, 0x0, 0xde, 0xe3, 0xc3, 0xc3, 0xc3,
    0xc3,

    /* U+00F2 "ò" */
    0x10, 0x8, 0x0, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+00F3 "ó" */
    0x8, 0x10, 0x0, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+00F4 "ô" */
    0x18, 0x3c, 0x0, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+00F5 "õ" */
    0xfe, 0x0, 0x0, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+00F6 "ö" */
    0x66, 0x0, 0x0, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3,
    0x7e,

    /* U+00F7 "÷" */
    0x30, 0x0, 0x7, 0xf0, 0x0, 0xc, 0x0,

    /* U+00F8 "ø" */
    0x3, 0x7e, 0xcb, 0xdb, 0xdb, 0xd3, 0x7e, 0x40,
    0xc0,

    /* U+00F9 "ù" */
    0x10, 0x8, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0x7b,

    /* U+00FA "ú" */
    0x8, 0x10, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0x7b,

    /* U+00FB "û" */
    0x18, 0x3c, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0x7b,

    /* U+00FC "ü" */
    0x66, 0x0, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0x7b,

    /* U+00FD "ý" */
    0x4, 0x4, 0x0, 0xc, 0x32, 0x10, 0xf0, 0x20,
    0x10, 0x38, 0x30, 0x38, 0x0,

    /* U+00FE "þ" */
    0xc0, 0xc0, 0xc0, 0xde, 0xe3, 0xe3, 0xe3, 0xff,
    0xc0, 0xc0, 0xc0,

    /* U+00FF "ÿ" */
    0x33, 0x0, 0x0, 0xc, 0x32, 0x10, 0xf0, 0x20,
    0x10, 0x38, 0x30, 0x38, 0x0,

    /* U+0104 "Ą" */
    0x1c, 0x5, 0x6, 0x33, 0x6, 0xc1, 0xbf, 0xec,
    0x1b, 0x6, 0xc3, 0x80, 0xc0, 0x3c,

    /* U+0105 "ą" */
    0xff, 0x0, 0xc0, 0x31, 0xfc, 0xc3, 0x1f, 0xe0,
    0x60, 0x1f,

    /* U+0106 "Ć" */
    0x1c, 0x0, 0x0, 0x7e, 0xe7, 0xc0, 0xc0, 0xc3,
    0x66, 0x3c,

    /* U+0107 "ć" */
    0xc, 0x18, 0x0, 0x7f, 0x40, 0xc0, 0x40, 0x40,
    0x7f,

    /* U+0108 "Ĉ" */
    0x3c, 0x0, 0x0, 0x7e, 0xe7, 0xc0, 0xc0, 0xc3,
    0x66, 0x3c,

    /* U+0109 "ĉ" */
    0x1c, 0x36, 0x0, 0x7f, 0x40, 0xc0, 0x40, 0x40,
    0x7f,

    /* U+010C "Č" */
    0x3c, 0x0, 0x0, 0x7e, 0xe7, 0xc0, 0xc0, 0xc3,
    0x66, 0x3c,

    /* U+010D "č" */
    0x36, 0x1c, 0x0, 0x0, 0x7f, 0x40, 0xc0, 0x40,
    0x40, 0x7f,

    /* U+010E "Ď" */
    0x3c, 0x0, 0x0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3,
    0xc6, 0xfc,

    /* U+010F "ď" */
    0x3c, 0x18, 0x0, 0x3, 0x7b, 0xc7, 0xc7, 0xc7,
    0xc7, 0x7b,

    /* U+0118 "Ę" */
    0xff, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0,
    0xff, 0x30, 0x3c,

    /* U+0119 "ę" */
    0x7e, 0xc3, 0xc3, 0xff, 0xc0, 0x7e, 0x30, 0x3c,

    /* U+011A "Ě" */
    0x3c, 0x0, 0x0, 0xff, 0xc0, 0xc0, 0xfc, 0xc0,
    0xc0, 0xff,

    /* U+011B "ě" */
    0x3c, 0x18, 0x0, 0x0, 0x7e, 0xc3, 0xff, 0xc0,
    0xc0, 0x7e,

    /* U+011C "Ĝ" */
    0x3c, 0x0, 0x0, 0xff, 0xc0, 0xc0, 0xcf, 0xc3,
    0xc3, 0x7e,

    /* U+011D "ĝ" */
    0x18, 0x2c, 0x0, 0x7f, 0x47, 0xc7, 0x7b, 0x3,
    0x7f,

    /* U+0124 "Ĥ" */
    0x3e, 0x0, 0x0, 0x18, 0x3c, 0x1f, 0xff, 0x7,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+0125 "ĥ" */
    0x18, 0x3c, 0x0, 0xc0, 0xde, 0xe3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0131 "ı" */
    0x71, 0x8c, 0x63, 0x7c,

    /* U+0134 "Ĵ" */
    0x18, 0x2c, 0x3, 0x3, 0x3, 0x3, 0x3, 0xc3,
    0x66, 0x3c,

    /* U+0135 "ĵ" */
    0x10, 0x51, 0xb0, 0x0, 0x1, 0xc1, 0x83, 0x7,
    0x8d, 0xf0,

    /* U+0141 "Ł" */
    0x30, 0xc, 0x3, 0x20, 0xd8, 0x3c, 0x1c, 0xb,
    0x0, 0xc0, 0x3f, 0xc0,

    /* U+0142 "ł" */
    0x72, 0x68, 0xf7, 0x83, 0x6, 0x3f, 0x80,

    /* U+0143 "Ń" */
    0xc, 0x0, 0x0, 0x1c, 0x3d, 0x9e, 0x4f, 0x37,
    0x87, 0xc1, 0xe0, 0xc0,

    /* U+0144 "ń" */
    0x8, 0x10, 0x0, 0xde, 0xe3, 0xc3, 0xc3, 0xc3,
    0xc3,

    /* U+0147 "Ň" */
    0x3e, 0x0, 0x0, 0x1c, 0x3d, 0x9e, 0x4f, 0x37,
    0x87, 0xc1, 0xe0, 0xc0,

    /* U+0148 "ň" */
    0x3c, 0x18, 0x0, 0x0, 0xde, 0xe3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0152 "Œ" */
    0x77, 0xe6, 0x33, 0x19, 0x8c, 0xfe, 0x63, 0x31,
    0x98, 0x77, 0x80,

    /* U+0153 "œ" */
    0x7f, 0x6c, 0xf7, 0xfb, 0xd, 0x83, 0xf8,

    /* U+0158 "Ř" */
    0x3c, 0x0, 0x0, 0xff, 0xc3, 0xc3, 0xff, 0xc6,
    0xc2, 0xc3,

    /* U+0159 "ř" */
    0x3c, 0x30, 0x0, 0xc, 0xfa, 0x38, 0x60, 0xc1,
    0x80,

    /* U+015A "Ś" */
    0x18, 0x7e, 0xc0, 0xc0, 0xc0, 0x7f, 0x3, 0x3,
    0x3, 0x7e,

    /* U+015B "ś" */
    0x8, 0x10, 0x0, 0x7e, 0xc0, 0x7e, 0x2, 0x3,
    0x7e,

    /* U+015C "Ŝ" */
    0x3c, 0x0, 0x0, 0x7e, 0xc0, 0x7f, 0x3, 0x3,
    0x3, 0x7e,

    /* U+015D "ŝ" */
    0x18, 0x3c, 0x0, 0x7e, 0xc0, 0x7e, 0x2, 0x3,
    0x7e,

    /* U+0160 "Š" */
    0x3c, 0x0, 0x0, 0x7e, 0xc0, 0x7f, 0x3, 0x3,
    0x3, 0x7e,

    /* U+0161 "š" */
    0x3c, 0x18, 0x0, 0x0, 0x7e, 0xc0, 0x7e, 0x2,
    0x3, 0x7e,

    /* U+0164 "Ť" */
    0x7e, 0x0, 0x0, 0x1f, 0xf1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x0,

    /* U+0165 "ť" */
    0x34, 0x30, 0xc1, 0x8f, 0xc6, 0xc, 0x18, 0x18,
    0x1c,

    /* U+016C "Ŭ" */
    0x3c, 0x18, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x7e,

    /* U+016D "ŭ" */
    0x3c, 0x18, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7,
    0x7b,

    /* U+016E "Ů" */
    0x3c, 0x18, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0x7e,

    /* U+016F "ů" */
    0x18, 0x3c, 0x18, 0x0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc7, 0x7b,

    /* U+0178 "Ÿ" */
    0x32, 0x0, 0x0, 0x18, 0x37, 0x30, 0x60, 0x30,
    0x18, 0xc, 0x6, 0x0,

    /* U+0179 "Ź" */
    0x39, 0xfc, 0x30, 0x43, 0x86, 0xc, 0x18, 0x71,
    0xfc,

    /* U+017A "ź" */
    0x8, 0x10, 0x0, 0xff, 0xfe, 0xc, 0x30, 0x7f,
    0xff,

    /* U+017B "Ż" */
    0x30, 0x63, 0xf8, 0x60, 0x87, 0xc, 0x18, 0x30,
    0xe3, 0xf8,

    /* U+017C "ż" */
    0x18, 0x0, 0x0, 0x1f, 0xff, 0xf0, 0x70, 0xe0,
    0xff, 0xff, 0x80,

    /* U+017D "Ž" */
    0x7c, 0x0, 0x7, 0xf1, 0xc7, 0xc, 0x38, 0x61,
    0xfc,

    /* U+017E "ž" */
    0x3c, 0x18, 0x0, 0x0, 0xff, 0xfe, 0xc, 0x30,
    0x7f, 0xff
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 168, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 168, .box_w = 7, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 8, .adv_w = 168, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 21, .adv_w = 168, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 33, .adv_w = 168, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 168, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 168, .box_w = 3, .box_h = 4, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 60, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 168, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 168, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 88, .adv_w = 168, .box_w = 3, .box_h = 4, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 90, .adv_w = 168, .box_w = 7, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 91, .adv_w = 168, .box_w = 2, .box_h = 1, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 168, .box_w = 4, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 168, .box_w = 2, .box_h = 6, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 168, .box_w = 3, .box_h = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 168, .box_w = 7, .box_h = 5, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 204, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 168, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 286, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 391, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 168, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 168, .box_w = 9, .box_h = 4, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 508, .adv_w = 168, .box_w = 9, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 510, .adv_w = 168, .box_w = 3, .box_h = 2, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 511, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 168, .box_w = 8, .box_h = 7, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 563, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 578, .adv_w = 168, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 588, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 597, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 623, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 631, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 639, .adv_w = 168, .box_w = 7, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 168, .box_w = 7, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 168, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 695, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 701, .adv_w = 168, .box_w = 6, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 708, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 168, .box_w = 7, .box_h = 2, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 719, .adv_w = 168, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 732, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 761, .adv_w = 168, .box_w = 2, .box_h = 9, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 764, .adv_w = 168, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 774, .adv_w = 168, .box_w = 5, .box_h = 1, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 775, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 787, .adv_w = 168, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 796, .adv_w = 168, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 168, .box_w = 7, .box_h = 4, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 809, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 168, .box_w = 5, .box_h = 4, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 824, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 168, .box_w = 6, .box_h = 6, .ofs_x = 3, .ofs_y = 4},
    {.bitmap_index = 838, .adv_w = 168, .box_w = 5, .box_h = 6, .ofs_x = 3, .ofs_y = 4},
    {.bitmap_index = 842, .adv_w = 168, .box_w = 3, .box_h = 2, .ofs_x = 4, .ofs_y = 7},
    {.bitmap_index = 843, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 851, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 860, .adv_w = 168, .box_w = 2, .box_h = 1, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 861, .adv_w = 168, .box_w = 4, .box_h = 2, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 862, .adv_w = 168, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 865, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 873, .adv_w = 168, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 882, .adv_w = 168, .box_w = 9, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 890, .adv_w = 168, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 168, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 909, .adv_w = 168, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 928, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 940, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 952, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 976, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 988, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 999, .adv_w = 168, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1010, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1020, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1030, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1040, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1050, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1059, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1068, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1077, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1086, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1097, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1109, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1129, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1139, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1149, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1159, .adv_w = 168, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1165, .adv_w = 168, .box_w = 8, .box_h = 12, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1177, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1187, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1197, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1207, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1217, .adv_w = 168, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1230, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1239, .adv_w = 168, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1250, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1261, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1272, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1283, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1294, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1305, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1317, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1324, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1332, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1341, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1350, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1359, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1368, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1374, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1380, .adv_w = 168, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1386, .adv_w = 168, .box_w = 5, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1391, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1401, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1410, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1419, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1428, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1437, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1446, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1455, .adv_w = 168, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1462, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1471, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1480, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1489, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1498, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1507, .adv_w = 168, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1520, .adv_w = 168, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1531, .adv_w = 168, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1544, .adv_w = 168, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1558, .adv_w = 168, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1568, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1578, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1587, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1597, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1606, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1616, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1626, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1636, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1646, .adv_w = 168, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1657, .adv_w = 168, .box_w = 8, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1665, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1675, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1685, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1695, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1704, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1716, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1726, .adv_w = 168, .box_w = 5, .box_h = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1730, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1740, .adv_w = 168, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1750, .adv_w = 168, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1762, .adv_w = 168, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1769, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1781, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1790, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1802, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1812, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1823, .adv_w = 168, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1830, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1840, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1849, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1859, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1868, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1878, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1887, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1897, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1907, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1919, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1928, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1938, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1947, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1957, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1967, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1979, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1988, .adv_w = 168, .box_w = 8, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1997, .adv_w = 168, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2007, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2018, .adv_w = 168, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2027, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 0, 13
};

static const uint16_t unicode_list_3[] = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x8, 0x9,
    0xa, 0xb, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
    0x20, 0x21, 0x2d, 0x30, 0x31, 0x3d, 0x3e, 0x3f,
    0x40, 0x43, 0x44, 0x4e, 0x4f, 0x54, 0x55, 0x56,
    0x57, 0x58, 0x59, 0x5c, 0x5d, 0x60, 0x61, 0x68,
    0x69, 0x6a, 0x6b, 0x74, 0x75, 0x76, 0x77, 0x78,
    0x79, 0x7a
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 15, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_1, .list_length = 15, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 176, .range_length = 80, .glyph_id_start = 110,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 260, .range_length = 123, .glyph_id_start = 190,
        .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 50, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .cmap_num = 4,
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
