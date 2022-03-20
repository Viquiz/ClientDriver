#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include <Singleton/ISingleTon.h>
#include <stdint.h>
namespace Viquiz{
	class INPUTManager: public ISINGLETON<INPUTManager>{

		public:
			void Init();			
			uint8_t GetInput();
		private:
			bool m_isInit;
	};
}


#endif