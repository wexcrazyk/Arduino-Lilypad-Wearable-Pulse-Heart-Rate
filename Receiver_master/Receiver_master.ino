//new code for receiver

#define greenLedPin 8
int dataFromSlave = "";
int bpmnumber = 0;
String number = "";
void setup() {
  pinMode(greenLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  //pinMode(masterSwitchPin, INPUT);
  //digitalWrite(masterSwitchPin,LOW);
  Serial.begin(9600); // Default baud rate of the Bluetooth module
}
void loop() {
  while (Serial.available() > 0) { // Checks whether data is comming from the serial port
    dataFromSlave = Serial.read(); // Reads the data from the serial port and store it in dataFromSlave variable
    // Serial.print(dataFromSlave);
    if (isDigit(dataFromSlave)) {
      number += (char)dataFromSlave;
      //number = dataFromSlave.substring(dataFromSlave.indexOf(':') + 1, 10);
      //Serial.println(number);
    }
    if (dataFromSlave == '\n') {
      bpmnumber = number.toInt();
      Serial.print(number.toInt());
      // Controlling the Buzzer
      if (bpmnumber >= 44) {
        digitalWrite(greenLedPin, LOW); // led ON
        delay (1000);
        digitalWrite(greenLedPin, HIGH); // led OFF
        Serial.println("led is on");
        
      }
      else {
        digitalWrite(greenLedPin, HIGH); // led OFF
        Serial.println("led is off");
      }
      // Reading the masterSwitchValue
      delay(1000);
      dataFromSlave = "";
      number = "";
    }
  }
}
