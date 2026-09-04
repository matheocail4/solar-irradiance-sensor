#include <Wire.h>            // Used to establish serial communication on the I2C bus
#include <SparkFun_TMP117.h> // Used to send and recieve specific information from our sensor

// The default address of the device is 0x48 = {GND}
TMP117 sensor; // Initialize sensor

// Constants for reading voltage
const int voltagePin = A0;          // Pin to read the voltage
const float referenceVoltage = 5.0; // Reference voltage of the Arduino (5V for most boards)

void setup()
{
  Wire.begin();
  Serial.begin(115200);   // Start serial communication at 115200 baud
  Wire.setClock(400000);  // Set clock speed to be the fastest for better communication (fast mode)

  Serial.println("TMP117");
  if (sensor.begin() == true) // Function to check if the sensor will correctly self-identify with the proper Device ID/Address
  {
    Serial.println("Begin");
  }
  else
  {
    Serial.println("Device failed to setup- Freezing code.");
    while (1); // Runs forever
  }
}

void loop()
{
  // Data Ready is a flag for the conversion modes - in continous conversion the dataReady flag should always be high
  if (sensor.dataReady() == true) // Function to make sure that there is data ready to be printed, only prints temperature values when data is ready
  {
    float tempC = sensor.readTempC();

    // Reading the voltage from the analog pin
    analogReadResolution(12); // Passe à une résolution de 12 bits
    int sensorValue = analogRead(voltagePin);                    // Read the input on analog pin A0
    float voltage = sensorValue * (referenceVoltage / 4095.0);   // Convert the analog reading (0 -4095.0) to voltage (0 - 5V)

    // Print
    Serial.println();
    Serial.print("Voltage in volt: ");
    Serial.println(voltage);
    Serial.print("Température en °C");
    Serial.println(tempC);

    delay(1000); // Delay added for easier readings
  }
}
