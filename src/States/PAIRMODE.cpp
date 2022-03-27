#include "Arduino.h"
#include "StateManager/Context.h"
#include <States/States.h>
#include "espnow.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <IOManager/INPUTManager.h>
#include <IOManager/OUTPUTManager.h>
using namespace STATES;

void PAIRMODE::Update(){
	delay(3000);
	Serial.println("Waiting for packet");
}

void PAIRMODE::Init(){
	Viquiz::INPUTManager::GetInstance()->Init();
	Viquiz::OUTPUTManager::GetInstance()->Init();
}


void PAIRMODE::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){

	Serial.println("Packet in coming");
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