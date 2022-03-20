#include <Config.hpp>
#include <EEPROM.h>


void CONFIGManager::LoadConfig(std::string file_name)
{
	EEPROM.begin(sizeof(CONFIG));
	EEPROM.get<CONFIG>(0,m_config);
	EEPROM.end();

}

const CONFIG& CONFIGManager::getConfig() const
{
	return m_config;
}
