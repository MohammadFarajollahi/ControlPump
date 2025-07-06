#ifndef __LED_ok_icon_STRUCTURE__   
#define __LED_ok_icon_STRUCTURE__ 
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
const uint8_t ok_icon[]=
{
0xff,0xfe,0xff,0xf6,0xff,0xe6,0xff,0xce,
0xff,0x9e,0xff,0x3e,0xfe,0x3e,0xcc,0x7e,
0xc0,0xfe,0xe0,0xfe,0xf1,0xfe,0xf1,0xfe,
0xfb,0xfe,0xff,0xfe,0xff,0xfe};
//Data Byte Quantity=30,it's about 0.02929688Kbyte
#endif
Picture2InfoTypeDef ok_icon_Info={15,15,2,ok_icon};
