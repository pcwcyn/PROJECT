
#include "stdafx.h"
#include "Camera.h"
#include "DXApp.h"

bool Camera::m_isRenderingCollider = true;

Camera::Camera ()
{
	m_LinkObject = NULL;
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
	DXApp::GetInst ()->DrawDXText ( 10, 10, L"F1 Key Rendering Collider On/Off " );

	// 카메라와 오브젝트가 연결되어 있다면
	if (m_LinkObject)
	{
		//카메라의 위치는 곧 오브젝트의 세계 좌표가 된다
		m_X = m_LinkObject->GetWorldX () - m_ScreenTargetX;
		m_Y = m_LinkObject->GetWorldY () - m_ScreenTargetY;
	}
	// 카메라 직접 이동
	else
	{
		if (KEYMANAGER->isOnceKeyDown ( VK_F1 ))
		{
			m_isRenderingCollider = !m_isRenderingCollider;
		}

		if (KEYMANAGER->isStayKeyDown ( VK_NUMPAD4 ))
		{
			m_X -= m_Speed;
		}
		if (KEYMANAGER->isStayKeyDown ( VK_NUMPAD6 ))
		{
			m_X += m_Speed;
		}
		if (KEYMANAGER->isStayKeyDown ( VK_NUMPAD8 ))
		{
			m_Y -= m_Speed;
		}
		if (KEYMANAGER->isStayKeyDown ( VK_NUMPAD2 ))
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
	}

	// 카메라가 화면을 넘어가지 않게 방지함
	if (m_X < 0)
		m_X = 0;
	if (m_X > m_WorldWidth)
		m_X = m_WorldWidth;

	if (m_Y < 0)
		m_Y = 0;
	if (m_Y > m_WorldHeight)
		m_X = m_WorldHeight;

	// 카메라가 찍는 세계의 지점을 구함
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
	object->SetScreenX ( object->GetWorldX () - m_WorldTargetX + m_ScreenTargetX );
	object->SetScreenY ( object->GetWorldY () - m_WorldTargetY + m_ScreenTargetY );
}

void Camera::WorldToScreen ( float * screenX, float * screenY, float worldX, float worldY )
{
	*screenX = ( worldX - m_WorldTargetX + m_ScreenTargetX );
	*screenY = ( worldY - m_WorldTargetY + m_ScreenTargetY );
}

void Camera::LinkObject ( Object * object )
{
	m_LinkObject = object;
}
