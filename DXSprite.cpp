#include "stdafx.h"

#include "DXApp.h"
#include "DXSprite.h"

#include "SpriteManager.h"
#include "MainGame.h"
#include <WICTextureLoader.h>
#include "DXApp.h"
#include "SimpleMath.h"
DXSprite::DXSprite ()	:
	m_CurrnetFrameOfMulti (0),
	m_MaxFrameOfMulti (0),
	m_CurrentFrameX(0),
	m_CurrentFrameY(0),
	m_Time(0),
	m_Width(0),
	m_Height(0),
	m_isOncePlay(FALSE),
	m_isChangedFrame(false),
	m_isStop(false),
	m_Angle(0),
	m_Scale(1,1)
{
}


DXSprite::~DXSprite ()
{
}

void DXSprite::Init (SPRITE_KIND spriteKind, int delay )
{
	m_SpriteKind = spriteKind;
	m_Delay = delay;
}

void DXSprite::InitSelfImage ( int delay, int maxFrameX, int maxFrameY )
{
	m_Delay = delay;
	m_MaxFrameX = maxFrameX;
	m_MaxFrameY = maxFrameY;
	m_SpriteKind = KIND_SELF;
	m_Delay = delay;
}

//void DXSprite::Render ( float x, float y, bool isXFlip)
//{
//	//Play ();
//
//	//if (isXFlip)
//	//{
//	//	m_vDXImage[m_CurrnetFrame]->SetSpriteEffect ( DirectX::SpriteEffects::SpriteEffects_FlipHorizontally );
//	//}
//
//	//m_vDXImage[m_CurrnetFrame]->SetScale ( DirectX::SimpleMath::Vector2 ( 1, 1 ) );
//	//m_vDXImage[m_CurrnetFrame]->SetPosition ( DirectX::SimpleMath::Vector2 ( x, y ) );
//	//m_vDXImage[m_CurrnetFrame]->Draw ( DXApp::GetInst ()->GetSpriteBatch () );
//}

//void DXSprite::Render ( float x, float y, float scaleX, float scaleY, bool isXFlip )
//{
//	//Play ();
//
//
//	//if (isXFlip)
//	//{
//	//	m_vDXImage[m_CurrnetFrame]->SetSpriteEffect ( DirectX::SpriteEffects::SpriteEffects_FlipHorizontally );
//	//}
//
//	//m_vDXImage[m_CurrnetFrame]->SetScale ( DirectX::SimpleMath::Vector2 ( scaleX, scaleY ) );
//	//m_vDXImage[m_CurrnetFrame]->SetPosition ( DirectX::SimpleMath::Vector2 ( x, y ) );
//	//m_vDXImage[m_CurrnetFrame]->Draw ( DXApp::GetInst ()->GetSpriteBatch () );
//}

void DXSprite::Load ( const wchar_t * file )
{
	m_vecResource.push_back ( NULL );
	m_vecTexture.push_back ( NULL );

	if (HRESULT ( DirectX::CreateWICTextureFromFile ( DXApp::GetInst ()->GetDevice (),
		file, &m_vecResource[0], &m_vecTexture[0] )))
	{
		//MessageBox ( DXApp::GetInst ()->GetHwnd (), "이미지로드 실패", "", MB_OK );
	}
	Utility::GetTextureDim ( m_vecResource[0], &m_Width, &m_Height );
	
	//{
	////	MessageBox ( DXApp::GetInst ()->GetHwnd (), "이미지로드 실패", "", MB_OK );
	//}
	m_Origin = Vector2 (0,0);
	m_SourceRect.left = 0;
	m_SourceRect.top = 0;
	m_SourceRect.right = m_Width;
	m_SourceRect.bottom = m_Height;
}

