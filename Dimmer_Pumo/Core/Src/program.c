extern Picture2InfoTypeDef SoftSet;
extern Picture2InfoTypeDef setcontrol;
extern Picture2InfoTypeDef logo;
extern Picture2InfoTypeDef Digitaldimerpic;
extern Picture2InfoTypeDef LogooPavan;

void show_uart2( char *ss1 , int ss2){
  char text[20];
  int len;
  sprintf(text,ss1);
  sprintf(ss , "%d",ss2);
  strcat(text , ss);
  strcat(text, "\r\n");
  len = strlen (text);
  HAL_UART_Transmit(&huart1, (uint8_t *) text, len, 200);
  
}

void show_uart( char *ss)
{
  char test[50];
  int len;
  strcpy(test, ss);
  strcat(test, "\r\n");
  len = strlen (test);
  HAL_UART_Transmit(&huart1, (uint8_t *) test, len, 200);
}

float Read_AD(uint32_t channel)
{
  ADC_ChannelConfTypeDef sConfig;		
  float ad_out; 
  HAL_ADC_DeInit(&hadc);
  HAL_ADC_Init(&hadc);
  sConfig.Channel = channel ;
  sConfig.Rank = 1;	
  HAL_ADC_ConfigChannel(&hadc, &sConfig);
  for(int i = 0 ; i<100 ; i++){
    HAL_ADCEx_Calibration_Start(&hadc);	
    HAL_ADC_Start(&hadc);  
    if (HAL_ADC_PollForConversion(&hadc, 100) == HAL_OK)       
      ad_out+=HAL_ADC_GetValue(&hadc); 
    HAL_Delay(1);
  }
  
  ad_out /=100;
  
  if(taqsim ==1){
    ad_out*=3.5;
    ad_out/=4095;
    ad_out *= 1.49;
  }
  
  return ad_out;				
}

void SoftSTART(){
  char ss[20];
  sprintf(ss , "Voltage:%dV " , Voltage);
  lcd_putsf_point(0,0,ss,TAHOMA_8x10);
  softTimer1 = 0;
  SecCount = 0;
  Voltage = StartVoltage_eeprom;
  show_uart("Starting...");
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
      softStart_State = 1;
      softTimer1=0;
      HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_SET);
      char ss[20];
      sprintf(ss , "Voltage:%dV " , Voltage);
      lcd_putsf_point(0,0,ss,TAHOMA_8x10);
      lcd_putsf_point(0,40,"          ",TAHOMA_8x10);
      Lcd_Refresh();
      show_uart("soft start done");
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
  sprintf(ss , "CUR:%.1f>%.1f" , current,Current_eeprom);
  lcd_putsf_point(0,10,ss,TAHOMA_8x10);
  Lcd_Refresh();
}

void Readpressure(){
  taqsim = 1;
  Pressure=Read_AD(ADC_CHANNEL_1); 
  //  sprintf(ss , "V:%.3f  " , Pressure);
  //  lcd_putsf_point(0,30,ss,TAHOMA_8x10);
  Pressure = (118.42f * Pressure) - 45.4f;  // تبدیل به PSI 
  bar = Pressure*0.0689476;
  sprintf(ss , "PSI:%.1f" , Pressure);
  lcd_putsf_point(0,20,ss,TAHOMA_8x10);
  sprintf(ss , "Set:%d " , pressure_eeprom);
  lcd_putsf_point(0,30,ss,TAHOMA_8x10);
  Lcd_Refresh();
}

void lcdBackLightControl(){
  if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 || HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 || HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0 || HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
    lcdLight = 1;
    HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);    
  }
  
}

void bluetooth(){
  sprintf(ss , "CURRENT:%.2f / Pressure:%.2f    " , current, Pressure);
  show_uart(ss);
  
}

