#ifndef _GAMEMODE_H
#define _GAMEMODE_H
#include <StateManager/IState.h>
#include <Singleton/ISingleTon.h>
#include <ESPNOWdef.h>
namespace STATES
{
    class GAMEMODE:public ISINGLETON<GAMEMODE>, public ISTATE{
		public:
			void Update() override;
			void onESPNowRecv(onRecvCbParams) override;

	};
}

#endif