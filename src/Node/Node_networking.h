#ifndef _NODE_NETWORKING_
#define _NODE_NETWORKING_
#include "stdint.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include "Singleton/ISingleTon.h"
#include "espnow.h"
class ESP_NOWHELPER: public ISINGLETON<ESP_NOWHELPER>
{
public:	
	void init(esp_now_recv_cb_t onRecvCallBack,esp_now_send_cb_t onSentCallback);

};


#endif