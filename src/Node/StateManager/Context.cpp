#include "Context.h"


void Context::ChangeState(ISTATE* _state)
{
	if(_state == nullptr) return;
	
	this->m_CurrentState = _state;
}


void Context::Update(){
	if(m_CurrentState == nullptr) return;
	m_CurrentState->Update();
}

