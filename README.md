

The topic of the project and its objective was to create a circuit with 3 or more sensors in Arduino environment. This paper deals with the creation and implementation of a biomedical mechanism in the form of a circuit with the help of Arduino code. More specifically it is a device with exactly 3 sensors(& resistors configured): 
	**1) DS18B20**
	**2) Potentiometer #1**
	**3) Potentiometer #2**
      The **first** **sensor** is a **temperature sensor** while the **other** **two** are **potentiometers**.

The idea was to create a biomedical system that measures 3 values: temperature , pulse and oxygen. When it detects unusual values that could put a person in danger, the system warns the user with special components. These are shown below:
1) LED
2) Buzzer
If oxygen is <95 % or body temperature is above 38°C or below 36°C or pulse < 50 or > 130 , the LED lights up and the buzzer sounds , as the display warns the user with CAUTION while providing the measured values. If, on the other hand, the user has normal values, the buzzer does not sound , the LED does not light and the display provides the message YOU ARE OKAY.

Thus, with this mechanism , the health of the human users is ensured and safeguarded.
