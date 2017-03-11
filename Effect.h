#pragma once
#include "Object.h"
class Effect :
	public Object
{
public:
	enum EFFECT_KIND { KIND_ONCE, KIND_REPEAT };

private:
	EFFECT_KIND m_effectKind;

public:
	void Init ( string spriteKey, EFFECT_KIND effectKind );	// 비충돌형 이펙트 초기화
	void Init ( string spriteKey, EFFECT_KIND effectKind, Collider collider); // 충돌형 이펙트 초기화
	void Update ();
	void Render ();

public:
	Effect ();
	~Effect ();

};

