#ifndef _VIQUIZSTATE_H
#define _VIQUIZSTATE_H
#include "StateManager/IState.h"
#include "Singleton/ISingleTon.h"
#include <ESPNOWdef.h>
namespace ViquizState{
	class PAIRMODE:public ISINGLETON<PAIRMODE>, public ISTATE{
		private:
			void onBeacon();
			bool isBeacon = false;
		public:
			void Update() override;
			void onESPNowRecv(onRecvCbParams) override;
		
	};
	class GAMEMODE:public ISINGLETON<GAMEMODE>, public ISTATE{
		public:
			void Update() override;
			void onESPNowRecv(onRecvCbParams) override;

	};
}


#endif