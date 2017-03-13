#include "stdafx.h"
#include "Object.h"


Object::Object ()
{
	m_WorldX = 0.f;
	m_WorldY = 0.f;
	m_Width = 0;
	m_Height = 0;
	m_isDestroy = false;
}

void Object::Init ( string spriteKey )
{
	m_Sprite = SPRITEMANAGER->InsertSpriteData ( spriteKey );
}

void Object::Init ( string spriteKey, float x, float y )
{
	m_Sprite = SPRITEMANAGER->InsertSpriteData ( spriteKey );
	m_WorldX = x;
	m_WorldY = y;
}

Object::~Object ()
{
}