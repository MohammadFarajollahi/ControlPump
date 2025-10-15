


//===========================
// UART Rx Callback
//===========================
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART1)
  {    
    if(rx_index1 >= RX_BUFFER_SIZE -1){    
      rx_index1 = 0;
    }       
    if (rx_index1 < RX_BUFFER_SIZE - 1)
    {
      rx_buffer1[rx_index1++] = rx_data1;
      uartTimeTest = 0;
      UartTrig = 1;
    }   
    HAL_UART_Receive_IT(&huart1, &rx_data1, 1);
  }
}



void MC60Uart(void)
{  
  uint32_t now = HAL_GetTick();
  if (now - last_time >= 100)
  {
    last_time = now;  // ریست تایمر
    ++uartTimeTest;
  }
  
  if(uartTimeTest >=5 && UartTrig == 1){
    uartTimeTest = 0;
    char *token;
    char *rest = (char*)rx_buffer1;
    
    
    while ((token = strtok_r(rest, "\r\n", &rest)) != NULL)
    { 
      snprintf(char_test1, sizeof(char_test1), "%s\r\n", token);
      //show_uart(char_test1);
      check();
    }
    
    UartTrig=0;
    memset(rx_buffer1, 0, sizeof(rx_buffer1));
    rx_index1 = 0; 
  }
}