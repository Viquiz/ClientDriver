#include "Node_networking.h"
#include "Arduino.h"
#include "ESP8266WiFi.h"


void ESP_NOWHELPER::init(esp_now_recv_cb_t onRecvCallBack,esp_now_send_cb_t onSentCallback)
{
	// WiFi.disconnect();
	// ESP.eraseConfig();
	// WiFi.mode(WIFI_STA);
	// esp_now_init();
	// esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  	WiFi.disconnect();
  	ESP.eraseConfig();
  	// Initialize Neopixel
  	// Wifi STA Mode
  	WiFi.mode(WIFI_STA);
  	// Get Mac Add
  	Serial.print("Mac Address: ");
  	Serial.print(WiFi.macAddress());
  	Serial.println("\nESP-Now Receiver");
  
  	// Initializing the ESP-NOW
  	if (esp_now_init() != 0) {
    		Serial.println("Problem during ESP-NOW init");
    		return;
  	}
  
  	//esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  	// We can register the receiver callback function
	if(onRecvCallBack != nullptr)
	{
		esp_now_register_recv_cb(onRecvCallBack);
	}
	if(onSentCallback != nullptr)
	{
		esp_now_register_send_cb(onSentCallback);
	}
}