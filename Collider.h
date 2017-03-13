#pragma once

struct DXRECT
{
	float left;
	float top;
	float right;
	float bottom;
};

class Collider
{
public:
	enum COLLIDER_COLOR
	{
		COLOR_RED,
		COLOR_BLUE,
		COLOR_GREEN,
	};
public:
	Collider ();
	~Collider ();

public:
	bool Init ();
	void Init ( float x, float y, int width, int height );
	void Init (int width, int height);
	void Update ();
	void Update ( float x, float y );
	void Render ( COLLIDER_COLOR color = COLOR_RED );

public:
	// 충돌 활성화
	void Enable ();

	// 충돌 비활성화
	void Disable ();

	// 마우스 충돌
	BOOL PtInRect ();

	// 고정 물체에 대한 충돌 처리
	bool RectInRect ( DXRECT rc );
	bool RectInRect ( Collider* collider );

	// 이동중인 물체에 대한 충돌 처리
	bool RectInRect ( DXRECT rc, float moveX );

	//은호표 충돌체크 착지할때
	bool RectLandingRect(Collider* collider, float Width, float Height,float GravityPlus);  

	//렉트 위에있나 체크
	bool RectOntheRect(Collider* collider, float Width);
private:
	void PositionToRect ();

private:
	bool m_IsEnable;
	unsigned int m_Width;
	unsigned int m_Height;
	DXRECT m_Rc;
	float m_WorldX;
	float m_WorldY;

public:
	bool IsEnable () { return m_IsEnable; }
	DXRECT GetRect () { return m_Rc; }
	float GetLeft () { return m_Rc.left; }
	float GetTop () { return m_Rc.top; }
	float GetRight () { return m_Rc.right; }
	float GetBottom () { return m_Rc.bottom; }

<<<<<<< HEAD
public:
	static void Rectangle (float left, float top, float right, float bottom);
=======
//<<<<<<< HEAD
//=======
//
//>>>>>>> origin/master
>>>>>>> origin/master
};

