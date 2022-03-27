#include <IOManager/OUTPUTManager.h>
#include <Adafruit_NeoPixel.h>

using namespace Viquiz;
constexpr uint8_t LED_PIN = 4;
constexpr uint8_t LED_COUNT =4;
constexpr uint8_t BRIGHTNESS = 20;
constexpr uint8_t MOTOR_PIN = 2;
void OUTPUTManager::Init()
{	
	Serial.println("Test output manager");
	if(m_isInit) return;
	m_isInit = true;
	strip = new Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
	strip->begin();

	pinMode(MOTOR_PIN,OUTPUT);
	digitalWrite(MOTOR_PIN, LOW);

	for(int i=0; i<strip->numPixels(); i++) { // For each pixel in strip...
		strip->setPixelColor(i, 0);         //  Set pixel's color (in RAM)
		strip->show();                          //  Update strip to match
	}
}


void OUTPUTManager::LED(uint8_t mask)
{
	// mask = 0b0001;
	Serial.print("Printing: ");
	Serial.println(mask,BIN);
	for(int i =0 ; i < strip->numPixels(); i++)
	{
		if(mask & (0b1000 >> i))
		{
			strip->setPixelColor(i,0xffffffff);
			continue;
		}
		strip->setPixelColor(i,0);
	}
	strip->show();
	// for(int i=0; i<strip->numPixels(); i++) { // For each pixel in strip...
	// 	strip->setPixelColor(i,UINT32_MAX );         //  Set pixel's color (in RAM)
	// 	strip->show();                          //  Update strip to match
	// }
}

