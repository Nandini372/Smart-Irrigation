# Smart Irrigation System

## Project Overview

This project is an Arduino-based Smart Irrigation System designed to automate watering using soil moisture sensing technology.

The system monitors:

* Soil Moisture
* Temperature
* Humidity

Based on soil conditions, the water pump is automatically controlled through a relay module.

## Technologies Used

* Arduino UNO
* Embedded C / Arduino IDE
* DHT11 Sensor
* Soil Moisture Sensor
* Relay Module
* LCD Display (I2C)
* Water Pump

## Features

* Automatic irrigation control
* Real-time temperature monitoring
* Real-time humidity monitoring
* Soil status detection (Wet/Dry)
* LCD display output
* Water conservation

## Working Principle

1. Soil moisture sensor checks soil condition.
2. DHT11 measures temperature and humidity.
3. Arduino processes sensor data.
4. If soil is dry, the relay activates the water pump.
5. If soil is wet, the pump is switched off.
6. Sensor readings are displayed on the LCD screen.

## Future Enhancements

* IoT monitoring using ESP8266
* Mobile application integration
* Cloud data storage
* Machine learning based irrigation scheduling

