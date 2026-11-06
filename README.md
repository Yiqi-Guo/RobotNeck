# 3-DOF Robot Neck

This project is a mechanical neck that connects a robot head, such as a robotic dog head, to the robot's body.

The neck assembly combines 3D-printed components with three 25 kg servo motors, linkages, and ball joints to provide three degrees of freedom (3DOF). The Arduino code in this repository coordinates the three servos so they can work together to move the neck.

## Project Overview

- **Purpose:** Connect a robot head to the robot's body with an articulated neck.
- **Mechanical assembly:** 3D-printed neck parts, three 25 kg servos, linkages, and ball joints.
- **Motion:** Three degrees of freedom (3DOF).
- **Controller:** Arduino Uno R3.
- **Servo signal pins:** D9, D10, and D11.
- **Code focus:** Coordinate the three servos to produce the neck's 3DOF movement.

## Repository Contents

This repository contains the Arduino code used to control and coordinate the three neck servos.

## Hardware

- Arduino Uno R3
- Three 25 kg servo motors
- 3D-printed neck components
- Linkages
- Ball joints
- Servo power supply and wiring

## Getting Started

1. Open the Arduino sketch in the Arduino IDE.
2. Connect the three servo signal wires to Arduino pins D9, D10, and D11.
3. Connect the servo power supply according to your hardware setup.
4. Upload the sketch to the Arduino Uno R3.
5. Test the neck movement carefully and adjust the code or mechanical setup as needed.

Servo motors should use an appropriate external power supply. Connect the Arduino GND and servo power-supply ground together. Check the sketch and your hardware setup before powering the servos.

## Project Status

The project is under development. The mechanical design and servo-control code may change as the neck assembly is tested and refined.
