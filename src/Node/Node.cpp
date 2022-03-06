#include <Arduino.h>
#include "Node.h"
#include "StateManager/Context.h"
#include "ViquizState.h"
#include "Node_networking.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <queue>
Context& cxt = *Context::GetInstance();
ESP_NOWHELPER& ESPnow = *ESP_NOWHELPER::GetInstance();
#define WIFI_CHANNEL 0



void onDataRecv(uint8_t* mac,uint8_t* data,uint8_t len)
{
	cxt.onESPNowRecv(mac,data,len);
}



void setup(){
	pinMode(2,OUTPUT);
	ESPnow.init(onDataRecv,nullptr);
	cxt.ChangeState(ViquizState::PAIRMODE::GetInstance());
	
}

void loop(){
	cxt.Update();
}