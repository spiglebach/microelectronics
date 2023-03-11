#include <IRremote.h>
// IRremote 4.1.0

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
IRData results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  enableLEDFeedback();
}

void loop() {
  if (irrecv.decode()) {
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    //Serial.println(irrecv.decodedIRData.protocol);
    irrecv.resume();
  }
}
