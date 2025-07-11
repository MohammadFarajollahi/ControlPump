#ifndef __LED_Aran_ICON_STRUCTURE__   
#define __LED_Aran_ICON_STRUCTURE__ 
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
const uint8_t Aran_ICON[]=
{
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xf3,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xe1,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd1,
0xf0,0x8e,0x0e,0x10,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xd8,0xf8,0x49,0xc7,0x0c,
0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xb8,
0xf8,0xe8,0xc7,0x1c,0x7f,0xff,0xff,0xff,
0xff,0xff,0xff,0xb8,0xf8,0xf8,0xc7,0x1c,
0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xbc,
0x78,0xff,0x07,0x1c,0x7f,0xff,0xff,0xff,
0xff,0xff,0xff,0x00,0x78,0xfe,0x47,0x1c,
0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0x7e,
0x38,0xfc,0xc7,0x1c,0x7f,0xff,0xff,0xff,
0xff,0xff,0xfe,0xfe,0x38,0xf8,0xc7,0x1c,
0x7f,0xff,0xff,0xff,0xff,0xff,0xfc,0xfe,
0x18,0xf8,0x87,0x1c,0x7f,0xff,0xff,0xff,
0xff,0xff,0xf8,0x3c,0x00,0x7c,0x62,0x0c,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0x80,0x0c,0x3f,0xff,
0xff,0xdf,0xff,0xff,0xff,0xf8,0xff,0xff,
0xe3,0xce,0x3f,0xff,0xff,0xdf,0xff,0xff,
0xff,0xf8,0xff,0xff,0xe3,0xee,0x3f,0xff,
0xff,0x9f,0xff,0xff,0xff,0xf8,0xff,0xff,
0xe3,0x6e,0x3f,0xff,0xff,0x1f,0xff,0xff,
0xff,0xff,0xff,0xff,0xe3,0x7e,0x3c,0x3f,
0x86,0x04,0x23,0x83,0x84,0x30,0xf8,0x7f,
0xe2,0x7e,0x39,0x9e,0x23,0x1e,0x13,0x11,
0xc3,0x38,0xe2,0x3f,0xe0,0x7e,0x31,0x8e,
0x63,0x1e,0x3b,0x39,0xc7,0x38,0xe6,0x3f,
0xe2,0x7e,0x31,0x8c,0x7f,0x1e,0x3e,0x38,
0xc7,0x38,0xc7,0xff,0xe3,0x7e,0x30,0x0c,
0x7f,0x1e,0x3e,0x38,0xc7,0x38,0xc7,0xff,
0xe3,0x7e,0x31,0xfc,0x7f,0x1e,0x3e,0x38,
0xc7,0x38,0xc7,0xff,0xe3,0xf6,0x31,0xfc,
0x7f,0x1e,0x3e,0x38,0xc7,0x38,0xc7,0xff,
0xe3,0xf6,0x31,0xec,0x7f,0x1e,0x3f,0x39,
0xc7,0x38,0xc7,0xff,0xe3,0xe6,0x38,0xde,
0x3b,0x1a,0x3f,0x11,0xc7,0x38,0xe3,0xbf,
0x80,0x0c,0x1c,0x3f,0x07,0x84,0x1f,0x83,
0x83,0x10,0x70,0x7f,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};
//Data Byte Quantity=768,it's about 0.75Kbyte
#endif
Picture2InfoTypeDef Aran_ICON_Info={96,64,12,Aran_ICON};
