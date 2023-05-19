#define soilSensor A0 // select the input pin for the soil moisture sensor
#include <DHT.h>
int DHT11_PIN = 7;  // Define the LED's pin
int LED_PIN = 1;   //Define the LED's object
int pumpPin = 13; // select the output pin for the water pump
int Value = 0; // variable to store the value coming from the soil moisture sensor
DHT dht(DHT11_PIN, DHT11);//create a DHT11 object
void setup() { 
  pinMode(LED_PIN, OUTPUT);   // Initialize the LED as an output
  dht.begin();     // Initialize the DHT11 sensor
  pinMode(pumpPin, OUTPUT); // declare the pumpPin as an OUTPUT
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

void loop() {
  Value = analogRead(soilSensor); // read the value from the soil moisture sensor
  Serial.print("Soil Moisture Sensor Value: ");
  Serial.println(Value);
  if (Value < 500) { // if soil moisture is less than 500
    digitalWrite(pumpPin, HIGH); // turn on water pump
    Serial.println("Water Pump ON");
    delay(5000); // wait for 5 seconds
  }
    else{
    digitalWrite(pumpPin, LOW); // turn off water pump
    Serial.println("Water Pump OFF");
    delay(5000); // wait for 5 seconds
  }

  float temperature = dht.readTemperature();   // Read the temperature and humidity from the DHT11 sensor
  float humidity = dht.readHumidity();
  // Print the temperature and humidity to the serial port
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C   Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  // If the temperature is above 25°C, turn on the LED
  if (temperature > 25) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  // Wait for 1 second before looping again

}