#ifndef _ISINGLETON_H
#define _ISINGLETON_H


template<class T>
class ISINGLETON
{
	protected:
		inline explicit ISINGLETON(){}
		~ISINGLETON(){}
	public:
		inline static T* GetInstance()
		{
			if(m_instance == nullptr)
			{
				m_instance = new T;
			}
			return m_instance;
		}
	protected:
		static T* m_instance;

};

template<class T>
T* ISINGLETON<T>::m_instance = nullptr;
#endif