
//************************************menu************************************
//extern Picture2InfoTypeDef Setting_up;
//extern Picture2InfoTypeDef Setting_down;
//extern Picture2InfoTypeDef tanzim_manual;
//extern  Picture2InfoTypeDef tanzim_Auto;
//extern Picture2InfoTypeDef freeScreen;
//extern Picture2InfoTypeDef Settinglogo;
extern Picture2InfoTypeDef StartVoltage;
extern Picture2InfoTypeDef StartTime;
//extern Picture2InfoTypeDef kadr;
extern Picture2InfoTypeDef saved;
extern Picture2InfoTypeDef SoftStartTime;
extern Picture2InfoTypeDef tanzimfeshar;
extern Picture2InfoTypeDef DeviceMode;
extern Picture2InfoTypeDef SoftSet;
extern Picture2InfoTypeDef setcontrol;
extern Picture2InfoTypeDef Digitaldimerpic;
extern Picture2InfoTypeDef CurrentSettingpic;
extern Picture2InfoTypeDef tanzimfesharDown;
extern Picture2InfoTypeDef offDelay;
extern Picture2InfoTypeDef OnDelay;
extern Picture2InfoTypeDef DownCurrent;
extern Picture2InfoTypeDef DownCurrent;
extern Picture2InfoTypeDef TimeHavaKeshi;
extern Picture2InfoTypeDef RealizeTime;



void buzzerbig(){
  HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
  HAL_Delay(10);
  HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
}

void BackTOtanzimDasti(){  
  Lcd_Clear();
  //Lcd_Put_Icon2_Invert(40,0,Setting_up);
  //Lcd_Put_Icon2_Invert(40,50,Setting_down);
  //Lcd_Put_Icon2_Invert(0,0,Settinglogo);
  //Lcd_Put_Icon2_Invert(5,28,StartVoltage);
  Lcd_Refresh();
  HAL_Delay(500); 
  changeMenu = 1;
  while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
}

void BackTOtanzimauto(){ 
  buzzerbig();
  Lcd_Clear();
 // Lcd_Put_Icon2_Invert(40,0,Setting_up);
 // Lcd_Put_Icon2_Invert(40,50,Setting_down);
  //Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
  //Lcd_Put_Icon2_Invert(0,0,DeviceMode);
  Lcd_Refresh();
  HAL_Delay(150); 
  changeMenu = 1;
  while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
}

void tanzimDasti_Device_Mode(){
  buzzerbig();
  Lcd_Clear();
  //Lcd_Put_Icon2_Invert(0,0,DeviceMode);
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
      HAL_IWDG_Refresh(&hiwdg);
      buzzerbig();
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

void tanzimDasti_TimeHavaKeshi(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,TimeHavaKeshi);
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%d " , TimeHavaKeshi_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      TimeHavaKeshi_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      TimeHavaKeshi_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%d " , TimeHavaKeshi_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(TimeHavaKeshi_eeprom,110);
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

void tanzimDasti_RealizeTime(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,RealizeTime);
  //Lcd_Put_Icon2_Invert(5,30,kadr);
 // Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  CurrentDownRealizeTime_eeprom /= 60;
  sprintf(lcdShow , "%d " , CurrentDownRealizeTime_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      CurrentDownRealizeTime_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      CurrentDownRealizeTime_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%d " , CurrentDownRealizeTime_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(CurrentDownRealizeTime_eeprom,120);
      CurrentDownRealizeTime_eeprom *= 60;
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

void tanzimDasti_Current(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,CurrentSettingpic);
  //Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%.1fA " , UpCurrent_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      UpCurrent_eeprom+=.1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      UpCurrent_eeprom-=.1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%.1fA " , UpCurrent_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      UpCurrent_eeprom *= 10;
      const uint16_t saveCurrent= (uint16_t)UpCurrent_eeprom;
      eeprom_write_int16(saveCurrent,50);
      HAL_Delay(1000);
      UpCurrent_eeprom /= 10;
      BackTOtanzimDasti();
      break;
    }    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimDasti();
      break;
    }
    
  }
  
}

