/* 
  File: cool_sonar_final
  Author: Yad Khoshnau
  Date: 2023-12-1
  Description: Program for operating arduino sonar
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
#define Trig 10
#define Echo 11
#define Buzzer 9

/* Initialize Objects */
Adafruit_SSD1306 display(-1);
Servo myservo;


void setup() {
  // initialize with the I2C address 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(9, OUTPUT); /*piezo setup*/
  Serial.begin(9600);
  myservo.attach(13);
  delay(1000);
  myservo.write(40);  //Display message on oled
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  display.println("booting up...");
  display.display();
  delay(2000);
}

// Global Variables
long distance, duration, Distance;

/* 
  Function: loop
  Description: Main loop function that executes a series of functions.
  Parameters: None
  Returns: None
*/
void loop() {
  centerLeftToTopLeft();
  leftToRight();
  topRightToCenterRight();
  reverseLoops();
  servo();
}

/* 
  Function: lowPitch
  Description: Plays a low-pitched sound when an object is not in range.
  Parameters: None
  Returns: None
*/
void lowPitch() {
  tone(9, 1000);  // Send 1KHz sound signal...
  delay(20);      // ...for 20 milliseconds
  noTone(9);      // Stop sound...
  delay(20);      // ...for 20 milliseconds
}

/* 
  Function: highPitch
  Description: Plays a high-pitched sound when an object is in range.
  Parameters: None
  Returns: None
*/
void highPitch() {
  tone(9, 1000);  
  delay(200);     
  noTone(9);      
  delay(200);     
}


/* 
  Function: centerLeftToTopLeft
  Description: Move the line from the center left to the top left.
  Parameters: None
  Returns: None
*/
void centerLeftToTopLeft() {
  int i;  // Loop variable for controlling the line movement
  for (i = 10; i >= 0; i -= 4) {
    int servomap = map(i, 0, 10, 60, 40);  
    Distance = Distance_value();           

    // Serial Print for debugging in the Processing IDE
    Serial.print(servomap);  
    Serial.print(",");       

    myservo.write(servomap);                // Set the servo motor position
    display.drawLine(64, 32, 0, i, WHITE);  // Draw a line on the display
    delay(100);
    lowPitch();  // Emit a low-pitched sound for objects out of range

    if (Distance >= 0 && Distance <= 40)  // If object is in range
    {
      // Map function for drawing a circle at the exact location of the object
      int xmap1 = map(Distance, 0, 40, 64, 0);
      int ymap1 = map(Distance, 0, 40, 32, i);

      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 0, i, WHITE);          // Draw a line on the display
      display.drawCircle(xmap1, ymap1, 3, WHITE);     // Draw object location circle
      display.fillCircle(10, 30, 1, WHITE);           // Object detection sign
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  // Object detection sign
      display.display();
      delay(100);
      highPitch();  // Emit an alarm sound for objects in range
    }
  }
}

/* 
  Function: leftToRight
  Description: Move the line from the left to the right.
  Parameters: None
  Returns: None
*/
void leftToRight() {
  int j;  // Loop variable for controlling the line movement
  for (j = 0; j <= 128; j += 4) {
    int servomap = map(j, 0, 128, 61, 120);
    Distance = Distance_value();

    // Serial Print for debugging in the Processing IDE
    Serial.print(servomap);  
    Serial.print(",");       

    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, j, 0, WHITE);  // Draw a line on the display
      display.display();
      delay(100);
      lowPitch();  // Emit a low-pitched sound for objects out of range
    } else if (Distance >= 0 && Distance <= 40) {
      // Map function for drawing a circle at the exact location of the object
      int xmap2 = map(Distance, 0, 40, 64, j);
      int ymap2 = map(Distance, 0, 40, 32, 0);

      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, j, 0, WHITE);          // Draw a line on the display
      display.drawCircle(xmap2, ymap2, 3, WHITE);     // Draw object location circle
      display.fillCircle(10, 30, 1, WHITE);           // Object detection sign
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  // Object detection sign
      display.display();
      delay(100);
      highPitch();  // Emit an alarm sound for objects in range
    }
  }
}

/* 
  Function: topRightToCenterRight
  Description: Move the line from the top right to the center right.
  Parameters: None
  Returns: None
*/
void topRightToCenterRight() {
  int k;  // Loop variable for controlling the line movement
  for (k = 0; k <= 10; k += 4) {
    int servomap = map(k, 0, 10, 121, 140);
    Distance = Distance_value();

    // Serial Print for debugging in the Processing IDE
    Serial.print(servomap); 
    Serial.print(",");       
    Serial.print(Distance);  
    Serial.print(".");      

    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, k, WHITE);  // Draw a line on the display
      display.display();
      delay(100);
      lowPitch();  // Emit a low-pitched sound for objects out of range
    } else if (Distance >= 0 && Distance <= 40) {
      // Map function for drawing a circle at the exact location of the object
      int xmap3 = map(Distance, 0, 40, 64, 128);
      int ymap3 = map(Distance, 0, 40, 32, k);

      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, k, WHITE);        // Draw a line on the display
      display.drawCircle(xmap3, ymap3, 3, WHITE);     // Draw object location circle
      display.fillCircle(10, 30, 1, WHITE);           // Object detection sign
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  // Object detection sign
      display.display();
      delay(100);
      highPitch();  // Emit an alarm sound for objects in range
    }
  }
}


