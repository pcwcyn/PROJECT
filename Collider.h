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
	void Init ( float x, float y, int width, int height, COLLIDER_COLOR color = COLOR_RED );
	void Update ();
	void Update ( float x, float y );
	void Render ( );

public:
	// �浹 Ȱ��ȭ
	void Enable ();

	// �浹 ��Ȱ��ȭ
	void Disable ();

	// ���콺 �浹
	BOOL PtInRect ();

	// ���� ��ü�� ���� �浹 ó��
	bool RectInRect ( DXRECT rc );
	bool RectInRect ( Collider* collider );

	// �̵����� ��ü�� ���� �浹 ó��
	bool RectInRect ( DXRECT rc, float moveX );

	//��ȣǥ �浹üũ �����Ҷ�
	bool RectLandingRect(Collider* collider, float Width, float Height,float GravityPlus);  

	//��Ʈ �����ֳ� üũ
	bool RectOntheRect(Collider* collider, float Width);
private:
	void PositionToRect ();

private:
	bool m_IsEnable;
	unsigned int m_Width;
	unsigned int m_Height;
	DXRECT m_Rc;
	float m_ScreenX;
	float m_ScreenY;
	float m_WorldX;
	float m_WorldY;
	COLLIDER_COLOR m_Color;

public:
	bool IsEnable () { return m_IsEnable; }
	DXRECT GetRect () { return m_Rc; }
	float GetLeft () { return m_Rc.left; }
	float GetTop () { return m_Rc.top; }
	float GetRight () { return m_Rc.right; }
	float GetBottom () { return m_Rc.bottom; }

public:
	static void Rectangle (float left, float top, float right, float bottom);
};

