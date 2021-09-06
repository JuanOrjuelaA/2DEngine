#include "Singleton.h"
#include <memory>

template<typename T>
T* WitzEngine::Singleton<T>::m_instance = nullptr;

template<typename T>
T* WitzEngine::Singleton<T>::GetInstance()
{
	if(!m_instance)
	{
		WitzEngine::Singleton<T>::m_instance = new T();
	}

	return m_instance;
}

template<typename T>
void WitzEngine::Singleton<T>::destroy()
{
	delete WitzEngine::Singleton<T>::m_instance;
	WitzEngine::Singleton<T>::m_instance = nullptr;
}