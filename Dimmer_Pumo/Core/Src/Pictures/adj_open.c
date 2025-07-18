#ifndef __LED_adj_open_icon_STRUCTURE__   
#define __LED_adj_open_icon_STRUCTURE__ 
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
const uint8_t adj_open_icon[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xc0,0x7f,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7b,0xff,0xfd,0xe1,0xc0,
0x38,0x73,0xff,0xfc,0xe1,0xc0,0x38,0x67,
0xff,0xfe,0x61,0xc0,0x38,0x40,0x46,0x20,
0x21,0xc0,0x38,0x67,0xff,0xfe,0x61,0xc0,
0x38,0x73,0xff,0xfc,0xe1,0xc0,0x38,0x7b,
0xff,0xfd,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x38,0x7f,0xff,0xff,0xe1,0xc0,
0x38,0x7f,0xff,0xff,0xe1,0xc0,0x38,0x7f,
0xff,0xff,0xe1,0xc0,0x38,0x7f,0xff,0xff,
0xe1,0xc0,0x00,0x00,0x00,0x00,0x00,0x00
};
//Data Byte Quantity=240,it's about 0.234375Kbyte
#endif
Picture2InfoTypeDef adj_open_icon_Info={44,40,6,adj_open_icon};
