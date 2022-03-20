#include <Config.hpp>


#ifdef SERVER

#include <Arduino.h>
#include <ESP8266WiFi.h>
extern "C"
{
	#include <espnow.h>

}

void onDataReceiver(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
   Serial.println("Message received.");
   // We don't use mac to verify the sender
   // Let us transform the incomingData into our message structure
}
void setup() {
  Serial.begin(115200);
  WiFi.disconnect();
  ESP.eraseConfig();
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
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
  esp_now_register_recv_cb(onDataReceiver);
}
void loop() {
  // put your main code here, to run repeatedly:
}
#endif