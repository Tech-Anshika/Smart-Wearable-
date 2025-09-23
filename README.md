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


🌸 **PCOSence – Smart PCOS/PCOD Health Companion**
==================================================

<div align="center">
 <img src="./assets/logo.png" alt="PCOSence App" width="200" height="200"/>
 <h3>Track • Manage • Heal • Empower Women’s Health with PCOSence</h3>

[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)  
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg)](https://github.com/Tech-Anshika/PCOSence)

</div>

* * *

🌟 **Features**
---------------

🔐 *User Authentication & Profiles*
- Secure SignUp/SignIn system  
- Personalized dashboard  
- Profile management with health details  

📅 *Cycle & Health Tracking*
- Menstrual cycle monitoring with predictions  
- Symptoms logging (mood, cramps, flow, etc.)  
- Notifications for irregularities  

💊 *Medication & Diet Management*
- Smart medicine reminders  
- Personalized diet suggestions  
- Water intake tracker  

🧘 *Wellness & Lifestyle Support*
- Yoga & exercise recommendations with images  
- Stress management activities  
- Daily progress logging  

🎮 *Gamification & Awareness*
- Mini games for pain distraction  
- PCOS/PCOD awareness quizzes  
- Fun puzzles for education  

🤖 *AI-Powered Chatbot*
- Provides lifestyle and health advice  
- Multilingual query support  
- Instant answers to PCOS-related questions  

🌐 *IoT Sensor Integration*
- Connect with ESP32 + sensors  
- Track pulse, temperature, and steps  
- Real-time health monitoring  

* * *

📱 **Screenshots**
------------------

<div align="center">
 <img src="./assets/screenshots/home.png" alt="Home Screen" width="200"/>
 <img src="./assets/screenshots/tracking.png" alt="Tracking Screen" width="200"/>
 <img src="./assets/screenshots/chatbot.png" alt="AI Chatbot" width="200"/>
 <img src="./assets/screenshots/progress.png" alt="Progress Report" width="200"/>
</div>

* * *

🚀 **Quick Start**
------------------

### *Prerequisites*
- Flutter SDK (3.x or higher)  
- Dart SDK  
- Android Studio / VS Code  
- Firebase project setup  

### *Installation*

```bash
# Clone the repository
git clone https://github.com/Tech-Anshika/PCOSence.git
cd PCOSence

# Install dependencies
flutter pub get

# Run the app
flutter run


## 📌 Authors
- **Anshika Tyagi**  
  - Hardware & Software development  
  - [GitHub](https://github.com/Tech-Anshika) | [LinkedIn](https://www.linkedin.com/in/anshika-tyagi-413b99266/)  
