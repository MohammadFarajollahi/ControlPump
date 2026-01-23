//################# icon###################
#include  "Pictures/Caution.c"
#include  "Pictures/open.c"
#include  "Pictures/lock.c"
#include  "Pictures/auto.c"
#include  "Pictures/input.c"
#include  "Pictures/output.c"
#include  "Pictures/adj_close.c"
#include  "Pictures/adj_open.c"
#include  "Pictures/ok.c"
#include  "Pictures/remote.c"
#include  "Pictures/remote1.c"
#include  "Pictures/snow.c"
#include  "Pictures/timer.c"
#include  "Pictures/bin.c"
#include  "Pictures/save.c"
#include  "Pictures/cancel.c"
#include  "Pictures/reset_factory_icon.c"
#include  "Pictures/back.c"
#include  "Pictures/bat.c"
#include  "Pictures/adler.c"
//#include  "Pictures/logo.c"
///////////////////////////////////////////
#include  "Pictures/test.c"
//#include  "Pictures/warning.c"
#include  "Pictures/caution2.c"
#include  "Pictures/wait.c"
#include  "Pictures/current_set.c"
#include  "Pictures/high_current1.c"
#include  "Pictures/low_current.c"
#include  "Pictures/reaction_time.c"
#include  "Pictures/retry_time.c"
#include  "Pictures/ok_button.c"
//#include  "Pictures/time_set.c"
//#include  "Pictures/menu_high_current.c"
//#include  "Pictures/menu_low_current.c"
//#include  "Pictures/menu_reacte_time.c"
//#include  "Pictures/menu_retry_time.c"
#include  "Pictures/exit1.c"
#include  "Pictures/return.c"
#include  "Pictures/up.c"
#include  "Pictures/down.c"
#include  "Pictures/amper.c"
#include  "Pictures/second.c"
#include  "Pictures/error.c"
#include  "Pictures/current.c"
#include  "Pictures/relay_off.c"
#include  "Pictures/relay_on.c"
#include  "Pictures/retry_number.c"
#include  "Pictures/number.c"
#include  "Pictures/loading.c"
#include  "Pictures/line.c"
#include  "Pictures/liney.c"
#include  "Pictures/input_open.c"
#include  "Pictures/input_close.c"
#include  "Pictures/output_open.c"
//#include  "Pictures/output_close.c"
#include  "Pictures/press_enter.c"
#include  "Pictures/illegal_current.c"
#include  "Pictures/pressure.c"
#include  "Pictures/current_A.c"
#include  "Pictures/pressure_A.c"
//#include  "Pictures/work_current.c"
#include  "Pictures/hc.c"
#include  "Pictures/lc.c"
#include  "Pictures/hc_manual.c"
#include  "Pictures/lc_manual.c"
#include  "Pictures/reset.c"
//#########################################
uint16_t status_function;
float ADC_Count;
float ADC_sensor;
uint16_t ssss;
float Current ;
int i=0;
#include "delay.c"
#include "nokia1202/nokia1202.c"
#include "lcd1202.c"
#include "slave.h"
#include "i2c_eeprom/i2c_eeprom.c"
#include "menu.c"


void slave(void){
char lcd[20];

I2C_init();


for(int i = 0 ; i < 5;i++){
 parameter[i] = read_para(i);
  parameter[i]= parameter[i]/10;
  HAL_Delay(50);
  
}


//{//######################################################################## init	
//IO_init();                            //io init
//internal_network_config();            //networl init
//SET_BACK_LIGHT;	                      //back ligh turn on
lcdinit();

//I2C_init();	
//	
//}//#########################################################################
//{//##################################################################### startup
Lcd_Clear();

//Lcd_Put_Icon2_Invert(0,0,Aran_ICON_Info); 
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1,GPIO_PIN_SET);
          HAL_TIM_Base_Start_IT(&htim1);
          
          
    lcd_putsf_point(30,20,"Aran",TAHOMA_8x10);
     lcd_putsf_point(10,35,"Electronic",TAHOMA_8x10);
    Lcd_Refresh();
    HAL_Delay(3000);

