const int analogPin = A0;
const float VREF = 3.3;             // ولتاژ مرجع ADC
const float offset = 1.65;          // بایاس DC (تقسیم مقاومتی)
const float burdenResistor = 20.0;  // مقاومت بار
const float CT_ratio = 2000.0;      // نسبت تبدیل ترانس جریان
const int samples = 200;            // تعداد نمونه‌ها

void setup() {
  Serial.begin(9600);
  pinMode(D8, OUTPUT);
  digitalWrite(D8, HIGH);
  delay(1000);
  Serial.println("شروع اندازه‌گیری RMS جریان AC");
}

void loop() {
  // float sumOfSquares = 0;

  // for (int i = 0; i < samples; i++) {
  //   int raw = analogRead(analogPin);
  //   float voltage = (raw / 1024.0) * VREF;   // تبدیل ADC به ولتاژ
  //   float centered = voltage - offset;       // حذف بایاس
  //   sumOfSquares += centered * centered;
  //   delayMicroseconds(200);  // کنترل سرعت نمونه‌گیری
  // }

  // float meanSquare = sumOfSquares / samples;
  // float voltageRMS = sqrt(meanSquare);
  // float currentSecondary = voltageRMS / burdenResistor;
  // float currentPrimary = currentSecondary * CT_ratio;

  // Serial.print("🔌 جریان RMS: ");
  // Serial.print(currentPrimary, 2);
  // Serial.println(" A");

  // delay(250);

  float sumOfSquares = 0;
  for (int i = 0; i < samples; i++) {
    int raw = analogRead(analogPin);
    sumOfSquares += raw;
    delayMicroseconds(200);
  }
  float meanSquare = sumOfSquares / samples;
  float Current = meanSquare -10;
  Serial.print("ADC:");
  Serial.print(meanSquare, 2);
  Serial.print(" | Current:");
  Serial.println(Current, 2);
  delay(250);
}
