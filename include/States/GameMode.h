#ifndef _GAMEMODE_H
#define _GAMEMODE_H
#include <StateManager/IState.h>
#include <Singleton/ISingleTon.h>
#include <ESPNOWdef.h>

namespace STATES
{
    class GAMEMODE:public ISINGLETON<GAMEMODE>, public ISTATE{
	    	private:
			uint64_t time;
			bool sended;
		public:
			void Init() override;
			void Update() override;
			void onESPNowRecv(onRecvCbParams) override;

	};
}

#endif
