int map(int x, int in_min, int in_max, int out_min, int out_max) {
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


typedef struct {
    int32_t time;
    int32_t volt;
} point_t;

static const point_t lut[] = {
    {300,  220},
    {1100, 200},
    {1500, 150},
    {1800, 110},
    {2000, 77},
    {2400, 20}
};

#define LUT_SIZE (sizeof(lut)/sizeof(lut[0]))

int32_t voltage_to_time(int32_t V) {
    // اگر خارج از محدوده باشه، لبه‌ها رو برگردون
    if (V >= lut[0].volt) return lut[0].time;
    if (V <= lut[LUT_SIZE-1].volt) return lut[LUT_SIZE-1].time;

    // جستجوی بازه‌ی مناسب
    for (int i = 0; i < LUT_SIZE-1; i++) {
        if (V <= lut[i].volt && V >= lut[i+1].volt) {
            // اینترپولیشن خطی بین دو نقطه
            int32_t x1 = lut[i].volt;
            int32_t y1 = lut[i].time;
            int32_t x2 = lut[i+1].volt;
            int32_t y2 = lut[i+1].time;

            // فرمول: t = y1 + (V - x1)*(y2 - y1)/(x2 - x1)
            int32_t t = y1 + (V - x1) * (y2 - y1) / (x2 - x1);
            return t;
        }
    }
    return -1; // حالت غیرممکن
}

void OutPut(int VoltageInput){
 // TimeSet = map(VoltageInput, 10, 230, 2400, 300);
 int32_t t1 = voltage_to_time(VoltageInput); // ~300
 TimeSet = t1;

  if (zero_cross_flag == 1) {   
    zero_cross_flag = 0;
    delay_us_soft(TimeSet);
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_SET);
    delay_us_soft(10);
    HAL_GPIO_WritePin(triak_GPIO_Port, triak_Pin, GPIO_PIN_RESET);
  }
  
}
