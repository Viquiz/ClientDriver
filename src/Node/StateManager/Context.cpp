#include "Context.h"
#include "stdint.h"

void Context::ChangeState(ISTATE* _state)
{
	if(_state == nullptr) return;
	
	this->m_CurrentState = _state;
}


void Context::Update(){
	if(m_CurrentState == nullptr) return;
	m_CurrentState->Update();
}

void Context::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){
	if(m_CurrentState == nullptr) return;
	m_CurrentState->onESPNowRecv(peerAddr,buffer,length);
}