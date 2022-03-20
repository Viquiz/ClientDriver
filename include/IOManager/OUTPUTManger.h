#ifndef _OUTPUTMANAGER_H
#define _OUTPUTMANAGER_H
#include <Config.hpp>
#include <Singleton/ISingleTon.h>

namespace Viquiz{
	class OUTPUTManager: public ISINGLETON<OUTPUTManager>
	{
	private:
		
	public:
		void Init();
	private:
		bool m_isInit;
	};

}



#endif

