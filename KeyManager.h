#pragma once
#include <bitset>

#define KEYMAX 256

class KeyManager :public Singleton<KeyManager>
{
public:
	KeyManager();
	~KeyManager();

	HRESULT init();
	void release();

	//키가 한번만 눌렷냐?
	bool isOnceKeyDown(int key);
	//키가 한번 눌렀다 띄었냐?
	bool isOnceKeyUp(int key);
	//키가 계속 눌러있냐?
	bool isStayKeyDown(int key);
	//토글키냐?(캡스락,넘버락)
	bool isToggleKey(int key);

private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;
};

