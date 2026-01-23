/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
//#include "NOKIA1202/NOKIA1202.c"
//#include "lcd1202.c"
//#include "eeprom.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
int a=0,b=0,aa=0,c=0;
int j;
char lcd[20];
float auto_para_0=0;
float auto_para_1=0;
float parameter_index;
float parameter[7] = {4,2,8,10,3,10,0};
float parameter_val=0;
uint16_t tv ;
uint16_t VirtAddVarTab[7] = {0,24,8,12,16,28,40};
uint16_t VirtdataVarTab[7] ;
int flag=0;
int timer,timer_mode=0;
int relay_counter=0;
int relay_mode=2;
int retry_counter,retry_mode=0;
//float startup_counter=0;
int startup_set_flag=0;
int startup_reset_flag=0;
int set_mode=0;
int menu_mode=1;
int menu_pose=0;
int exit_mode=0;
int retry_number=0;
int dis_mode=1;
int menu_exit=0;
int menu_return=0;
int relay_counter_flag=1;
int retry_error=0;
float adc=0;
float ADC_CF;
float CF=0.1;
float CFF=0;
int error_mode=0;
int sampling_timer=0;
int sampling_flag=0;
int retry_error_flag=0;
int startup_set=0;
float startup_reset=0;
int buffer[2]={0,0};
float b0=0,b1=0;
int retry_cancel=0;
int pressure_high=0;
int pressure_low=0;
int startup_mode=1;
int check=0,check_1=0,check_2=0,check_para=0;
int Backlight_timer=0;



/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;
DMA_HandleTypeDef hdma_adc;

IWDG_HandleTypeDef hiwdg;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim14;
TIM_HandleTypeDef htim16;
TIM_HandleTypeDef htim17;

/* USER CODE BEGIN PV */



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM14_Init(void);
static void MX_TIM16_Init(void);
static void MX_TIM17_Init(void);
static void MX_IWDG_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */
void setting_mode(void);
int setting_menu(void);
int incr_decr(uint8_t parameter_index , float parameter_val , int minimum , int maximum , int mode);
void save_para(uint16_t para , float val);
int read_para(uint16_t para);
void lcd_mode(int mode , float par);
void Relay_setting(void);
void Display(void);
void Error_Display(void);
int menu_para(int para);
int auto_mode(int position);


# include "slave.c"

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

     void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

       
     if ( htim->Instance == htim1.Instance ){      //Backlight
     
          
     Backlight_timer++;
    
       if ( Backlight_timer > 130 ){

         HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1,GPIO_PIN_RESET);   //Backlight Pin
         Backlight_timer=0;
         
       }
  

   }
       
       
       
   if ( htim->Instance == htim3.Instance ){      //Paresh az menu
     
     HAL_IWDG_Refresh(&hiwdg);
     startup_reset++;
     timer++;
    
       if ( timer > 25 ){
          timer_mode=1;
          timer = 0;       
          exit_mode=1;
       }
  
       if( startup_reset > 5 ){
          startup_reset_flag=1;
          startup_reset=0;
       }
   }
  
   if ( htim->Instance == htim14.Instance ){          //reaction delay(for reset relay)
     
     HAL_IWDG_Refresh(&hiwdg);
     relay_counter++;

       if ( relay_counter > 12 ){
          Lcd_Refresh();
          relay_mode=0;
          set_mode=1;
          relay_counter = 0;   
       }
   }
  
   if ( htim->Instance == htim16.Instance ){          //retry delay
       
     HAL_IWDG_Refresh(&hiwdg);
     startup_reset=0;
     relay_counter = 0;
     retry_counter++;
       
       if ( retry_counter >= parameter[3] ){
          retry_mode=1;
          retry_counter = 0;
       }
   }
  
   if ( htim->Instance == htim17.Instance ){
      
     HAL_IWDG_Refresh(&hiwdg);
     sampling_timer++;
    
       if( sampling_timer > 60 ){
          sampling_flag=1;
          sampling_timer=0;
       }
    
   }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
  
}	



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
  MX_DMA_Init();
  MX_ADC_Init();
  MX_TIM3_Init();
  MX_TIM14_Init();
  MX_TIM16_Init();
  MX_TIM17_Init();
  MX_IWDG_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
 //HAL_FLASH_Unlock();
 //EE_Init();
 
 HAL_ADC_Start_DMA(&hadc, buffer, 2);
  

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    
 


     slave();
   
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
  hadc.Init.ContinuousConvMode = ENABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = ENABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
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
  hiwdg.Init.Reload = 1250;
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
  htim1.Init.Prescaler = 7999;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 3000;
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
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 7999;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 3000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 7000;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 5000;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 7500;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 4000;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

}

