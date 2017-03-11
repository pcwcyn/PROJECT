#pragma once
#include <map>
#include "DXSprite.h"
#include "Singleton.h"
using namespace std;

class SpriteManager : public Singleton<SpriteManager>
{
public:
	map<string, DXSprite*> m_SpriteClones;

public: // FUNCTION
	// ���� �̹����� ��������Ʈ�� �ε��Ѵ�.
	void MakeSpriteToOnceImage ( string key, string path );

	// �̹��� �������� ��������Ʈ�� �ε��Ѵ�.
	void MakeSpriteToMultiImage ( string key, vector<string> vPath, int delay);

	// �̹��� ��ü�� ��������Ʈ�� �ε��Ѵ�.
	void MakeSpriteToSelfImage ( string key, string path, int maxFrameX, int maxFrameY, int delay);

	// �ʿ� �ִ� ��������Ʈ Ŭ�� �����͸� ���� ��ȯ�Ѵ�.
	DXSprite InsertSpriteData ( string key );

	// ��������Ʈ Ŭ���� ������ ��ȯ�Ѵ�.
	DXSprite* FindSprite ( string key );
		
public:
	SpriteManager () {};
	~SpriteManager () {};

};

