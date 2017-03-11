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
	// 단일 이미지를 스프라이트로 로드한다.
	void MakeSpriteToOnceImage ( string key, string path );

	// 이미지 여러장을 스프라이트로 로드한다.
	void MakeSpriteToMultiImage ( string key, vector<string> vPath, int delay);

	// 이미지 자체를 스프라이트로 로드한다.
	void MakeSpriteToSelfImage ( string key, string path, int maxFrameX, int maxFrameY, int delay);

	// 맵에 있는 스프라이트 클론 데이터를 복사 반환한다.
	DXSprite InsertSpriteData ( string key );

	// 스프라이트 클론의 정보를 반환한다.
	DXSprite* FindSprite ( string key );
		
public:
	SpriteManager () {};
	~SpriteManager () {};

};

