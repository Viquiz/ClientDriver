#include <StateManager/Context.h>
#include "stdint.h"


// Call Init every time state change
void Context::ChangeState(ISTATE* _state)
{
	if(_state == nullptr) return;
	this->m_CurrentState = _state;
	Init();
}


void Context::Update(){
	if(m_CurrentState == nullptr) return;
	m_CurrentState->Update();
}

void Context::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length) {
	if(m_CurrentState == nullptr) return;
	m_CurrentState->onESPNowRecv(peerAddr,buffer,length);
}

void Context::Init(){
	if(m_CurrentState == nullptr) return;
	m_CurrentState->Init();
}