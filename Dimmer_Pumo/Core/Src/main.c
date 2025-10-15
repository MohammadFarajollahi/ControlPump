/* USER CODE BEGIN Header */
/**
******************************************************************************
* @file           : main.c
* @brief          : Main program body
******************************************************************************
* @attention
*
* Copyright (c) 2025 STMicroelectronics.
* All rights reserved.
*
* This software is licensed under terms that can be found in the LICENSE file
* in the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
******************************************************************************
*/
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
//#include "cJSON.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

IWDG_HandleTypeDef hiwdg;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;

WWDG_HandleTypeDef hwwdg;

/* USER CODE BEGIN PV */
int zero_cross_flag;
int Voltage;


int SoftVoltage;
int SoftUpCount;
int softTimer1;
int softStart_State=0;
int SecMain;
int SecCount;
//lcd light
int lcdLight=1;

int lcdLightTimer;

//seting
int setting;

uint16_t StartVoltage_eeprom;
uint16_t StartTime_eeprom;
uint16_t SoftTime_eeprom;
uint16_t pressure_eeprom;
uint16_t mode_eeprom;
float Current_eeprom;
uint16_t TurnOnDelay_eeprom;
uint16_t PressureDown_eeprom;
uint16_t ofTimer_eeprom;
float UpCurrent_eeprom;
float DownCurrent_eeprom;
uint16_t TimeHavaKeshi_eeprom;
uint16_t CurrentDownRealizeTime_eeprom;

float Pressure;
float current;
//ADC_HandleTypeDef hadc;
//ADC_ChannelConfTypeDef sConfig = {0};

uint32_t adc_val_ch0 = 0;
uint32_t adc_val_ch1 = 0;
float adc1;
float bar;
int mode;
int modeControlCount;
int menuSelect;
int changeMenu;
char lcdShow[20];

int oftimerCount;
int ofTimer;

int DimerModeTimer;

int volt2;
int timeSoft2;
char ss[100];
int taqsim;
long TimeSet;

int PumpState;
int TurnOnDelay;
int TurnOnDelayTimer;

int currentAlarmTimer;
int CurrentAllarmCount;
int CurrentAlarm;
int currentRealizeTime;
int CurrentFulat;
int TimeReturn;

//*** Uart ***
#define RX_BUFFER_SIZE 290
uint8_t rx_buffer1[RX_BUFFER_SIZE];
uint8_t rx_data1;
volatile uint16_t rx_index1 = 0;
int UartTrigTime;
int UartTrig;
char char_test1[295];
uint32_t last_time;
int uartTimeTest;

int hang;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM1_Init(void);
static void MX_IWDG_Init(void);
static void MX_WWDG_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#include "delay.c"
#include "nokia1202/nokia1202.c" // YplusOnXbyte = (LedHeight + 7) / 8;
#include "lcd1202.c"
#include "ZeroCross.c"
#include "program.c"
//#include  "Pictures/logopavan.c"
//#include  "Pictures/setting.c"
//#include  "Pictures/settingup.c"
//#include  "Pictures/settingdown.c"
//#include  "Pictures/manualSetting.c"
//#include  "Pictures/autoSetting.c"
//#include  "Pictures/freeScreen.c"
#include "i2c_eeprom/i2c_eeprom.c"
#include "Pictures/menu.c"
//#include "Pictures/Settinglogo.c"
#include "Pictures/StartVoltage.c"
#include "Pictures/Starttime.c"
#include "Pictures/kadr.c"
#include "Pictures/saveEEprom.c"
#include "Pictures/softstarttime.c"
#include "Pictures/tanzimFeshar.c"
//#include "Pictures/devicemode.c"
//#include "Pictures/softset.c"
#include "Pictures/setcontrol.c"
//#include "Pictures/dimermode.c"
#include "Pictures/currensetting.c"
#include "Pictures/tanzimFesharDown.c"
#include "Pictures/OfDelay.c"
#include "Pictures/Ondelay.c"
#include "Pictures/DownCurrent.c"
#include "Pictures/TimeHavaKeshi.c"
#include "Pictures/RealizeTime.c"
#include "checl.c"
#include "uart.c"
//#include "Pictures/pavanlogo.c"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) // 100ms
{
  
  if (htim->Instance == TIM1) //++count=1000 ---> 1s
  {
    
    if(softStart_State == 0)softTimer1++;
    
    ++SecMain;
    if(SecMain >=1000){
      SecMain = 0;     
      if(TurnOnDelay == 1)++TurnOnDelayTimer;
      if(oftimerCount == 1)++ofTimer;          
      if(lcdLight == 1 && setting ==0) ++lcdLightTimer;
      if(CurrentAllarmCount >= 1)++currentAlarmTimer;
      if(CurrentAlarm >= 1)++currentRealizeTime;
      if(CurrentFulat == 2)++TimeReturn;  
      if(lcdLightTimer >= 60 && lcdLight == 1){
        lcdLight = 0;
        lcdLightTimer =0;
        HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_RESET);
      }
    }
  }  
}


