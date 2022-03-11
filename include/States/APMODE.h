#ifndef _APMODE_H
#define _APMODE_H


#include <StateManager/IState.h>
#include <Singleton/ISingleTon.h>
#include <ESPNOWdef.h>
namespace STATES
{
	class APMODE: public ISTATE,public ISINGLETON<APMODE> {
		public:
			void Init() override;
			void Update() override;
			void onESPNowRecv(onRecvCbParams) override;

	};
}


#endif