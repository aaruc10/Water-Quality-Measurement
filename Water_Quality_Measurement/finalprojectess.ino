#include <OneWire.h>
#include <LiquidCrystal_I2C.h>

// Data wire is connected to Arduino pin D4
#define ONE_WIRE_BUS 4

// Pin for TDS sensor
#define TDS_SENSOR_PIN A0

// Pin for turbidity sensor
#define TURBIDITY_SENSOR_PIN A1

// Set the LCD address
#define I2C_ADDR    0x3F  // Address for 16x2 LCD, change if necessary

// Initialize the LiquidCrystal_I2C library with the LCD address
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);  // 16x2 LCD

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

void setup() {
  // Start serial communication for the serial monitor
  Serial.begin(9600);
  
  // Initialize the LCD
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
  
  // Display a welcome message
  lcd.setCursor(0, 0);
  lcd.print("TDS & Turbidity");
  lcd.setCursor(0, 1);
  lcd.print("Sensor Reading");
  delay(2000);  // Display message for 2 seconds
}

void loop() {
  // Read TDS sensor
  int tdsValue = analogRead(TDS_SENSOR_PIN);
  
  // Read turbidity sensor
  int turbidityValue = analogRead(TURBIDITY_SENSOR_PIN);
  
  // Display readings on serial monitor
  Serial.print("TDS Value: ");
  Serial.print(tdsValue);
  Serial.println(" ppm ");
 
  Serial.print("Turbidity Value: ");
  Serial.print(turbidityValue);       
  Serial.println(" NTU ");

  // Display readings on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TDS: ");
  lcd.print(tdsValue);
  lcd.print(" ppm");

  lcd.setCursor(0, 1);
  lcd.print("Turbidity: ");
  lcd.print(turbidityValue);
  lcd.print(" NTU");

  // Wait 1 second before reading again
  delay(3000);
}
