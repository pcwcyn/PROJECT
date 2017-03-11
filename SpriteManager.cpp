#include "stdafx.h"

#include "SpriteManager.h"

#include "MainGame.h"


void SpriteManager::MakeSpriteToOnceImage ( string key, string path )
{
	wstring wstr;
	DXSprite* dxSprite = new DXSprite;
	wstr.assign ( path.begin (), path.end () );
	dxSprite->Init ( DXSprite::KIND_ONCE );
	dxSprite->Load ( wstr.c_str() );

	m_SpriteClones.insert ( make_pair(key, dxSprite ) );
}

void SpriteManager::MakeSpriteToMultiImage ( string key, vector<string> vPath, int delay )
{
		DXSprite* dxSprite = new DXSprite;
		dxSprite->Init ( DXSprite::KIND_MULTI );

		vector<wstring> vWstrPath;

		for (int i = 0; i < vPath.size(); ++i)
		{
			vWstrPath[i].assign ( vPath[i].begin (), vPath[i].end () );
		}
		dxSprite->Load ( vWstrPath );

		m_SpriteClones.insert ( make_pair ( key, dxSprite ) );
}


void SpriteManager::MakeSpriteToSelfImage ( string key, string path, int maxFrameX, int maxFrameY, int delay )
{
	wstring wstr;
	DXSprite* dxSprite = new DXSprite;

	dxSprite->InitSelfImage( 100, maxFrameX, maxFrameY );
	wstr.assign ( path.begin (), path.end () );

	dxSprite->Load ( wstr.c_str() );

	int frameWidth = dxSprite->GetWidth () / maxFrameX;
	int frameHeight = dxSprite->GetHeight () / maxFrameY;

	for (int y = 0; y < maxFrameY; ++y)
	{
		for (int x = 0; x < maxFrameX; ++x)
		{
			DXSprite::FrameInfo frameInfo;
			frameInfo.frameWidth = frameWidth;
			frameInfo.frameHeight = frameHeight;
			frameInfo.frameX = x * frameWidth;
			frameInfo.frameY = y * frameHeight;

			dxSprite->AddFrame ( frameInfo );
		}
	}
	dxSprite->SetWidth ( frameWidth );
	dxSprite->SetHeight ( frameWidth );

	m_SpriteClones.insert ( make_pair ( key, dxSprite ) );
}

DXSprite SpriteManager::InsertSpriteData ( string key )
{
	return *m_SpriteClones.find ( key )->second;
}

DXSprite * SpriteManager::FindSprite ( string key )
{
	return m_SpriteClones.find ( key )->second;
}
