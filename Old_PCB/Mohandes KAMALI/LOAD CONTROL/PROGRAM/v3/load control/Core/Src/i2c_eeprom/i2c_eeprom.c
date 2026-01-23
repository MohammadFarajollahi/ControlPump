/***********************************************************************************************
*	  			  EEPROM I2C
* File name		: I2C_EEPROM 
* Programmer 	: 
* Web presence  :  
* Note			:  
* Language		: 
* Hardware		: 
* Date			:  
************************************************************************************************/ 
#include "i2c_eeprom.h"
#include "eeprom_define.h"
//#include "delay.c"
//---------------------------------------------------------------------------------
uint8_t MAKE_8_FLOAT(float var,uint8_t offset){
union
{
uint8_t b[4];
float f;
} data;
data.f =var;


return data.b[offset];
}
//---------------------------------------------------------------------------------
float MAKE_FLOAT(uint8_t var1,uint8_t var2,uint8_t var3,uint8_t var4){
union
{
uint8_t b[4];
float f;
} data;
data.b[0]=var1;
data.b[1]=var2;
data.b[2]=var3;
data.b[3]=var4;


return data.f;
}
//----------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
void I2C_init(void)
{
 GPIO_InitTypeDef GPIO_InitStruct;
	
		I2C_SCL_RCC_ENABLE;
	  I2C_SDA_RCC_ENABLE;
/*I2C_SDA*/
  GPIO_InitStruct.Pin = I2C_SDA_BIT;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;	
  HAL_GPIO_Init(I2C_SDA_PORT, &GPIO_InitStruct);	
/*I2C_SCL*/
  GPIO_InitStruct.Pin = I2C_SCL_BIT;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;	
  HAL_GPIO_Init(I2C_SCL_PORT, &GPIO_InitStruct);
	

}
//-----------------------------------------------------------------------------------
void I2C_start()
{
//	osDelay(1);
SET_SDA;
//	delay_us(100);
SET_SCL;
//delay_us(100);
RESET_SDA;
//	delay_us(100);
RESET_SCL;
//	delay_us(100);
}
//-----------------------------------------------------------------------------------
void I2C_stop()
{
//		delay_us(100);
RESET_SCL;	
//		delay_us(100);
RESET_SDA;	
//		delay_us(100);
SET_SCL;
//		delay_us(100);
SET_SDA;	
//		delay_us(1000);
}
//-----------------------------------------------------------------------------------
uint8_t I2C_RW(uint8_t data,uint8_t ACK)
{
uint8_t i,j,k=0;	
 RESET_SCL;	
	    for(i=0,j=128;i<8;i++)
      {
      
       if((data&j)>0)	
       SET_SDA;							 
       else
       RESET_SDA;	
//       delay_us(100);			 
       SET_SCL; 
//			 delay_us(100);	
			 RESET_SCL;	
			     if((I2C_SDA_PORT->IDR & I2C_SDA_BIT)!=0)k|=j;
			 j>>=1;	
      }	
RESET_SDA;	

if(ACK==1)
{			
SET_SCL; 	
//			 delay_us(100);		
RESET_SCL;
//       delay_us(100);		
}

//delay_us(100);	

	
return k;			
}
//-----------------------------------------------------------------------------------
uint8_t EEPROM_WRIGHT(uint16_t address,uint8_t data)
{

uint8_t device_address=0xA0,k=0;	
	
k=address/256;	
k=k<<1;
device_address|=k;	

I2C_start();
I2C_RW(device_address,1);
I2C_RW(address,1);
I2C_RW(data,1);	
I2C_stop();		
	osDelay(15);
return 0;
}
//------------------------------------------------------------------------------------
uint8_t EEPROM_READ(uint16_t address)
{
	
uint8_t device_address;
uint8_t i,k[10];	

	for(i=0;i<9;i++){

k[i]=0;	
device_address=0xA0;	
k[i]=address/256;	
k[i]=k[i]<<1;
device_address|=k[i];	
		
I2C_start();
I2C_RW(device_address,1);		
I2C_RW(address,1);		
I2C_start();	

device_address=0xA1;	
k[i]=address/256;	
k[i]=k[i]<<1;
device_address|=k[i];	
	
I2C_RW(device_address,1);		
k[i]=I2C_RW(0xFF,0);	
	
	
I2C_stop();
osDelay(1);
if(i!=0)if(k[i-1]==k[i])return k[i];	
}

return k[0];

	
	
}
//************************************************************************************
uint8_t eeprom_write_int8(uint8_t var,uint16_t eeprom_i){
	EEPROM_WRIGHT(eeprom_i,(uint8_t) var);	
	return 0;
}
//************************************************************************************
//************************************************************************************
uint8_t eeprom_write_int24(uint32_t var,uint16_t eeprom_i){
EEPROM_WRIGHT(eeprom_i,(uint8_t) var);
	var>>=8;
EEPROM_WRIGHT(eeprom_i+1,(uint8_t) var);
	var>>=8;
EEPROM_WRIGHT(eeprom_i+2,(uint8_t) var);	
	return 0;
}
//************************************************************************************
//************************************************************************************
uint32_t eeprom_read_int24(uint16_t eeprom_i){
	uint32_t var=0;
	
var=EEPROM_READ(eeprom_i+2);
var<<=8;
var+=EEPROM_READ(eeprom_i+1);	
var<<=8;
var+=EEPROM_READ(eeprom_i);		
		return var;
}
//************************************************************************************
//************************************************************************************
uint8_t eeprom_write_int16(uint16_t var,uint16_t eeprom_i){
EEPROM_WRIGHT(eeprom_i,(uint8_t) var);
	var>>=8;
EEPROM_WRIGHT(eeprom_i+1,(uint8_t) var);
return 0;	
}
//************************************************************************************
//************************************************************************************
uint8_t eeprom_write_float(float var,uint16_t eeprom_i){
uint8_t i;
for(i=0;i<3;i++)	EEPROM_WRIGHT(eeprom_i+i,MAKE_8_FLOAT(var,i));
return 0;
}
//************************************************************************************
//************************************************************************************
uint8_t eeprom_read_int8(uint16_t eeprom_i){
uint8_t var;	
var=EEPROM_READ(eeprom_i);	
	return var;
}
//************************************************************************************
//************************************************************************************
uint16_t eeprom_read_int16(uint16_t eeprom_i){
	uint16_t var=0;
	
var=EEPROM_READ(eeprom_i+1);
var<<=8;
var+=EEPROM_READ(eeprom_i);	
		return var;
}
//************************************************************************************
//************************************************************************************
float eeprom_read_float(uint16_t eeprom_i){
uint8_t i[4];
float var=0;	
	
i[0]=EEPROM_READ(eeprom_i);
i[1]=EEPROM_READ(eeprom_i+1);
i[2]=EEPROM_READ(eeprom_i+2);
i[3]=EEPROM_READ(eeprom_i+3);	
var=MAKE_FLOAT(i[0],i[1],i[2],i[3]);	
	return var;
}
//************************************************************************************

