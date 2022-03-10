#ifndef _CONFIG_
#define _CONFIG_

// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <espnow.h>
#include "ServerClientProtocol/ServerClientProtocol.hpp"

#define WIFI_CHANNEL 0

#define SERVER

#ifndef SERVER
#define NODE
#endif


#endif // !_CONFIG_