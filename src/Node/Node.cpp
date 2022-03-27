#include <Config.hpp>
#ifdef NODE
#include <System.h>
#include <Arduino.h>
#include "StateManager/Context.h"
#include <States/States.h>
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <IOManager/INPUTManager.h>
#include <IOManager/OUTPUTManager.h>
#include <Network/NETWORKManager.h>
Context& cxt = *Context::GetInstance();







void setup(){
	Serial.begin(115200);
	CONFIGManager::GetInstance()->LoadConfig("");
	Viquiz::INPUTManager::GetInstance()->Init();
	Viquiz::OUTPUTManager::GetInstance()->Init();
	NETWORKManager::GetInstance()->Init();	
	cxt.ChangeState(STATES::GAMEMODE::GetInstance());
	cxt.Init();
}

void loop(){
	cxt.Update();
}
#endif