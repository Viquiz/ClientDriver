#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "IState.h"
#include "../Singleton/ISingleTon.h"

class Context: public ISINGLETON<Context>{
private:
	ISTATE* m_CurrentState;
public:
	Context(){}
	void ChangeState(ISTATE* _state);
	void Update();
	
};
#endif