/**
  * @brief TIM17 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM17_Init(void)
{

  /* USER CODE BEGIN TIM17_Init 0 */

  /* USER CODE END TIM17_Init 0 */

  /* USER CODE BEGIN TIM17_Init 1 */

  /* USER CODE END TIM17_Init 1 */
  htim17.Instance = TIM17;
  htim17.Init.Prescaler = 7000;
  htim17.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim17.Init.Period = 2000;
  htim17.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim17.Init.RepetitionCounter = 0;
  htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim17) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM17_Init 2 */

  /* USER CODE END TIM17_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel2_3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_SCE_Pin|POWER_VOLTAGE_Pin|LCD_SCLK_Pin|LCD_RST_Pin
                          |LCD_DN_Pin|SCL_Pin|SDA_Pin|BUZZER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, backlight_Pin|Relay_Main_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : INPUT_Pin */
  GPIO_InitStruct.Pin = INPUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(INPUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_SCE_Pin POWER_VOLTAGE_Pin LCD_SCLK_Pin LCD_RST_Pin
                           LCD_DN_Pin BUZZER_Pin */
  GPIO_InitStruct.Pin = LCD_SCE_Pin|POWER_VOLTAGE_Pin|LCD_SCLK_Pin|LCD_RST_Pin
                          |LCD_DN_Pin|BUZZER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : backlight_Pin Relay_Main_Pin */
  GPIO_InitStruct.Pin = backlight_Pin|Relay_Main_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : SCL_Pin SDA_Pin */
  GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SW3_Pin SW4_Pin SW2_Pin SW1_Pin */
  GPIO_InitStruct.Pin = SW3_Pin|SW4_Pin|SW2_Pin|SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void setting_mode(void){
     
     while (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0){
       

       
           for (int i = 0 ; i < 4 ;i++){
             
              Lcd_Clear();
              sprintf(lcd, "%.01f" , parameter[6] );
              lcd_putsf_point(22,37,lcd,TAHOMA_8x10);
              Lcd_Refresh();
              HAL_Delay(400);
              
              //lcd_putsf_point(17,40,"          ",TAHOMA_8x10);
              lcd_putsf_point(20,38,"          ",TAHOMA_8x10);
              lcd_putsf_point(20,39,"          ",TAHOMA_8x10);
              lcd_putsf_point(20,40,"          ",TAHOMA_8x10);
              lcd_putsf_point(20,41,"          ",TAHOMA_8x10);
              //lcd_putsf_point(22,40,"          ",TAHOMA_8x10);
              Lcd_Refresh();
              HAL_Delay(400);
              
             if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==1){
                  menu_mode=0;
                     
                 //setting_active = 0 ;
                 break;
                 }
              
           }
           
           
           
           }
  
     int setting_active = 1;
     while (HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==0){
       
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1,GPIO_PIN_SET);
       HAL_TIM_Base_Stop_IT(&htim1);
       
     for (int i = 0 ; i < 4 ;i++){
       HAL_TIM_Base_Stop_IT(&htim14);
       relay_counter = 0;
       relay_mode = 2;
       retry_counter=0;
       retry_mode=0;
                 Lcd_Clear();
                 
                Lcd_Put_Icon2_Invert(6,28,wait_icon_Info);
                
                 Lcd_Refresh();
                 HAL_Delay(400);
                 lcd_putsf_point(3,28,"              ",TAHOMA_8x10);
                 lcd_putsf_point(3,29,"              ",TAHOMA_8x10);
                 lcd_putsf_point(3,30,"              ",TAHOMA_8x10);
                 lcd_putsf_point(3,31,"              ",TAHOMA_8x10);
                 lcd_putsf_point(3,32,"              ",TAHOMA_8x10);
                 
                 Lcd_Refresh();               
                 HAL_Delay(400);
                 HAL_IWDG_Refresh(&hiwdg);                                
                 menu_mode=1;
                 
                 if (HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==1){
                     menu_mode=0;
                     setting_active = 0 ;
                     break;
                 }
     }

       if ( setting_active == 1 )
         
       if ( setting_menu()== 0 ){
        timer=0;
        timer_mode=0;
        flag=0;      
        
        //HAL_TIM_Base_Stop_IT(&htim1);
        //Backlight_timer=0;
        HAL_TIM_Base_Stop_IT(&htim3);
        HAL_TIM_Base_Stop_IT(&htim14);
        HAL_TIM_Base_Stop_IT(&htim16);
        HAL_TIM_Base_Stop_IT(&htim17);

        break;
       }
    }
 }

