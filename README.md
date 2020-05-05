# SonarRangeFinder
This is code used to program a MC9S12XEP100 to create a Sonar Range Finder. This range finder uses sound to find the range, in feet, between a sonic transmitter and an object at the push of a button. The distance is displayed on an LCD screen. 

### Hardware 

**NXP MC9S12XEP100 Dev Kit** - This dev kit includes the MC9S12XEP100 Micro-Controller, LCD screen, and buttons on a single board

**Sonar Transmitter/Receiver Module** - Connects to the Dev kit via RJ11 connection. Transmits and receives sound pulses.

<img src="images/sonar.jpg" width="500">

### Files Discription

**SonarRangeFinder/ECET309_Lab10&11/defs.c**
- file contains defines for different settings on the LCD screen 

**SonarRangeFinder/ECET309_Lab10&11/protos.h**
- function prototypes

**SonarRangeFinder/ECET309_Lab10&11/Sources/ECT.c**
- file contains the inititalization process for the Enhanced Capture Timer

**SonarRangeFinder/ECET309_Lab10&11/Sources/LCDfunctions.c**
- contains all the functions to create the LCD drive

**SonarRangeFinder/ECET309_Lab10&11/Sources/functions.c**
- This file contains functions that drive the sonar module to send/receive a pulse, use ECT to time echo, and display data on the LCD



