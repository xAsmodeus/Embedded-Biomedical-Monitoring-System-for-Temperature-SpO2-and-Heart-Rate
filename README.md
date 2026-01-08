---

# Embedded Biomedical Monitoring System for Health Indicators

This program uses C++ and Arduino to implement a device that can measure Temperature , SpO2 and Heart-Rate.

                                                ** Runned and Tested in Wokwi.com **

--- 

## Overview

The idea was to create a biomedical system that measures 3 values: temperature , pulse and oxygen. When it detects unusual values that could put a person in danger, the system warns the user with special components.

If oxygen is <95 % or body temperature is above 38°C or below 36°C or pulse < 50 or > 130 , the LED lights up and the buzzer sounds , as the display warns the user with CAUTION while providing the measured values. If, on the other hand, the user has normal values, the buzzer does not sound , the LED does not light and the display provides the message YOU ARE OKAY.
## Sensors
    1) DS18B20
    2) Potentiometer #1
    3) Potentiometer #2

## Other Components

    1) LED
    2) Buzzer

---
