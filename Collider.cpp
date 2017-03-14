#include "stdafx.h"

#include "Collider.h"

#include "SpriteManager.h"
#include "DXSprite.h"

#include <windows.h>
#include "DXApp.h"

Collider::Collider ()	: 
	m_WorldX(0),
	m_WorldY(0),
	m_Width(0),
	m_Height(0),
	m_IsEnable(false)
{
}


Collider::~Collider ()
{
	//delete m_pSprite;
	//m_pSprite = NULL;
}

void Collider::Init ( float x, float y, int width, int height, COLLIDER_COLOR color )
{
	m_IsEnable = true;
	m_Width = width;
	m_Height = height;
	m_Rc.left = m_WorldX = x;
	m_Rc.top = m_WorldY = y;
	m_Rc.right = m_Rc.left + width;
	m_Rc.bottom = m_Rc.top + height;

	m_Color = color;
}

void Collider::Enable ()
{
	m_IsEnable = TRUE;
}

void Collider::Disable ()
{
	m_IsEnable = FALSE;
}

BOOL Collider::PtInRect ()
{
	POINT pt;

	RECT rc;
	rc.bottom = (LONG)m_Rc.bottom;
	rc.left = (LONG)m_Rc.left;
	rc.right = (LONG)m_Rc.right;
	rc.top = (LONG)m_Rc.top;
	GetCursorPos ( &pt );
	ScreenToClient ( DXApp::GetInst ()->GetHwnd (), &pt );

	return ::PtInRect ( &rc, pt );
}

void Collider::Update ()
{
	if (!m_IsEnable) return;

	PositionToRect ();
}

void Collider::Update ( float x, float y )
{
	if (!m_IsEnable) return;

	m_WorldX = x;
	m_WorldY = y;

	PositionToRect ();
}

void Collider::Render ()
{
	if (!Camera::m_isRenderingCollider) return;

	CAMERA->WorldToScreen ( &m_ScreenX, &m_ScreenY, m_WorldX, m_WorldY );

	if (!m_IsEnable) return;

	string str;
	switch (m_Color)
	{
	case COLOR_RED:
		str = "컬라이더빨강";
		break;
	case COLOR_BLUE:
		str = "컬라이더파랑";
		break;
	case COLOR_GREEN:
		str = "컬라이더초록";
		break;
	}

	SPRITEMANAGER->FindSprite ( str )->SetFixSize ( m_Width, m_Height );
	SPRITEMANAGER->FindSprite ( str )->Render ( m_ScreenX, m_ScreenY );
}

bool Collider::RectInRect ( DXRECT otherRc )
{
	if (!m_IsEnable) return false;

	return m_Rc.left < otherRc.right && m_Rc.right > otherRc.left &&
		m_Rc.top < otherRc.bottom && m_Rc.bottom > otherRc.top;
}

bool Collider::RectInRect ( Collider * collider )
{
	if (!m_IsEnable) return false;

	DXRECT otherRc = collider->GetRect ();

	return m_Rc.left < otherRc.right && m_Rc.right > otherRc.left &&
		m_Rc.top < otherRc.bottom && m_Rc.bottom > otherRc.top;
}

bool Collider::RectInRect ( DXRECT otherRc, float moveX )
{
	if (!m_IsEnable) return false;

	return m_Rc.left + moveX < otherRc.right && m_Rc.right + moveX > otherRc.left &&
		m_Rc.top < otherRc.bottom && m_Rc.bottom > otherRc.top&&moveX>0;
}


bool Collider::RectLandingRect(Collider * collider, float Width, float Height,float GravityPlus)
{
	if (!m_IsEnable)	return false;
	if (m_Rc.left>collider->GetLeft() - Width / 2 && m_Rc.right<collider->GetRight() + Width / 2)
	{
		return collider->GetTop() - Height > m_Rc.top&&collider->GetTop() - Height - GravityPlus <= m_Rc.top;
	}
	return false;

}

bool Collider::RectOntheRect(Collider * collider, float Width)
{
	if (!m_IsEnable)	return false;
	if (m_Rc.left>collider->GetLeft() - Width / 2 && m_Rc.right<collider->GetRight() + Width / 2)
	{
		return m_Rc.bottom <= collider->GetTop();
	}
	return false;
}

void Collider::PositionToRect ()
{
	m_Rc.left = m_WorldX;
	m_Rc.right = m_WorldX + m_Width;
	m_Rc.top = m_WorldY;
	m_Rc.bottom = m_WorldY + m_Height;
}

//void Collider::Rectangle ( float left, float top, float right, float bottom )
//{
//	SPRITEMANAGER->FindSprite ( "컬라이더" )->SetFixSize ( right - left, bottom - top );
//	SPRITEMANAGER->FindSprite ( "컬라이더" )->Render ( left, top );
//}

