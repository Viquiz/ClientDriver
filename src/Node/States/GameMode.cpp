#include "Arduino.h"
#include "StateManager/Context.h"
#include <States/GameMode.h>
#include "espnow.h"
#include <ServerClientProtocol/ServerClientProtocol.hpp>
#include <Adafruit_NeoPixel.h>


using namespace STATES;



void GAMEMODE::Update(){

}



void GAMEMODE::onESPNowRecv(uint8_t* peerAddr,uint8_t* buffer,uint8_t length){
}
