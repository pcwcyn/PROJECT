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
	Collider ();
	~Collider ();

public:
	bool Init ();
	void Init ( float x, float y, int width, int height );
	void Init (int width, int height);
	void Update ();
	void Update ( float x, float y );
	void Render ();

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

private:
	void PositionToRect ();

private:
	bool m_IsEnable;
	unsigned int m_Width;
	unsigned int m_Height;
	DXRECT m_Rc;
	float m_X;
	float m_Y;

public:
	bool IsEnable () { return m_IsEnable; }
	DXRECT GetRect () { return m_Rc; }
	float GetLeft () { return m_Rc.left; }
	float GetTop () { return m_Rc.top; }
	float GetRight () { return m_Rc.right; }
	float GetBottom () { return m_Rc.bottom; }

};

