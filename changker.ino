#include <IRremote.h>

 
int RECV_PIN = 15;

IRsend irsend;
IRrecv irrecv(RECV_PIN);


decode_results results;
 
void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver

}
 
void loop() 
{

//  Serial.println(getIrDataFromRemote());
//  delay(500);

//  for (int i = 0; i < 3; i++) {
//    irsend.sendNEC(0x20DF10EF,32);
//    delay(40);
//  }
//  delay(800); //E5 second delay between each signal burst


  for (int i = 0; i < 3; i++) {
    irsend.sendSony(0xa90, 12);
    delay(40);
  }
  delay(300);
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

int getIrDataFromRemote() {
    if (irrecv.decode(&results)) {
    irrecv.resume();
    return results.value;
    } else {
    return 0;
    }
  }
