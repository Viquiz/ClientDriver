#include "Arduino.h"
#include "StateManager/Context.h"
#include <States/GameMode.h>
#include "espnow.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <Adafruit_NeoPixel.h>
#include <InputManager/INPUTManager.h>

using namespace STATES;

void GAMEMODE::Init()
{
	Viquiz::INPUTManager::GetInstance()->Init();
}

void GAMEMODE::Update(){
	Serial.println("TEST");
}



void GAMEMODE::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){
}
