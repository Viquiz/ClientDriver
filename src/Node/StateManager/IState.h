#ifndef _ISTATE_H
#define _ISTATE_H
class ISTATE{
public:
	virtual void Update() = 0;
	virtual void onESPNowRecv(uint8_t* peer_addr,uint8_t* buffer,uint8_t length) = 0;
};
#endif