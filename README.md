Arduino Sonar

**Overview**

Welcome to the Cool Sonar Project! This repository hosts an Arduino-based sonar system that combines an ultrasonic sensor, servo motor, and OLED display to create an interactive distance-sensing experience. The project provides real-time feedback on object proximity through visual and auditory cues.

**Features**

- **Scanning Motion**: The system employs a servo motor to create a sweeping motion, enhancing the coverage area.
- **Visual Feedback**: An OLED display visualizes the environment with a moving line and object location circles.
- **Auditory Alerts**: A piezo buzzer emits different pitches to indicate the presence of objects within a certain range.

## Author

- **Yad Khoshnau**
- **Date:** 2023-11-30

## Getting Started

1. **Hardware Setup:**
   - Connect the ultrasonic sensor to pins 10 (Trig) and 11 (Echo).
   - Attach the piezo buzzer to pin 9.
   - Connect the servo motor to pin 13.
   - Set up the OLED display using I2C.

2. **Dependencies:**
   - [Adafruit_GFX](https://github.com/adafruit/Adafruit-GFX-Library)
   - [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
   - [Servo](https://www.arduino.cc/en/Reference/Servo)

3. **Upload:**
   - Upload the "cool_sonar_final" sketch to your Arduino board.

4. **Power On:**
   - Power on the system and observe the interactive sonar experience.

## Usage

1. The system will display a "booting up" message on the OLED screen during initialization.
2. Once booted, the scanning motion will start, accompanied by visual and auditory cues based on object proximity.

## Functions

- Explore various functions like `lowPitch`, `highPitch`, and motion functions to understand the system's behavior.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to contribute and enhance the project!

## Acknowledgments

Special thanks to the open-source community and libraries that made this project possible.

---

**Note:** Customize this README further based on additional features, acknowledgments, or any specific instructions for contributors.
