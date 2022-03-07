#ifndef _PAIRMODE_H
#define _PAIRMODE_H
#include <StateManager/IState.h>
#include <Singleton/ISingleTon.h>
#include <ESPNOWdef.h>
namespace STATES{
	class PAIRMODE:public ISINGLETON<PAIRMODE>, public ISTATE{
		private:
			void onBeacon();
			bool isBeacon = false;
		public:
			void Update() override;
			void onESPNowRecv(onRecvCbParams) override;
		
	};
	
}


#endif