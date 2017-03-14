#include "stdafx.h"
#include "EffectManager.h"


EffectManager::EffectManager ()
{
}


EffectManager::~EffectManager ()
{
}

void EffectManager::Init ()
{
	CreateEffect ( "¿Ã∆Â∆Æ1", WIN_WIDTH / 2, WIN_HEIGHT / 2 );
}

void EffectManager::Update ()
{
	for (vector<Effect>::iterator iter = m_EffectList.begin ();
		iter != m_EffectList.end ();)
	{
		if ( ( *iter ).IsDestroy() )
		{
			iter = m_EffectList.erase ( iter );
		}
		else
		{
			( *iter ).Update ();
			++iter;
		}
	}
}

void EffectManager::Render ()
{
	for (vector<Effect>::iterator iter = m_EffectList.begin ();
		iter != m_EffectList.end ();)
	{
		if (( *iter ).IsDestroy ())
		{
			iter = m_EffectList.erase ( iter );
		}
		else
		{
			( *iter ).Render ();
			++iter;
		}
	}
}

void EffectManager::MakeEffect ( string effectKey, string spriteKey, Effect::EFFECT_KIND effectKind )
{
	Effect effect;
	effect.Init ( spriteKey, effectKind );

	m_EffectClones.insert ( make_pair ( effectKey, effect ) );
}

void EffectManager::MakeEffect ( string effectKey, string spriteKey, Effect::EFFECT_KIND effectKind, Collider collider )
{
	Effect effect;
	effect.Init ( spriteKey, effectKind, collider );

	m_EffectClones.insert ( make_pair ( effectKey, effect ) );
}

void EffectManager::CreateEffect ( string effectKey, float x, float y )
{
	Effect effect = InsertEffectData ( effectKey );
	effect.SetWorldX ( x );
	effect.SetWorldY ( y );

	m_EffectList.push_back(effect);
}

Effect EffectManager::InsertEffectData ( string effectKey )
{
	return m_EffectClones.find ( effectKey )->second;
}
