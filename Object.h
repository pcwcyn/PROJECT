#pragma once

#include "DXSprite.h"
#include "Collider.h"

class Object
{
protected:
	float	 m_WorldX;	  // ���� ��ǥ  X	
	float	 m_WorldY;	  // ���� ��ǥ Y
	float	 m_ScreenX;	  // ȭ�� ��ǥ X
	float	 m_ScreenY;	  // ȭ�� ��ǥ Y
	float	 m_Width;     // ������Ʈ ��
	float	 m_Height;    // ������Ʈ ����
	bool     m_isDestroy; // ������Ʈ �ı� ����
	DXSprite m_Sprite;	  // ��������Ʈ
	Collider m_Collider;  // �ö��̴�

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

	// ������Ʈ �ڱ� �ڽ��� �ı��Ѵ�.
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

