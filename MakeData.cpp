#include "stdafx.h"
#include "MakeData.h"

#include "SpriteManager.h"

void MakeData ()
{
	// ��������Ʈ
	SPRITEMANAGER->MakeSpriteToOnceImage ( "�ö��̴�", "image/collider/rect.png" );
	SPRITEMANAGER->MakeSpriteToSelfImage ( "����Ʈ1", "image/effect/effect1.png", 5, 1, 40, 39, 10 );

	// ����Ʈ
	EFFECTMANAGER->MakeEffect ( "����Ʈ1", "����Ʈ1", Effect::KIND_REPEAT, Collider());
}
// ����
// ���� �׽�Ʈ
