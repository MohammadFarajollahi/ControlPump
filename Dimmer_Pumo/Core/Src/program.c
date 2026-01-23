//extern Picture2InfoTypeDef SoftSet;
//extern Picture2InfoTypeDef setcontrol;
//extern Picture2InfoTypeDef logo;
//extern Picture2InfoTypeDef Digitaldimerpic;
//extern Picture2InfoTypeDef LogooPavan;


void show_uart( char *ss){
  strcat(ss, "\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *) ss, strlen (ss), 1000);
}

void bluetooth(){
  sprintf(ss, "value/%d/%.1f/%.1f/%d/%d",Voltage,current,Pressure,PumpState,CurrentAlarm);
  show_uart(ss); 
}

float Read_AD(uint32_t channel){
  ADC_ChannelConfTypeDef sConfig;		
  float ad_out; 
  HAL_ADC_DeInit(&hadc);
  HAL_ADC_Init(&hadc);
  sConfig.Channel = channel ;
  sConfig.Rank = 1;	
  HAL_ADC_ConfigChannel(&hadc, &sConfig);
  for(int i = 0 ; i<150 ; i++){
    HAL_ADCEx_Calibration_Start(&hadc);	
    HAL_ADC_Start(&hadc);  
    if (HAL_ADC_PollForConversion(&hadc, 100) == HAL_OK)       
      ad_out+=HAL_ADC_GetValue(&hadc); 
    HAL_Delay(1);
  }
  
  ad_out /=150;
  
  if(taqsim ==1){
    ad_out*=3.5;
    ad_out/=4095;
    ad_out *= 1.49;
  }
  
  return ad_out;				
}

void SoftSTART(){
  Voltage = StartVoltage_eeprom;
  char ss[20];
  sprintf(ss , "Volt:%dV " , Voltage);
  lcd_putsf_point(0,0,ss,TAHOMA_8x10);
  softTimer1 = 0;
  SecCount = 0;  
  while(softTimer1 <= StartTime_eeprom){
    HAL_IWDG_Refresh(&hiwdg);
    OutPut(Voltage);
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 || HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 || HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0 || HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0)break;
  }
  volt2 =220 - StartVoltage_eeprom;
  timeSoft2 = SoftTime_eeprom / volt2;
  softTimer1= 0;
  while(1){
    HAL_IWDG_Refresh(&hiwdg);
    OutPut(Voltage);
    if(softTimer1 >= timeSoft2){
      Voltage+=1;
      softTimer1 = 0;
    }    
    if(Voltage>=210){
      Voltage = 220;
      softStart_State = 1;
      softTimer1=0;
      HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_SET);
      char ss[20];
      sprintf(ss , "Volt:%dV " , Voltage);
      lcd_putsf_point(0,0,ss,TAHOMA_8x10);
      lcd_putsf_point(0,40,"          ",TAHOMA_8x10);
      Lcd_Refresh();
      break;
    }
    
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 || HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 || HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0 || HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
      HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
      softStart_State = 1;      
      softTimer1=0;
      break;
    }
  }
  
  
}

void readCurrent(){
  taqsim = 0;
  current=Read_AD(ADC_CHANNEL_0); 
  current /= 70.934256055363; 
  current /= 1.5;
  //current *=2.3;
  sprintf(ss , "CUR:%.1f>%.1f" , current,DownCurrent_eeprom);
  lcd_putsf_point(0,10,ss,TAHOMA_8x10);
  Lcd_Refresh();
  {//Current Control
    ////////////////////////////////////////HIGH Current//////////////////////////////////
    if(current >= UpCurrent_eeprom && CurrentAllarmCount == 0  && softStart_State == 1){ //High Current Error
      CurrentAllarmCount = 1;
      //show_uart("ALARM Up_Current");     
    }
    
    if(CurrentAllarmCount == 1 && current > DownCurrent_eeprom && current < UpCurrent_eeprom){ //Nothing
      currentAlarmTimer = 0;
      CurrentAllarmCount = 0;
      CurrentAlarm = 0;
      currentRealizeTime = 0;     
    }
    
    if(CurrentAllarmCount == 1 && currentAlarmTimer >= 5){
      HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
      softStart_State = 0;
      CurrentAllarmCount = 0;
      CurrentAlarm = 1;
      currentAlarmTimer = 0;
      PumpState = 0;
      CurrentFulat = 1;
//      sprintf(ss , "High Cur Fualt");
//      lcd_putsf_point(0,30,ss,TAHOMA_8x10);
    }
    
    if(CurrentAlarm == 1){
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(100);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(100);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      if(currentRealizeTime >= 20){
        currentRealizeTime = 0;
        CurrentAlarm = 0;
      }
    }
    
    ////////////////////////////////////////LOW Current//////////////////////////////////
    
    if(current <= DownCurrent_eeprom && CurrentAllarmCount == 0 && Current_eeprom > 0 && softStart_State == 1  && current > .3){
      CurrentAllarmCount = 2;
      //show_uart("ALARM Down_Cerrent");     
    }
    
    if(CurrentAllarmCount == 2 && current > DownCurrent_eeprom && current < UpCurrent_eeprom){
      CurrentAllarmCount = 0;
      currentAlarmTimer = 0;
      CurrentAlarm = 0;
      CurrentFulat = 0;
      currentRealizeTime = 0;
      TimeReturn = 0;
    }
    
    if(CurrentAllarmCount == 2 && currentAlarmTimer >= TimeHavaKeshi_eeprom){
      HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
      softStart_State = 0;
      CurrentAllarmCount = 0;
      CurrentAlarm = 2;
      currentAlarmTimer = 0;
      CurrentFulat = 2;
      PumpState = 0;
//      sprintf(ss , "Low Cur Fualt");
//      lcd_putsf_point(0,30,ss,TAHOMA_8x10);
    }
    
    if(CurrentAlarm == 2){
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      HAL_Delay(30);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      if(currentRealizeTime >= 30){
        currentRealizeTime = 0;
        CurrentAlarm = 0;
      }
    }
    
    if(CurrentFulat == 2 && TimeReturn >= CurrentDownRealizeTime_eeprom){
      CurrentFulat = 0;
      TurnOnDelay = 0;
      PumpState = 0;
      TimeReturn = 0;
    }   
  }
}

