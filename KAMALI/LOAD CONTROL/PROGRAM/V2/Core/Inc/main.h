/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define INPUT_Pin GPIO_PIN_0
#define INPUT_GPIO_Port GPIOA
#define LCD_SCE_Pin GPIO_PIN_2
#define LCD_SCE_GPIO_Port GPIOA
#define POWER_VOLTAGE_Pin GPIO_PIN_3
#define POWER_VOLTAGE_GPIO_Port GPIOA
#define LCD_SCLK_Pin GPIO_PIN_4
#define LCD_SCLK_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_5
#define LCD_RST_GPIO_Port GPIOA
#define backlight_Pin GPIO_PIN_1
#define backlight_GPIO_Port GPIOB
#define LCD_DN_Pin GPIO_PIN_8
#define LCD_DN_GPIO_Port GPIOA
#define SCL_Pin GPIO_PIN_9
#define SCL_GPIO_Port GPIOA
#define SDA_Pin GPIO_PIN_10
#define SDA_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOA
#define SW3_Pin GPIO_PIN_3
#define SW3_GPIO_Port GPIOB
#define SW4_Pin GPIO_PIN_4
#define SW4_GPIO_Port GPIOB
#define Relay_Main_Pin GPIO_PIN_5
#define Relay_Main_GPIO_Port GPIOB
#define SW2_Pin GPIO_PIN_6
#define SW2_GPIO_Port GPIOB
#define SW1_Pin GPIO_PIN_7
#define SW1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
