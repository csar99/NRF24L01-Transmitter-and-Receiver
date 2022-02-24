#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

 /*          MEGA    UNO   NANO
 * SCK  -   52      13    13
 * MOSI -   51      11    11
 * MISO -   50      12    12
 * CSN  -   8       8     8
 * CE   -   7       7     7
 * 
 */

RF24 radio(7,8);
const byte address[6] = "00001"; // must be same as the transmitter address

struct ReceiveData{
  byte ReceiveChannel_1;
  byte ReceiveChannel_2;
  byte ReceiveChannel_3;
  byte ReceiveChannel_4;
  byte ReceiveChannel_5;
  byte ReceiveChannel_6;
  byte ReceiveChannel_7;
};

ReceiveData data;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening(); // make the device as receiver
}

void loop() {
  delay(5);
  if(radio.available()){
    while(radio.available()){
     
      radio.read(&data, sizeof(ReceiveData));
     

  Serial.print("channel 1 = " );
  Serial.print(data.ReceiveChannel_1);
  Serial.print("channel 2 = " );
  Serial.print(data.ReceiveChannel_2);
  Serial.print("channel 3 = " );
  Serial.print(data.ReceiveChannel_3);
  Serial.print("channel 4 = " );
  Serial.print(data.ReceiveChannel_4);
  Serial.print("channel 5 = " );
  Serial.print(data.ReceiveChannel_5);
  Serial.print("channel 6 = " );
  Serial.print(data.ReceiveChannel_6);
  Serial.print("channel 7 = " );
  Serial.print(data.ReceiveChannel_7);
     
    }
  }
  
  

}
