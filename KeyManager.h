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

	//Ű�� �ѹ��� ���ǳ�?
	bool isOnceKeyDown(int key);
	//Ű�� �ѹ� ������ �����?
	bool isOnceKeyUp(int key);
	//Ű�� ��� �����ֳ�?
	bool isStayKeyDown(int key);
	//���Ű��?(ĸ����,�ѹ���)
	bool isToggleKey(int key);

private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;
};

