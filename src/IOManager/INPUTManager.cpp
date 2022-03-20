#include <IOManager/INPUTManager.h>
#include <Config.hpp>
#include <Arduino.h>
using namespace Viquiz;

void INPUTManager::Init()
{
	if(m_isInit) 
	{
		Serial.println("already Init input manager");
		return;
	}
	m_isInit = true;
	pinMode(15,INPUT);
	pinMode(14,INPUT);
	pinMode(13,INPUT);
	pinMode(12,INPUT);

}

uint8_t INPUTManager::GetInput(){
	constexpr uint8_t btn1_offset = 0;
	constexpr uint8_t btn2_offset = 1;
	constexpr uint8_t btn3_offset = 2;
	constexpr uint8_t btn4_offset = 3;

	uint8_t btn1 = digitalRead(15);
	uint8_t btn2 = !digitalRead(14);
	uint8_t btn3 = !digitalRead(13);
	uint8_t btn4 = digitalRead(12);

	uint8_t result = 0 | (btn1 << btn1_offset) |( btn2 << btn2_offset) | (btn3 << btn3_offset) | (btn4 << btn4_offset);
	return result;
}