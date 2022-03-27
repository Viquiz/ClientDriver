#ifndef _OUTPUTMANAGER_H
#define _OUTPUTMANAGER_H
#include <Config.hpp>
#include <Singleton/ISingleTon.h>
#include <Adafruit_NeoPixel.h>
namespace Viquiz{
	class OUTPUTManager: public ISINGLETON<OUTPUTManager>
	{
	private:
		Adafruit_NeoPixel *strip;
		public:
		void Init();
		void LED(uint8_t mask);
	private:
		bool m_isInit = false;
	};

}



#endif

