#include "Arduino.h"
#include "StateManager/Context.h"
#include <States/GameMode.h>
#include "espnow.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <Adafruit_NeoPixel.h>
#include <IOManager/INPUTManager.h>
#include <States/APMODE.h>
#include <Network.h>
#include <Config.hpp>
using namespace STATES;


#define MAC_ADDRESS_SIZE 6
uint8_t bit_count(uint8_t input){
	uint8_t result = 0;
	while(input >0)
	{
		result += input & 0b1;
		input >>= 1;
	}
	return result;	
}
void GAMEMODE::Init()
{
	Viquiz::INPUTManager::GetInstance()->Init();
	sended = false;
	time = 0;
}

void GAMEMODE::Update(){
	uint8_t input_result = Viquiz::INPUTManager::GetInstance()->GetInput();
	uint8_t btn_count = bit_count(input_result);
	if(btn_count == 1)
	{
		btn_t button = static_cast<btn_t>(input_result);
		AnswPacket answer_p(button);
		NETWORKManager::GetInstance()->send(answer_p);
	}else{
		if(!sended && time >= millis())
		{
			btn_t button = btn_t::NO_ANSW;
			AnswPacket answer_p(button);
			NETWORKManager::GetInstance()->send(answer_p);
		}
	}
}



void GAMEMODE::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){

	BasePacket* packet = reinterpret_cast<BasePacket*>(buffer);
	switch(packet->type)
	{
		case packet_t::BEACON:
			{
				BeaconPacket* beaconPacket = reinterpret_cast<BeaconPacket*>(packet);
				NETWORKManager* net = NETWORKManager::GetInstance();
				const uint8_t* saved_host = CONFIGManager::GetInstance()->getConfig().MAC_ADDRESS;
				if(memcmp(peerAddr,saved_host,MAC_ADDRESS_SIZE))
				{
					time = millis() + beaconPacket->milliRemain;
				}
			}
		default:
			break;
	}
}
