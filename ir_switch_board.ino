#include <IRremote.h>//out,gnd,5v
#define irPin 2
IRrecv irrec
(irPin);
decode_results results;
#define r1 3
int relay1 = LOW;
#define r2 4
int relay2 = LOW;
#define r3 5
int relay3 = LOW;
#define r4 7
int relay4 = LOW;
void setup() 
{
    irrec.enableIRIn();
    pinMode(r1, OUTPUT); 
    pinMode(r2, OUTPUT);
    pinMode(r3, OUTPUT);
    pinMode(r4, OUTPUT);   
}
void loop() {
   if (irrec.decode(&results)) {
      switch (results.value) {
            case 542976215:
            digitalWrite(r1,0);
            digitalWrite(r2,0);  //all off
            digitalWrite(r3,0);
            digitalWrite(r4,0);
            
            delay(250);
            break;        
            case 543002735:
            relay1 = ~ relay1;
            digitalWrite(r1,relay1);
            delay(250);
            break;
            case 543012935:
            relay2 = ~ relay2;
            digitalWrite(r2,relay2);
            delay(250);
            break;
            case 543029255:
            relay3 = ~ relay3;
            digitalWrite(r3,relay3);
            delay(250);
            break;
            case 543010895:
            relay4 = ~ relay4;
            digitalWrite(r4,relay4);
            delay(250);
            break;
            
           }
 
   irrec.resume();
   }
}
