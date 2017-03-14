#pragma once

#include "DXSprite.h"
#include "Collider.h"

class Object
{
protected:
	float	 m_WorldX;	  // 세계 좌표  X	
	float	 m_WorldY;	  // 세계 좌표 Y
	float	 m_ScreenX;	  // 화면 좌표 X
	float	 m_ScreenY;	  // 화면 좌표 Y
	float	 m_Width;     // 오브젝트 폭
	float	 m_Height;    // 오브젝트 높이
	bool     m_isDestroy; // 오브젝트 파괴 여부
	DXSprite m_Sprite;	  // 스프라이트
	Collider m_Collider;  // 컬라이더

public:	// GETTER
	float GetWorldX () { return m_WorldX; }
	float GetWorldY () { return m_WorldY; }
	float GetWidth () { return m_Width; }
	float GetHeight () { return m_Height; }
	bool  IsDestroy () { return m_isDestroy; }

public: // SETTER
	void SetWorldX ( float x ) { m_WorldX = x; }
	void SetWorldY ( float y ) { m_WorldY = y; }
	void SetScreenX ( float x ) { m_ScreenX = x; }
	void SetScreenY ( float y ) { m_ScreenY = y; }
	void SetWidth ( float width ) { m_Width = width; }
	void SetHeight ( float height ) { m_Height = height; }

public: // FUNCTION

	// 오브젝트 자기 자신을 파괴한다.
	void Destroy () { m_isDestroy = true; }

public: // VIRTUAL
	virtual void Init ( string spriteKey );
	virtual void Init ( string spriteKey, float x, float y );
	virtual void Update () = 0;
	virtual void Render () = 0;

public:
	Object ();
	virtual ~Object ();

};

