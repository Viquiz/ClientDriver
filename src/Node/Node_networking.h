#ifndef _NODE_NETWORKING_
#define _NODE_NETWORKING_
#include "stdint.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
namespace ESP_NOWHELPER
{
	typedef void (*onDataCallback)(uint8_t*, uint8_t*,uint8_t);

	
	void init(onDataCallback onRecvCallback,onDataCallback onSentCallback);
}


#endif