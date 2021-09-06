#ifndef SINGLETON_H
#define SINGLETON_H

namespace WitzEngine
{
	template<typename T>
	class Singleton
	{
	public:
		static T* GetInstance();
		static void destroy();

	private:

		Singleton(Singleton const&){};
		Singleton& operator=(Singleton const&){};

	protected:
		static T* m_instance;

		Singleton(){ m_instance = static_cast <T*> (this); };
		~Singleton(){  };
	};

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
}

#endif // SINGLETON_H

