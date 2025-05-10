#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 6

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

DeviceAddress sensor;

int buzzer = 11;
int temperature_sensor = 6;
int heart_rate = A0;
int spo2 = A2;
int led_pin = 12;

int temperature_signal;
int heartrate_signal;
int spo2_signal;

int heartrate_value;
int spo2_value;
float voltage;
float temperature;

void setup() 
{
  Serial.begin(9600);
  sensors.begin();
  Serial.print(sensors.getDeviceCount(), DEC);
  sensors.setResolution(sensor, 9);

  if(sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");

  if(!sensors.getAddress(sensor, 0)) Serial.println("error");

  pinMode(temperature_sensor, INPUT);
  pinMode(heart_rate, INPUT);
  pinMode(spo2, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_pin, OUTPUT); 
}

void loop() 
{
  sensors.requestTemperatures();
  temperature = sensors.getTempC(sensor);
  Serial.println(temperature);
  delay(100);

  heartrate_signal = analogRead(A0);
  byte heartrate_value = map(heartrate_signal , 0, 1023, 50, 140);
  Serial.println(heartrate_value);

  spo2_signal = analogRead(A2);
  byte spo2_value = map(spo2_signal , 0, 1023, 80, 100);
  Serial.println(spo2_value);

  if(temperature < 36.0 || temperature > 38.0 || heartrate_value < 50 || heartrate_value > 130 || spo2_value < 95)

  {
    Serial.println("CAUTION");
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 1000); 
    digitalWrite(led_pin, HIGH);
  }
  else
  {
    Serial.println("YOU ARE OKAY");
    digitalWrite(buzzer, LOW);
    noTone(buzzer);
    digitalWrite(led_pin, LOW);
  }
}

 //temperature_signal = digitalRead(temperature_sensor);
  //voltage = temperature_signal * (5000 / 1024.0); 
  //temperature = voltage / 10; 
  //Serial.print (temperature);
  //Serial.print(" \xC2\xB0");
  //Serial.print("C");

  //temperature_signal = analogRead(temperature_sensor);
  //temperature = map(temperature_signal, 0, 1023, 300, 420) / 10.0;
  //Serial.println(temperature);

  //potentiometer_signal = analogRead(A0);
  //potentiometer_value = map(potentiometer_signal, 0, 1023, 50, 130); 
  //Serial.println(potentiometer_value);

  //potentiometer_signal2 = analogRead(A2);
 //potentiometer_value2 = map(potentiometer_signal2, 0, 1023, 80, 100); 
  //Serial.println(potentiometer_value2);

   

  //temperature_signal = digitalRead(temperature_sensor);
  //temperature = temperature_sensor.getTempCByIndex(0);

  //if(temperature > 38.0 && spo2 < 95 && (heart_rate < 60 || heart_rate > 100))
  //{
   // Serial.print("provlhma");
    //digitalWrite(buzzer, HIGH);
    //digitalWrite(led_pin, HIGH);
  //}
  //else
  //{
    //Serial.print("fysiologiko");
    //digitalWrite(buzzer, LOW);
    //digitalWrite(led_pin, LOW);
 //}
  //delay(500);