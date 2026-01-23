//################# icon###################
//#include  "Pictures/Caution.c"
//#include  "Pictures/open.c"
//#include  "Pictures/lock.c"
//#include  "Pictures/auto.c"
//#include  "Pictures/input.c"
//#include  "Pictures/output.c"
//#include  "Pictures/adj_close.c"
//#include  "Pictures/adj_open.c"
//#include  "Pictures/ok.c"
//#include  "Pictures/remote.c"
//#include  "Pictures/remote1.c"
//#include  "Pictures/snow.c"
//#include  "Pictures/timer.c"
//#include  "Pictures/bin.c"
//#include  "Pictures/save.c"
//#include  "Pictures/cancel.c"
//#include  "Pictures/reset_factory_icon.c"
//#include  "Pictures/back.c"
//#include  "Pictures/bat.c"
//#include  "Pictures/adler.c"
//#include  "Pictures/logo.c"
///////////////////////////////////////////

#include  "Pictures/line.c"
#include  "Pictures/liney.c"
#include  "Pictures/high_current1.c"
#include  "Pictures/low_current.c"
#include  "Pictures/up.c"
#include  "Pictures/down.c"
#include  "Pictures/retry_time.c"
#include  "Pictures/retry_number.c"
#include  "Pictures/hc_manual.c"
#include  "Pictures/lc_manual.c"
#include  "Pictures/pressure.c"
#include  "Pictures/reaction_time.c"
#include  "Pictures/caution2.c"
#include  "Pictures/wait.c"
#include  "Pictures/exit1.c"
#include  "Pictures/current_set.c"
#include  "Pictures/return.c"
#include  "Pictures/ok_button.c"
#include  "Pictures/amper.c"
#include  "Pictures/second.c"
#include  "Pictures/error.c"
#include  "Pictures/current.c"
#include  "Pictures/relay_off.c"
#include  "Pictures/relay_on.c"
#include  "Pictures/number.c"
#include  "Pictures/loading.c"
#include  "Pictures/input_open.c"
#include  "Pictures/input_close.c"
#include  "Pictures/output_open.c"
#include  "Pictures/press_enter.c"
#include  "Pictures/illegal_current.c"
#include  "Pictures/current_A.c"
#include  "Pictures/pressure_A.c"
#include  "Pictures/hc.c"
#include  "Pictures/lc.c"
#include  "Pictures/reset.c"







//#include "delay.c"
#include "nokia1202/nokia1202.c"
#include "lcd1202.c"
#include "i2c_eeprom/i2c_eeprom.c"
//#include "menu.c"

#define buzzer_on   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  
#define buzzer_off  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); 

#define relay_on   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);  
#define relay_off  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET); 

float Read_AD(uint32_t channel)
{
ADC_ChannelConfTypeDef sConfig;		
float ad_out;

	
HAL_ADC_DeInit(&hadc);
HAL_ADC_Init(&hadc);
sConfig.Channel = channel ;
sConfig.Rank = 1;	
HAL_ADC_ConfigChannel(&hadc, &sConfig);
HAL_ADCEx_Calibration_Start(&hadc);	
	HAL_ADC_Start(&hadc);
	if (HAL_ADC_PollForConversion(&hadc, 100) == HAL_OK) 
//          HAL_Delay(15);
//       if(ADC_CHANNEL_TEMPSENSOR!=channel) {
         ad_out=HAL_ADC_GetValue(&hadc); 
//       }else {
 //        temp= HAL_ADC_GetValue(&hadc1);
 //        ad_out = (1.43 - (3.3/ 4096.0 * temp)) / 0.0043 + 25.0;
 //        return ad_out;
 //       return(__LL_ADC_CALC_TEMPERATURE (1800,temp,ADC_RESOLUTION_12B)); 
 //      }

ad_out*=3.3;
ad_out/=4095;

return ad_out;				
}


//******************************************************************************
void menu(void){
 char lcd[20];
  
  
                 Lcd_Clear();   
                 
               Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
               Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
               Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
               Lcd_Put_Icon2_Invert(0,66,line_icon_Info);    //frame lcd
 /*              
                Lcd_Put_Icon2_Invert(12,95,exit1_icon_Info);//exit frome menu
                Lcd_Put_Icon2_Invert(4,100,return_icon_Info);//return to menu                 
                Lcd_Put_Icon2_Invert(7,96,high_current1_icon_Info);//high current level             
                Lcd_Put_Icon2_Invert(34,118,down_icon_Info);       //down icon               
                Lcd_Put_Icon2_Invert(1,96,low_current_icon_Info);//low current level 
                Lcd_Put_Icon2_Invert(8,90,reaction_time_icon_Info);   //reaction time
                Lcd_Put_Icon2_Invert(2,97,retry_time_icon_Info);     //retry time                 
                Lcd_Put_Icon2_Invert(34,2,up_icon_Info);             //up                   
                Lcd_Put_Icon2_Invert(0,97,retry_number_icon_Info);       
                Lcd_Put_Icon2_Invert(8,89,hc_manual_icon_Info);    //high current manual           
                Lcd_Put_Icon2_Invert(3,91,lc_manual_icon_Info);                                 
                Lcd_Put_Icon2_Invert(27,98,pressure_icon_Info); 
                Lcd_Put_Icon2_Invert(40,36,amper_icon_Info); //amper                 
                Lcd_Put_Icon2_Invert(0,0,caution2_icon_Info);
                Lcd_Put_Icon2_Invert(0,0,wait_icon_Info); 
                Lcd_Put_Icon2_Invert(0,0,ok_button_icon_Info); 
                Lcd_Put_Icon2_Invert(0,0,current_set_icon_Info);                
                Lcd_Put_Icon2_Invert(0,0,second_icon_Info);   
                Lcd_Put_Icon2_Invert(0,0,error_icon_Info);    
                Lcd_Put_Icon2_Invert(0,0,current_icon_Info);   
                Lcd_Put_Icon2_Invert(0,0,relay_off_icon_Info);                                   
                Lcd_Put_Icon2_Invert(0,0,number_icon_Info);                      
                Lcd_Put_Icon2_Invert(0,0,loading_icon_Info); 
                Lcd_Put_Icon2_Invert(0,0,reset_icon_Info); 
*/
//               Lcd_Put_Icon2_Invert(27,98,pressure_icon_Info);
               
                    

               while(1){
           Lcd_Put_Icon2_Invert(23,4,relay_off_icon_Info);
             
           Lcd_Put_Icon2_Invert(42,37,current_A_icon_Info);
           sprintf(lcd, "%.02f " , 4.56 );
           lcd_putsf_point(3,37,lcd,TAHOMA_8x10);
             
           Lcd_Put_Icon2_Invert(55,20,pressure_icon_Info);
           sprintf(lcd, "%.01f " ,1.23 );
           lcd_putsf_point(3,20,lcd,TAHOMA_8x10);             
                    
//           sprintf(lcd, "%.01f " , 7.8 );
//           lcd_putsf_point(3,52,lcd,TAHOMA_8x10); 
//           Lcd_Put_Icon2_Invert(28,51,lc_icon_Info); 
              Lcd_Refresh();         
               osDelay(2000);
               }
               
               
}