void tanzimDasti_CurrentDown(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,DownCurrent);
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%.1fA " , DownCurrent_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      DownCurrent_eeprom+=.1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      DownCurrent_eeprom-=.1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%.1fA " , DownCurrent_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      DownCurrent_eeprom *= 10;
      const uint16_t saveCurrent= (uint16_t)DownCurrent_eeprom;
      eeprom_write_int16(saveCurrent,100);
      HAL_Delay(1000);
      DownCurrent_eeprom /= 10;
      BackTOtanzimDasti();
      break;
    }    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){           
      BackTOtanzimDasti();
      break;
    }
    
  }
  
}

void tanzimDasti_OffDelay(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,offDelay);
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%d " , ofTimer_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      ofTimer_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      ofTimer_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%d " , ofTimer_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(ofTimer_eeprom,80);
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

void tanzimDasti_OnDelay(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,OnDelay);
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%d " , TurnOnDelay_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      TurnOnDelay_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      TurnOnDelay_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%d " , TurnOnDelay_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(TurnOnDelay_eeprom,60);
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

void tanzimDasti_feshar(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,tanzimfeshar);
  //Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%d " , pressure_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      pressure_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      pressure_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
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

void tanzimDasti_FesharDown(){
  Lcd_Clear();
  Lcd_Put_Icon2_Invert(0,0,tanzimfesharDown);
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%d " , PressureDown_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(500);
  changeMenu = 0;
  while(1){ 
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      PressureDown_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      PressureDown_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(150);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%d " , PressureDown_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();     
    }  
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      Lcd_Clear();
      Lcd_Put_Icon2_Invert(7,30,saved);
      Lcd_Refresh();
      eeprom_write_int16(PressureDown_eeprom,70);
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
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
  sprintf(lcdShow , "%dV " , StartVoltage_eeprom);
  lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
  Lcd_Refresh();
  HAL_Delay(200);
  changeMenu = 0;
  while(1){   
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
      StartVoltage_eeprom+=1;
      changeMenu = 1;
      HAL_Delay(100);
    }   
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      StartVoltage_eeprom-=1;
      changeMenu = 1;
      HAL_Delay(100);
    }   
    if(changeMenu == 1){
      HAL_IWDG_Refresh(&hiwdg);
      changeMenu = 0;
      buzzerbig();
      sprintf(lcdShow , "%dV " , StartVoltage_eeprom);
      lcd_putsf_point(20,36,lcdShow,TAHOMA_8x10);
      Lcd_Refresh();
      HAL_Delay(50);
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
//  Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
  //Lcd_Put_Icon2_Invert(70,45,Setting_down); 
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
      HAL_IWDG_Refresh(&hiwdg);
      buzzerbig();
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
 // Lcd_Put_Icon2_Invert(5,30,kadr);
  //Lcd_Put_Icon2_Invert(70,25,Setting_up);
 // Lcd_Put_Icon2_Invert(70,45,Setting_down); 
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
      HAL_IWDG_Refresh(&hiwdg);
      buzzerbig();
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
  //Lcd_Put_Icon2_Invert(40,0,Setting_up);
  //Lcd_Put_Icon2_Invert(40,50,Setting_down);
  //Lcd_Put_Icon2_Invert(0,0,Settinglogo);
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
      HAL_Delay(300);
    }
    
    if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
      --menuSelect;
      changeMenu = 1;
      HAL_Delay(300);
    }
    
    if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
      Lcd_Clear();
      //Lcd_Put_Icon2_Invert(40,0,Setting_up);
      //Lcd_Put_Icon2_Invert(40,50,Setting_down);
      //Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
      Lcd_Refresh();
      HAL_Delay(100);
      menuSelect =1;
      changeMenu = 0;
      while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
      softStart_State = 0;
      TurnOnDelay = 0;
      CurrentAlarm = 0;
      PumpState = 0;
      CurrentFulat = 0;
      break;
    }
    
    if(menuSelect >11)menuSelect = 11;
    if(menuSelect <1)menuSelect = 1;
    
    if(changeMenu ==1 ){
      HAL_IWDG_Refresh(&hiwdg);
      buzzerbig();
      changeMenu = 0;
      Lcd_Clear();
      //Lcd_Put_Icon2_Invert(40,0,Setting_up);
      //Lcd_Put_Icon2_Invert(40,50,Setting_down);
      //Lcd_Put_Icon2_Invert(0,0,Settinglogo);
      
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
        Lcd_Put_Icon2_Invert(0,28,tanzimfesharDown);         
      }
      
      if(menuSelect == 6){
        Lcd_Put_Icon2_Invert(0,28,offDelay);         
      }
      
      if(menuSelect == 7){
        Lcd_Put_Icon2_Invert(0,28,OnDelay);         
      }
      
      if(menuSelect == 8){
        Lcd_Put_Icon2_Invert(13,28,CurrentSettingpic);         
      }
      
      if(menuSelect == 9){
        Lcd_Put_Icon2_Invert(10,28,DownCurrent);         
      }
      
      if(menuSelect == 10){
        Lcd_Put_Icon2_Invert(5,28,TimeHavaKeshi);         
      }
      
      if(menuSelect == 11){
        Lcd_Put_Icon2_Invert(10,28,RealizeTime);         
      }
      