//

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  MX_IWDG_Init();
  MX_WWDG_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim1); 
  HAL_UART_Receive_IT(&huart1, &rx_data1, 1);
  HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);
  //eeprom config
  I2C_init();
  //HAL_Delay(5);
   if(HAL_GPIO_ReadPin(k_up_GPIO_Port, k_up_Pin) == 0){
    HAL_GPIO_WritePin(blut_GPIO_Port, blut_Pin, GPIO_PIN_SET); 
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);   
    HAL_Delay(5000);
    show_uart("AT");
    HAL_Delay(1000);
    show_uart("AT");
    HAL_Delay(1000);
    show_uart("AT+NAME=Pump-V1_3");
    HAL_Delay(1000);
    show_uart("AT+UART=38400,0,0");
    HAL_Delay(1000);
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
    eeprom_write_int16(110,0);
    HAL_Delay(5);
    eeprom_write_int16(2500,10);
    HAL_Delay(5);
    eeprom_write_int16(4000,20);
    HAL_Delay(5);
    eeprom_write_int16(50,30);
    HAL_Delay(5);
    eeprom_write_int16(1,40);
    HAL_Delay(5);
    eeprom_write_int16(25,50);
    HAL_Delay(5);
    eeprom_write_int16(5,60);
    HAL_Delay(5);
    eeprom_write_int16(45,70);
    HAL_Delay(5);
    eeprom_write_int16(10,80);
    HAL_Delay(5);
    eeprom_write_int16(60,90);
    HAL_Delay(5);
    eeprom_write_int16(35,100);
    HAL_Delay(5);
    eeprom_write_int16(15,110);
    HAL_Delay(5);
    eeprom_write_int16(120,120);
    HAL_Delay(5);  
    hang = 1;
    HAL_Delay(1000); 
  }
  
  StartVoltage_eeprom = eeprom_read_int16(0);
  Voltage = StartVoltage_eeprom;
  HAL_Delay(5);
  StartTime_eeprom = eeprom_read_int16(10);
  HAL_Delay(5);
  SoftTime_eeprom = eeprom_read_int16(20);
  HAL_Delay(5);
  pressure_eeprom = eeprom_read_int16(30);
  HAL_Delay(5);
  mode_eeprom = eeprom_read_int16(40);
  HAL_Delay(5);
  Current_eeprom = eeprom_read_int16(50);
  Current_eeprom /= 10;
  HAL_Delay(5);
  TurnOnDelay_eeprom = eeprom_read_int16(60);
  HAL_Delay(5);
  PressureDown_eeprom = eeprom_read_int16(70);
  HAL_Delay(5);
  ofTimer_eeprom = eeprom_read_int16(80);
  HAL_Delay(5);
  UpCurrent_eeprom = eeprom_read_int16(90);
  UpCurrent_eeprom /=10;
  HAL_Delay(5);
  DownCurrent_eeprom = eeprom_read_int16(100);
  DownCurrent_eeprom /=10;
  HAL_Delay(5);
  TimeHavaKeshi_eeprom = eeprom_read_int16(110);
  HAL_Delay(5);
  CurrentDownRealizeTime_eeprom = eeprom_read_int16(120);
  CurrentDownRealizeTime_eeprom*=60;
  HAL_Delay(5);
  
  //LCD
  lcdinit();
  HAL_Delay(5);
  Lcd_Clear();
  Lcd_Refresh();
  
  HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
  HAL_Delay(100);
  HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
 
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    
    MainCod();
    menu();
    MC60Uart();
    HAL_IWDG_Refresh(&hiwdg);    
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */
          
  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */
          
  /* USER CODE END ADC_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */
          
  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */

  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_256;
  hiwdg.Init.Window = 4095;
  hiwdg.Init.Reload = 4095;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */

  /* USER CODE END IWDG_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */
          
  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */
          
  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 500;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 100;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */
          
  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */
          
  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */
          
  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
          
  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief WWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_WWDG_Init(void)
{

  /* USER CODE BEGIN WWDG_Init 0 */

  /* USER CODE END WWDG_Init 0 */

  /* USER CODE BEGIN WWDG_Init 1 */

  /* USER CODE END WWDG_Init 1 */
  hwwdg.Instance = WWDG;
  hwwdg.Init.Prescaler = WWDG_PRESCALER_1;
  hwwdg.Init.Window = 64;
  hwwdg.Init.Counter = 127;
  hwwdg.Init.EWIMode = WWDG_EWI_ENABLE;
  if (HAL_WWDG_Init(&hwwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN WWDG_Init 2 */

  /* USER CODE END WWDG_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
          
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, blut_Pin|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|buzzer_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|triak_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LcdLight_GPIO_Port, LcdLight_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : blut_Pin PA5 PA6 PA7
                           PA10 buzzer_Pin */
  GPIO_InitStruct.Pin = blut_Pin|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_10|buzzer_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 LcdLight_Pin triak_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_0|LcdLight_Pin|triak_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : k_back_Pin */
  GPIO_InitStruct.Pin = k_back_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(k_back_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : k_up_Pin k_down_Pin k_ok_Pin */
  GPIO_InitStruct.Pin = k_up_Pin|k_down_Pin|k_ok_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : cross_Pin */
  GPIO_InitStruct.Pin = cross_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(cross_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
          
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
    if(hang == 0) HAL_WWDG_Refresh(hwwdg);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
          /* User can add his own implementation to report the HAL error return state */
          __disable_irq();
          while (1)
          {
          }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
          /* User can add his own implementation to report the file name and line number,
          ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
