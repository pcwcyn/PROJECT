#pragma once

#include "Object.h"
#include "Effect.h"

class EffectManager : public Singleton<EffectManager>
{
public:
	EffectManager ();
	~EffectManager ();

public:
	void Init ();
	void Update ();
	void Render ();

	// 이펙트를 만든다.
	void MakeEffect ( string effectKey, string spriteKey, Effect::EFFECT_KIND effectKind );
	void MakeEffect ( string effectKey, string spriteKey, Effect::EFFECT_KIND effectKind, Collider collider );

	// 이펙트를 생성한다.
	void CreateEffect ( string effectKey, float x, float y );

	// 클론에 있는 이펙트 데이터를 복사한다.
	Effect InsertEffectData ( string effectKey );

private:
	map<string, Effect> m_EffectClones;
	vector<Effect>		m_EffectList;
};

