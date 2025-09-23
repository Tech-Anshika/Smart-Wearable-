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

**Workflow:**  
👉 **User logs data → App stores & processes → AI/IoT provide insights → User gets personalized health feedback**  

* * *

## 📌 Authors
- **Anshika Tyagi**  
  - Hardware & Software development  
  - [GitHub](https://github.com/Tech-Anshika) | [LinkedIn](https://www.linkedin.com/in/anshika-tyagi-413b99266/)  