//      if(menuSelect == 12){
//        Lcd_Put_Icon2_Invert(0,28,DeviceMode);         
//      }
      
      
      
      Lcd_Refresh();
    }
    
    
    if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
      buzzerbig();
      if(menuSelect == 1)tanzimDasti_start_voltage();
      if(menuSelect == 2)tanzimDasti_start_time();
      if(menuSelect == 3)tanzimDasti_start_soft();
      if(menuSelect == 4)tanzimDasti_feshar();
      if(menuSelect == 5)tanzimDasti_FesharDown();
      if(menuSelect == 6)tanzimDasti_OffDelay();
      if(menuSelect == 7)tanzimDasti_OnDelay();
      if(menuSelect == 8)tanzimDasti_Current();
      if(menuSelect == 9)tanzimDasti_CurrentDown();
      if(menuSelect == 10)tanzimDasti_TimeHavaKeshi();
      if(menuSelect == 11)tanzimDasti_RealizeTime();
     // if(menuSelect == 12)tanzimDasti_Device_Mode();
      
    }
    
    
  }
}  

void menu(){
  
  //****menu****
  if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
    buzzerbig();
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);
    setting = 1;
    Lcd_Refresh();
    HAL_Delay(500);
    menuSelect =1;
    changeMenu = 0;
    modeControlCount = 0;
    while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
    tanzimDasti();
  }
  
}


//void menu(){
//  
//  //****menu****
//  if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
//    buzzerbig();
//    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);
//    setting = 1;
//    HAL_Delay(50);
//    Lcd_Clear();
//    Lcd_Put_Icon2_Invert(40,0,Setting_up);
//    Lcd_Put_Icon2_Invert(40,50,Setting_down);
//    Lcd_Put_Icon2_Invert(2,25,tanzim_manual);
//    Lcd_Refresh();
//    HAL_Delay(500);
//    menuSelect =1;
//    changeMenu = 0;
//    modeControlCount = 0;
//    while(HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0);
//    while(1){
//      
//      
//      if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
//        ++menuSelect;
//        changeMenu = 1;
//      }
//      
//      if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0){
//        --menuSelect;
//        changeMenu = 1;
//      }
//      
//      if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
//        HAL_Delay(500);
//        while(HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0);
//        softStart_State = 0;
//        TurnOnDelay = 0;
//        CurrentAlarm = 0;
//        PumpState = 0;
//        CurrentFulat = 0;
//        break;
//      }
//      
//      if(menuSelect >2)menuSelect = 2;
//      if(menuSelect <1)menuSelect = 1;
//      
//      if(changeMenu ==1 ){
//        HAL_IWDG_Refresh(&hiwdg);
//        buzzerbig();
//        changeMenu = 0;
//        Lcd_Clear();
//        Lcd_Put_Icon2_Invert(40,0,Setting_up);
//        Lcd_Put_Icon2_Invert(40,50,Setting_down);
//
//        if(menuSelect == 1){
//          Lcd_Put_Icon2_Invert(2,25,tanzim_manual);            
//        }         
//
//        if(menuSelect == 2){
//          Lcd_Put_Icon2_Invert(2,25,tanzim_Auto);            
//        }
//
//        Lcd_Refresh();
//         HAL_Delay(500);
//      }
//      
//      
//      if (HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0){
//        if(menuSelect == 1)tanzimDasti();
//        if(menuSelect == 2)tanzimAutomatic();
//        
//      }
//      
//      
//    }
//  }
//  
//}