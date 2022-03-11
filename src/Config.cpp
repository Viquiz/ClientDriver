#include <Config.hpp>



void CONFIGManager::LoadConfig(std::string file_name)
{
	// m_config.pins.push_back(15);
	// m_config.pins.push_back(14);
	// m_config.pins.push_back(13);
	// m_config.pins.push_back(12);
	m_config.pins.push_back(2);

}

const CONFIG& CONFIGManager::getConfig() const
{
	return m_config;
}