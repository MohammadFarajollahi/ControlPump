
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
extern Picture2InfoTypeDef saved;
extern Picture2InfoTypeDef SoftStartTime;

int menuSelect;
int changeMenu;

char lcdShow[20];

void menuExit(){
  Voltage = StartVoltage_eeprom;
  Lcd_Clear();
   Lcd_Put_Icon2_Invert(0,45,logo); // YplusOnXbyte = (LedHeight + 7) / 8; // YplusOnXbyte = (LedHeight + 7) / 8;
  Lcd_Refresh();
  char ss[20];
  sprintf(ss , "Voltage:%dV " , Voltage);
  lcd_putsf_point(0,0,ss,TAHOMA_8x10);
  //lcd_putsf_point(0,40,"Press button",TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
}

//*************************************tanzim dasti******************************************
void BackTOtanzimDasti(){  
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(40,0,Setting_up);
  Lcd_Put_Icon2_Invert(40,50,Setting_down);
  Lcd_Put_Icon2_Invert(0,0,Settinglogo);
  //Lcd_Put_Icon2_Invert(5,28,StartVoltage);
  Lcd_Refresh();
  HAL_Delay(500); 
  changeMenu = 1;
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
      StartVoltage_eeprom+=5;
      changeMenu = 1;
      HAL_Delay(250);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      StartVoltage_eeprom-=5;
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
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(StartVoltage_eeprom,0);
      HAL_Delay(1000);
      BackTOtanzimDasti();
      break;
    }    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimDasti();
      break;
     }
       
  }
  
}


void tanzimDasti_start_time(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(5,0,StartTime);
  Lcd_Put_Icon2_Invert(5,30,kadr);
  Lcd_Put_Icon2_Invert(70,25,Setting_up);
  Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%dms " , StartTime_eeprom);
  lcd_putsf_point(15,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
   changeMenu = 0;
  while(1){   
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      StartTime_eeprom+=100;
      changeMenu = 1;
      HAL_Delay(200);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      StartTime_eeprom-=100;
      changeMenu = 1;
      HAL_Delay(200);
    }  
    
    if(StartTime_eeprom <100)StartTime_eeprom=100;
    
    if(changeMenu == 1){
      changeMenu = 0;
      sprintf(lcdShow , "%dms " , StartTime_eeprom);
      lcd_putsf_point(15,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(StartTime_eeprom,10);
      HAL_Delay(100);
      BackTOtanzimDasti();
      while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
      break;
    }   
    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimDasti();
      break;
     }
       
  }
  
}

void tanzimDasti_start_soft(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(5,0,SoftStartTime);
  Lcd_Put_Icon2_Invert(5,30,kadr);
  Lcd_Put_Icon2_Invert(70,25,Setting_up);
  Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%dms " , SoftTime_eeprom);
  lcd_putsf_point(15,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(250);
   changeMenu = 0;
  while(1){   
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      SoftTime_eeprom+=100;
      changeMenu = 1;
      HAL_Delay(200);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      SoftTime_eeprom-=100;
      changeMenu = 1;
      HAL_Delay(200);
    }   
    
    if(SoftTime_eeprom <100)SoftTime_eeprom =100;
    
    if(changeMenu == 1){
      changeMenu = 0;
      sprintf(lcdShow , "%dms " , SoftTime_eeprom);
      lcd_putsf_point(15,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(SoftTime_eeprom,20);
      HAL_Delay(1000);
      BackTOtanzimDasti();    
      while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
      break;
    }
    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimDasti();
      while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
      break;
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
      HAL_Delay(250);
    }
    
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      --menuSelect;
      changeMenu = 1;
      HAL_Delay(250);
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
      HAL_Delay(250);
      while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
      break;
    }
    
    if(menuSelect >3)menuSelect = 3;
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
      
      if(menuSelect == 3){
        Lcd_Put_Icon2_Invert(5,28,SoftStartTime);         
      }
      Lcd_Refresh();
    }
    
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      if(menuSelect == 1)tanzimDasti_start_voltage();
      if(menuSelect == 2)tanzimDasti_start_time();
      if(menuSelect == 3)tanzimDasti_start_soft();
      
    }
    
    
  }
}  

//*************************************main Menu******************************************
void menu(){
  
  //****menu****
  if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
    setting = 1;
    HAL_Delay(50);
    Lcd_Clear();
    Lcd_Put_Icon2_Invert(40,0,Setting_up);
    Lcd_Put_Icon2_Invert(40,50,Setting_down);
    Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
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
        menuExit(); 
        while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
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
          Lcd_Put_Icon2_Invert(2,25,tanzim_manual);            
        }         
        if(menuSelect == 2){
          Lcd_Put_Icon2_Invert(2,25,tanzim_Auto);            
        }
        Lcd_Refresh();
      }
      
      
      if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
        if(menuSelect == 1)tanzimDasti();
        
      }
      
      
    }
  }
  
}