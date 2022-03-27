#ifndef _NETWORK_MANAGER_H
#define _NETWORK_MANAGER_H
#include <Singleton/ISingleTon.h>
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <StateManager/Context.h>
class NETWORKManager: public ISINGLETON<NETWORKManager>
{
	private:
		bool m_isInit = false;
		Context *cxt  =nullptr;
		static void onDataRecv(uint8_t* mac,uint8_t* buffer, uint8_t length);
	public:
		void send(const BasePacket& packet);
		void Init();
};









#endif
