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


RF24 radio(7,8); // CE,CSN
const byte address[6] = "00001"; // address of the transmitter

struct sendData{
  byte channel_1;
  byte channel_2;
  byte channel_3;
  byte channel_4;
  byte channel_5;
  byte channel_6;
  byte channel_7;
};

sendData data; // data object


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); // Make the device as transmitter

}

void loop() {

  // potentiometeres are connected to from A0 to A6
  data.channel_1 = map(analogRead(A0), 0, 1023, 0, 255);
  data.channel_2 = map(analogRead(A1), 0, 1023, 0, 255);
  data.channel_3 = map(analogRead(A2), 0, 1023, 0, 255);
  data.channel_4 = map(analogRead(A3), 0, 1023, -255, 255);
  data.channel_5 = map(analogRead(A4), 0, 1023, -255, 255);
  data.channel_6 = map(analogRead(A5), 0, 1023, -255, 255);
  data.channel_7 = map(analogRead(A6), 0, 1023, -255, 255);

   Serial.print("channel 1 = " );
  Serial.print(data.channel_1);
  Serial.print("channel 2 = " );
  Serial.print(data.channel_2);
  Serial.print("channel 3 = " );
  Serial.print(data.channel_3);
  Serial.print("channel 4 = " );
  Serial.print(data.channel_4);
  Serial.print("channel 5 = " );
  Serial.print(data.channel_5);
  Serial.print("channel 6 = " );
  Serial.print(data.channel_6);
  Serial.print("channel 7 = " );
  Serial.print(data.channel_7);
  
  radio.write(&data, sizeof(sendData));
  
  delay(5);
}