int setting_menu(void){
          HAL_TIM_Base_Stop_IT(&htim14);
          HAL_TIM_Base_Stop_IT(&htim16);
          HAL_TIM_Base_Stop_IT(&htim17);        
          startup_set_flag=0;
          startup_reset_flag=0;  
          startup_reset=0; 
          HAL_TIM_Base_Start_IT(&htim3);
          timer_mode=0;
          timer = 0;
          relay_counter = 0;
          relay_mode = 2;
          retry_counter=0;
          retry_mode=0;
          Lcd_Clear();
                 
          menu_high :
               
               HAL_TIM_Base_Start_IT(&htim3);
               menu_para(0);
               HAL_Delay(1300);      
               Lcd_Refresh();
                                                
  while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==1){
    
    menu_exit=1;
    menu_return=0;
    
    if (timer_mode==1) {
      Backlight_timer=0;
      HAL_TIM_Base_Start_IT(&htim1);
      
      return 0 ;
    }
           
          if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
                         
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
                HAL_Delay(70);
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
                
               exit_mode=1;
               timer_mode=0;
               timer=22;         
               Lcd_Clear();
               Lcd_Put_Icon2_Invert(12,95,exit1_icon_Info);
               Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
               Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
               Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
               Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
               Lcd_Refresh();         
               HAL_Delay(2000);
               menu_mode=0;
               
               Backlight_timer=0;
               HAL_TIM_Base_Start_IT(&htim1);
               
    }
      
        if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==0) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);         
        menu_low :  
        HAL_TIM_Base_Start_IT(&htim3);  
        menu_para(1); //show menu_low_current
        HAL_Delay(500);         
        }
 
     /*   else if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==1) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        menu_reacte :
        HAL_TIM_Base_Start_IT(&htim3);  
        menu_para(2); //show menu_reacte_time
        HAL_Delay(1000);                                
        }*/
    
        else if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==1) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
        menu_retry_time :  
        HAL_TIM_Base_Start_IT(&htim3);  
        menu_para(3); //show menu_retry_time
        HAL_Delay(500);
        }
        
        else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==3) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
        //menu_reacte :  
        menu_para(1); //show menu_low_current
        HAL_Delay(500);
        }
        
    /*    else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==2) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
        //menu_low :  
        menu_para(1); //show menu_low_current
        HAL_Delay(1000);
        }*/
        
        else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==1) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
          
        menu_para(0); //show menu_high_current
        HAL_Delay(500);
        }
        
        else if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==3) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
        menu_retry_number : 
        HAL_TIM_Base_Start_IT(&htim3);
        menu_para(4); //show menu_retry_number
        HAL_Delay(500);
        }
        
        else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==4) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
          
        menu_para(3); //show menu_retry_time
        HAL_Delay(500);
        } 
        
        else if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==4) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        menu_hc_manual :
        HAL_TIM_Base_Start_IT(&htim3);  
        menu_para(6); //show menu_hc_manual
        HAL_Delay(500);                                
        }  
        
        else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==6) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
        //HAL_TIM_Base_Start_IT(&htim3);
        menu_para(4); //show menu_retry_number
        HAL_Delay(500);
        }        
        
        else if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==6) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        menu_lc_manual :
        HAL_TIM_Base_Start_IT(&htim3);  
        menu_para(7); //show menu_lc_manual
        HAL_Delay(500);                                
        }  
        
        else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==7) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
        //HAL_TIM_Base_Start_IT(&htim3);
        menu_para(6); //show menu_hc_manual
        HAL_Delay(500);
        }         
   /*     else if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0 && (menu_pose==4) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        menu_pressure :
        HAL_TIM_Base_Start_IT(&htim3);  
        menu_para(5); //show menu_pressure
        HAL_Delay(1000);                                
        }
        
        else if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0 && (menu_pose==5) ) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);          
          
        menu_para(4); //show menu_retry_number
        HAL_Delay(1000);
        } */
        
                     if (HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==0){
                          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
                          HAL_Delay(70);
                          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
                     }
  }
                    
        Lcd_Clear();
        HAL_Delay(500);

          if ( menu_pose==0 ){      
          //incr_decr(0 , parameter[0] , 0 ,10 , 0);
           auto_mode(0);           
           retry_number=0;
           goto menu_high;   
           }  
         
          if ( menu_pose==1 ){
          //incr_decr(1 , parameter[1] , 0 ,10 , 1);
          auto_mode(1);  
          retry_number=0;
          //parameter[1]=parameter[1]+0.000001;
          goto menu_low;      
          }        
                       
       /*   if ( menu_pose==2 ){
          incr_decr(2 , parameter[2] , 8 , 15 , 2);
          retry_number=0;
          goto menu_reacte;
          } */
        
          if ( menu_pose==3 ){
          incr_decr(3 , parameter[3] , 15 ,180 , 3);
          retry_number=0;
          goto menu_retry_time;
          }         
        
          if ( menu_pose==4 ){
          incr_decr(4 , parameter[4] , 1 ,5 , 4);
          retry_number=0;
          goto menu_retry_number;
          }  
        
          if ( menu_pose==6 ){
          incr_decr(0 , parameter[0] , 0 ,20 , 6);
          retry_number=0;
          goto menu_hc_manual;
          }            
          
          if ( menu_pose==7 ){
          incr_decr(1 , parameter[1] , 0 ,20 , 7);
          retry_number=0;
          goto menu_lc_manual;
          }          
          
        
          
        /*  if ( menu_pose==5 ){
          incr_decr(5 , parameter[5] , 200 ,360 , 5);
          retry_number=0;
          goto menu_pressure;
          }  */
                         
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
                HAL_Delay(70);
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
              
        return 1 ;      
}

int incr_decr(uint8_t parameter_index , float parameter_val , int minimum , int maximum ,int mode ){
      
    menu_exit=0;
    menu_return=1;

     Lcd_Clear();
     HAL_TIM_Base_Start_IT(&htim3);
     timer=0;
     timer_mode=0;
  
  while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==1){
    
    if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
      Lcd_Clear();
      timer_mode=0;
      timer=22;   
      Lcd_Put_Icon2_Invert(4,100,return_icon_Info);
                Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
                Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
   
      Lcd_Refresh();
      HAL_Delay(2000);
      Lcd_Clear();
      menu_mode=0;
      return 0;      
      }
    
      if (timer_mode==1){
      flag=1;
      

      return 0 ;
      }
    
      lcd_mode(mode,parameter_val);
  
      if (HAL_GPIO_ReadPin(SW4_GPIO_Port,SW4_Pin)==0){
        
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        
        timer=0;
        timer_mode=0;
        
        if(mode==0 | mode==1){
        
            parameter_val=parameter_val + 0.1;
    
               if ( parameter_val >= maximum ){
                  parameter_val = maximum;
               }
                HAL_Delay(300); 
        }
        
         if (mode==2 | mode==3 | mode==4 ){
        
             parameter_val++;
    
               if ( parameter_val >= maximum ){
                  parameter_val = maximum;
               }
                 HAL_Delay(200);  
         }  
        
         if( mode==6 | mode==7 ){
        
            parameter_val=parameter_val + 0.1;
    
               if ( parameter_val >= maximum ){
                  parameter_val = maximum;
               }
                HAL_Delay(300); 
         }        
        
        
           /*     if( mode==5 ){
        
            parameter_val=parameter_val + 20;
    
               if ( parameter_val > maximum ){
      
                  parameter_val = minimum;
               }
                HAL_Delay(300); 
        } */
        
   }
        
      if (HAL_GPIO_ReadPin(SW2_GPIO_Port,SW2_Pin)==0){

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
        HAL_Delay(70);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        
        timer=0;
        timer_mode=0;
 
           if(mode==0 | mode==1){
        
              parameter_val=parameter_val - 0.1 ;
    
                 if ( parameter_val <= minimum ){
                     parameter_val = minimum;
                 }
                  HAL_Delay(300); 
           }
        
          if (mode==2 | mode==3 | mode==4 ){
        
               parameter_val--;
               HAL_Delay(150);
               
                       if ( parameter_val <= minimum ){
                         parameter_val = minimum;
                         HAL_Delay(200);
                       }
          }
          
          if( mode==6 | mode==7 ){
        
             parameter_val=parameter_val - 0.1;
    
               if ( parameter_val <= minimum ){
                  parameter_val = minimum;
               }
                HAL_Delay(300); 
          }          
          
                  /*   if( mode==5 ){
        
              parameter_val=parameter_val - 20 ;
    
                 if ( parameter_val < minimum ){
    
                     parameter_val = maximum;
                 }
                  HAL_Delay(300); 
           }   */      
      }
  }
      Lcd_Clear();
      while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==0);
    
      HAL_TIM_Base_Stop_IT(&htim3);
             
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
      HAL_Delay(70);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
              
      Lcd_Put_Icon2_Invert(0,96,ok_button_icon_Info);
      Lcd_Refresh();
      HAL_Delay(2000); 
      Lcd_Clear();

   error_mode=0;
   retry_cancel=0;
   parameter[parameter_index]=parameter_val;
   save_para(parameter_index , parameter_val);
   error_mode=0;
   parameter[6]=0;
   return  parameter_val;
}


