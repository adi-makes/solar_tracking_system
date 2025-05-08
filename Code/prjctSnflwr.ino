#include <Servo.h>

// Define Servo objects
Servo servoLR; // Left-Right servo
Servo servoUD; // Up-Down servo

// Define LDR pins
const int ldrL = A0;
const int ldrR = A1;
const int ldrM = A2;
const int ldrU = A3;
const int ldrD = A4;

// Variables to store LDR readings
int lValueL, lValueR, lValueM, lValueU, lValueD;
int diffL, diffR, diffU, diffD;
int threshold = 50;

// Variables to store current servo angles
int angleLR = 90; // Start from center position
int angleUD = 90;

void setup() {
  Serial.begin(9600);
  
  pinMode(ldrL, INPUT);
  pinMode(ldrR, INPUT);
  pinMode(ldrM, INPUT);
  pinMode(ldrU, INPUT);
  pinMode(ldrD, INPUT); 

  servoLR.attach(9);  // Servo for Left-Right control
  servoUD.attach(10);  // Servo for Up-Down control
  
  servoLR.write(angleLR);
  servoUD.write(angleUD);
}

void loop() {
  // Read LDR values
  lValueL = analogRead(ldrL);
  lValueR = analogRead(ldrR);
  lValueM = analogRead(ldrM);
  lValueU = analogRead(ldrU);
  lValueD = analogRead(ldrD);

  // Calculate differences
  diffL = lValueM - lValueL;
  diffR = lValueM - lValueR;
  diffU = lValueM - lValueU;
  diffD = lValueM - lValueD;

  // Print for debugging
  Serial.print("Left:"); Serial.print(lValueL);
  Serial.print(" | Middle:"); Serial.print(lValueM);
  Serial.print(" | Right:"); Serial.println(lValueR);
  
  Serial.print("DiffL="); Serial.print(diffL);
  Serial.print(" | DiffR="); Serial.println(diffR);

  Serial.print("Up:"); Serial.print(lValueU);
  Serial.print(" | Middle:"); Serial.print(lValueM);
  Serial.print(" | Down:"); Serial.println(lValueD);
  
  Serial.print("DiffU="); Serial.print(diffU);
  Serial.print(" | DiffD="); Serial.println(diffD);

  // Left-Right control
  if (abs(diffL) > threshold || abs(diffR) > threshold) {
    if (abs(diffL) > abs(diffR)) {
      if (diffL > 0 && angleLR > 0) { // Light stronger on Left side, rotate Left
        angleLR -= 1;
      }
      else if (diffL < 0 && angleLR < 180) { // Light weaker on Left side, rotate Right
        angleLR += 1;
      }
    } else {
      if (diffR > 0 && angleLR < 180) { // Light stronger on Right side, rotate Right
        angleLR += 1;
      }
      else if (diffR < 0 && angleLR > 0) { // Light weaker on Right side, rotate Left
        angleLR -= 1;
      }
    }
    angleLR = constrain(angleLR, 0, 180);
    servoLR.write(angleLR);
  }

  // Up-Down control
  if (abs(diffU) > threshold || abs(diffD) > threshold) {
    if (abs(diffU) > abs(diffD)) {
      if (diffU > 0 && angleUD > 0) { // Light stronger Up, tilt Up
        angleUD -= 1;
      }
      else if (diffU < 0 && angleUD < 180) { // Light weaker Up, tilt Down
        angleUD += 1;
      }
    } else {
      if (diffD > 0 && angleUD < 180) { // Light stronger Down, tilt Down
        angleUD += 1;
      }
      else if (diffD < 0 && angleUD > 0) { // Light weaker Down, tilt Up
        angleUD -= 1;
      }
    }
    angleUD = constrain(angleUD, 0, 180);
    servoUD.write(angleUD);
  }

  delay(20); // Small delay for smooth movement
}
