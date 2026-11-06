#include <Servo.h>

Servo neckServo9;   // Top-right servo
Servo neckServo10;  // Top-left servoa
Servo neckServo11;  // Bottom servo

const int rightNeutral = 1390;   // Calibrated neutral position for the right servo
const int leftNeutral = 1440;    // Calibrated neutral position for the left servo
const int bottomNeutral = 1550;  // Calibrated neutral position for the bottom servo

const int stepUs = 35;           // Offset added per keypress
const int maxTiltOffsetUs = 100;  // Maximum pitch or roll command offset
const int maxYawOffsetUs = 100;   // Maximum yaw command offset
const int maxUpperOffsetUs = 100; // Maximum offset for each upper servo

int pitchOffsetUs = 0;
int rollOffsetUs = 0;
int yawOffsetUs = 0;

void setup() {
  neckServo9.attach(9, 500, 2500);
  neckServo10.attach(10, 500, 2500);
  neckServo11.attach(11, 500, 2500);

  Serial.begin(9600);

  // Move all servos to their calibrated neutral positions
  updateServos();

  Serial.println("Pitch: A/D, Roll: W/S, Yaw: J/L, Neutral: 0");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Control pitch: move both upper servos in the same direction
    if (command == 'a') pitchOffsetUs += stepUs;
    if (command == 'd') pitchOffsetUs -= stepUs;

    // Control roll: move the upper servos in opposite directions
    if (command == 'w') rollOffsetUs += stepUs;
    if (command == 's') rollOffsetUs -= stepUs;

    // Control yaw: move the bottom servow
    
    if (command == 'l') yawOffsetUs += stepUs;
    if (command == 'j') yawOffsetUs -= stepUs;

    // Return all three directions to their neutral positions
    if (command == '0') {
      pitchOffsetUs = 0;
      rollOffsetUs = 0;
      yawOffsetUs = 0;
    }

    pitchOffsetUs = constrain(pitchOffsetUs, -maxTiltOffsetUs, maxTiltOffsetUs);
    rollOffsetUs = constrain(rollOffsetUs, -maxTiltOffsetUs, maxTiltOffsetUs);
    yawOffsetUs = constrain(yawOffsetUs, -maxYawOffsetUs, maxYawOffsetUs);

    updateServos();
  }
}

void updateServos() {
  // Limit each upper servo after combining pitch and roll.
  const int rightOffsetUs = constrain(
      pitchOffsetUs + rollOffsetUs, -maxUpperOffsetUs, maxUpperOffsetUs);
  const int leftOffsetUs = constrain(
      pitchOffsetUs - rollOffsetUs, -maxUpperOffsetUs, maxUpperOffsetUs);

  neckServo9.writeMicroseconds(rightNeutral + rightOffsetUs);
  neckServo10.writeMicroseconds(leftNeutral + leftOffsetUs);

  // Apply yaw independently to the bottom servo.
  neckServo11.writeMicroseconds(bottomNeutral + yawOffsetUs);
}