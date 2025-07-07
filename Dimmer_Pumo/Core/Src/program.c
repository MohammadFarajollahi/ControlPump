
int volt2;
int timeSoft2;

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
      lcd_putsf_point(0,10,"Reset Pump",TAHOMA_8x10);
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
ADC_HandleTypeDef hadc;
uint32_t adc_val_ch0 = 0;
uint32_t adc_val_ch1 = 0;
float adc1;
void readCurrent(){
  ADC_ChannelConfTypeDef sConfig = {0};
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  adc1 = 0;
  adc_val_ch0 =0;
  for(int i = 0 ; i < 100 ; i++) {
    HAL_ADC_Start(&hadc); // start the adc
    HAL_ADC_PollForConversion(&hadc, 100);
    adc_val_ch0 += HAL_ADC_GetValue(&hadc);
    HAL_ADC_Stop(&hadc); // stop adc
    //adc1 += adc_val_ch0;
    HAL_Delay(1);
  }
  adc_val_ch0 /=100;
  float current;
  current =adc_val_ch0 / 70.934256055363;
  char ss[20];
  sprintf(ss , "CU:%.2f    " , current);
  lcd_putsf_point(0,20,ss,TAHOMA_8x10);
  Lcd_Refresh();
  
}

void lcdBackLightControl(){
  if (HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0 || HAL_GPIO_ReadPin(k_down_GPIO_Port, k_down_Pin) == 0 || HAL_GPIO_ReadPin(k_ok_GPIO_Port, k_ok_Pin) == 0 || HAL_GPIO_ReadPin(k_back_GPIO_Port, k_back_Pin) == 0){
    lcdLight = 1;
    HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);    
  }
  
}

void MainCod(){
  
  if(softStart_State == 0) SoftSTART();
  readCurrent();
  lcdBackLightControl();
  
}


