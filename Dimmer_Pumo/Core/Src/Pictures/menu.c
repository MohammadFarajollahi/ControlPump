
//************************************menu************************************
extern Picture2InfoTypeDef Setting_up;
extern Picture2InfoTypeDef Setting_down;
extern Picture2InfoTypeDef tanzim_manual;
extern  Picture2InfoTypeDef tanzim_Auto;
extern Picture2InfoTypeDef freeScreen;
extern Picture2InfoTypeDef Settinglogo;
extern Picture2InfoTypeDef StartVoltage;
extern Picture2InfoTypeDef StartTime;
int menuSelect;
int changeMenu;



void tanzimDasti_start_voltage(){
  
  
}


void tanzimDasti(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(40,0,Setting_up);
  Lcd_Put_Icon2_Invert(40,50,Setting_down);
  Lcd_Put_Icon2_Invert(0,0,Settinglogo);
  Lcd_Put_Icon2_Invert(5,28,StartVoltage);
  Lcd_Refresh();
  HAL_Delay(500);
  menuSelect =1;
  changeMenu = 0;
  while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
  while(1){
   
      
      if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
        ++menuSelect;
        changeMenu = 1;
        HAL_Delay(500);
      }
      
      if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
        --menuSelect;
        changeMenu = 1;
        HAL_Delay(500);
      }
      
      if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
        Lcd_Clear(); Lcd_Put_Icon2_Invert(0,0,logo); // YplusOnXbyte = (LedHeight + 7) / 8;
        Lcd_Refresh();
        char ss[20];
        sprintf(ss , "Voltage:%dV " , Voltage);
        lcd_putsf_point(0,0,ss,TAHOMA_8x10);
        lcd_putsf_point(0,10,"Soft Start",TAHOMA_8x10);
        Lcd_Refresh();
        HAL_Delay(1500);
        break;
      }
      
      if(menuSelect >2)menuSelect = 2;
      if(menuSelect <1)menuSelect = 1;
      
      if(changeMenu ==1 ){
        changeMenu = 0;
        Lcd_Clear();
        Lcd_Put_Icon2_Invert(40,0,Setting_up);
        Lcd_Put_Icon2_Invert(40,50,Setting_down);
         Lcd_Put_Icon2_Invert(0,0,Settinglogo);
        if(menuSelect == 1){
            Lcd_Put_Icon2_Invert(5,28,StartVoltage);
        }         
        if(menuSelect == 2){
           Lcd_Put_Icon2_Invert(5,28,StartTime);         
        }
        Lcd_Refresh();
      }
      
      
      if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
        if(menuSelect == 1)tanzimDasti_start_voltage();
        
      }
      
      
    }
}  
    
    
    
    
    
    void menu(){
      
      
      //****menu****
      if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
        HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
        setting = 1;
        HAL_Delay(50);
        Lcd_Clear();
        Lcd_Put_Icon2_Invert(40,0,Setting_up);
        Lcd_Put_Icon2_Invert(40,50,Setting_down);
        Lcd_Put_Icon2_Invert(18,28,tanzim_manual);
        Lcd_Refresh();
        HAL_Delay(500);
        menuSelect =1;
        changeMenu = 0;
        while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
        while(1){
          
          if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
            ++menuSelect;
            changeMenu = 1;
            HAL_Delay(500);
          }
          
          if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
            --menuSelect;
            changeMenu = 1;
            HAL_Delay(500);
          }
          
          if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
            Lcd_Clear(); Lcd_Put_Icon2_Invert(0,0,logo); // YplusOnXbyte = (LedHeight + 7) / 8;
            Lcd_Refresh();
            char ss[20];
            sprintf(ss , "Voltage:%dV " , Voltage);
            lcd_putsf_point(0,0,ss,TAHOMA_8x10);
            lcd_putsf_point(0,10,"Soft Start",TAHOMA_8x10);
            Lcd_Refresh();
            HAL_Delay(1500);
            break;
          }
          
          if(menuSelect >2)menuSelect = 2;
          if(menuSelect <1)menuSelect = 1;
          
          if(changeMenu ==1 ){
            changeMenu = 0;
            Lcd_Clear();
            Lcd_Put_Icon2_Invert(40,0,Setting_up);
            Lcd_Put_Icon2_Invert(40,50,Setting_down);
            if(menuSelect == 1){
              Lcd_Put_Icon2_Invert(18,28,tanzim_manual);            
            }         
            if(menuSelect == 2){
              Lcd_Put_Icon2_Invert(14,28,tanzim_Auto);            
            }
            Lcd_Refresh();
          }
          
          
          if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
            if(menuSelect == 1)tanzimDasti();
            
          }
          
          
        }
      }
      
    }