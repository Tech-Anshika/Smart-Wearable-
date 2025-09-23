# Smart Wearable Project

This repository contains two main parts:

- **hardware/** → Arduino/ESP32 code ()
- **software/** → Flutter/React Native app code (coming soon)



---

## ⚙️ Hardware Overview

The **hardware** part is based on an **ESP32** microcontroller connected with multiple sensors:

### 🔹 Sensors Used
1. **Pulse Sensor (connected to GPIO34)**  
   - Measures **heart rate** by detecting changes in blood volume with each heartbeat.  
   - Outputs analog values which ESP32 processes to estimate pulse rate.  

2. **NTC Thermistor (connected to GPIO35)**  
   - Measures **body temperature**.  
   - Connected in a voltage divider circuit with a resistor.  
   - ESP32 reads analog voltage, converts it to resistance, and then applies the **Steinhart-Hart equation** to calculate the temperature in Celsius.  

3. **MPU6050 Accelerometer + Gyroscope (I²C interface)**  
   - Provides **motion tracking** and **orientation data**.  
   - Accelerometer measures linear acceleration.  
   - Gyroscope measures angular velocity (rotation in °/s).  
   - Useful for activity recognition (walking, movement, falls).  

---

## 🔄 How the Hardware Works

1. **Sensors collect data**  
   - Pulse sensor → heart rate signal  
   - Thermistor → body temperature  
   - MPU6050 → acceleration & rotation  

2. **ESP32 processes signals**  
   - Converts raw ADC readings into meaningful temperature values.  
   - Converts gyroscope raw values into °/s.  
   - Keeps pulse sensor readings ready for further processing.  

3. **Wi-Fi & Web Server**  
   - ESP32 connects to Wi-Fi.  
   - Hosts a simple **web server** on `/data`.  
   - Returns JSON data in this format:
     ```json
     {
       "pulse": 1920,
       "temperature": 36.8,
       "gyro": {
         "gx": -2.3,
         "gy": 1.8,
         "gz": 0.7
       }
     }
     ```

4. **Mobile App (software)**  
   - Future app (to be added in `software/` folder) will fetch this JSON from ESP32 and display it in a user-friendly interface.  

---

## 🚀 Future Scope
- Add data logging (SD card or cloud).  
- Integrate with the companion mobile app for real-time monitoring.  
- Add alert system for abnormal health readings.  

---


## 🛠️ Getting Started

### Requirements
- ESP32 board  
- Arduino IDE with ESP32 board support installed  
- Libraries: `WiFi.h`, `WebServer.h`, `Wire.h`, `MPU6050.h`, `math.h`

### Uploading Code
1. Open `hardware/pcodhardwarecode.ino` in Arduino IDE.  
2. Enter your Wi-Fi SSID & Password in the code.  
3. Upload to ESP32.  
4. Open Serial Monitor to see device logs.  
5. Visit `http://<ESP32-IP>/data` in browser to check JSON output.  

---

🌸 **PCOSence – Your Smart PCOS/PCOD Health Companion**
=======================================================

**PCOSence** is a **Flutter-based mobile application** designed to help women manage **PCOS/PCOD** through smart tracking, AI-driven insights, and IoT integration.  
The app serves as a **personalized health companion**, combining **medical support, lifestyle management, and awareness tools** in one platform.  

* * *

✨ **Features**
--------------

* 📅 **Menstrual Cycle Tracking** – Monitor and predict cycle phases, helping detect irregularities.  
* 💊 **Medication & Diet Management** – Personalized reminders for medicines, meals, and water intake.  
* 🧘 **Yoga & Exercise Guidance** – Suggests yoga poses and exercises with **images and benefits**.  
* 📊 **Progress Tracking** – Daily logs for **exercise, diet, medicines, yoga, and walking steps**.  
* 🎮 **Gamified Learning** – Interactive games for **PCOS awareness, education, and pain distraction**.  
* 🤖 **AI Chatbot** – Provides **instant health support**, answers queries, and lifestyle suggestions.  
* 🌐 **IoT Sensor Integration** – Connects with **ESP32 and sensors** to monitor **pulse, temperature, step count, and activity**.  

* * *

🖥️ **Software Description**
----------------------------

The **PCOSence app** is built using **Flutter** for cross-platform mobile support.  

* **Frontend:** Flutter (Dart)  
* **Backend & APIs:** Firebase + AI Chatbot APIs  
* **Database:** Firebase Firestore (cloud-based storage)  
* **AI/ML Models:** YOLO for image-based recognition, Gemini-powered chatbot  
* **IoT Support:** ESP32 + health sensors for real-time monitoring  


