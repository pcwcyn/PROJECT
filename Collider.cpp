#include "stdafx.h"

#include "Collider.h"

#include "SpriteManager.h"
#include "DXSprite.h"

#include <windows.h>
#include "DXApp.h"

Collider::Collider ()	: 
	m_X(0),
	m_Y(0),
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

bool Collider::Init ()
{
	m_IsEnable = false;
	return true;
}

void Collider::Init ( float x, float y, int width, int height )
{
	m_Width = width;
	m_Height = height;
	m_Rc.left = m_X = x;
	m_Rc.top = m_Y = y;
	m_Rc.right = m_Rc.left + width;
	m_Rc.bottom = m_Rc.top + height;
}

void Collider::Init ( int width, int height )
{

	m_IsEnable = true;
	m_Width = width;
	m_Height = height;
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

	m_X = x;
	m_Y = y;

	PositionToRect ();
}

void Collider::Render ()
{
	if (!m_IsEnable) return;

	SPRITEMANAGER->FindSprite ( "컬라이더" )->SetFixSize ( m_Width, m_Height );
	SPRITEMANAGER->FindSprite ( "컬라이더" )->Render ( m_X, m_Y );
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
		m_Rc.top < otherRc.bottom && m_Rc.bottom > otherRc.top;
}

void Collider::PositionToRect ()
{
	m_Rc.left = m_X;
	m_Rc.right = m_X + m_Width;
	m_Rc.top = m_Y;
	m_Rc.bottom = m_Y + m_Height;
}

void Collider::Rectangle ( float left, float top, float right, float bottom )
{
	SPRITEMANAGER->FindSprite ( "컬라이더" )->SetFixSize ( right - left, bottom - top );
	SPRITEMANAGER->FindSprite ( "컬라이더" )->Render ( left, top );
}

