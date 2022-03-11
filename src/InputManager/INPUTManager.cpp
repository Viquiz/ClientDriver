#include <InputManager/INPUTManager.h>
#include <Config.hpp>
#include <Arduino.h>
using namespace Viquiz;

void INPUTManager::Init()
{
	if(m_isInit) return;
	auto cfg = CONFIGManager::GetInstance()->getConfig();
	for(uint8_t i :cfg.pins)
	{
		pinMode(i,OUTPUT);
	}
}