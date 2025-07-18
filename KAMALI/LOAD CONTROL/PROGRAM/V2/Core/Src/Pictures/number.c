#ifndef __LED_number_STRUCTURE__   
#define __LED_number_STRUCTURE__ 
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
const uint8_t number_icon[]=
{
0xff,0xff,0xfd,0x7f,0xff,0xe0,0xfd,0xff,
0xfd,0x7f,0xff,0x60,0xfb,0xff,0xff,0xff,
0xff,0xa0,0x3b,0xef,0xff,0xff,0xff,0xa0,
0x3b,0xc7,0xfe,0xff,0xe3,0xc0,0xf7,0xb7,
0xde,0xff,0xc3,0xc0,0xf3,0x97,0xde,0xf9,
0xcb,0xc0,0x3b,0x80,0x00,0xfc,0x03,0xa0,
0x3b,0xf8,0x31,0xfc,0x23,0xa0,0xfd,0xff,
0xff,0xfd,0xff,0x60,0xff,0xff,0xff,0xf9,
0xff,0xe0,0xff,0xff,0x9f,0xf1,0xff,0xe0,
0xff,0xff,0xff,0xe3,0xff,0xe0};
//Data Byte Quantity=78,it's about 0.07617188Kbyte
#endif
Picture2InfoTypeDef number_icon_Info={43,13,6,number_icon};
