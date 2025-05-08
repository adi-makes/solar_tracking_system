# solar_tracking_system
An Arduino-based dual-axis solar tracking system that automatically adjusts solar panels to maximize sunlight capture using 5 LDRs and 2 MG996 servo motors.

# Project Sunflower 🌻  
**An Arduino-based Dual-Axis Solar Tracker**  

## Introduction  
Project Sunflower is a DIY solar tracking system designed to maximize solar panel efficiency by following the sun's position throughout the day.  

## Features  
- Dual-axis rotation for precise solar tracking  
- Lightweight, modular design using 3D-printed parts  
- Efficient light detection using 5 LDRs  
- Controlled by Arduino Uno  
- Uses 2 MG996R servo motors for movement  
- Low-cost power supply using a recycled mobile charger  

## Components  
- **Arduino Uno**: Control unit  
- **5 LDRs**: Light direction detection  
- **2 MG996R Servos**: Horizontal and vertical movement  
- **3D-Printed Parts**: Petal holders and base  
- **PVC Frame**: Durable and lightweight  
- **Power Supply**: Repurposed mobile charger  

## Wiring Diagram  
The wiring diagram can be found in the **Schematics** folder.  

## Installation  
1. Upload the Arduino code from the `Code` folder to your Arduino Uno.  
2. Assemble the mechanical components as shown in the prototype images.  
3. Connect the circuit as per the schematic.  
4. Power the system using the mobile charger.  

## Working Principle  
The 5 LDRs sense the sunlight intensity and calculate the brightest direction. The servos are adjusted to align the solar panel with the maximum sunlight.  

## Media  
Check out the **Media** folder for images and videos of the working prototype.  

## Future Improvements  
- Integrate solar panel efficiency monitoring  
- Implement weather data integration for dynamic tracking  
- Build a mobile app for real-time monitoring  

## License  
This project is licensed under the MIT License.  
