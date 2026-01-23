#ifndef __LED_cancel_icon_STRUCTURE__   
#define __LED_cancel_icon_STRUCTURE__ 
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
const uint8_t cancel_icon[]=
{
0xff,0xfe,0xff,0xfe,0xcf,0xe6,0xc7,0xc6,
0xe3,0x8e,0xf0,0x1e,0xf8,0x3e,0xf8,0x3e,
0xf8,0x3e,0xf0,0x1e,0xe3,0x8e,0xc7,0xc6,
0xcf,0xe6,0xff,0xfe,0xff,0xfe};
//Data Byte Quantity=30,it's about 0.02929688Kbyte
#endif
Picture2InfoTypeDef cancel_icon_Info={15,15,2,cancel_icon};
