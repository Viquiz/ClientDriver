#include "ViquizState.h"
#include "Arduino.h"
#include "StateManager/Context.h"
#define ToggleDigital(X) digitalWrite(X,!digitalRead(X));

using namespace ViquizState;

void PAIRMODE::Update(){

}

void GAMEMODE::Update(){
}
