#include "stdafx.h"
#include "Effect.h"


Effect::Effect ()
{
}


Effect::~Effect ()
{
}


void Effect::Init ( string spriteKey, EFFECT_KIND effectKind )
{
	m_Sprite = SPRITEMANAGER->InsertSpriteData(spriteKey);
	m_Width = m_Sprite.GetWidth ();
	m_Height = m_Sprite.GetHeight ();
	m_effectKind = effectKind;
}

void Effect::Init ( string spriteKey, EFFECT_KIND effectKind, Collider collider )
{
	m_Sprite	 = SPRITEMANAGER->InsertSpriteData ( spriteKey );
	m_Width = m_Sprite.GetWidth ();
	m_Height = m_Sprite.GetHeight ();
	m_Collider   = collider;
	m_effectKind = effectKind;
	m_Collider.Init ( m_Width, m_Height );
	m_Collider.Enable ();
}

void Effect::Update ()
{
	if (m_Collider.IsEnable ())
		m_Collider.Update (m_X, m_Y);
}

void Effect::Render ()
{
	m_Sprite.Render ( m_X, m_Y );

	if (m_Collider.IsEnable ())
		m_Collider.Render ();
}