int menu_para(int para){
         
  if(para==0){  //show high_current
    exit_mode=0;
    menu_pose=0;
    timer_mode=0;
    timer = 0;
    Lcd_Clear();
  
       if (timer_mode==1){
         return 0;
       }

       Lcd_Put_Icon2_Invert(7,96,high_current1_icon_Info);
       Lcd_Put_Icon2_Invert(34,118,down_icon_Info);
       Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
       Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);        
       Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
       Lcd_Put_Icon2_Invert(0,66,line_icon_Info);  
       Lcd_Refresh();
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
  }
  
  else if (para==1){   //show low_current
     menu_pose=1;
     timer_mode=0;
     timer = 0;
        if (timer_mode==1){
           return 0;  
        }
        
           Lcd_Put_Icon2_Invert(34,118,down_icon_Info);
           Lcd_Put_Icon2_Invert(1,96,low_current_icon_Info);
           Lcd_Put_Icon2_Invert(34,2,up_icon_Info);           
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);         
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();
  }
  
  /*  else if (para==2){   //show reaction_time
       menu_pose=2;
       timer_mode=0;
       timer = 0;
       Lcd_Clear();
          if (timer_mode==1){      
            return 0; 
          }
          
           Lcd_Put_Icon2_Invert(34,118,down_icon_Info);
           Lcd_Put_Icon2_Invert(34,2,up_icon_Info);
           Lcd_Put_Icon2_Invert(8,90,reaction_time_icon_Info);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);           
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();        
    }*/
  
      else if (para==3){     //show retry_time
          menu_pose=3;
          timer_mode=0;
          timer = 0;
          Lcd_Clear();
             if (timer_mode==1){ 
               return 0;    
             }
                Lcd_Put_Icon2_Invert(34,118,down_icon_Info);
                Lcd_Put_Icon2_Invert(2,97,retry_time_icon_Info);
                Lcd_Put_Icon2_Invert(34,2,up_icon_Info);                
                Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);        
                Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                Lcd_Refresh();      
      }
  
       else if (para==4){    //show retry_number
           menu_pose=4;
           timer_mode=0;
           timer = 0;
           Lcd_Clear();
              if (timer_mode==1){
                return 0; 
              }
                  Lcd_Put_Icon2_Invert(34,118,down_icon_Info);
                  Lcd_Put_Icon2_Invert(0,97,retry_number_icon_Info);
                  Lcd_Put_Icon2_Invert(34,2,up_icon_Info);                  
                  Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                  Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);                
                  Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                  Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                  Lcd_Refresh();      
       }  
  
       else if (para==6){    //show hc_manual
           menu_mode=1;
           menu_pose=6;
           timer_mode=0;
           timer = 0;
           Lcd_Clear();
              if (timer_mode==1){
                return 0; 
              }
                  Lcd_Put_Icon2_Invert(34,118,down_icon_Info);
                  Lcd_Put_Icon2_Invert(8,89,hc_manual_icon_Info);
                  Lcd_Put_Icon2_Invert(34,2,up_icon_Info);                  
                  Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                  Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);                
                  Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                  Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                  Lcd_Refresh();      
       }
  
       else if (para==7){    //show lc_manual
           menu_mode=1;
           menu_pose=7;
           timer_mode=0;
           timer = 0;
           Lcd_Clear();
              if (timer_mode==1){
                return 0; 
              }
                  Lcd_Put_Icon2_Invert(34,2,up_icon_Info);
                  Lcd_Put_Icon2_Invert(3,91,lc_manual_icon_Info);
                  Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                  Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);                
                  Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                  Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                  Lcd_Refresh();      
       }  
  
  
      /*   else if (para==5){    //show pressure
           menu_pose=5;
           timer_mode=0;
           timer = 0;
           Lcd_Clear();
              if (timer_mode==1){
                return 0; 
              }
                  Lcd_Put_Icon2_Invert(34,2,up_icon_Info);
                  Lcd_Put_Icon2_Invert(27,98,pressure_icon_Info);
                  Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                  Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);                
                  Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                  Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                  lcd_putsf_point(11,25,"   ",TAHOMA_8x10);
                  lcd_putsf_point(11,27,"   ",TAHOMA_8x10);                              
                  Lcd_Refresh();      
       }  */
  
           return para;
}

