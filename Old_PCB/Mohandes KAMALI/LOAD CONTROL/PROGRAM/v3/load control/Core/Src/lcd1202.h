#ifndef __LCD1202_H_INCLUDED__
#define  __LCD1202_H_INCLUDED__
 
 
 /** 
    @brief
		this LCD driver is ste2007 which interfaces in 9 bit data serial
		first bit is command/data(0 is command) the rest 8 bit are CMD or data
		Y pixel=68
		X pixel=96
		it has 8 pixel in every page(it means you should write 8bit data instead of pixel)
		68/8=8  it has 8 page of 8 bit
		and 1 page 4 bit
 **/

#define SCREEN_HOR_SIZE 96
#define SCREEN_VER_SIZE 68 

#define LCD_MAX_X      95
#define LCD_MAX_Y      8      //page 8


//define MOSI PIN
#define LCD_SDA_CLOCK    __HAL_RCC_GPIOA_CLK_ENABLE();
#define LCD_SDA_PORT     GPIOA
#define LCD_SDA_PIN      GPIO_PIN_8
//define CS PIN
#define LCD_CS_CLOCK    __HAL_RCC_GPIOA_CLK_ENABLE();
#define LCD_CS_PORT     GPIOA
#define LCD_CS_PIN      GPIO_PIN_2
//define CLK PIN
#define LCD_CLK_CLOCK    __HAL_RCC_GPIOA_CLK_ENABLE();
#define LCD_CLK_PORT     GPIOA
#define LCD_CLK_PIN      GPIO_PIN_4
//define RESET PIN
#define LCD_RESET_CLOCK    __HAL_RCC_GPIOA_CLK_ENABLE();
#define LCD_RESET_PORT     GPIOA
#define LCD_RESET_PIN      GPIO_PIN_5


//operation SDA
#define LCD_SDA_LOW()     LCD_SDA_PORT->ODR&=~LCD_SDA_PIN
#define LCD_SDA_HIGH()    LCD_SDA_PORT->ODR|=LCD_SDA_PIN
//operation CS
#define LCD_CS_LOW()     LCD_CS_PORT->ODR&=~LCD_CS_PIN
#define LCD_CS_HIGH()    LCD_CS_PORT->ODR|=LCD_CS_PIN
//operation CLK
#define LCD_CLK_LOW()     LCD_CLK_PORT->ODR&=~LCD_CLK_PIN
#define LCD_CLK_HIGH()    LCD_CLK_PORT->ODR|=LCD_CLK_PIN
//operation RESET
#define LCD_RESET_LOW()     LCD_RESET_PORT->ODR&=~LCD_RESET_PIN
#define LCD_RESET_HIGH()    LCD_RESET_PORT->ODR|=LCD_RESET_PIN
/*membuat purwarupa (prototype) fungsi-----------------------------------------------------*/

uint8_t lcd_x=0,lcd_y=0;

typedef struct 
{
	/** @defgroup Lcd1202  
	 *  
	*/
	uint8_t Memory[96][9];           /*!< horizontal pixel=96 ,vertical pixel=68 ,68/8=8 page of 8 bit and
                                         one 4bit page in the bottom>	*/
	uint8_t X;                       /*!< horizontal position >*/ 
	
	uint8_t Y;                       /*!<Vartical position >*/ 
	
	uint8_t X_Start;                 /*!<Horizontal start Area which is set to be written >*/ 
	
	uint8_t X_End;                   /*!<Horizontal End Area which is set to be written >*/ 
	
	uint8_t Y_Start;                 /*!<Vertical Start  Area which is set to be written >*/ 
	
	uint8_t Y_End;                   /*!<Vertical End Area which is set to be written >*/ 
	
}Lcd1202RegTypeDef;


 
 
#ifndef _PICTURE_STRUCT_
#define _PICTURE_STRUCT_ 
typedef struct  
{
uint16_t LedWidth;               //Horizontal Pixel
uint16_t LedHeight;             //Vertical Pixel
uint8_t YplusOnXbyte;            //Jump on next vertical after per YplusOnXbyte
const 	uint8_t* Icon;
}Picture2InfoTypeDef;
#endif
 

 
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#endif
