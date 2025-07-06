
//************************************menu************************************
extern Picture2InfoTypeDef Setting_up;
extern Picture2InfoTypeDef Setting_down;
extern Picture2InfoTypeDef tanzim_manual;
extern  Picture2InfoTypeDef tanzim_Auto;
extern Picture2InfoTypeDef freeScreen;
extern Picture2InfoTypeDef Settinglogo;
extern Picture2InfoTypeDef StartVoltage;
extern Picture2InfoTypeDef StartTime;
extern Picture2InfoTypeDef kadr;
int menuSelect;
int changeMenu;

char lcdShow[20];

void BackTOtanzimDasti(){  
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
}

void tanzimDasti_start_voltage(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(5,0,StartVoltage);
  Lcd_Put_Icon2_Invert(5,30,kadr);
  Lcd_Put_Icon2_Invert(70,25,Setting_up);
  Lcd_Put_Icon2_Invert(70,45,Setting_down);
  
  sprintf(lcdShow , "%dV " , StartVoltage_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
   changeMenu = 0;
  while(1){
    
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      ++StartVoltage_eeprom;
      changeMenu = 1;
      HAL_Delay(250);
    }
    
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      --StartVoltage_eeprom;
      changeMenu = 1;
      HAL_Delay(250);
    }
    
    if(changeMenu == 1){
      changeMenu = 0;
      sprintf(lcdShow , "%dV " , StartVoltage_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }
    
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      sprintf(lcdShow , "%dV " , StartVoltage_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();
      eeprom_write_int16(StartVoltage_eeprom,0);
      BackTOtanzimDasti();
      break;
    }
    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
       
       
     }
    
    
  }
  
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
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(40,0,Setting_up);
      Lcd_Put_Icon2_Invert(40,50,Setting_down);
      Lcd_Put_Icon2_Invert(18,28,tanzim_manual);
      Lcd_Refresh();
      HAL_Delay(500);
      menuSelect =1;
      changeMenu = 0;
      HAL_Delay(750);
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
        Lcd_Clear();
        Lcd_Put_Icon2_Invert(0,0,logo); // YplusOnXbyte = (LedHeight + 7) / 8;
        Lcd_Refresh();
        char ss[20];
        sprintf(ss , "Voltage:%dV " , Voltage);
        lcd_putsf_point(0,0,ss,TAHOMA_8x10);
        lcd_putsf_point(0,10,"Soft Start",TAHOMA_8x10);
        Lcd_Refresh();
        HAL_Delay(750);
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