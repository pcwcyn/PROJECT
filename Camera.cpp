#include "stdafx.h"
#include "Camera.h"


Camera::Camera ()
{
}


Camera::~Camera ()
{
}

void Camera::Init ( float x, float y, float z, float screenTargetX, float screenTargetY )
{
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_ScreenTargetX = screenTargetX;
	m_ScreenTargetY = screenTargetY;
	m_Speed = 5.f;
}

void Camera::Update ()
{
	if (KEYMANAGER->isStayKeyDown ( 'A' ))
	{
		m_X -= m_Speed;
	}
	if (KEYMANAGER->isStayKeyDown ( 'D' ))
	{
		m_X += m_Speed;
	}
	if (KEYMANAGER->isStayKeyDown ( 'W' ))
	{
		m_Y -= m_Speed;
	}
	if (KEYMANAGER->isStayKeyDown ( 'S' ))
	{
		m_Y += m_Speed;
	}
	if (KEYMANAGER->isStayKeyDown ( VK_F4 ))
	{
		if (m_Z <= CAMERA_MIN_Z)
			m_Z = CAMERA_MIN_Z;
		else
			m_Z -= m_Speed;
	}
	if (KEYMANAGER->isStayKeyDown ( VK_F5 ))
	{
		if (m_Z >= CAMERA_MAX_Z)
			m_Z = CAMERA_MAX_Z;
		else
			m_Z += m_Speed;
	}

	if (m_X < 0)
		m_X = 0;
	if (m_X > m_WorldWidth)
		m_X = m_WorldWidth;

	if (m_Y < 0)
		m_Y = 0;
	if (m_Y > m_WorldWidth)
		m_X = m_WorldWidth;

	m_WorldTargetX = m_X + m_ScreenTargetX;
	m_WorldTargetY = m_Y + m_ScreenTargetY;
}

void Camera::SetWorld ( float width, float height )
{
	m_WorldWidth = width;
	m_WorldHeight = height;
}

void Camera::WorldToScreen ( Object* object )
{
	// 카메라 중심점 타겟으로부터 오브젝트 세계 좌표에 대한 연산
	object->SetScreenX( object->GetWorldX () - m_WorldTargetX + m_ScreenTargetX );
	object->SetScreenY( object->GetWorldY () - m_WorldTargetY + m_ScreenTargetY );

	//// Z 좌표
	//object->SetScreenScaleX ( object->GetScaleX () * m_Z / MAX_SCALE );
	//object->SetScreenScaleY ( object->GetScaleY () * m_Z / MAX_SCALE );
	//object->GetSprite ()->SetSize ( object->GetScreenScaleX (), object->GetScreenScaleY() );
}

void Camera::WorldToScreen ( float * screenX, float * screenY, float worldX, float worldY )
{
	// 카메라 중심점 타겟으로부터 오브젝트 세계 좌표에 대한 연산
	*screenX =  ( worldX - m_WorldTargetX + m_ScreenTargetX );
	*screenY = ( worldY - m_WorldTargetY + m_ScreenTargetY );
}
