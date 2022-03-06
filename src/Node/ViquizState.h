#ifndef _VIQUIZSTATE_H
#define _VIQUIZSTATE_H
#include "StateManager/IState.h"
#include "Singleton/ISingleTon.h"
namespace ViquizState{
	class PAIRMODE:public ISINGLETON<PAIRMODE>, public ISTATE{
		public:
			void Update() override;
		
	};
	class GAMEMODE:public ISINGLETON<GAMEMODE>, public ISTATE{
		public:
			void Update() override;
		
	};
}


#endif