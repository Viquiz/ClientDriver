#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include <Singleton/ISingleTon.h>

namespace Viquiz{
	class INPUTManager: public ISINGLETON<INPUTManager>{

		public:
			void Init();			
		private:
			bool m_isInit;
	};
}


#endif