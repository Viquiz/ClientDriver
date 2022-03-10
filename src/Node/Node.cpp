#include <Config.hpp>

#ifdef NODE
#include <Arduino.h>
#include "StateManager/Context.h"
#include <States/States.h>
#include "Node_networking.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <queue>
Context& cxt = *Context::GetInstance();
ESP_NOWHELPER& ESPnow = *ESP_NOWHELPER::GetInstance();
#define WIFI_CHANNEL 0



void onDataRecv(uint8_t* mac,uint8_t* data,uint8_t len)
{
	Serial.println("message");
	cxt.onESPNowRecv(mac,data,len);
}



void setup(){
	pinMode(2,OUTPUT);
	Serial.begin(115200);
	Serial.println("booting");
	ESPnow.init(onDataRecv,nullptr);
	cxt.ChangeState(STATES::PAIRMODE::GetInstance());	
}

void loop(){
	// cxt.Update();
}
#endif