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