while(1){
  
  //parameter[2]=5;
    //parameter[1]=0;
     //parameter[3]=30;
      //parameter[1]=3;
 // pressure_high=parameter[5]+50;
 //pressure_low=parameter[5]-50;

     //HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
 
    
      /*  for ( j=0 ; j<80 ; j++) {
      
           b0  +=buffer[0];
           HAL_Delay(10);
        }
       
           b0 /= 80 ;
           HAL_Delay(100);  */

           Lcd_Refresh();	
       
     //  Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
      // Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);            
     //  Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
     //  Lcd_Put_Icon2_Invert(0,66,line_icon_Info); 
    
           
    /*  if(error_mode==1){
           
         if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){ 

         
           error_mode=0;
           retry_cancel=0;
           
       }
           
      }      */     
   

   if(retry_cancel==0 && error_mode==0){
            
      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==0){    //automatic is on
        
          retry_counter=0;
          relay_counter_flag=0;
          relay_mode=1;
          b++;

        if ( startup_reset_flag==0 && startup_mode==1 ) {
            HAL_TIM_Base_Start_IT(&htim3);
        }
       
            //HAL_TIM_Base_Stop_IT(&htim14);
            sampling_timer=0;
            
        /*    if( Current<parameter[1] | Current>parameter[0]){
            
            retry_cancel=1;
            }*/
            
            if ( Current<parameter[0] && Current>parameter[1] ){
            
              HAL_TIM_Base_Stop_IT(&htim14);
              relay_counter=0;
            }
            
                if(startup_reset_flag==1){
                    relay_counter=0;
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_SET);

                    dis_mode=2;
                    startup_mode=2;
                    menu_mode=0;
                    startup_reset=0;
                    startup_reset_flag=0;
                    HAL_TIM_Base_Stop_IT(&htim3);
                }
      }
 

      else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==1){   //automatic is off
           timer=0;
           sampling_timer=0;
           //startup_counter=0;
           startup_set_flag=0;
           a++;
           relay_counter=0; 
           //menu_mode=1;
           HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
           
                               
        for ( j=0 ; j<40 ; j++) { 
          b1  +=buffer[1];   
          HAL_Delay(7);
         }
       
        b1 /= 40 ;  
        ADC_CF = b1 + CFF;    
        adc = ADC_CF - (ADC_CF*CF); 
 
         if (adc<20 | adc>700){
              Current=0;
         }
           
         else if (adc>=21 && adc<=250){
            Current = ( adc + 47.818) / 93.309 ;     
         }
        
         else if (adc>251 && adc<=700){
            Current = ( adc - 54.888) / 61.022 ;
         }      
                    
            if( HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==0 && Current>0.2 ){ 
              
              
              check_1=0;
                 check_2=1;   
               check= check_2 - check_1;
                 
               tv= check*10;
               check_para=tv;
               parameter[6]=check_para;
               eeprom_write_int16(tv,VirtAddVarTab[6]);
           }
           
         else if(  HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==1 && Current>0.2 ){ 
              
              
              check_1=0;
                 check_2=2;   
               check= check_2 - check_1;
                 
               tv= check*10;
               check_para=tv;
               parameter[6]=check_para;
               eeprom_write_int16(tv,VirtAddVarTab[6]);
           }         
         
           
           dis_mode=1;
           startup_mode=1;
           menu_mode=0;

           HAL_TIM_Base_Stop_IT(&htim17);
           //HAL_TIM_Base_Stop_IT(&htim14);
           HAL_TIM_Base_Start_IT(&htim3);
       
           if(startup_reset_flag==1){
              HAL_TIM_Base_Stop_IT(&htim3);
           }

                  if(retry_counter==parameter[3]){
                       HAL_TIM_Base_Stop_IT(&htim16);
                  }
      }
   }


       
     Display();
              
     setting_mode();
     
     Relay_setting();
         
   }		
}





//==============================================================================



