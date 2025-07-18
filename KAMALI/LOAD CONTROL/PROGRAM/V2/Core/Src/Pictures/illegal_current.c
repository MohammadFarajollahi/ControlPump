#ifndef __LED_illegal_current_STRUCTURE__   
#define __LED_illegal_current_STRUCTURE__ 
#ifndef _PICTURE_STRUCT_
#define _PICTURE_STRUCT_ 
typedef struct  
{
uint16_t LedWidth;               //Horizontal Pixel
uint16_t LedHeight;             //Vertical Pixel
uint8_t YplusOnXbyte;;            //Jump on next vertical after per YplusOnXbyte
const 	uint8_t* Icon;
}Picture2InfoTypeDef;
#endif
const uint8_t illegal_current_icon[]=
{
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,
0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,
0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,
0xff,0xff,0xff,0xff,0xfd,0xfd,0xff,0xff,
0xc7,0xff,0xff,0xf9,0xfd,0xef,0xff,0x81,
0xff,0xff,0xff,0xfd,0xe7,0xff,0xb0,0x3f,
0xff,0xff,0xbd,0xe7,0xff,0xfc,0x7f,0xff,
0xff,0x9d,0xf7,0xe7,0xf1,0xff,0xff,0xdf,
0x9c,0x07,0xe0,0x07,0xff,0xff,0xdf,0xde,
0x0f,0xf0,0x1f,0xff,0xff,0xdf,0xef,0xff,
0xfb,0xff,0xff,0xff,0x9f,0xff,0xff,0xf7,
0xff,0xff,0xff,0xcf,0x9f,0xcb,0xe7,0xf9,
0xff,0xff,0xc0,0x1f,0xfb,0x87,0xff,0xff,
0xff,0xe0,0x7f,0xff,0x0f,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xef,0xff,0xbf,0xff,0xff,0xff,
0xff,0xcf,0xff,0x3f,0xff,0xff,0xff,0xff,
0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,
0xf3,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,
0xbe,0x1f,0xff,0xff,0xff,0xc7,0xff,0xbc,
0x01,0xe7,0xff,0xff,0x83,0xff,0xbd,0xc3,
0xc3,0xff,0xff,0x7f,0xf9,0xbf,0xcf,0xdb,
0xff,0xef,0x3f,0xf9,0xbf,0x07,0xcb,0xe7,
0xcf,0x01,0xfd,0x80,0x30,0x03,0xe0,0x10,
0x03,0xfd,0xc0,0xf8,0x63,0xf0,0x30,0x3f,
0xfd,0xff,0xff,0xff,0xfb,0xff,0xff,0xf9,
0xff,0xff,0xff,0xf7,0xff,0xff,0xe3,0xff,
0x9f,0xff,0xe7,0xa7,0xff,0xc7,0xff,0xff,
0xff,0x87,0xb7,0xff,0xff,0xff,0xff,0xff,
0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff};
//Data Byte Quantity=266,it's about 0.2597656Kbyte
#endif
Picture2InfoTypeDef illegal_current_icon_Info={56,38,7,illegal_current_icon};
