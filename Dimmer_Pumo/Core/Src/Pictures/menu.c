
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
extern Picture2InfoTypeDef tanzimfeshar;
extern Picture2InfoTypeDef DeviceMode;
extern Picture2InfoTypeDef SoftSet;
extern Picture2InfoTypeDef setcontrol;
extern Picture2InfoTypeDef Digitaldimerpic;
extern Picture2InfoTypeDef CurrentSettingpic;


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

void tanzimDasti_Current(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,CurrentSettingpic);
  Lcd_Put_Icon2_Invert(5,30,kadr);
  Lcd_Put_Icon2_Invert(70,25,Setting_up);
  Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%.1fA " , Current_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){   
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      Current_eeprom+=.1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      Current_eeprom-=.1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      changeMenu = 0;
      sprintf(lcdShow , "%.1fA " , Current_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      Current_eeprom *= 10;
      const uint16_t saveCurrent= (uint16_t)Current_eeprom;
      eeprom_write_int16(saveCurrent,50);
      HAL_Delay(1000);
       Current_eeprom /= 10;
      BackTOtanzimDasti();
      break;
    }    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimDasti();
      break;
    }
    
  }
  
}

void tanzimDasti_feshar(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,tanzimfeshar);
  Lcd_Put_Icon2_Invert(5,30,kadr);
  Lcd_Put_Icon2_Invert(70,25,Setting_up);
  Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%d " , pressure_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){   
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      pressure_eeprom+=5;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      pressure_eeprom-=5;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      changeMenu = 0;
      sprintf(lcdShow , "%d " , pressure_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(pressure_eeprom,30);
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

void tanzimDasti_start_voltage(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,StartVoltage);
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
  Lcd_Put_Icon2_Invert(0,0,StartTime);
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
  Lcd_Put_Icon2_Invert(0,0,SoftStartTime);
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
  Lcd_Put_Icon2_Invert(0,28,StartVoltage);
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
      Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
      Lcd_Refresh();
      HAL_Delay(500);
      menuSelect =1;
      changeMenu = 0;
      HAL_Delay(250);
      while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
      break;
    }
    
    if(menuSelect >5)menuSelect = 5;
    if(menuSelect <1)menuSelect = 1;
    
    if(changeMenu ==1 ){
      changeMenu = 0;
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(40,0,Setting_up);
      Lcd_Put_Icon2_Invert(40,50,Setting_down);
      Lcd_Put_Icon2_Invert(0,0,Settinglogo);
      
      if(menuSelect == 1){
        Lcd_Put_Icon2_Invert(0,28,StartVoltage);
      }         
      if(menuSelect == 2){
        Lcd_Put_Icon2_Invert(0,28,StartTime);         
      }
      
      if(menuSelect == 3){
        Lcd_Put_Icon2_Invert(0,28,SoftStartTime);         
      }
      
      if(menuSelect == 4){
        Lcd_Put_Icon2_Invert(0,28,tanzimfeshar);         
      }
      
      if(menuSelect == 5){
        Lcd_Put_Icon2_Invert(0,28,CurrentSettingpic);         
      }
      Lcd_Refresh();
    }
    
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      if(menuSelect == 1)tanzimDasti_start_voltage();
      if(menuSelect == 2)tanzimDasti_start_time();
      if(menuSelect == 3)tanzimDasti_start_soft();
      if(menuSelect == 4)tanzimDasti_feshar();
      if(menuSelect == 5)tanzimDasti_Current();
    }
    
    
  }
}  

//****************************************tanzim auto*******************************
void BackTOtanzimauto(){  
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(40,0,Setting_up);
  Lcd_Put_Icon2_Invert(40,50,Setting_down);
  //Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
  Lcd_Put_Icon2_Invert(0,0,DeviceMode);
  Lcd_Refresh();
  HAL_Delay(150); 
  changeMenu = 1;
  while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
}

void tanzimDasti_Device_Mode(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,DeviceMode);
  // Lcd_Put_Icon2_Invert(5,30,kadr);
  // Lcd_Put_Icon2_Invert(70,20,Setting_up);
  //Lcd_Put_Icon2_Invert(70,20,Setting_down); 
  
  if(mode_eeprom == 0){
    Lcd_Put_Icon2_Invert(0,30,SoftSet);    
  }  
  if(mode_eeprom == 1){
    Lcd_Put_Icon2_Invert(0,30,setcontrol);
  }
  
  if(mode_eeprom == 2){
    Lcd_Put_Icon2_Invert(0,30,Digitaldimerpic);
  }
  
  Lcd_Refresh();
  HAL_Delay(250);
  changeMenu = 0;
  while(1){   
    
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      ++mode_eeprom;
      changeMenu = 1;
      HAL_Delay(200);
    }
    
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 && mode_eeprom >0){
      --mode_eeprom;
      changeMenu = 1;
      HAL_Delay(200);
    } 
    
    if(mode_eeprom > 2)mode_eeprom=2;
 
    
    if(changeMenu == 1){
      changeMenu = 0;
      
        if(mode_eeprom == 0){
        Lcd_Put_Icon2_Invert(0,30,SoftSet);
      }
      
      if(mode_eeprom == 1){
        Lcd_Put_Icon2_Invert(0,30,setcontrol);
      }           
      
      if(mode_eeprom == 2){
        Lcd_Put_Icon2_Invert(0,30,Digitaldimerpic);
      }
      Lcd_Refresh();     
    } 
    
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(mode_eeprom,40);
      HAL_Delay(1000);
      BackTOtanzimauto();    
      while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
      break;
    }
    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimauto();
      while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
      break;
    }
    
  }
  
}

void tanzimAutomatic(){
  
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(40,0,Setting_up);
  Lcd_Put_Icon2_Invert(40,50,Setting_down);
  Lcd_Put_Icon2_Invert(0,28,DeviceMode);
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
      Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
      Lcd_Refresh();
      HAL_Delay(500);
      menuSelect =1;
      changeMenu = 0;
      HAL_Delay(250);
      while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
      break;
    }
    
    if(menuSelect >1)menuSelect = 1;
    if(menuSelect <1)menuSelect = 1;
    
    if(changeMenu ==1 ){
      changeMenu = 0;
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(40,0,Setting_up);
      Lcd_Put_Icon2_Invert(40,50,Setting_down);
      
      if(menuSelect == 1){
        Lcd_Put_Icon2_Invert(0,28,DeviceMode);
      }         
      //      if(menuSelect == 2){
      //        Lcd_Put_Icon2_Invert(0,28,StartTime);         
      //      }
      //      
      //      if(menuSelect == 3){
      //        Lcd_Put_Icon2_Invert(0,28,SoftStartTime);         
      //      }
      //      
      //      if(menuSelect == 4){
      //        Lcd_Put_Icon2_Invert(0,28,tanzimfeshar);         
      //      }
      Lcd_Refresh();
    }
    
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      if(menuSelect == 1)tanzimDasti_Device_Mode();
      //      if(menuSelect == 2)tanzimDasti_start_time();
      //      if(menuSelect == 3)tanzimDasti_start_soft();
      //      if(menuSelect == 4)tanzimDasti_feshar();
      
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
    modeControlCount = 0;
    while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
    while(1){
      
      if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
        ++menuSelect;
        changeMenu = 1;
      }
      
      if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
        --menuSelect;
        changeMenu = 1;
      }
      
      if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
        HAL_Delay(500);
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
         HAL_Delay(500);
      }
      
      
      if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
        if(menuSelect == 1)tanzimDasti();
        if(menuSelect == 2)tanzimAutomatic();
        
      }
      
      
    }
  }
  
}