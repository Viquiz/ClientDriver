#include <Network/NETWORKManager.h>
#include <ESP8266WiFi.h>
#include <StateManager/Context.h>
#include <Config.hpp>
extern "C"
{
	#include <espnow.h>
}

void NETWORKManager::send(const BasePacket& packet) 
{
	CONFIG cfg = CONFIGManager::GetInstance()->getConfig();
	esp_now_send((uint8_t*)cfg.MAC_ADDRESS,(uint8_t*)&packet,sizeof(packet));
}

void NETWORKManager::Init(){
	if(m_isInit) return;

	WiFi.disconnect();
	ESP.eraseConfig();
	// Wifi STA Mode
	WiFi.mode(WIFI_STA);
	// Get Mac Add
	Serial.print("Mac Address: ");
	Serial.print(WiFi.macAddress());
	Serial.println("\nESP-Now Receiver");


	if (esp_now_init() != 0) {
	Serial.println("Problem during ESP-NOW init");
		return;
	}

	//esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
	// We can register the receiver callback function
	esp_now_register_recv_cb(NETWORKManager::onDataRecv);
	cxt = Context::GetInstance();
	m_isInit = true;
}

void NETWORKManager::onDataRecv(uint8_t* mac,uint8_t* buffer, uint8_t length){
	Serial.println("In coming data");
	if(NETWORKManager::m_instance == nullptr) return;
	if(NETWORKManager::m_instance->cxt == nullptr) return;

	
 	NETWORKManager::m_instance->cxt->onESPNowRecv(mac,buffer,length);
}