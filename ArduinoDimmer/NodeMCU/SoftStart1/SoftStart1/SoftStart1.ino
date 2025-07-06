#include <ESP8266WiFi.h>

#include <TM1637Display.h>
#define CLK 12  // پین CLK ماژول
#define DIO 13  // پین DIO ماژول
TM1637Display display(CLK, DIO);
#define ZERO_CROSS_PIN 14
#define TRIAC_PIN D8
const int analogPin = A0;
volatile bool zero_cross_flag = false;
volatile int dim_delay;
const int samples = 300;
// ISR برای تشخیص عبور از صفر
void ICACHE_RAM_ATTR zeroCrossISR() {
  zero_cross_flag = true;
}

int ss;
int ZeroDelay = 30;
int Second;

unsigned long previousMillis = 0;
const unsigned long interval = 100;
unsigned long counter = 0;
const uint8_t dash[4] = {
  SEG_G, SEG_G, SEG_G, SEG_G
};

void setup() {
    WiFi.disconnect(true);  // قطع اتصال و پاک کردن اطلاعات ذخیره‌شده
  WiFi.mode(WIFI_OFF);    // خاموش کردن وای‌فای
  pinMode(ZERO_CROSS_PIN, INPUT);
  pinMode(TRIAC_PIN, OUTPUT);
  digitalWrite(TRIAC_PIN, LOW);
  attachInterrupt(digitalPinToInterrupt(ZERO_CROSS_PIN), zeroCrossISR, RISING);
  display.setBrightness(0x0f);  // روشنایی روی حداکثر
   display.setSegments(dash);
  delay(500);
  
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  MillisTimer();

  dim_delay = map(100 - ZeroDelay, 0, 100, 200, 7000);

  if (zero_cross_flag && ZeroDelay < 100) {
    if (zero_cross_flag) {
      zero_cross_flag = false;
      delayMicroseconds(dim_delay);
      digitalWrite(TRIAC_PIN, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIAC_PIN, LOW);
    }
  }

  if (ZeroDelay >= 100) {
    digitalWrite(TRIAC_PIN, HIGH);
    float sumOfSquares = 0;
    for (int i = 0; i < samples; i++) {
      int raw = analogRead(analogPin);
      sumOfSquares += raw;
      delayMicroseconds(500);
    }
    float meanSquare = sumOfSquares / samples;
    float Current = meanSquare - 10;
    if(Current < .2)Current = 0;
    Serial.print("ADC:");
    Serial.print(meanSquare, 2);
    Serial.print(" | Current:");
    Serial.println(Current, 2);
    delay(250);
    int scaledValue = Current * 100;  // تبدیل به عدد صحیح: 256
    display.showNumberDecEx(scaledValue, 0b01000000, true);
  }
}


void MillisTimer() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Second++;
    if (Second > 10 && ZeroDelay < 100) {
      //display.showNumberDec(ZeroDelay, true);
      ++ZeroDelay;
    }
  }
}
