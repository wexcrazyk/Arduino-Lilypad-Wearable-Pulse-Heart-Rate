//new code for receiver

#define reLay 8
int dataFromSlave = "";
int bpmnumber = 0;
String number = "";
void setup() {
  pinMode(reLay, OUTPUT);
  digitalWrite(reLay, LOW);
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
      // Controlling the push button of diffuser to turn ON
      if (bpmnumber >= 100) {
        digitalWrite(reLay, LOW); // relay ON
        delay (180);
        digitalWrite(reLay, HIGH); // relay OFF
        delay (500);
        digitalWrite(reLay, LOW); // relay ON
        delay (180);
        digitalWrite(reLay, HIGH); // relay OFF
        Serial.println("Relay is ON");
        
      }
      else {
        digitalWrite(reLay, HIGH); // relay OFF
        Serial.println("Relay is OFF");
      }
      // Reading the masterSwitchValue
      delay(1000);
      dataFromSlave = "";
      number = "";
    }
  }
}
