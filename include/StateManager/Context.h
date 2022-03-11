#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "IState.h"
#include "../Singleton/ISingleTon.h"
#include <ESPNOWdef.h>
class Context:public ISTATE, public ISINGLETON<Context>{
private:
	ISTATE* m_CurrentState;
public:
	Context(){}
	void ChangeState(ISTATE* _state);
	void Update() override;
	void Init() override;
	void onESPNowRecv(onRecvCbParams) override;
	
};
#endif