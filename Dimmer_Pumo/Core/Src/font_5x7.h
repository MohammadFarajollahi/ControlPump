/*
 * font_5x7.h
 *
 *  Created on: Mar 15, 2012
 *      Author: RG1540
 */

#ifndef FONT_5X7_H_
#define FONT_5X7_H_

const unsigned char font_5x7[][6] = {		// basic font
	 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 20
	,{0x00, 0x00, 0x5f, 0x00, 0x00, 0x00} // 21 !
	,{0x00, 0x07, 0x00, 0x07, 0x00, 0x00} // 22 "
	,{0x14, 0x7f, 0x14, 0x7f, 0x14, 0x00} // 23 #
	,{0x24, 0x2a, 0x7f, 0x2a, 0x12, 0x00} // 24 $
	,{0x23, 0x13, 0x08, 0x64, 0x62, 0x00} // 25 %
	,{0x36, 0x49, 0x55, 0x22, 0x50, 0x00} // 26 &
	,{0x00, 0x05, 0x03, 0x00, 0x00, 0x00} // 27 '
	,{0x00, 0x1c, 0x22, 0x41, 0x00, 0x00} // 28 (
	,{0x00, 0x41, 0x22, 0x1c, 0x00, 0x00} // 29 )
	,{0x14, 0x08, 0x3e, 0x08, 0x14, 0x00} // 2a *
	,{0x08, 0x08, 0x3e, 0x08, 0x08, 0x00} // 2b +
	,{0x00, 0x50, 0x30, 0x00, 0x00, 0x00} // 2c ,
	,{0x08, 0x08, 0x08, 0x08, 0x08, 0x00} // 2d -
	,{0x00, 0x60, 0x60, 0x00, 0x00, 0x00} // 2e .
	,{0x20, 0x10, 0x08, 0x04, 0x02, 0x00} // 2f /
	,{0x3e, 0x51, 0x49, 0x45, 0x3e, 0x00} // 30 0
	,{0x00, 0x42, 0x7f, 0x40, 0x00, 0x00} // 31 1
	,{0x42, 0x61, 0x51, 0x49, 0x46, 0x00} // 32 2
	,{0x21, 0x41, 0x45, 0x4b, 0x31, 0x00} // 33 3
	,{0x18, 0x14, 0x12, 0x7f, 0x10, 0x00} // 34 4
	,{0x27, 0x45, 0x45, 0x45, 0x39, 0x00} // 35 5
	,{0x3c, 0x4a, 0x49, 0x49, 0x30, 0x00} // 36 6
	,{0x01, 0x71, 0x09, 0x05, 0x03, 0x00} // 37 7
	,{0x36, 0x49, 0x49, 0x49, 0x36, 0x00} // 38 8
	,{0x06, 0x49, 0x49, 0x29, 0x1e, 0x00} // 39 9
	,{0x00, 0x36, 0x36, 0x00, 0x00, 0x00} // 3a :
	,{0x00, 0x56, 0x36, 0x00, 0x00, 0x00} // 3b ;
	,{0x08, 0x14, 0x22, 0x41, 0x00, 0x00} // 3c <
	,{0x14, 0x14, 0x14, 0x14, 0x14, 0x00} // 3d =
	,{0x00, 0x41, 0x22, 0x14, 0x08, 0x00} // 3e >
	,{0x02, 0x01, 0x51, 0x09, 0x06, 0x00} // 3f ?
	,{0x32, 0x49, 0x79, 0x41, 0x3e, 0x00} // 40 @
	,{0x7e, 0x11, 0x11, 0x11, 0x7e, 0x00} // 41 A
	,{0x7f, 0x49, 0x49, 0x49, 0x36, 0x00} // 42 B
	,{0x3e, 0x41, 0x41, 0x41, 0x22, 0x00} // 43 C
	,{0x7f, 0x41, 0x41, 0x22, 0x1c, 0x00} // 44 D
	,{0x7f, 0x49, 0x49, 0x49, 0x41, 0x00} // 45 E
	,{0x7f, 0x09, 0x09, 0x09, 0x01, 0x00} // 46 F
	,{0x3e, 0x41, 0x49, 0x49, 0x7a, 0x00} // 47 G
	,{0x7f, 0x08, 0x08, 0x08, 0x7f, 0x00} // 48 H
	,{0x00, 0x41, 0x7f, 0x41, 0x00, 0x00} // 49 I
	,{0x20, 0x40, 0x41, 0x3f, 0x01, 0x00} // 4a J
	,{0x7f, 0x08, 0x14, 0x22, 0x41, 0x00} // 4b K
	,{0x7f, 0x40, 0x40, 0x40, 0x40, 0x00} // 4c L
	,{0x7f, 0x02, 0x0c, 0x02, 0x7f, 0x00} // 4d M
	,{0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00} // 4e N
	,{0x3e, 0x41, 0x41, 0x41, 0x3e, 0x00} // 4f O
	,{0x7f, 0x09, 0x09, 0x09, 0x06, 0x00} // 50 P
	,{0x3e, 0x41, 0x51, 0x21, 0x5e, 0x00} // 51 Q
	,{0x7f, 0x09, 0x19, 0x29, 0x46, 0x00} // 52 R
	,{0x46, 0x49, 0x49, 0x49, 0x31, 0x00} // 53 S
	,{0x01, 0x01, 0x7f, 0x01, 0x01, 0x00} // 54 T
	,{0x3f, 0x40, 0x40, 0x40, 0x3f, 0x00} // 55 U
	,{0x1f, 0x20, 0x40, 0x20, 0x1f, 0x00} // 56 V
	,{0x3f, 0x40, 0x38, 0x40, 0x3f, 0x00} // 57 W
	,{0x63, 0x14, 0x08, 0x14, 0x63, 0x00} // 58 X
	,{0x07, 0x08, 0x70, 0x08, 0x07, 0x00} // 59 Y
	,{0x61, 0x51, 0x49, 0x45, 0x43, 0x00} // 5a Z
	,{0x00, 0x7f, 0x41, 0x41, 0x00, 0x00} // 5b [
	,{0x02, 0x04, 0x08, 0x10, 0x20, 0x00} // 5c �
	,{0x00, 0x41, 0x41, 0x7f, 0x00, 0x00} // 5d ]
	,{0x04, 0x02, 0x01, 0x02, 0x04, 0x00} // 5e ^
	,{0x40, 0x40, 0x40, 0x40, 0x40, 0x00} // 5f _
	,{0x00, 0x01, 0x02, 0x04, 0x00, 0x00} // 60 `
	,{0x20, 0x54, 0x54, 0x54, 0x78, 0x00} // 61 a
	,{0x7f, 0x48, 0x44, 0x44, 0x38, 0x00} // 62 b
	,{0x38, 0x44, 0x44, 0x44, 0x20, 0x00} // 63 c
	,{0x38, 0x44, 0x44, 0x48, 0x7f, 0x00} // 64 d
	,{0x38, 0x54, 0x54, 0x54, 0x18, 0x00} // 65 e
	,{0x08, 0x7e, 0x09, 0x01, 0x02, 0x00} // 66 f
	,{0x0c, 0x52, 0x52, 0x52, 0x3e, 0x00} // 67 g
	,{0x7f, 0x08, 0x04, 0x04, 0x78, 0x00} // 68 h
	,{0x00, 0x44, 0x7d, 0x40, 0x00, 0x00} // 69 i
	,{0x20, 0x40, 0x44, 0x3d, 0x00, 0x00} // 6a j
	,{0x7f, 0x10, 0x28, 0x44, 0x00, 0x00} // 6b k
	,{0x00, 0x41, 0x7f, 0x40, 0x00, 0x00} // 6c l
	,{0x7c, 0x04, 0x18, 0x04, 0x78, 0x00} // 6d m
	,{0x7c, 0x08, 0x04, 0x04, 0x78, 0x00} // 6e n
	,{0x38, 0x44, 0x44, 0x44, 0x38, 0x00} // 6f o
	,{0x7c, 0x14, 0x14, 0x14, 0x08, 0x00} // 70 p
	,{0x08, 0x14, 0x14, 0x18, 0x7c, 0x00} // 71 q
	,{0x7c, 0x08, 0x04, 0x04, 0x08, 0x00} // 72 r
	,{0x48, 0x54, 0x54, 0x54, 0x20, 0x00} // 73 s
	,{0x04, 0x3f, 0x44, 0x40, 0x20, 0x00} // 74 t
	,{0x3c, 0x40, 0x40, 0x20, 0x7c, 0x00} // 75 u
	,{0x1c, 0x20, 0x40, 0x20, 0x1c, 0x00} // 76 v
	,{0x3c, 0x40, 0x30, 0x40, 0x3c, 0x00} // 77 w
	,{0x44, 0x28, 0x10, 0x28, 0x44, 0x00} // 78 x
	,{0x0c, 0x50, 0x50, 0x50, 0x3c, 0x00} // 79 y
	,{0x44, 0x64, 0x54, 0x4c, 0x44, 0x00} // 7a z
	,{0x00, 0x08, 0x36, 0x41, 0x00, 0x00} // 7b {
	,{0x00, 0x00, 0x7f, 0x00, 0x00, 0x00} // 7c |
	,{0x00, 0x41, 0x36, 0x08, 0x00, 0x00} // 7d }
	,{0x10, 0x08, 0x08, 0x10, 0x08, 0x00} // 7e ~
	,{0x00, 0x06, 0x09, 0x09, 0x06, 0x00} // 7f Deg Symbol
	,{0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0} // 80 Cursor
};


#endif /* FONT_5X7_H_ */
