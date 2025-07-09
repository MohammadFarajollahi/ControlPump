
int volt2;
int timeSoft2;
char ss[50];
int taqsim;

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
  ad_out*=3.3;
  ad_out/=4095;
  }
  
  return ad_out;				
}


void SoftSTART(){
  softTimer1 = 0;
  SecCount = 0;
  Voltage = StartVoltage_eeprom;
  while(softTimer1 <= StartTime_eeprom){
    OutPut(Voltage);
    if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 || HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 || HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0 || HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0)break;
  }
  volt2 =220 - StartVoltage_eeprom;
  //volt2 /= 5;
  timeSoft2 = SoftTime_eeprom / volt2;
  softTimer1= 0;
  while(1){
    if(softTimer1 >= timeSoft2){
      Voltage+=1;
      softTimer1 = 0;
    }
    OutPut(Voltage);
    if(Voltage>=220){
      softStart_State = 1;
      softTimer1=0;
      HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_SET);
      char ss[20];
      sprintf(ss , "Voltage:%dV " , Voltage);
      lcd_putsf_point(0,0,ss,TAHOMA_8x10);
      //lcd_putsf_point(0,10,"Reset Pump",TAHOMA_8x10);
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
   
  sprintf(ss , "CURRENT:%.2f    " , current);
  lcd_putsf_point(0,10,ss,TAHOMA_8x10);
}


void Readpressure(){
  taqsim = 1;
  Pressure=Read_AD(ADC_CHANNEL_1);
  float adc = Pressure;
  Pressure *=100;
  if(adc < .3)Pressure -=50;
  if(adc >= .3)Pressure -=30;
  sprintf(ss , "PSI:%.2f    " , Pressure);
  lcd_putsf_point(0,20,ss,TAHOMA_8x10);
  sprintf(ss , "ADC:%.2f    " , adc);
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

void MainCod(){
   //HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_SET);
  if(softStart_State == 0) SoftSTART();
  readCurrent();
  Readpressure();
  
  
  bluetooth();

   
  lcdBackLightControl();
  
}