int auto_mode(int position){
  
  if(position==0){
     timer_mode=0;
     timer = 0;
       while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==1){
  
     sampling_flag=0;
     Lcd_Put_Icon2_Invert(8,0,input_open_icon_Info);
     Lcd_Put_Icon2_Invert(8,17,output_open_icon_Info);
     Lcd_Put_Icon2_Invert(12,33,press_enter_icon_Info);
     Lcd_Refresh();
     
     if (timer_mode==1){  
       return 0;  
     }
       
         if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
           
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
               HAL_Delay(70);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
               Lcd_Clear();
               timer_mode=0;
               timer=22;   
               Lcd_Put_Icon2_Invert(4,100,return_icon_Info);
               Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
               Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
               Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
               Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
               Lcd_Refresh();
               HAL_Delay(2000);
               Lcd_Clear();
               menu_mode=0;
               return 0;
          }
  }
  
       while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==0);
         HAL_TIM_Base_Stop_IT(&htim3);
         HAL_TIM_Base_Start_IT(&htim17);
         HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_SET);
              while(sampling_flag==0){
     
                   if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
                       HAL_TIM_Base_Stop_IT(&htim17);
                       sampling_timer=0;
                       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
                       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
                       HAL_Delay(70);
                       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
                       Lcd_Clear();
                       timer_mode=0;
                       timer=22;   
                       Lcd_Put_Icon2_Invert(4,100,return_icon_Info);
                       Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                       Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
                       Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                       Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                       Lcd_Refresh();
                       HAL_Delay(2000);
                       Lcd_Clear();
                       
                       return 0;
                    }
     
         /*   for ( j=0 ; j<80 ; j++) {
      
               b0  +=buffer[0];
               HAL_Delay(10);
             }      
                b0 /= 80 ;
                HAL_Delay(10);   */
    
      for ( j=0 ; j<200 ; j++) {  
  
        b1  +=buffer[1]; 
        HAL_Delay(10);
      }
       
        b1 /= 200 ;
        ADC_CF = b1 + CFF;
        adc = ADC_CF - (ADC_CF*CF);    
        
        if (adc<20 | adc>700){
           Current=0;
        }
        
        else if (adc>=21 && adc<=250){
          Current = ( adc + 47.818) / 93.309 ;     
        }
        
        else if (adc>251 && adc<=700){    
          Current = ( adc - 54.888) / 61.022 ;
        }
     
     Lcd_Clear();
     Lcd_Put_Icon2_Invert(6,16,high_current1_icon_Info);
     Lcd_Put_Icon2_Invert(40,36,amper_icon_Info);
     sprintf(lcd, "%.01f" , Current );
     lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
     Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
     Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
     Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
     Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
     Lcd_Refresh();  
  }
  
   Lcd_Clear();
   HAL_TIM_Base_Start_IT(&htim3);
   timer_mode=0;
   timer = 0;
   HAL_TIM_Base_Stop_IT(&htim17);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
   Lcd_Put_Icon2_Invert(0,96,ok_button_icon_Info);
   Lcd_Refresh();
   tv= Current * (10+5) ; //5 means 50% increase
   auto_para_0=tv;
   parameter[0]=(auto_para_0/10);
   eeprom_write_int16(tv,VirtAddVarTab[0]);
   error_mode=0;
   retry_cancel=0;
   HAL_Delay(2000); 
  }
  
  else if(position==1){
    timer_mode=0;
    timer = 0;
  while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==1){
  
     sampling_flag=0;
     Lcd_Put_Icon2_Invert(1,1,input_close_icon_Info);
     Lcd_Put_Icon2_Invert(8,17,output_open_icon_Info);
     Lcd_Put_Icon2_Invert(12,33,press_enter_icon_Info);
     Lcd_Refresh();
     
     if (timer_mode==1){
       Lcd_Clear();
       return 0;   
     }
       
         if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
              
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
               HAL_Delay(70);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
               Lcd_Clear();
               timer_mode=0;
               timer=22;   
               Lcd_Put_Icon2_Invert(4,100,return_icon_Info);
               Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
               Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
               Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
               Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
               Lcd_Refresh();
               HAL_Delay(2000);
               Lcd_Clear();
               menu_mode=0;
               return 0;
          }
  }
  
  while(HAL_GPIO_ReadPin(SW1_GPIO_Port,SW1_Pin)==0);
      HAL_TIM_Base_Stop_IT(&htim3);
      HAL_TIM_Base_Start_IT(&htim17);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_SET);
          while(sampling_flag==0){
     
              if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
                 HAL_TIM_Base_Stop_IT(&htim17);
                 sampling_timer=0;
                 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
                 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);  
                 HAL_Delay(70);
                 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
                 Lcd_Clear();
                 timer_mode=0;
                 timer=22;   
                 Lcd_Put_Icon2_Invert(4,100,return_icon_Info);
                 Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                 Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
                 Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                 Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                 Lcd_Refresh();
                 HAL_Delay(2000);
                 Lcd_Clear();
                 
                 return 0;
    }
     
         /*   for ( j=0 ; j<80 ; j++) {
              b0  +=buffer[0];  
              HAL_Delay(10);
            }
       
              b0 /= 80 ;
              HAL_Delay(10);   */
    
      for ( j=0 ; j<200 ; j++) {
         b1  +=buffer[1];
         HAL_Delay(10);
      }  
        b1 /= 200 ;
        ADC_CF = b1 + CFF;
        adc = ADC_CF - (ADC_CF*CF); 
    
        if (adc<20 | adc>700){
          Current=0;
        }
        
        else if (adc>=21 && adc<=250){
            Current = ( adc + 47.818) / 93.309 ;     
        }
        
        else if (adc>251 && adc<=700){
            Current = ( adc - 54.888) / 61.022 ;
        }

           Lcd_Clear();
           Lcd_Put_Icon2_Invert(1,16,low_current_icon_Info);
           Lcd_Put_Icon2_Invert(40,36,amper_icon_Info);
           sprintf(lcd, "%.01f" , Current );
           lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();  
  }
  
   Lcd_Clear();
   HAL_TIM_Base_Stop_IT(&htim17);
   HAL_TIM_Base_Start_IT(&htim3);
   timer_mode=0;
   timer = 0;
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
   Lcd_Put_Icon2_Invert(0,96,ok_button_icon_Info);
   Lcd_Refresh();
   tv= Current * (10-2) ; //2 means 20% decrease
   auto_para_1=tv;
   parameter[1]=auto_para_1/10;
   eeprom_write_int16(tv,VirtAddVarTab[1]);
   error_mode=0;
   retry_cancel=0;
   HAL_Delay(2000);
  
  }
 return position; 
}



