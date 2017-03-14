#pragma once

/*==============================================*/
/*
	DXSprite

	�̹��� ������ �����԰� ���ÿ�, ���� �׸��� ���� ����� 
	����� �� �ִ� Ŭ�����̴�.
*/
/*==============================================*/
#include <vector>
#include "DXUtil.h"
#include "SimpleMath.h"
#include "SpriteBatch.h"
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
		KIND_ONCE,	// ���� �̹���
		KIND_MULTI,	// ���� ��������Ʈ �̹���
		KIND_SELF,	// ���� ��������Ʈ �̹���
	};

public:
	DXSprite ();
	~DXSprite ();

public:
	void Init ( SPRITE_KIND spriteKind, int delay = 0 );
	void InitSelfImage ( int delay, int maxFrameX, int maxFrameY );
	void XFlip ();
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
	// �ڰ� ��������Ʈ�� ����
	vector<FrameInfo>	m_vecFrameInfo;

	// ���� ��������Ʈ�� ����
	vector<ID3D11Resource*>			  m_vecResource;
	vector<ID3D11ShaderResourceView*> m_vecTexture;

	// �ִϸ��̼� 
	int m_CurrnetFrameOfMulti;
	int m_MaxFrameOfMulti;

	int m_CurrentFrameX;
	int m_CurrentFrameY;
	int m_MaxFrameX;
	int m_MaxFrameY;

	int m_Delay;
	DWORD m_Time;

	float m_TransWidth;
	float m_TransHeight;
	float m_CenterOffsetX;
	float m_CenterOffsetY;

	UINT m_Width, m_Height;
	bool m_isOncePlay;
	bool m_isChangedFrame;
	bool m_isStop;

	float  m_Angle;
	DirectX::SimpleMath::Vector2  m_Origin;
	Vector2 m_Scale;
	RECT    m_SourceRect;

	SPRITE_KIND m_SpriteKind;

	DirectX::SpriteEffects m_SpriteEffect;

public:
	UINT GetWidth () { return m_Width; }
	UINT GetHeight () { return m_Height; }
	ID3D11Resource* GetResource () { return m_vecResource[0]; }
	bool IsOncePlay () { return m_isOncePlay; }
	int GetCurrentFrameOfMulti () { return m_CurrnetFrameOfMulti; }
	bool IsChangedFrame ( int frame ) { return m_CurrnetFrameOfMulti == frame && m_isChangedFrame; }
	void Reset () { m_isOncePlay = FALSE; m_CurrnetFrameOfMulti = 0; }
	int GetMaxFrameOfMulti () { return m_MaxFrameOfMulti; }
	void SetCurrentFrameOfMulti ( int frame ) { m_CurrnetFrameOfMulti = frame; }
	void Rotate ( float degree ) { m_Angle = degree * 3.141592 / 180.f; }
	void SetSize ( float sx, float sy ) { m_Scale = Vector2 ( sx, sy ); m_TransWidth = m_Width * sx; m_TransHeight = m_Height * sy; }
	void SetWidth ( float width ) { m_Width = width; }
	void SetHeight ( float height ) { m_Height = height; }
	void SetCenterOffset ( float offsetX, float offsetY ) { m_CenterOffsetX = offsetX; m_CenterOffsetY = offsetY; }

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

