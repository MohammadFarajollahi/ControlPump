

//-----------------------------------------------------------------io define
#define BACK_LIGHT_Pin          GPIO_PIN_1
#define BACK_LIGHT_GPIO_Port    GPIOB
#define BACK_LIGHT_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

#define SET_BACK_LIGHT    BACK_LIGHT_GPIO_Port->ODR |= BACK_LIGHT_Pin
#define RESET_BACK_LIGHT    BACK_LIGHT_GPIO_Port->ODR &=~ BACK_LIGHT_Pin

//#define BUZZER_Pin          GPIO_PIN_0
//#define BUZZER_GPIO_Port    GPIOA
//#define BUZZER_Rcc          __HAL_RCC_GPIOA_CLK_ENABLE();

//#define SET_BUZZER    BUZZER_GPIO_Port->ODR |= BUZZER_Pin
//#define RESET_BUZZER    BUZZER_GPIO_Port->ODR &=~ BUZZER_Pin

//#define SW_OPEN_Pin          GPIO_PIN_4
//#define SW_OPEN_GPIO_Port    GPIOA
//#define SW_OPEN_Rcc          __HAL_RCC_GPIOA_CLK_ENABLE();

//#define SW_OPEN             (SW_OPEN_GPIO_Port ->IDR & SW_OPEN_Pin)

//#define SW_LOCK_Pin          GPIO_PIN_6
//#define SW_LOCK_GPIO_Port    GPIOA
//#define SW_LOCK_Rcc          __HAL_RCC_GPIOA_CLK_ENABLE();

//#define SW_LOCK             (SW_LOCK_GPIO_Port ->IDR & SW_LOCK_Pin)

//#define SW_HALF_Pin          GPIO_PIN_1
//#define SW_HALF_GPIO_Port    GPIOB
//#define SW_HALF_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

//#define SW_HALF             (SW_HALF_GPIO_Port ->IDR & SW_HALF_Pin)

//#define SW_ONLY_OUT_Pin          GPIO_PIN_7
//#define SW_ONLY_OUT_GPIO_Port    GPIOA
//#define SW_ONLY_OUT_Rcc          __HAL_RCC_GPIOA_CLK_ENABLE();

//#define SW_ONLY_OUT             (SW_ONLY_OUT_GPIO_Port ->IDR & SW_ONLY_OUT_Pin)

#define SW_ONLY_IN_Pin          GPIO_PIN_3
#define SW_ONLY_IN_GPIO_Port    GPIOB
#define SW_ONLY_IN_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

#define SW_ONLY_IN             (SW_ONLY_IN_GPIO_Port ->IDR & SW_ONLY_IN_Pin)

#define SW_UP_Pin          GPIO_PIN_4
#define SW_UP_GPIO_Port    GPIOB
#define SW_UP_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

#define SW_UP             (SW_UP_GPIO_Port ->IDR & SW_UP_Pin)

#define SW_DOWN_Pin          GPIO_PIN_6
#define SW_DOWN_GPIO_Port    GPIOB
#define SW_DOWN_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

#define SW_DOWN             (SW_DOWN_GPIO_Port ->IDR & SW_DOWN_Pin)

#define SW_OK_Pin          GPIO_PIN_7
#define SW_OK_GPIO_Port    GPIOB
#define SW_OK_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

#define SW_OK             (SW_OK_GPIO_Port ->IDR & SW_OK_Pin)

//#define SW_AUTO_Pin          GPIO_PIN_0
//#define SW_AUTO_GPIO_Port    GPIOB
//#define SW_AUTO_Rcc          __HAL_RCC_GPIOB_CLK_ENABLE();

//#define SW_AUTO             (SW_AUTO_GPIO_Port ->IDR & SW_AUTO_Pin)
//----------------------------------------------------------------------

				
#define speed_door_close_n                  0x0012
#define speed_door_open_n                   0x0010	
#define delay_open_door_n                   0x0016
#define lenght_half_n                       0x0014
#define error_code_n                        0x0104
#define flag_function_n                     0x44
#define direction_n                         0x0018
//#define status_function_n                  0x0020
//#define battery_error_n                    0x40


#define   n_status_function            0x0020
#define   En_inner_sensor              (0x01) 
#define   En_outter_sensor             (0x02) 
#define   lock_mode                    (0x04)
#define   summer_mode                  (0x08)
#define   reset_error                  (0x10)
#define   winter_mode                  (0x20)
#define   direction_main               (0x40)
#define   fan_en                       (0x80)


#define   En_safe                     (0x0100) 


#define n_status_door                  0x0146   //uint16
//============================================================================
#define   n_status_mission_complate          (Main_Register[n_status_door+1]|=0x01) 

#define   n_anti_thief                       (Main_Register[n_status_door+1]&0x02) 

#define   n_status_learn_1                       (Main_Register[n_status_door+1]&0x04) 

#define   n_status_learn_2                       (Main_Register[n_status_door+1]&0x08) 

#define   n_status_learn_3                       (Main_Register[n_status_door+1]&0x10) 



//============================================================================

