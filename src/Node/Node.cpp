#include <Arduino.h>
#include "Node.h"
#include "StateManager/Context.h"
#include "ViquizState.h"
#include "Node_networking.h"

Context& cxt = *Context::GetInstance();


void setup(){
	pinMode(2,OUTPUT);
	// digitalWrite(2,HIGH);
	cxt.ChangeState(ViquizState::PAIRMODE::GetInstance());
}

void loop(){
	cxt.Update();
}