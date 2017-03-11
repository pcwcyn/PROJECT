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
	void Init ( string spriteKey, EFFECT_KIND effectKind );	// ���浹�� ����Ʈ �ʱ�ȭ
	void Init ( string spriteKey, EFFECT_KIND effectKind, Collider collider); // �浹�� ����Ʈ �ʱ�ȭ
	void Update ();
	void Render ();

public:
	Effect ();
	~Effect ();

};

