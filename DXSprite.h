#pragma once

/*==============================================*/
/*
	DXSprite

	이미지 파일을 소유함과 동시에, 각종 그리기 관련 기능을 
	사용할 수 있는 클래스이다.
*/
/*==============================================*/
#include <vector>
#include "DXUtil.h"
#include "SimpleMath.h"
using namespace std;

using namespace DirectX::SimpleMath;


class DXSprite
{
public:
	struct FrameInfo
	{
		int frameX;
		int frameY;
		int frameWidth;
		int frameHeight;
	};

public:
	enum SPRITE_KIND
	{
		KIND_ONCE,	// 단일 이미지
		KIND_MULTI,	// 다중 스프라이트 이미지
		KIND_SELF,	// 단일 스프라이트 이미지
	};

public:
	DXSprite ();
	~DXSprite ();

public:
	void Init ( SPRITE_KIND spriteKind, int delay = 0 );
	void InitSelfImage ( int delay, int maxFrameX, int maxFrameY );
//	void Render ( float x, float y, bool isFlip = false );
//	void Render ( float x, float y, float scaleX, float scaleY, bool isFlip = false );
	void Render ( float x, float y );
	void SetFixSize ( float width, float height );
	void AddImage (wstring imageKey);
	void Load ( const wchar_t * file );
	void Load ( vector<wstring> vecFile );
	void AddFrame ( FrameInfo frameImage );

private:
	void Play ();

public:
	void Stop () { m_isStop = true; };
	void Resume () { m_isStop = false; }
	void SetFrame (int currentFrameX, int currentFrameY) {
		m_CurrentFrameX = currentFrameX;
		m_CurrentFrameY = currentFrameY;
	}
	void SetFrame ( int currentFrameOfMulti ) {
		m_CurrnetFrameOfMulti = currentFrameOfMulti;
	}
	void StopAndFixFrame ( int currentFrameX, int currentFrameY )
	{
		SetFrame ( currentFrameX, currentFrameY );
		m_isStop = true;
	}

private:
	// 자가 스프라이트용 벡터
	vector<FrameInfo>	m_vecFrameInfo;

	// 다중 스프라이트용 벡터
	vector<ID3D11Resource*>			  m_vecResource;
	vector<ID3D11ShaderResourceView*> m_vecTexture;

	// 애니메이션 
	int m_CurrnetFrameOfMulti;
	int m_MaxFrameOfMulti;

	int m_CurrentFrameX;
	int m_CurrentFrameY;
	int m_MaxFrameX;
	int m_MaxFrameY;

	int m_Delay;
	DWORD m_Time;

	UINT m_Width, m_Height;
	bool m_isOncePlay;
	bool m_isChangedFrame;
	bool m_isStop;

	float  m_Angle;
	DirectX::SimpleMath::Vector2  m_Origin;
	Vector2 m_Scale;
	RECT    m_SourceRect;

	SPRITE_KIND m_SpriteKind;

public:
	UINT GetWidth () { return m_Width; }
	UINT GetHeight () { return m_Height; }

	bool IsOncePlay () { return m_isOncePlay; }
	int GetCurrentFrameOfMulti () { return m_CurrnetFrameOfMulti; }
	bool IsChangedFrame ( int frame ) { return m_CurrnetFrameOfMulti == frame && m_isChangedFrame; }
	void Reset () { m_isOncePlay = FALSE; m_CurrnetFrameOfMulti = 0; }
	int GetMaxFrameOfMulti () { return m_MaxFrameOfMulti; }
	void SetCurrentFrameOfMulti ( int frame ) { m_CurrnetFrameOfMulti = frame; }
	void SetAngle ( float angle ) { m_Angle = angle; }
	void SetSize ( float sx, float sy ) { m_Scale = Vector2(sx, sy); }
	void SetWidth ( float width ) { m_Width = width; }
	void SetHeight ( float height ) { m_Height = height; }


	int GetFrameX() { return m_CurrentFrameX; }
	void SetFrameX(int x) { m_CurrentFrameX = x; }
	int GetFrameY() { return m_CurrentFrameY; }
	void SetFrameY(int y) { m_CurrentFrameY = y; }
	int GetMaxFrameX() { return m_MaxFrameX; }
	int GetMaxFrameY() { return m_MaxFrameY; }

	void SetOrigin(float x, float y) { m_Origin = Vector2( x,y ); }
	void SetCenterOrigin() { m_Origin = Vector2(m_Width/2,m_Height/2); }

	float GetAngle() { return m_Angle; }
};

