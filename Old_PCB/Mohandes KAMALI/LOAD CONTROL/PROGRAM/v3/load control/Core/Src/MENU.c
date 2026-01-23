#define status_sw_up    (GPIOA->IDR & GPIO_PIN_9)==0
#define status_sw_down  (GPIOA->IDR & GPIO_PIN_0)==0
#define status_sw_ok    (GPIOF->IDR & GPIO_PIN_1)==0
#define status_sw_esc   (GPIOA->IDR & GPIO_PIN_10)==0
#define Relay_Switch    (GPIOF->IDR & GPIO_PIN_0)==0
