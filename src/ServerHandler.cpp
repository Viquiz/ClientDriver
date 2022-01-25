#include "ServerHandler.hpp"

void sendRequestRegister(uint8_t *serverAddr)
{
    RequestRegisterPacket p;
    esp_now_send(serverAddr, (uint8_t *)&p, sizeof(p));
}