void FirstConfig(){
  modeControlCount = 1;
  setting = 0;
  Lcd_Clear();
  Lcd_Refresh();
  
  //soft starter
  if(mode_eeprom == 0){   
    char ss[20];
    sprintf(ss , "Voltage:%dV " , StartVoltage_eeprom);
    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
    Lcd_Put_Icon2_Invert(0,45,SoftSet); // YplusOnXbyte = (LedHeight + 7) / 8;
    Lcd_Refresh();
    show_uart("soft start mode");
  }
  
  //Set Control
  if(mode_eeprom == 1){
//    Lcd_Put_Icon2_Invert(25,0,LogooPavan); // YplusOnXbyte = (LedHeight + 7) / 8;
//    Lcd_Refresh();
//    HAL_Delay(1000);
//    Lcd_Clear();
//    Lcd_Refresh();
    softStart_State = 0;
    char ss[20];
    sprintf(ss , "Voltage:%dV " , StartVoltage_eeprom);
    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
    Lcd_Put_Icon2_Invert(0,48,logo); // YplusOnXbyte = (LedHeight + 7) / 8;
    Lcd_Refresh();
  }
  
  //Dimmer Digital
  if(mode_eeprom == 2){
//    Lcd_Put_Icon2_Invert(25,0,LogooPavan); // YplusOnXbyte = (LedHeight + 7) / 8;
//    Lcd_Refresh();
//    HAL_Delay(1000);
//    Lcd_Clear();
//    Lcd_Refresh();
    Voltage = StartVoltage_eeprom;
    char ss[20];
    sprintf(ss , "Voltage:%dV " , Voltage);
    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
    Lcd_Refresh();
    Lcd_Put_Icon2_Invert(0,45,Digitaldimerpic);
    Lcd_Refresh();
  }
  
  
}

void SoftStartMode(){
  if(softStart_State == 0) SoftSTART();
  readCurrent();
  Readpressure();
  bluetooth();
  
  
  if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0 && softStart_State == 1){  
    softStart_State = 0;
    lcd_putsf_point(0,40,"Reset Pump",TAHOMA_8x10);
    Lcd_Refresh();
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
    HAL_Delay(2000);   
  }
}

void SetControlMode(){
  readCurrent();
  Readpressure();
  bluetooth();
  
  { //Pressure Control
    if(Pressure <= (pressure_eeprom - PressureTelurance_eeprom) && PumpState == 0 && TurnOnDelay == 0){
      PumpState = 1;
      if(softStart_State == 0)SoftSTART();
    }
    
    if(Pressure > pressure_eeprom && PumpState == 1){
      oftimerCount=1;    
      if(ofTimer >= ofTimer_eeprom){
        ofTimer = 0;
        PumpState = 0;
        oftimerCount = 0;
        TurnOnDelay = 1;
        HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
      }    
    }
    
    if(TurnOnDelay == 1 && TurnOnDelayTimer >= TurnOnDelay_eeprom){
      TurnOnDelay = 0;
      TurnOnDelayTimer = 0;
    }
  }
  
  {//Current Control
    
    
    
    
  }
  
  if (HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0 && softStart_State == 1){  
    softStart_State = 0;
    lcd_putsf_point(0,40,"Reset Pump",TAHOMA_8x10);
    Lcd_Refresh();
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
    HAL_Delay(2000);   
  }
  
}

void DigitalDimmerMode(){
  //Voltage Change in Timer1
  
  if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 ){
    StartVoltage_eeprom += 5;
    // StartVoltage_eeprom += 100;
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
    char ss[20];
    sprintf(ss , "Voltage:%dV " , Voltage);
    lcd_putsf_point(0,0,ss,TAHOMA_8x10);
    sprintf(ss , "Time:%d " , TimeSet);
    lcd_putsf_point(0,20,ss,TAHOMA_8x10);
    Lcd_Refresh();
    HAL_Delay(100);
  }
  
}

void MainCod(){
  lcdBackLightControl();
  
  if(modeControlCount == 0)FirstConfig();

  if(mode_eeprom == 0)SoftStartMode();
  if(mode_eeprom == 1)SetControlMode();
  if(mode_eeprom == 2)DigitalDimmerMode();
   
}


