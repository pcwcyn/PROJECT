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

	// ����Ʈ�� �����.
	void MakeEffect ( string effectKey, string spriteKey, Effect::EFFECT_KIND effectKind );
	void MakeEffect ( string effectKey, string spriteKey, Effect::EFFECT_KIND effectKind, Collider collider );

	// ����Ʈ�� �����Ѵ�.
	void CreateEffect ( string effectKey, float x, float y );

	// Ŭ�п� �ִ� ����Ʈ �����͸� �����Ѵ�.
	Effect InsertEffectData ( string effectKey );

private:
	map<string, Effect> m_EffectClones;
	vector<Effect>		m_EffectList;
};

