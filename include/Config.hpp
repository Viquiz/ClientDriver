#ifndef _CONFIG_
#define _CONFIG_

// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <espnow.h>
// #include "ServerClientProtocol/ServerClientProtocol.hpp"
#include <Singleton/ISingleTon.h>
#include <vector>
#include <stdint.h>
#include <string>
#define WIFI_CHANNEL 0

// #define SERVER

#ifndef SERVER
#define NODE
#endif

struct CONFIG
{
	std::vector<uint8_t> pins;
};

//future implementation to use config file instead hardcode
class CONFIGManager: public ISINGLETON<CONFIGManager>
{
	private:
	public:
		const CONFIG& getConfig() const;
		void LoadConfig(std::string file_name);
	private:
		CONFIG m_config;
};
#endif // !_CONFIG_