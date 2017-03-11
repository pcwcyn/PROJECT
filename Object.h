#pragma once

#include "DXSprite.h"
#include "Collider.h"

class Object
{
protected:
	float	 m_X;	      // ��ġ X	
	float	 m_Y;	      // ��ġ Y
	float	 m_Width;     // ������Ʈ ��
	float	 m_Height;    // ������Ʈ ����
	bool     m_isDestroy; // ������Ʈ �ı� ����
	DXSprite m_Sprite;	  // ��������Ʈ
	Collider m_Collider;  // �ö��̴�

public:	// GETTER
	float GetX () { return m_X; }
	float GetY () { return m_Y; }
	float GetWidth () { return m_Width; }
	float GetHeight () { return m_Height; }
	bool  IsDestroy () { return m_isDestroy; }

public: // SETTER
	void SetX ( float x ) { m_X = x; }
	void SetY ( float y ) { m_Y = y; }
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