/* 
  Function: reverseLoops
  Description: Reverses loops for moving the line from top left to center left.
  Parameters: None
  Returns: None
*/
void reverseLoops() {
  int l; // Loop variable for controlling the line movement
  for (l = 10; l >= 0; l -= 4) {
    int servomap = map(l, 10, 0, 140, 120);  // Map the servo values for positioning
    Distance = Distance_value();  // Get the distance sensor value by calling the function

    // Serial Print for debugging in the Processing IDE
    Serial.print(servomap);  
    Serial.print(",");       
    Serial.print(Distance);  
    Serial.print(".");   

    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, l, WHITE);  // Draw a line on the display
      display.display();
      delay(100);
      lowPitch(); // Emit a low-pitched sound for objects out of range
    } else if (Distance >= 0 && Distance <= 40) {
      // Map function for drawing a circle at the exact location of the object
      int xmap3 = map(Distance, 0, 40, 64, 128);
      int ymap3 = map(Distance, 0, 40, 32, l);

      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, l, WHITE);  // Draw a line on the display
      display.drawCircle(xmap3, ymap3, 3, WHITE);  // Draw object location circle
      display.fillCircle(10, 30, 1, WHITE);   // Object detection sign
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  // Object detection sign
      display.display();
      delay(100);
      highPitch(); // Emit an alarm sound for objects in range
    }
  }
}


/* 
  Function: servo
  Description: Executes servo movement loops to create a scanning motion.
  Parameters: None
  Returns: None
*/
void servo() {
  int m, n; // Loop variables for controlling the servo movement

  // Scanning motion from right to left
  for (m = 128; m >= 0; m -= 4) {
    int servomap = map(m, 128, 0, 121, 60);  // Map the servo values for positioning
    Distance = Distance_value();  // Get the distance sensor value by calling the function

    // Serial Print for debugging in the Processing IDE
    Serial.print(servomap);
    Serial.print(",");
    Serial.print(Distance); 
    Serial.print(".");

    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, m, 0, WHITE);  // Draw a line on the display
      display.display();
      delay(100);
      lowPitch(); // Emit a low-pitched sound for objects out of range
    } else if (Distance >= 0 && Distance <= 40) {
      // Map function for drawing a circle at the exact location of the object
      int xmap2 = map(Distance, 0, 40, 64, m);
      int ymap2 = map(Distance, 0, 40, 32, 0);

      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, m, 0, WHITE);  // Draw a line on the display
      display.drawCircle(xmap2, ymap2, 3, WHITE);  // Draw object location circle
      display.fillCircle(10, 30, 1, WHITE);   // Object detection sign
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  // Object detection sign
      display.display();
      delay(100);
      highPitch(); // Emit an alarm sound for objects in range
    }
  }

  // Scanning motion from left to right
  for (n = 0; n <= 10; n += 4) {
    int servomap = map(n, 0, 10, 60, 40);  // Map the servo values for positioning
    Distance = Distance_value();  // Get the distance sensor value by calling the function

    // Serial Print for debugging in the Processing IDE
    Serial.print(servomap); 
    Serial.print(",");       
    Serial.print(Distance); 
    Serial.print(".");      

    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 0, n, WHITE);  // Draw a line on the display
      display.display();
      delay(100);
      lowPitch(); // Emit a low-pitched sound for objects out of range
    } else if (Distance >= 0 && Distance <= 40) {
      // Map function for drawing a circle at the exact location of the object
      int xmap1 = map(Distance, 0, 40, 64, 0);
      int ymap1 = map(Distance, 0, 40, 32, n);

      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 0, n, WHITE);  // Draw a line on the display
      display.drawCircle(xmap1, ymap1, 3, WHITE);  // Draw object location circle
      display.fillCircle(10, 30, 1, WHITE);   // Object detection sign
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  // Object detection sign
      display.display();
      delay(100);
      highPitch(); // Emit an alarm sound for objects in range
    }
  }
}

/* 
  Function: Distance_value
  Description: Measure and return the distance using an ultrasonic sensor.
  Parameters: None
  Returns: Integer - Distance value in centimeters
*/
int Distance_value() {
  // Trigger the ultrasonic sensor to start the measurement
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(Echo, HIGH);

  // Calculate the distance in centimeters based on the speed of sound
  distance = (duration / 2) / 29.1;

  // Display the distance value on the OLED display
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(100, 25);
  display.println(distance);
  delay(15);
  display.display();

  // Return the distance value
  return distance;
}