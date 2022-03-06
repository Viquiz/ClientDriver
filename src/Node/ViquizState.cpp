#include "ViquizState.h"
#include "Arduino.h"
#include "StateManager/Context.h"
#include "espnow.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#define ToggleDigital(X) digitalWrite(X,!digitalRead(X));

using namespace ViquizState;

void PAIRMODE::Update(){

}


void PAIRMODE::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){
	BasePacket* packetData = (BasePacket*)buffer;
	if(packetData->type == packet_t::BEACON)
	{
		RequestRegisterPacket p;
    		esp_now_send(peerAddr, (uint8_t *)&p, sizeof(p));
	}
	if(packetData->type == packet_t::RESPOND_REG)
	{
		GAMEMODE* gameModeState = GAMEMODE::GetInstance();
		Context* cxt = Context::GetInstance();
		cxt->ChangeState(gameModeState);
	}
}

void GAMEMODE::Update(){
}



void GAMEMODE::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){
}
