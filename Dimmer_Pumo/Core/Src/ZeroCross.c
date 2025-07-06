long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (HAL_GPIO_ReadPin(cross_GPIO_Port, cross_Pin) == 1 )
  {
    zero_cross_flag = 1;
  }
}

void delay_us_soft(uint32_t us)
{
  while(us--)
  {
    for(volatile int i = 0; i < 12; i++) {
      __NOP();
    }
  }
}

void OutPut(int VoltageInput){
  long TimeSet = map(VoltageInput, 0, 220, 2000, 0);
  if (zero_cross_flag == 1) {   
    zero_cross_flag = 0;
    delay_us_soft(TimeSet);
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_SET);
    delay_us_soft(10);
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
  }
  
}
