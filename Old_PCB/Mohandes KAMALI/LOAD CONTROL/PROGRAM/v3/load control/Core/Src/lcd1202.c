#ifndef __LCD1202_C_INCLUDED__
#define  __LCD1202_C_INCLUDED__
 
#include "lcd1202.h"
 
 
 
 #include "Arial6x8.c" 
 #include "Tahoma8x10.c"
 
 
 
 
     
 
  
Lcd1202RegTypeDef Lcd1;
 

 
#define __PIXEL_MODE__
//---------------------------------------------------------------------------------------------
//base Region of lcd such as init ,write data etc.
#ifndef _REGION_LCD1202_BASE_
#define _REGION_LCD1202_BASE_
  
void _delay(uint32_t delay)
{
	while(--delay);
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcd_port_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	LCD_SDA_CLOCK;
	LCD_CS_CLOCK; 
	LCD_CLK_CLOCK;
	LCD_RESET_CLOCK;
	
	
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	//SDA
  GPIO_InitStruct.Pin = LCD_SDA_PIN;
  HAL_GPIO_Init(LCD_SDA_PORT, &GPIO_InitStruct);
	//CS
  GPIO_InitStruct.Pin = LCD_CS_PIN;
  HAL_GPIO_Init(LCD_CS_PORT, &GPIO_InitStruct);
	//CLK
  GPIO_InitStruct.Pin = LCD_CLK_PIN;
  HAL_GPIO_Init(LCD_CLK_PORT, &GPIO_InitStruct);
	//RESET
  GPIO_InitStruct.Pin = LCD_RESET_PIN;
  HAL_GPIO_Init(LCD_RESET_PORT, &GPIO_InitStruct);
}	
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcdreset(void)		
{
	LCD_RESET_LOW();
	HAL_Delay(50);
	LCD_RESET_HIGH();
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcdsend(unsigned char bits8, unsigned char cord)	/*fungsi ini digunakan untuk mengirim data*/
{						/*atau fungsi ke lcd*/
	int loop_send; 
uint16_t i;	

	LCD_CS_LOW();
	if(cord)            
	 { LCD_SDA_HIGH();}
	 else
	 {LCD_SDA_LOW();}
   LCD_CLK_HIGH();
	 _delay(20);
	for(loop_send=7;loop_send>=0;loop_send--)        /*mengirim 8-bit selanjutnya*/
	{
      LCD_CLK_LOW();
		if((bits8>>loop_send) & 1)       
		{ LCD_SDA_HIGH();}
else{ LCD_SDA_LOW();}
//for(i=0;i<10;i++);
LCD_CLK_HIGH();
	}

	LCD_CLK_LOW();
	LCD_CS_HIGH();
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcd_gotoxy(uint8_t x,uint8_t y)
{
    char sequence[3];
	   
    sequence[0] = 0xB0 | (y & 0x0F);        //Y addressing: 1011yyyy
    sequence[1] = x & 0x0F;                 //X addressing: 0000xxxx, lower bits
    sequence[2] = 0x10 | ((x >> 4) & 0x07); //X addressing: 00010xxx, higher bits
	
	
	lcdsend(sequence[0],0);
	lcdsend(sequence[1],0);
	lcdsend(sequence[2],0);
   lcd_x= x;
   lcd_y = y;
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcdinit(void)               
{
//	LCD_RESET_LOW();
//	HAL_Delay(50);
	lcd_port_init();
	LCD_CLK_HIGH();
	LCD_CS_HIGH();
	LCD_RESET_HIGH();

	LCD_SDA_LOW();
	
	lcdreset();		/*atur ulang lcd*/
	
	lcdsend(0xe2, 0);	/*internal reset*/
	HAL_Delay(10);		/*tunda 10ms*/
	
	lcdsend(0xa4, 0);	/*power saver off (display all point off/black)*/
	lcdsend(0xa6, 0);	/*Normal mode not reversed  (0xA7==REVERSED)*/
	lcdsend(0x2f, 0);	/*power control set (booster off, voltage regulator off, voltage follower off)*/
        
     //   lcdsend(0xa1,0);	// set contrast	
        HAL_Delay(10);		/*tunda 10ms*/
	lcdsend(0x20 | 15,0);	// 20/32
        
        
	lcdsend(0xaf, 0);	/*display on*/
	
	
  //lcdsend(0xa7, 0); //display reverse
	
	
	//lcdsend(0xc8, 0); //display upside down
	//lcdsend(0xa1, 0); //display row 
}


/*fungsi lcdsend()---------------------------------------------------------------------------*/
#endif




//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#ifdef __PIXEL_MODE__

//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_X_Plus()
{
	if((Lcd1.Y>Lcd1.Y_End)&&(Lcd1.X>Lcd1.X_End)) return;
	++Lcd1.X;
if(Lcd1.X>Lcd1.X_End)
  {	
	Lcd1.X=Lcd1.X_Start;
	if(Lcd1.Y<Lcd1.Y_End) {Lcd1.Y++;}
	//else                  {Lcd1.Y=Lcd1.Y_Start;}
  }
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//---------------------------------------------------------------
/** @brief   Sets a pixel on x and y position
* @param x: Horizontal position
* @param y: Vertical position
* @param pixel:if it's '0' resets pixel,otherwise sets it
*/
//------------------------------------------------------------------
void Lcd_Set_Pixel(uint8_t x,uint8_t y,uint8_t pixel)
{
	uint8_t d,d1;
	
	d=y/8;     //calculate Row
	d1=y%8;    //shift
	//Now prepare
	if(pixel>0)  {pixel=1;}
	//set
if(pixel) {Lcd1.Memory[x][d]|=(1<<d1);}
//reset
else      {Lcd1.Memory[x][d]&=~(1<<d1);}	

}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Put_Pixel_xy(uint8_t x,uint8_t y,uint8_t pixel)
{
	uint8_t d,d1;
	
	d=y/8;     //calculate Row
	d1=y%8;    //shift
	//Now prepare
	if(pixel>0)  {pixel=1;}
	//set
if(pixel) {Lcd1.Memory[x][d]|=(1<<d1);}
//reset
else      {Lcd1.Memory[x][d]&=~(1<<d1);}	
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Put_Pixel(uint8_t pixel)
{
	uint8_t d,d1;
	
	d=Lcd1.Y/8;     //calculate Row
	d1=Lcd1.Y%8;    //shift
	//Now prepare
	if(pixel>0)  {pixel=1;}
	//set
if(pixel) {Lcd1.Memory[Lcd1.X][d]|=(1<<d1);}
//reset
else      {Lcd1.Memory[Lcd1.X][d]&=~(1<<d1);}	
Lcd_X_Plus();
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Set_Area(uint8_t X1,uint8_t Y1,uint8_t X2,uint8_t Y2)
{
	Lcd1.X_Start=X1;
	Lcd1.Y_Start=Y1;
	Lcd1.X_End=X2;
	Lcd1.Y_End=Y2;
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Write_Pixel(uint8_t pixel)
{
	uint16_t d,d1;
	
	d=Lcd1.Y/8;     //calculate Row
	d1=Lcd1.Y%8;    //shift
	//Now prepare
	if(pixel>0)  {pixel=1;}
	//set
if(pixel) {Lcd1.Memory[Lcd1.X][d]|=(1<<d1);}
//reset
else      {Lcd1.Memory[Lcd1.X][d]&=~(1<<d1);}	
//Now Increment X position
Lcd_X_Plus();
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Refresh()
{
	uint8_t i,j;


//	lcd_port_init();
//	LCD_CLK_HIGH();
//	LCD_CS_HIGH();
//	LCD_RESET_HIGH();

//	LCD_SDA_LOW();
//	
//	lcdreset();		/*atur ulang lcd*/
//	
//	lcdsend(0xe2, 0);	/*internal reset*/
//	HAL_Delay(10);		/*tunda 10ms*/
//	
//	lcdsend(0xa4, 0);	/*power saver off (display all point off/black)*/
//	lcdsend(0xa6, 0);	/*Normal mode not reversed  (0xA7==REVERSED)*/
//	lcdsend(0x2f, 0);	/*power control set (booster off, voltage regulator off, voltage follower off)*/
//	lcdsend(0xaf, 0);	/*display on*/
//	
	
	
	lcd_gotoxy(0,0);
	for(j=0;j<9;j++)
	  {
			for(i=0;i<96;i++)
			  {
				lcdsend(Lcd1.Memory[i][j],1);
					//HAL_Delay(50);
				}
		}
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Clear()
{
	uint8_t i,j;

	
	lcd_gotoxy(0,0);
	for(j=0;j<9;j++)
	  {
			for(i=0;i<96;i++)
			  {
					Lcd1.Memory[i][j]=0;
				//lcdsend(Lcd1.Memory[i][j],1);
					//HAL_Delay(50);
				}
		}
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcd_test()
{

	while(1)
	{
		lcd_gotoxy(0,0);
	Lcd_Set_Pixel(0,0,1);
	Lcd_Refresh();	
	HAL_Delay(1000);
	Lcd_Set_Pixel(95,67,1);
		Lcd_Refresh();
	HAL_Delay(1000);
		
		Lcd_Set_Pixel(0,0,0);
		Lcd_Refresh();
	HAL_Delay(1000);
	Lcd_Set_Pixel(95,67,0);
		Lcd_Refresh();
	HAL_Delay(1000);
		
	}
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Invert()
{
	uint8_t i,j;
	lcd_gotoxy(0,0);
	for(j=0;j<9;j++)
	  {
			for(i=0;i<96;i++)
			  {
				lcdsend(~Lcd1.Memory[i][j],1);
					//HAL_Delay(50);
				}
		}
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Put_Icon1(uint16_t Xpos,uint16_t Ypos,const uint8_t * Icon,uint16_t width,uint16_t height,uint8_t XjumpAfter)
{
	uint8_t d;
	uint32_t bit_counter=0,x,y,byte_counter=0;
	for(y=0;y<height;y++)
	{
		d=Icon[y*XjumpAfter];
		byte_counter=0;
		bit_counter=0;
		for(x=0;x<width;x++)
		{
			 if(d & (1<<(7-(x%8)) ))
			 
			{Lcd_Put_Pixel_xy(Xpos+x,Ypos+y,1);}
			else
			{Lcd_Put_Pixel_xy(Xpos+x,Ypos+y,0);}
			bit_counter++;
			if(bit_counter>=8)
			{
				bit_counter=0;
				byte_counter++;
				d=Icon[(y*XjumpAfter)+byte_counter];
			}
			//HAL_Delay(10);
		}
	}
	
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Put_Icon2(uint16_t Xpos,uint16_t Ypos,Picture2InfoTypeDef Pic)
{
	uint8_t d;
	uint32_t bit_counter=0,x,y,byte_counter=0;
	for(y=0;y<Pic.LedHeight;y++)
	{
		d=Pic.Icon[y*Pic.YplusOnXbyte];
		byte_counter=0;
		bit_counter=0;
		for(x=0;x<Pic.LedWidth;x++)
		{
			 if(d & (1<<(7-(x%8)) ))
			 
			{Lcd_Put_Pixel_xy(Xpos+x,Ypos+y,1);}
			else
			{Lcd_Put_Pixel_xy(Xpos+x,Ypos+y,0);}
			bit_counter++;
			if(bit_counter>=8)
			{
				bit_counter=0;
				byte_counter++;
				d=Pic.Icon[(y*Pic.YplusOnXbyte)+byte_counter];
			}
			//HAL_Delay(10);
		}
	}
	
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Put_Icon2_Invert(uint16_t Xpos,uint16_t Ypos,Picture2InfoTypeDef Pic)
{
	uint8_t d;
	uint32_t bit_counter=0,x,y,byte_counter=0;
	for(y=0;y<Pic.LedHeight;y++)
	{
		d=Pic.Icon[y*Pic.YplusOnXbyte];
		byte_counter=0;
		bit_counter=0;
		for(x=0;x<Pic.LedWidth;x++)
		{
			 if(d & (1<<(7-(x%8)) ))
			 
			{Lcd_Put_Pixel_xy(Xpos+x,Ypos+y,0);}
			else
			{Lcd_Put_Pixel_xy(Xpos+x,Ypos+y,1);}
			bit_counter++;
			if(bit_counter>=8)
			{
				bit_counter=0;
				byte_counter++;
				d=Pic.Icon[(y*Pic.YplusOnXbyte)+byte_counter];
			}
			//HAL_Delay(10);
		}
	}
	
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Box2(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY,uint16_t Thickness)
{
uint16_t i,j;
//top Horizontal line	
for(j=StartY;j<StartY+Thickness;j++)
    {
	  for(i=StartX;i<EndX;i++)
      {
				Lcd_Put_Pixel_xy(i,j,1);
		  }
		}	
 //bottom horizontal line
for(j=EndY-Thickness;j<EndY;j++)
    {
	  for(i=StartX;i<EndX;i++)
      {
			Lcd_Put_Pixel_xy(i,j,1);
		  }
		}		
//left vertical
 for(j=StartX;j<StartX+Thickness;j++)
    {
	  for(i=StartY;i<EndY;i++)
      {
			Lcd_Put_Pixel_xy(j,i,1);
		  }
		}		
//Right vertical
 for(j=EndX-Thickness;j<EndX;j++)
    {
	  for(i=StartY;i<EndY;i++)
      {
			Lcd_Put_Pixel_xy(j,i,1);
		  }
		}	
 } 
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcdclr(void)	/*fungsi ini untuk menghapus tampilan*/
{
    	unsigned int loop;
    	lcdsend(0xB0, 0); 	/*atur alamat halaman (page address set), page 0*/
    	lcdsend(0x10, 0);	/*atur alamat kolom (collumn address set) 3-bit tertinggi, collumn 0*/
    	lcdsend(0x00, 0);	/*atur alamat kolom (collumn address set) 4-bit terendah, collumn 0*/

    	for(loop = 0; loop < 864; loop++)
    	{
        	lcdsend(0x00, 1);	/*ubah semua piksel menjadi 0*/
    	}
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_Putchar_Point(uint16_t x,uint16_t y,uint8_t c,FontStructTypeDef FONT)
{
	const uint16_t  FONT_WIDTH=6;
	const uint16_t  FONT_HEIGHT=8;
	const uint32_t  FONT_MASK=0x80;
  uint16_t i=0;
  uint16_t j=0;
  uint32_t tmp_char=0;
	
	if((x+(FONT.Width-1))>SCREEN_HOR_SIZE-1)   return;
	if(y+(FONT.Height-1)>SCREEN_VER_SIZE-1)   return;
	
	 
 //Start Writing data
for (j=0;j<FONT.Height;j++)
 {
			tmp_char=FONT.Data[((c-0x20)*FONT.Height)+j];
  for (i=0;i<FONT.Width;i++)
  {
  	if ((tmp_char & FONT.Mask)!= 0)  
       {
			 // LCD_WriteRAM(charColor);
		  	Lcd_Put_Pixel_xy(x+i,y+j,1);	 
			 }
	  
    else       {Lcd_Put_Pixel_xy(x+i,y+j,0);}
		tmp_char<<=1;
  }
 }	
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void Lcd_putsf(uint16_t x,uint16_t y,const unsigned char * text,FontStructTypeDef FONT)
{
	const uint16_t  FONT_WIDTH=6;
	uint8_t i=0;
	x*=6;
	y*=8;
	while(text[i])
	{
		Lcd_Putchar_Point(x,y,text[i],FONT);
		x+=FONT_WIDTH;
		i++;
	}
} 
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcd_putsf_point(uint16_t x,uint16_t y,const unsigned char * text,FontStructTypeDef FONT)
{
	const uint16_t  FONT_WIDTH=6;
	uint8_t i=0;
 
	while(text[i])
	{
		Lcd_Putchar_Point(x,y,text[i],FONT);
		x+=FONT.Width;
		i++;
	}
} 
//--------------------------------------------------------------------------------------------------------
#else
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcd_putchar6x8(uint8_t c) 
	{
	uint8_t line;
	uint8_t ch = 0, i;
	c = c - 32;
		
	for (line = 0; line < 6; line++) {
		ch = font6_8[c][line];
		//if(lcd_x<=LCD_MAX_X)
		//{
		 lcdsend(ch,1);
		 
		 lcd_x++;
		
	  //}
	}
}
	//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
void lcd_puts_xy_6x8(uint8_t x,uint8_t y,char* string)
{
	uint8_t i=0,xx,x1;
	 x1=x*6;
	 //xx=LCD_MAX_X-x1;
	//if(xx>=6) xx-=6;
	xx=x1;
	while(string[i])
	{
		 lcd_gotoxy(xx,y);
		 
		lcd_putchar6x8(string[i]);
		i++;
		xx+=6;
		if(xx>=LCD_MAX_X)
		  {  return;}
	}
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#endif



#endif