void lcd_mode(int mode , float par){
  
  /*  if (mode==0){  
      
      Lcd_Put_Icon2_Invert(6,10,high_current1_icon_Info);
      Lcd_Put_Icon2_Invert(40,34,amper_icon_Info);
      //Lcd_Refresh();
      sprintf(lcd, "%.01f" , par );
      lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
      Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
      Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
      Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
      Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
      Lcd_Refresh();    
   }
                                                              //we have auto set for HC & LC
      else if (mode==1){                                     //we dont need mode0 & mode1 in auto set
  
           Lcd_Put_Icon2_Invert(1,10,low_current_icon_Info);
           Lcd_Put_Icon2_Invert(40,34,amper_icon_Info);
           sprintf(lcd, "%.01f" , par );
           lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();
      }*/
  
   /*    if (mode==2){
           Lcd_Put_Icon2_Invert(12,10,reaction_time_icon_Info);
           Lcd_Put_Icon2_Invert(43,40,second_icon_Info);
           sprintf(lcd, "%.01f" , par );
           lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
           lcd_putsf_point(28,40,"  ",TAHOMA_8x10);

               if( par < 10 ){
                   lcd_putsf_point(19,40,"   ",TAHOMA_8x10);
               }
                 Lcd_Put_Icon2_Invert(43,40,second_icon_Info);   
                 Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);               
                 Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
                 Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                 Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                 Lcd_Refresh();  
       }*/
  
       if (mode==3){
           Lcd_Put_Icon2_Invert(0,10,retry_time_icon_Info);
           sprintf(lcd, "%.01f" , par );
           lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
  
              if( par < 100){
                   lcd_putsf_point(31,40,"         ",TAHOMA_8x10);
                   }
              if( par >= 100){
                   lcd_putsf_point(36,40,"         ",TAHOMA_8x10);
                   }
                  Lcd_Put_Icon2_Invert(43,40,second_icon_Info);
                  Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
                  Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
                  Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
                  Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
                  Lcd_Refresh();
          }
  
      else if (mode==4){
   
          Lcd_Put_Icon2_Invert(1,10,retry_number_icon_Info);
          Lcd_Put_Icon2_Invert(43,42,number_icon_Info);
          sprintf(lcd, "%.01f" , par );
          lcd_putsf_point(13,42,lcd,TAHOMA_8x10);
          lcd_putsf_point(19,42,"   ",TAHOMA_8x10);
          Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
          Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
          Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
          Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
          Lcd_Refresh();
          }
     
      else if (mode==6){
       
        
            
           // lcd_putsf_point(36,42,"       ",TAHOMA_8x10);
           // lcd_putsf_point(36,34,"       ",TAHOMA_8x10);
           // lcd_putsf_point(36,44,"       ",TAHOMA_8x10);
          
        
          Lcd_Put_Icon2_Invert(6,16,high_current1_icon_Info);
          
          sprintf(lcd, "%.01f" , par );
          lcd_putsf_point(10,40,lcd,TAHOMA_8x10);
          if( par < 10){
          //lcd_putsf_point(32,35," ",TAHOMA_8x10);
          lcd_putsf_point(33,36," ",TAHOMA_8x10);
          lcd_putsf_point(33,37," ",TAHOMA_8x10);
          lcd_putsf_point(33,38," ",TAHOMA_8x10);
          lcd_putsf_point(33,39," ",TAHOMA_8x10);
          lcd_putsf_point(33,40," ",TAHOMA_8x10);
          }
          Lcd_Put_Icon2_Invert(44,36,amper_icon_Info);
          Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
          Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
          Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
          Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
          Lcd_Refresh();
          }
       
      else if (mode==7){
           Lcd_Put_Icon2_Invert(1,16,low_current_icon_Info);
           Lcd_Put_Icon2_Invert(40,36,amper_icon_Info);
           sprintf(lcd, "%.01f" , par );
           lcd_putsf_point(13,40,lcd,TAHOMA_8x10);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();  
          }

     
  
   /*   else if (mode==5){
          Lcd_Put_Icon2_Invert(28,90,pressure_icon_Info);       
          sprintf(lcd, "%.01f" , par );
          lcd_putsf_point(34,42,lcd,TAHOMA_8x10);
          lcd_putsf_point(56,42,"     ",TAHOMA_8x10);
          Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
          Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
          Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
          Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
          Lcd_Refresh();
     }  */
}


