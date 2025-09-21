#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <MPU6050.h>
#include <math.h> // math functions

// Wi-Fi Credentials
const char* ssid = "vivo 1901";  // Replace with your Wi-Fi SSID
const char* password = "1234567890";  // Replace with your Wi-Fi Password

// Web Server on port 80
WebServer server(80);

// Pin definitions
const int pulsePin = 34;       // Pulse sensor signal pin
const int thermistorPin = 35;  // Thermistor analog pin

// Gyroscope Variables
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

// Thermistor Calibration
#define SERIES_RESISTOR 1000.0       // Adjusted resistor to 1kΩ
#define NOMINAL_RESISTANCE 10000.0   // 10kΩ at 25°C
#define NOMINAL_TEMPERATURE 25.0     // 25°C
#define B_COEFFICIENT 3950.0         // Beta coefficient

// Read temperature from thermistor
float readTemperature() {
  int rawValue = analogRead(thermistorPin);

  // Clamp ADC to avoid invalid readings
  if (rawValue < 1) rawValue = 1;
  if (rawValue > 4094) rawValue = 4094;

  // Convert ADC to voltage
  float Vout = rawValue * (3.3 / 4095.0);

  // Calculate thermistor resistance
  // Adjusted formula for low ADC readings
  float resistance = SERIES_RESISTOR * (3.3 / Vout - 1.0);

  // Beta equation / Steinhart-Hart
  float tempK = 1.0 / ( (1.0 / (NOMINAL_TEMPERATURE + 273.15)) + (1.0 / B_COEFFICIENT) * log(resistance / NOMINAL_RESISTANCE) );
  float tempC = tempK - 273.15;

  // Optional: clamp realistic human temperature
  if (tempC < 20) tempC = 20;
  if (tempC > 45) tempC = 45;

  return tempC;
}

// Handle web requests
void handleRoot() {
  int pulseValue = analogRead(pulsePin);

  // Gyro data
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  float gx_dps = gx / 131.0;
  float gy_dps = gy / 131.0;
  float gz_dps = gz / 131.0;

  float temperature = readTemperature();

  // JSON response
  String jsonData = "{";
  jsonData += "\"pulse\":" + String(pulseValue) + ",";
  jsonData += "\"temperature\":" + String(temperature) + ",";
  jsonData += "\"gyro\":{\"gx\":" + String(gx_dps) + ",\"gy\":" + String(gy_dps) + ",\"gz\":" + String(gz_dps) + "}";
  jsonData += "}";

  server.send(200, "application/json", jsonData);
}

void setup() {
  Serial.begin(115200);
  pinMode(pulsePin, INPUT);
  pinMode(thermistorPin, INPUT);

  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  } else {
    Serial.println("MPU6050 connected!");
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Start Web Server
  server.on("/data", handleRoot);
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  server.handleClient();
}
