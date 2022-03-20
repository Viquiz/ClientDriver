#include <States/APMODE.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
using namespace STATES;

void APMODE::Init()
{
	Serial.println("INIT AP MODE");
	WiFi.mode(WIFI_AP);
	WiFi.disconnect();
}


void APMODE::Update(){

}


void APMODE::onESPNowRecv(uint8_t* addr,uint8_t* buffer, uint8_t length)
{

}