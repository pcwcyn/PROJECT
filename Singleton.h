#pragma once
template<typename T>
class Singleton
{
protected:
	Singleton () {};
	~Singleton () {};

public:
	static T* GetInst ()
	{
		if (!m_Inst)
		{
			m_Inst = new T;
		}

		return m_Inst;
	}
	static void Destroy ()
	{
		delete m_Inst;
		m_Inst = nullptr;
	}

public:
	static T* m_Inst;
};

template<typename T>
T* Singleton<T>::m_Inst = nullptr;

