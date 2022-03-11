#include "Arduino.h"
#include "StateManager/Context.h"
#include <States/States.h>
#include "espnow.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>

using namespace STATES;

void PAIRMODE::Update(){
	Serial.println("TEST");
}

void PAIRMODE::Init(){
	
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