#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define ZERO_CROSS_PIN 14
#define TRIAC_PIN D8

volatile bool zero_cross_flag = false;
volatile int dim_delay = 6000;

// ساخت Access Point
const char* ssid = "DimmerWiFi";
const char* password = "12345678";

// وب‌سرور روی پورت 80
ESP8266WebServer server(80);

// ISR برای تشخیص عبور از صفر
void ICACHE_RAM_ATTR zeroCrossISR() {
  zero_cross_flag = true;
}

void handleRoot() {
  String html = R"====(
    <html>
    <head>
      <title>MOTOR CONTROL</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
    </head>
    <body style="text-align:center;font-family:sans-serif;">
      <h2>PUMP CONTROL:</h2>
      <input type="range" min="0" max="100" value="50" id="slider" oninput="updateLabel(this.value)" onchange="sendValue(this.value)">
      <p>DUTY: <span id="val">50</span>%</p>
      <script>
        function updateLabel(val) {
          document.getElementById("val").innerText = val;
        }
        function sendValue(val) {
          fetch("/set?val=" + val);
        }
      </script>
    </body>
    </html>
  )====";
  server.send(200, "text/html", html);
}

void handleSet() {
  if (server.hasArg("val")) {
    int ZeroDelay = server.arg("val").toInt();
    if (ZeroDelay >= 0 && ZeroDelay <= 100) {
      dim_delay = map(100 - ZeroDelay, 0, 100, 200, 7000);
    }
  }
  server.send(200, "text/plain", "OK");
}
int ss;
int ZeroDelay = 0;
int Second;
void setup() {
  pinMode(ZERO_CROSS_PIN, INPUT);
  pinMode(TRIAC_PIN, OUTPUT);
  digitalWrite(TRIAC_PIN, LOW);
  attachInterrupt(digitalPinToInterrupt(ZERO_CROSS_PIN), zeroCrossISR, RISING);

  Serial.begin(9600);
  Serial.println("🚀 راه‌اندازی WiFi Access Point...");

  WiFi.softAP(ssid, password);
  IPAddress ip = WiFi.softAPIP();
  Serial.print("✅ WiFi آماده شد. IP: ");
  Serial.println(ip);

  server.on("/", handleRoot);
  server.on("/set", handleSet);
  server.begin();
  Serial.println("📡 وب‌سرور اجرا شد");
}

void loop() {
  server.handleClient();

  // if (Serial.available()) {
  //   Serial.println(Serial.available());
  //   int ZeroDelay = Serial.parseInt();
  //   if (ZeroDelay >= 0 && ZeroDelay <= 100) {
  //     dim_delay = map(100 - ZeroDelay, 0, 100, 200, 7000);
  //     Serial.print("🔆 روشنایی تنظیم شد: ");
  //     Serial.print(ZeroDelay);
  //     Serial.println("%");
  //   }
  // }

  // while (Serial.available() > 0) {
  //   String sim_data = Serial.readStringUntil('\n');
  //   sim_data.trim();
  //   Serial.print("Power:");
  //   Serial.println(sim_data);
  //   ZeroDelay = sim_data.toInt();
  // }

 // MillisTimer();

//  dim_delay = map(100 - ZeroDelay, 0, 100, 200, 7000);

  // if (zero_cross_flag && ZeroDelay < 100) {
  if (zero_cross_flag) {
    zero_cross_flag = false;
    delayMicroseconds(dim_delay);
    digitalWrite(TRIAC_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIAC_PIN, LOW);
  }
}


void MillisTimer() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() >= timer) {
    deciSeconds++;  
    timer += 100;
    if (deciSeconds > 100) {
      ++Second;
      deciSeconds= 0;
    }
  }
}
