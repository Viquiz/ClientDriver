#ifndef _NETWORK_MANAGER_H
#define _NETWORK_MANAGER_H
#include <Singleton/ISingleTon.h>
#include <ServerClientProtocol/ServerClientProtocol.hpp>

class NETWORKManager: public ISINGLETON<NETWORKManager>
{
	public:
		void send(BasePacket);
};









#endif
