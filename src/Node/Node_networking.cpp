#include "Node_networking.h"
#include "Arduino.h"
#include "ESP8266WiFi.h"


void ESP_NOWHELPER::init(esp_now_recv_cb_t onRecvCallBack,esp_now_send_cb_t onSentCallback)
{
	WiFi.disconnect();
	ESP.eraseConfig();
	WiFi.mode(WIFI_STA);
	esp_now_init();
	esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
	if(onRecvCallBack != nullptr)
	{
		esp_now_register_recv_cb(onRecvCallBack);
	}
	if(onSentCallback != nullptr)
	{
		esp_now_register_send_cb(onSentCallback);
	}
}