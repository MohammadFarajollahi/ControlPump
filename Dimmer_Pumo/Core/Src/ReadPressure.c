

// --- تنظیمات سخت‌افزاری ---
#define VREF            3.3f        // ولتاژ مرجع ADC (V)
#define ADC_MAX         4095.0f     // 12-bit ADC: 0..4095

// مقاومت‌ها (اهم)
#define R_SERIES_MAIN   4700.0f     // 4.7k (اونی که گفتی)
#define R_SERIES_PROT   10.0f       // 10Ω حفاظتی که اضافه کردی
#define R_PULLDOWN      1000.0f     // 1k پول‌دان

// مجموع سری
#define R_SERIES_TOTAL  (R_SERIES_MAIN + R_SERIES_PROT)

// ضریب تقسیم و ضریب تبدیل (محاسبه شده از بالا)
#define DIV_RATIO       (R_PULLDOWN / (R_SERIES_TOTAL + R_PULLDOWN))   // ~0.1751313
// VIN = ADC_raw * VIN_SCALE
#define VIN_SCALE       ((VREF / DIV_RATIO) / ADC_MAX)   // ~0.0046014652

// بیشینه ولتاژ سنسور (طبق توضیح شما)
#define SENSOR_VMAX     5.0f

// --- توابع سخت‌افزاری / جایگزین ---
/* تابع فرضی خواندن ADC (باید با HAL/LL/رجیستر پر شود)
   باید مقدار صحیح 0..4095 برگرداند. */
uint16_t ADC_Read(uint8_t channel)
{
    // نمونه: مقدار ثابت برای تست (باید حذف بشه)
    // return 2000;
    // جای پیاده‌سازی ADC واقعی
    return 0;
}

// خواندن Vin از یک کانال ADC
float Read_Vin(uint8_t channel)
{
    uint16_t adc_raw = ADC_Read(channel);    // 0..4095
    float vin = ((float)adc_raw) * VIN_SCALE;
    return vin;
}

void ReadPr(){
  
        float vin = Read_Vin(0); // فرض: کانال 0
        // اگر خواستی میلی‌ولت چاپ کنی:
        float vin_mv = vin * 1000.0f;
        Pressure = vin_mv;

//        // هشدار اگر بالاتر از حد منطقی سنسور باشه
//        if (vin > SENSOR_VMAX + 0.05f) // کمی تلورانس 50mV
//        {
//            printf("Warning: Vin = %.3f V (exceeds SENSOR_VMAX = %.2f V)\r\n", vin, SENSOR_VMAX);
//        }
//        else
//        {
//            printf("Vin = %.3f V (%.0f mV)\r\n", vin, vin_mv);
//        }

        // تاخیر ساده (یا از HAL_Delay استفاده کن)
        for (volatile uint32_t i = 0; i < 200000; ++i);
}