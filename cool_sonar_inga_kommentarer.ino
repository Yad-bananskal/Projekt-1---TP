#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
#define Trig 10
#define Echo 11
#define Buzzer 9  //piezo bla bla bla

Adafruit_SSD1306 display(-1);
Servo myservo;

void setup() {
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(9, OUTPUT); /*piezo setuo*/
  Serial.begin(9600);
  myservo.attach(13);
  delay(1000);
  myservo.write(40);  //Display message on oled
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  display.println("cool sonar");
  display.display();
  delay(2000);
}

long distance, duration, Distance;

void loop() {
  centerLeftToTopLeft();
  leftToRight();
  topRightToCenterRight();
  reverseLoops();
  servo();
}

void lowPitch() {
  tone(9, 1000);  // Send 1KHz sound signal...
  delay(20);      // ...for 1 sec
  noTone(9);      // Stop sound...
  delay(20);
}

void highPitch() {
  tone(9, 1000);
  delay(200);
  noTone(9);
  delay(200);
}
/*Hej Hej
*/
void centerLeftToTopLeft() {
  int i, j, k, l, m, n;
  for (i = 10; i >= 0; i -= 4)  //loop for moving the line from centre left to top left
  {
    int servomap = map(i, 0, 10, 60, 40);  //map the servo values
    Distance = Distance_value();           //get the distance sensor value by calling the function
                                           // Serial Print for processing IDE
    Serial.print(servomap);                // Sends the current degree into the Serial Port Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing Serial.print(Distance); // Sends the distance value into the Serial Port Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing if (Distance > 40 )   //if object is out of range (no circle will be displayed on the line
    display.clearDisplay();
    myservo.write(servomap);
    display.drawLine(64, 32, 0, i, WHITE);  //draw a line   display.display();
    delay(100);
    lowPitch(); 
    if (Distance >= 0 && Distance <= 40)  //if object is in range
    {
      int xmap1 = map(Distance, 0, 40, 64, 0);  //map funtion for draw circle at exact location of the object
      int ymap1 = map(Distance, 0, 40, 32, i);
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 0, i, WHITE);  //draw line   display.drawCircle(xmap1, ymap1, 3, WHITE);  //draw object location circle
      display.fillCircle(10, 30, 1, WHITE);   //object detection sign   display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  //object detection sign
      display.display();
      delay(100);
      highPitch();
    }
  }
}

void leftToRight() {
  int i, j, k, l, m, n;
  for (j = 0; j <= 128; j += 4)  //moving from left to right
  {
    int servomap = map(j, 0, 128, 61, 120);
    Distance = Distance_value();
    //Serial Print for Processing IDE
    Serial.print(servomap);  // Sends the current degree into the Serial Port Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing Serial.print(Distance); // Sends the distance value into the Serial Port Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, j, 0, WHITE);
      display.display();
      delay(100);
      lowPitch();
    } else if (Distance >= 0 && Distance <= 40) {
      int xmap2 = map(Distance, 0, 40, 64, j);
      int ymap2 = map(Distance, 0, 40, 32, 0);
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, j, 0, WHITE);
      display.drawCircle(xmap2, ymap2, 3, WHITE);
      display.fillCircle(10, 30, 1, WHITE);
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);
      display.display();
      delay(100);
      highPitch();
    }
  }
}

void topRightToCenterRight() {
  int i, j, k, l, m, n;
  for (k = 0; k <= 10; k += 4)  //moving from top right to centre right
  {
    int servomap = map(k, 0, 10, 121, 140);
    Distance = Distance_value();
    //Serial Print for Processing IDE
    Serial.print(servomap);  // Sends the current degree into the Serial Port Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing Serial.print(Distance); // Sends the distance value into the Serial Port Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, k, WHITE);
      display.display();
      delay(100);
      lowPitch();
    } else if (Distance >= 0 && Distance <= 40) {
      int xmap3 = map(Distance, 0, 40, 64, 128);
      int ymap3 = map(Distance, 0, 40, 32, k);
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, k, WHITE);
      display.drawCircle(xmap3, ymap3, 3, WHITE);
      display.fillCircle(10, 30, 1, WHITE);
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);
      display.display();
      delay(100);
      highPitch();
    }
  }
}

void reverseLoops() {
  int i, j, k, l, m, n;
  for (l = 10; l >= 0; l -= 4)  //reserve loops
  {
    int servomap = map(l, 10, 0, 140, 120);
    Distance = Distance_value();
    //Serial Print for Processing IDE
    Serial.print(servomap);  // Sends the current degree into the Serial Port Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing Serial.print(Distance); // Sends the distance value into the Serial Port Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, l, WHITE);
      display.display();
      delay(100);
      lowPitch();
    } else if (Distance >= 0 && Distance <= 40) {
      int xmap3 = map(Distance, 0, 40, 64, 128);
      int ymap3 = map(Distance, 0, 40, 32, l);
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 128, l, WHITE);
      display.drawCircle(xmap3, ymap3, 3, WHITE);
      display.fillCircle(10, 30, 1, WHITE);
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);
      display.display();
      delay(100);
      highPitch();
    }
  }
}

void servo() {
  int i, j, k, l, m, n;
  for (m = 128; m >= 0; m -= 4) {
    int servomap = map(m, 128, 0, 121, 60);
    Distance = Distance_value();
    //Serial Print for Processing IDE
    Serial.print(servomap);  // Sends the current degree into the Serial Port Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing Serial.print(Distance); // Sends the distance value into the Serial Port Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, m, 0, WHITE);
      display.display();
      delay(100);
      lowPitch();
    } else if (Distance >= 0 && Distance <= 40) {
      int xmap2 = map(Distance, 0, 40, 64, m);
      int ymap2 = map(Distance, 0, 40, 32, 0);
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, m, 0, WHITE);
      display.drawCircle(xmap2, ymap2, 3, WHITE);
      display.fillCircle(10, 30, 1, WHITE);
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);
      display.display();
      delay(100);
      highPitch();
    }
  }

  for (n = 0; n <= 10; n += 4) {
    int servomap = map(n, 0, 10, 60, 40);
    Distance = Distance_value();
    //Serial Print for Processing IDE
    Serial.print(servomap);  // Sends the current degree into the Serial Port Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing Serial.print(Distance); // Sends the distance value into the Serial Port Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    if (Distance > 40) {
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 0, n, WHITE);
      display.display();
      delay(100);
      lowPitch();
    } else if (Distance >= 0 && Distance <= 40) {
      int xmap1 = map(Distance, 0, 40, 64, 0);
      int ymap1 = map(Distance, 0, 40, 32, n);
      display.clearDisplay();
      myservo.write(servomap);
      display.drawLine(64, 32, 0, n, WHITE);
      display.drawCircle(xmap1, ymap1, 3, WHITE);
      display.fillCircle(10, 30, 1, WHITE);
      display.fillRoundRect(10, 20, 2, 8, 2, WHITE);
      display.display();
      delay(100);
      highPitch();
    }
  }
}


int Distance_value()  //funtion to get the distance valueAC
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = (duration / 2) / 29.1;
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(100, 25);
  display.println(distance);  //display distance value on oled display
  delay(15);
  display.display();
  return distance;  //return the distance value
}
