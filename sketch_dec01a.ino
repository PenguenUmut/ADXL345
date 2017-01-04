#include <SparkFun_ADXL345.h>         // SparkFun ADXL345 Library

/*********** COMMUNICATION SELECTION ***********/
/*    Comment Out The One You Are Not Using    */
ADXL345 adxl = ADXL345();           // USE FOR SPI COMMUNICATION, ADXL345(CS_PIN);


int ledPin4 = 4;
int ledPin7 = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //pinMode(ledPin4, OUTPUT); 
  //pinMode(ledPin7, OUTPUT);

  Serial.println("SparkFun ADXL345 Accelerometer Hook Up Guide Example");
Serial.println();

adxl.powerOn();                     // Power on the ADXL345

adxl.setRangeSetting(2);           // Give the range settings
                                    // Accepted values are 2g, 4g, 8g or 16g
                                    // Higher Values = Wider Measurement Range
                                    // Lower Values = Greater Sensitivity

adxl.setSpiBit(0);                  // Configure the device to be in 4 wire SPI mode when set to '0' or 3 wire SPI mode when set to 1
                                    // Default: Set to 1
                                    // SPI pins on the ATMega328: 11, 12 and 13 as reference in SPI Library 

adxl.setActivityXYZ(1, 0, 0);       // Set to activate movement detection in the axes "adxl.setActivityXYZ(X, Y, Z);" (1 == ON, 0 == OFF)
adxl.setActivityThreshold(75);      // 62.5mg per increment   // Set activity   // Inactivity thresholds (0-255)

adxl.setInactivityXYZ(1, 0, 0);     // Set to detect inactivity in all the axes "adxl.setInactivityXYZ(X, Y, Z);" (1 == ON, 0 == OFF)
adxl.setInactivityThreshold(75);    // 62.5mg per increment   // Set inactivity // Inactivity thresholds (0-255)
adxl.setTimeInactivity(10);         // How many seconds of no activity is inactive?

adxl.setTapDetectionOnXYZ(0, 0, 1); // Detect taps in the directions turned ON "adxl.setTapDetectionOnX(X, Y, Z);" (1 == ON, 0 == OFF)

// Set values for what is considered a TAP and what is a DOUBLE TAP (0-255)
adxl.setTapThreshold(50);           // 62.5 mg per increment
adxl.setTapDuration(15);            // 625 μs per increment
adxl.setDoubleTapLatency(80);       // 1.25 ms per increment
adxl.setDoubleTapWindow(200);       // 1.25 ms per increment

// Set values for what is considered FREE FALL (0-255)
adxl.setFreeFallThreshold(7);       // (5 - 9) recommended - 62.5mg per increment
adxl.setFreeFallDuration(30);       // (20 - 70) recommended - 5ms per increment

// Setting all interupts to take place on INT1 pin
//adxl.setImportantInterruptMapping(1, 1, 1, 1, 1);     // Sets "adxl.setEveryInterruptMapping(single tap, double tap, free fall, activity, inactivity);" 
                                                        // Accepts only 1 or 2 values for pins INT1 and INT2. This chooses the pin on the ADXL345 to use for Interrupts.
                                                        // This library may have a problem using INT2 pin. Default to INT1 pin.

// Turn on Interrupts for each mode (1 == ON, 0 == OFF)
adxl.InactivityINT(1);
adxl.ActivityINT(1);
adxl.FreeFallINT(1);
adxl.doubleTapINT(1);
adxl.singleTapINT(1);

//attachInterrupt(digitalPinToInterrupt(interruptPin), ADXL_ISR, RISING);   // Attach Interrupt
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(ledPin4, HIGH);
  //digitalWrite(ledPin7, LOW);
  //Serial.println("Sari");
//  delay(1000);
  //digitalWrite(ledPin4, LOW);
  //digitalWrite(ledPin7, HIGH);
  //Serial.println("Kirmizi");
  //delay(1000); 
  
  int x,y,z;  
  adxl.readAccel(&x, &y, &z);


  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(z);
  
  //ADXL_ISR();
  delay(500);
}