void DXSprite::Load ( vector<wstring> vecFile )
{
	UINT width, height;
	for (int i = 0; i < vecFile.size (); ++i)
	{
		HRESULT ( DirectX::CreateWICTextureFromFile ( DXApp::GetInst ()->GetDevice (), vecFile[i].c_str(), &m_vecResource[i], &m_vecTexture[i] ) );
		Utility::GetTextureDim ( m_vecResource[i], &width, &height );
		m_Origin = Vector2 ( 0, 0 );
		m_SourceRect.left = 0;
		m_SourceRect.top = 0;
		m_SourceRect.right = m_Width;
		m_SourceRect.bottom = m_Height;
	}
}

void DXSprite::AddFrame ( FrameInfo frameImage )
{
	m_vecFrameInfo.push_back ( frameImage );
}

void DXSprite::Render ( float x, float y )
{
	Play ();

	switch (m_SpriteKind)
	{
		case KIND_ONCE: case KIND_MULTI:
		{
			DXApp::GetInst ()->GetSpriteBatch ()->Draw ( m_vecTexture[m_CurrnetFrameOfMulti], Vector2 ( x, y ),
				&m_SourceRect, DirectX::Colors::White.v, m_Angle, m_Origin,
				m_Scale, DirectX::SpriteEffects::SpriteEffects_None, 0.0f );
		} break;

		case KIND_SELF:
		{
			int frameWidth = m_vecFrameInfo[m_CurrentFrameX].frameWidth;
			int frameHeight = m_vecFrameInfo[m_CurrentFrameX].frameHeight;

			RECT frameRc = { m_CurrentFrameX * frameWidth, m_CurrentFrameY * frameHeight,
				m_CurrentFrameX * frameWidth + frameWidth, m_CurrentFrameY * frameHeight + frameHeight };

			DXApp::GetInst ()->GetSpriteBatch ()->Draw ( m_vecTexture[0], Vector2 ( x, y ),
				&frameRc, DirectX::Colors::White.v, m_Angle, m_Origin,
				m_Scale, DirectX::SpriteEffects::SpriteEffects_None, 0.0f );
		} break;
	}
}

void DXSprite::SetFixSize ( float width, float height )
{
	UINT oriWidth = m_Width;
	UINT oriHeight = m_Height;

	float transWidthRate = (float)width / oriWidth;
	float transHeightRate = (float)height / oriHeight;

	SetSize ( transWidthRate, transHeightRate );
}

void DXSprite::AddImage (wstring imageKey)
{
//	m_vDXImage.push_back ( ( SpriteManager::GetInst ()->FindImage ( imageKey ) ) );
//	m_MaxFrame = m_vDXImage.size ();
}

void DXSprite::Play ()
{
	if (m_isStop) return;
	m_isChangedFrame = FALSE;

	switch (m_SpriteKind)
	{
		case KIND_MULTI: case KIND_ONCE:
		{
			if (m_Time == 0)
			{
				m_Time = GetTickCount64 ();
			}

			if (GetTickCount64 () >= m_Time + m_Delay)
			{
				m_Time = GetTickCount ();
				++m_CurrnetFrameOfMulti;
				m_isChangedFrame = TRUE;

				if (m_CurrnetFrameOfMulti >= m_MaxFrameOfMulti)
				{
					m_CurrnetFrameOfMulti = 0;
					m_isOncePlay = TRUE;
				}
			}
		} break;

		case KIND_SELF:
		{
			if (m_Time == 0)
			{
				m_Time = GetTickCount64 ();
			}

			if (GetTickCount64 () >= m_Time + m_Delay)
			{
				m_Time = GetTickCount ();
				++m_CurrentFrameX;

				if (m_CurrentFrameX >= m_MaxFrameX)
				{
					m_CurrentFrameX = 0;
					++m_CurrentFrameY;

					if (m_CurrentFrameY >= m_MaxFrameY)
					{
						m_CurrentFrameY = 0;
					}
				}
			}
		} break;
	}
}
//
//void DXSprite::Draw ()
//{
//
//}

