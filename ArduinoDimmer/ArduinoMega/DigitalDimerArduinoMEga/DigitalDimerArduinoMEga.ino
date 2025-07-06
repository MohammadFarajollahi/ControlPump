/*
  AC Dimmer with Arduino Mega
  - Zero Cross input: pin 2 (INT4)
  - TRIAC control output: pin 5 (یا هر پایه دیجیتال دیگر)
*/

#define ZERO_CROSS_PIN 2  // INT4 روی Arduino Mega
#define TRIAC_PIN 5       // خروجی به گیت اپتوترایاک مثل MOC3021

volatile int dim_delay = 5000;  // delay after zero cross in microseconds
volatile bool zero_cross_flag = false;

int ss;
int brightness;

void setup() {
  pinMode(ZERO_CROSS_PIN, INPUT);
  pinMode(TRIAC_PIN, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(TRIAC_PIN, LOW);

  attachInterrupt(digitalPinToInterrupt(ZERO_CROSS_PIN), zeroCrossISR, FALLING);

  Serial.begin(9600);
  Serial.println("✅ دیمر روی Arduino Mega آماده است. مقدار روشنایی (0 تا 100) را وارد کن:");
}

void loop() {
  // دریافت مقدار از سریال مانیتور
  if (Serial.available()) {
     brightness = Serial.parseInt();
    if (brightness >= 0 && brightness <= 100) {
      dim_delay = map(100 - brightness, 0, 100, 200, 7000);
      Serial.print("🔆 روشنایی تنظیم شد: ");
      Serial.print(brightness);
      Serial.println("%");
    }
  }

  ++ss;
  if (ss >= 20000) {
    ss = 0;

    brightness += 1;
    if (brightness >= 100) brightness = 10;
    dim_delay = map(100 - brightness, 0, 100, 200, 7000);
  }
  // ++dim_delay;
  // if(dim_delay > 7000)dim_delay = 7000;

  // اجرای پالس تریگر تریاک بعد از وقفه
  if (zero_cross_flag) {
    zero_cross_flag = false;

    delayMicroseconds(dim_delay);
    digitalWrite(TRIAC_PIN, HIGH);
    delayMicroseconds(10);  // عرض پالس گیت تریاک
    digitalWrite(TRIAC_PIN, LOW);
  }
}

void zeroCrossISR() {
  zero_cross_flag = true;
  digitalWrite(3, !digitalRead(3));
}
