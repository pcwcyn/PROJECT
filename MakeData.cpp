#include "stdafx.h"
#include "MakeData.h"

#include "SpriteManager.h"

void MakeData ()
{
	// ��������Ʈ

	SPRITEMANAGER->MakeSpriteToSelfImage("����Ʈ1", "image/effect/effect1.png", 5, 1,  10);

	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾�Ӹ�", "image/player/p_head.png", 3, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾���", "image/player/p_arm.png", 5, 1,  10);
	SPRITEMANAGER->MakeSpriteToOnceImage("�÷��̾���2", "image/player/p_arm2.png");
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾�����", "image/player/p_jump.png", 2, 1,  1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾��", "image/player/p_body.png", 6, 1,  1000);

	SPRITEMANAGER->MakeSpriteToSelfImage("�����۹���", "image/item/i_weapon.png", 4, 1,  1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�����۰���", "image/item/i_armor.png", 4, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("���������", "image/item/i_helmet.png", 4, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�����۹���", "image/item/i_oile.png", 4, 1, 1000);

	SPRITEMANAGER->MakeSpriteToOnceImage("�ö��̴�����", "image/collider/rect_r.png");
	SPRITEMANAGER->MakeSpriteToOnceImage ( "�ö��̴��Ķ�", "image/collider/rect_g.png" );
	SPRITEMANAGER->MakeSpriteToOnceImage ( "�ö��̴��ʷ�", "image/collider/rect_b.png" );

	// ����Ʈ
	//EFFECTMANAGER->MakeEffect ( "����Ʈ1", "����Ʈ1", Effect::KIND_REPEAT, Collider());
}

