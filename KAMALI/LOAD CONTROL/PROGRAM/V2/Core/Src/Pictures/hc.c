#ifndef __LED_hc_STRUCTURE__   
#define __LED_hc_STRUCTURE__ 
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
const uint8_t hc_icon[]=
{
0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,
0xef,0xff,0xff,0xff,0xff,0xfe,0xfd,0xe9,
0xff,0xff,0x3f,0xff,0xfe,0xfc,0xed,0xff,
0xff,0xbf,0xff,0xfe,0xec,0x6d,0xff,0xff,
0xbf,0xff,0xfe,0xef,0x7d,0xdf,0xcf,0xbb,
0xff,0x1e,0xff,0x9d,0xdf,0xff,0xbb,0xfe,
0x02,0xff,0x9d,0xdf,0xfb,0xbb,0xf7,0xe2,
0xef,0x5c,0x1f,0x79,0x83,0xe0,0x0e,0xee,
0x1c,0x3f,0xfd,0x87,0xf0,0x3e,0xff,0xff,
0xfe,0xfd,0xff,0xff,0xfe,0xff,0xff,0xfe,
0x7d,0xff,0xf7,0xee,0xff,0xff,0x9f,0x03,
0xf5,0xe7,0xee,0xff,0xff,0xff,0x87,0xff,
0x8f,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,
0xfe};
//Data Byte Quantity=105,it's about 0.1025391Kbyte
#endif
Picture2InfoTypeDef hc_icon_Info={55,15,7,hc_icon};
