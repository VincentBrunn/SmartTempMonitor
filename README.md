# SmartTempMonitor 🏠🌡️  
An **Arduino-powered temperature monitoring system** that measures ambient temperature and alerts users when it exceeds a predefined range. Features **real-time temperature readings, an LCD display, and an alarm system (buzzer + LED)**.  

![Project Preview](https://i.imgur.com/rcuTFhA.png)
(A full design report can be found above in the repository's files)

## 🔹 Features  
✅ **Real-time temperature monitoring** (TMP36 sensor)  
✅ **LCD display** shows temperature readings  
✅ **Buzzer and LED alarm** for out-of-range temperatures  
✅ **Portable design** in a custom ABS enclosure  
✅ **Standalone battery-powered system** (9V battery)  

---

## 📌 How It Works  
1️⃣ **Temperature Sensing:** The TMP36 sensor measures ambient temperature.  
2️⃣ **Processing Data:** The Arduino converts the sensor's voltage output into a readable temperature.  
3️⃣ **Displaying Readings:** The LCD screen updates with the current temperature.  
4️⃣ **Activating Alarm:** If the temperature goes outside the **70-75°F range**, the buzzer and red LED are triggered.  
5️⃣ **Returning to Normal:** The alarm deactivates when the temperature is back in range.  

---

## 🛠️ Hardware Components  
| Component | Function |
|-----------|----------|
| **Arduino Uno** | Main microcontroller processing data |
| **TMP36 Temperature Sensor** | Measures ambient temperature |
| **16x2 LCD (I2C)** | Displays real-time temperature |
| **Buzzer + Red LED** | Alarm system for temperature alerts |
| **Green LED** | Power indicator |
| **9V Battery + Snap** | Provides power to the system |
| **Protoboard & Wires** | Wiring and connections |
| **ABS Enclosure** | Custom housing for protection |

---

## 🔧 Wiring Diagram  
📷 *(https://i.imgur.com/khsl17K.png)*  

---

## 📜 Code Explanation  
The **Arduino code** does the following:
1. Reads the **TMP36 sensor** voltage and converts it into Fahrenheit.
2. Displays the temperature on the **LCD screen**.
3. Checks if the temperature is **within the acceptable range (70-75°F)**.
4. If outside the range, **activates the buzzer and red LED**.
5. If back in range, **deactivates the alarm**.

### **Main Code Snippet:**
```cpp
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1024.0);
  float temperatureF = (voltage - 0.5) * 100 * (9.0 / 5.0) + 32;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureF);
  lcd.print(" F");

  if (temperatureF < 70 || temperatureF > 75) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(redLED, LOW);
  }

  delay(1000);
}
```

---

## 🛠️ How to Build This Project  
### **1️⃣ Hardware Setup**
1. Connect the **TMP36 sensor** to **Arduino’s A0** (analog pin).  
2. Wire the **LCD screen** to the **I2C pins (SDA, SCL)**.  
3. Attach the **buzzer + LED** to digital pins.  
4. Power everything with a **9V battery**.  

### **2️⃣ Software Setup**
1. **Clone this repository**:
   ```bash
   git clone https://github.com/yourusername/Room-Temperature-Monitor.git
   cd Room-Temperature-Monitor
   ```
2. **Install Arduino IDE** (if not installed).
3. **Upload the code to Arduino**.
4. **Check Serial Monitor** for temperature readings.

---

## 📈 Future Improvements  
🔹 **Optimize Battery Life** – Implement sleep modes for efficiency.  
🔹 **Smaller Form Factor** – 3D-print a more compact enclosure.  
🔹 **Adjustable Temperature Range** – Add buttons to set custom thresholds.  
🔹 **Wireless Connectivity** – Send temperature data to a phone app via Bluetooth/WiFi.  

---

## 📄 License  
This project is licensed under the **MIT License** – feel free to use and modify it.  

---

## 🤝 Contributing  
Want to improve this project? Feel free to **fork the repo**, submit **pull requests**, or open **issues**!  

🚀 **Made with Arduino and a passion for hardware development!**  
```
