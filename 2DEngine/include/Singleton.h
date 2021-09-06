#ifndef WITZ_ENGINE_SINGLETON_H
#define WITZ_ENGINE_SINGLETON_H

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

		Singleton(){ m_instance = static_cast <T*> (this); }
		~Singleton(){  }
	};

	template<typename T>
	T* Singleton<T>::m_instance = nullptr;

	template<typename T>
	T* Singleton<T>::GetInstance()
	{
		if(!m_instance)
		{
			m_instance = new T();
		}

		return m_instance;
	}

	template<typename T>
	void Singleton<T>::destroy()
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

#endif // WITZ_ENGINE_SINGLETON_H

