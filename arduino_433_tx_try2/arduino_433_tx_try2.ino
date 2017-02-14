//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
// THIS CODE WORKS - AARON 5/6/2016
//http://www.instructables.com/id/RF-315433-MHz-Transmitter-receiver-Module-and-Ardu/?ALLSTEPS
#include <VirtualWire.h>
char *controller;

void setup() {
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  controller = "1";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  delay(50);
  controller = "0"  ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,0);
  delay(50);
}