void Readpressure(){
  taqsim = 1;
  Pressure=Read_AD(ADC_CHANNEL_1); 
  Pressure = (118.42f * Pressure) - 45.4f;  // تبدیل به PSI 
  if(Pressure < 0)Pressure = 0;
  //bar = Pressure*0.0689476;
  sprintf(ss , "P:%.1f>%.1d  " , Pressure , pressure_eeprom);
  lcd_putsf_point(0,20,ss,TAHOMA_8x10);
  Lcd_Refresh();
}

void lcdBackLightControl(){
  if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 || HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 || HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0 || HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
    lcdLight = 1;
    HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);    
  }
  
}

void FirstConfig(){
  modeControlCount = 1;
  setting = 0;
  Lcd_Clear();
  Lcd_Refresh();
  
  //soft starter
//  if(mode_eeprom == 0){   
//    char ss[20];
//    sprintf(ss , "Voltage:%dV " , StartVoltage_eeprom);
//    lcd_putsf_point(0,0,ss,TAHOMA_8x10); 
//    Lcd_Refresh();
//    show_uart("soft start mode");
//  }
  
  //Set Control
  if(mode_eeprom == 1){
    softStart_State = 0;
    char ss[20];
    sprintf(ss , "Voltage:%dV " , StartVoltage_eeprom);
    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
  }
  
  //Dimmer Digital
//  if(mode_eeprom == 2){
//    Voltage = StartVoltage_eeprom;
//    char ss[20];
//    sprintf(ss , "Voltage:%dV " , Voltage);
//    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
//    Lcd_Refresh();
//
//  }
  
  
}

void SoftStartMode(){
//  if(softStart_State == 0) SoftSTART();
//  readCurrent();
//  Readpressure();
//  bluetooth();
//  
//  
//  if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0 && softStart_State == 1){  
//    softStart_State = 0;
//    lcd_putsf_point(0,40,"Reset Pump",TAHOMA_8x10);
//    Lcd_Refresh();
//    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
//    HAL_Delay(2000);   
//  }
}

void SetControlMode(){
  readCurrent();
  Readpressure();
  bluetooth();
  
  { //Pressure Control
    if(Pressure <=  PressureDown_eeprom && PumpState == 0 && TurnOnDelay == 0 && CurrentFulat == 0){
      PumpState = 1;
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(10);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      sprintf(ss , "Pump On    ");
      lcd_putsf_point(0,30,ss,TAHOMA_8x10);
      Lcd_Refresh();
      if(softStart_State == 0)SoftSTART();
      
    }
    
    if(Pressure > pressure_eeprom && PumpState == 1 && CurrentFulat == 0){
      oftimerCount=1;    
      if(ofTimer >= ofTimer_eeprom){
        ofTimer = 0;
        PumpState = 0;
        oftimerCount = 0;
        TurnOnDelay = 1;
        softStart_State = 0;
        sprintf(ss , "Pump Off   ");
        lcd_putsf_point(0,30,ss,TAHOMA_8x10);
        HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
      }    
    }
    
    if(TurnOnDelay == 1 && TurnOnDelayTimer >= TurnOnDelay_eeprom){
      TurnOnDelay = 0;
      TurnOnDelayTimer = 0;
    }
  }
  
  if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){  
    softStart_State = 0;
    TurnOnDelay = 0;
    CurrentAlarm = 0;
    PumpState = 0;
    CurrentFulat = 0;
//    lcd_putsf_point(0,30,"Reset Pump  ",TAHOMA_8x10);
//    Lcd_Refresh();
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
    HAL_Delay(1000);   
  }
  
}

void DigitalDimmerMode(){
  //Voltage Change in Timer1
  
  if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 ){
    StartVoltage_eeprom += 5;
    changeMenu = 1;
  }
  
  if (HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 ){
    StartVoltage_eeprom -= 5; 
    // StartVoltage_eeprom -= 100;
    changeMenu = 1;
  }
  
  if(StartVoltage_eeprom >= 220)StartVoltage_eeprom =220;
  if(StartVoltage_eeprom <10)StartVoltage_eeprom =10;
  Voltage = StartVoltage_eeprom;
  OutPut(Voltage);
  
  if(changeMenu == 1){    
    changeMenu = 0;
    sprintf(ss , "Volt:%dV " , Voltage);
    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
    Lcd_Refresh();
    HAL_Delay(100);
  }
  
}

void MainCod(){
  lcdBackLightControl();
  
  if(modeControlCount == 0)FirstConfig();
  
  //if(mode_eeprom == 0)SoftStartMode();
  if(mode_eeprom == 1)SetControlMode();
  if(mode_eeprom == 2)DigitalDimmerMode();
  
}