void Relay_setting(void){
  
  if( menu_mode==0){
    
     if( Current<parameter[1] | Current>parameter[0]){
            
            
            
                  if( ( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==1 )  &&  retry_number==0 ){
                      retry_cancel=0;
                      }
                                
               if(relay_counter_flag==1){ 
                    relay_counter=0;
                    relay_counter_flag=2;
               }
         
          HAL_TIM_Base_Stop_IT(&htim16);
          HAL_TIM_Base_Start_IT(&htim14);
       c++;
                       if(relay_mode==0){
                         
                           retry_cancel=1;
                           dis_mode=1;
                           HAL_TIM_Base_Stop_IT(&htim14);
                           HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
                           HAL_TIM_Base_Start_IT(&htim16);    
                           relay_counter=0;
                           set_mode=0;
                           
                   if( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==1){
                      retry_cancel=1;
                   }
    
                                  if(retry_mode==1){
     
                                     dis_mode=2;
                                     Lcd_Refresh();
                                     HAL_TIM_Base_Stop_IT(&htim16);
                                     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_SET);
                                     retry_number++;
                                     relay_mode=1;
                                     HAL_TIM_Base_Start_IT(&htim14);
                                     set_mode=0; 
                                  }
    
     else if((retry_number == (parameter[4])) && (retry_cancel==1)){
        HAL_Delay(6000); 
        retry_error_flag=1;    
     }
    }
  }
    retry_mode=0;
   
     if( Current>parameter[1] && Current<parameter[0] ) {
       
         HAL_TIM_Base_Start_IT(&htim14);
         
         if ( relay_mode==0 ) {
            retry_cancel=0;
            retry_number=0;
            HAL_TIM_Base_Stop_IT(&htim14);
         }
          if(relay_counter_flag==2){
                relay_counter=0;
                relay_counter_flag=1;
          }
            HAL_TIM_Base_Stop_IT(&htim16);
            retry_counter=0;
            HAL_TIM_Base_Start_IT(&htim14);
  
           if(set_mode==1){
               HAL_TIM_Base_Stop_IT(&htim14);
               HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_SET);
               dis_mode=2;
               retry_mode=0;
               relay_mode=1;    
            }
       }
   }
}



