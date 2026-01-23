#ifndef __LED_line_STRUCTURE__   
#define __LED_line_STRUCTURE__ 
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
const uint8_t line_icon[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
//Data Byte Quantity=24,it's about 0.0234375Kbyte
#endif
Picture2InfoTypeDef line_icon_Info={96,2,12,line_icon};