void Display(void){
   
      for ( j=0 ; j<80 ; j++) { 
          b1  +=buffer[1];   
          HAL_Delay(10);
      }
       
        b1 /= 80 ;  
        ADC_CF = b1 + CFF;    
        adc = ADC_CF - (ADC_CF*CF); 
 
           if (adc<20 | adc>700){
              Current=0;
           }
        
      /*  else if (ADC_Count>25){
        Current = ( ADC_Count + 47.07) / 93.42 ;      //rabete koli
        //Current = Current/10;
        //Current = ( ADC_Count - 504.852) / 240.536 ;  //test_ghaempanah
        }*/
        
        else if (adc>=21 && adc<=250){
          
        Current = ( adc + 47.818) / 93.309 ;     
        //Current = ( ADC_Count - 504.852) / 240.536 ;
        }
        
        else if (adc>251 && adc<=700){
          
          Current = ( adc - 54.888) / 61.022 ;
        //Current = ( ADC_Count - 81.119) / 52.776 ;     
        //Current = ( ADC_Count - 504.852) / 240.536 ;
        }
        
           HAL_TIM_Base_Stop_IT(&htim3);
           timer_mode=0;
  
        if(exit_mode==1 && menu_exit==1){
      HAL_IWDG_Refresh(&hiwdg);
           Lcd_Clear();
           Lcd_Put_Icon2_Invert(12,95,exit1_icon_Info);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();         
           HAL_Delay(3000);
           menu_exit=0;
       }
  
      if(exit_mode==1 && menu_return==1){
        HAL_IWDG_Refresh(&hiwdg);
           Lcd_Clear();
           Lcd_Put_Icon2_Invert(14,100,return_icon_Info);
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);          
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
           Lcd_Refresh();         
           HAL_Delay(3000);
           menu_return=0;
      }
  
       if(dis_mode==5){  //show loading   
         HAL_IWDG_Refresh(&hiwdg);
           Lcd_Clear();
           Lcd_Refresh();
           Lcd_Put_Icon2_Invert(16,17,loading_icon_Info);                           
       }
  
        if(dis_mode==1){ //show relay_off
          HAL_IWDG_Refresh(&hiwdg);
          
             /*     for ( j=0 ; j<80 ; j++) {
      
           b0  +=buffer[0];
           HAL_Delay(10);
        }
       
           b0 /= 80 ;
           HAL_Delay(100);  */
           
           Lcd_Refresh();  
           
           lcd_putsf_point(10,21,"           ",TAHOMA_8x10);
           lcd_putsf_point(10,22,"           ",TAHOMA_8x10);
           lcd_putsf_point(10,23,"           ",TAHOMA_8x10);
           lcd_putsf_point(10,27,"          ",TAHOMA_8x10);

           Lcd_Put_Icon2_Invert(23,4,relay_off_icon_Info);
             
           Lcd_Put_Icon2_Invert(42,37,current_A_icon_Info);
           sprintf(lcd, "%.02f " , Current );
           lcd_putsf_point(3,37,lcd,TAHOMA_8x10);
             
           Lcd_Put_Icon2_Invert(39,20,hc_icon_Info);
           sprintf(lcd, "%.01f " , parameter[0] );
           lcd_putsf_point(3,20,lcd,TAHOMA_8x10);             
                    
           sprintf(lcd, "%.01f " , parameter[1] );
           lcd_putsf_point(3,52,lcd,TAHOMA_8x10); 
           Lcd_Put_Icon2_Invert(28,51,lc_icon_Info); 
           
           Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
           Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);            
           Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
           Lcd_Put_Icon2_Invert(0,66,line_icon_Info);
             
           //  Lcd_Put_Icon2_Invert(58,31,pressure_A_icon_Info);
           //  sprintf(lcd, "%.02f " , b0 );
           //  lcd_putsf_point(3,33,lcd,TAHOMA_8x10);
             
             Lcd_Refresh();
        }
  
     if(dis_mode==2){  //show relay_on          
       HAL_IWDG_Refresh(&hiwdg);
             /*  for ( j=0 ; j<80 ; j++) {
      
           b0  +=buffer[0];
           HAL_Delay(10);
        }
       
           b0 /= 80 ;
           HAL_Delay(100);  */
       
          Lcd_Refresh();
          lcd_putsf_point(10,21,"           ",TAHOMA_8x10);
          lcd_putsf_point(10,22,"           ",TAHOMA_8x10);
          lcd_putsf_point(10,23,"           ",TAHOMA_8x10);
          lcd_putsf_point(10,27,"          ",TAHOMA_8x10);
          lcd_putsf_point(5,37,"            ",TAHOMA_8x10);
          lcd_putsf_point(5,4,"            ",TAHOMA_8x10);
          lcd_putsf_point(5,5,"            ",TAHOMA_8x10);
          lcd_putsf_point(5,6,"            ",TAHOMA_8x10);
          lcd_putsf_point(5,7,"            ",TAHOMA_8x10);
          lcd_putsf_point(5,8,"            ",TAHOMA_8x10);
          lcd_putsf_point(5,9,"            ",TAHOMA_8x10);
          
          Lcd_Put_Icon2_Invert(29,4,relay_on_icon_Info);
          
          Lcd_Put_Icon2_Invert(42,37,current_A_icon_Info);
          sprintf(lcd, "%.02f " , Current );
          lcd_putsf_point(3,37,lcd,TAHOMA_8x10);
                 
          Lcd_Put_Icon2_Invert(39,20,hc_icon_Info);
          sprintf(lcd, "%.01f " , parameter[0] );
          lcd_putsf_point(3,20,lcd,TAHOMA_8x10); 
             
          sprintf(lcd, "%.01f " , parameter[1] );
          lcd_putsf_point(3,52,lcd,TAHOMA_8x10); 
          Lcd_Put_Icon2_Invert(28,51,lc_icon_Info); 
          
          Lcd_Put_Icon2_Invert(0,0,liney_icon_Info);
          Lcd_Put_Icon2_Invert(94,0,liney_icon_Info);            
          Lcd_Put_Icon2_Invert(0,0,line_icon_Info);
          Lcd_Put_Icon2_Invert(0,66,line_icon_Info);          
          
          Lcd_Refresh();      
     }
     
     if (parameter[1] >= parameter[0]){  //show current value error
       HAL_IWDG_Refresh(&hiwdg);
       HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
        HAL_TIM_Base_Stop_IT(&htim17);
        error_mode=1;
        menu_mode=1;
        HAL_TIM_Base_Stop_IT(&htim14);
        HAL_TIM_Base_Stop_IT(&htim3);
        HAL_TIM_Base_Stop_IT(&htim16);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);
        Lcd_Clear();
        lcd_putsf_point(0,10,"          ",TAHOMA_8x10);
        lcd_putsf_point(0,21,"         ",TAHOMA_8x10);
        lcd_putsf_point(0,33,"          ",TAHOMA_8x10);
        lcd_putsf_point(0,45,"          ",TAHOMA_8x10);
        Lcd_Put_Icon2_Invert(15,2,error_icon_Info);
        Lcd_Put_Icon2_Invert(6,19,current_set_icon_Info);   
        Lcd_Refresh();
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
        lcd_putsf_point(10,0,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,1,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,2,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,3,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,4,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,5,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,6,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,7,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,8,"             ",TAHOMA_8x10);
        lcd_putsf_point(10,9,"             ",TAHOMA_8x10);
        Lcd_Put_Icon2_Invert(6,19,current_set_icon_Info);
        Lcd_Refresh(); 
        
        }
  
        if(retry_error_flag==1){  //show  retry error
          HAL_IWDG_Refresh(&hiwdg);
           HAL_TIM_Base_Stop_IT(&htim17);
           startup_reset=0; 
           error_mode=1;
           HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);
           startup_set_flag=0;
           menu_mode=1;
           HAL_TIM_Base_Stop_IT(&htim14);
           HAL_TIM_Base_Stop_IT(&htim3);
           HAL_TIM_Base_Stop_IT(&htim16);
           Lcd_Clear();
           HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_SET);
           Lcd_Put_Icon2_Invert(15,2,error_icon_Info);
           Lcd_Put_Icon2_Invert(18,25,illegal_current_icon_Info);
           Lcd_Refresh();
           HAL_Delay(300);   
           HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,GPIO_PIN_RESET);
           
           if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){ 
             
             Lcd_Clear();
             Lcd_Put_Icon2_Invert(12,28,reset_icon_Info);
             Lcd_Refresh();
             HAL_Delay(400);
             Lcd_Clear();
             HAL_Delay(400);
             //Lcd_Clear();
             Lcd_Put_Icon2_Invert(12,28,reset_icon_Info);
             Lcd_Refresh();
             HAL_Delay(400);
             Lcd_Clear();
             HAL_Delay(400);            
             Lcd_Put_Icon2_Invert(12,28,reset_icon_Info);
             Lcd_Refresh();
             HAL_Delay(400);
             Lcd_Clear();
             
             if (HAL_GPIO_ReadPin(SW3_GPIO_Port,SW3_Pin)==0){
           

           retry_number=0;
           error_mode=0;
           retry_cancel=0;
           retry_error_flag=0;
           menu_mode=0;
           relay_mode=1;
             }
           }
           
           }   
}


void save_para(uint16_t para , float val){
 //tv =  (val*10) + 32767 ; 
 tv=val*10;
 //tv = val + 32767;
 
//EE_WriteVariable(VirtAddVarTab[para], tv);
eeprom_write_int16(tv,VirtAddVarTab[para]);
retry_error_flag=0;
//EE_WriteVariable(para,tv);
//parameter[para] = val ;

return;
}
int read_para(uint16_t para){
 //EE_ReadVariable(VirtAddVarTab[para], &VirtdataVarTab[para]);
//EE_ReadVariable(para,&tv);
 tv = eeprom_read_int16(VirtAddVarTab[para]);
 //tv = VirtdataVarTab[para] ;
//return tv - 32767 ;
return tv;
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
