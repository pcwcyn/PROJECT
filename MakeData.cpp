#include "stdafx.h"
#include "MakeData.h"

#include "SpriteManager.h"

void MakeData ()
{
	// ��������Ʈ

	SPRITEMANAGER->MakeSpriteToSelfImage("����Ʈ1", "image/effect/effect1.png", 5, 1,  10);

	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾�Ӹ�", "image/player/p_head.png", 2, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾���", "image/player/p_arm.png", 11, 1,  10);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾���_��", "image/player/p_arm_sword.png",8,1,10);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾���_â", "image/player/p_arm_lance.png", 10, 1, 10);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾���_������", "image/player/p_arm_wand.png", 8, 1, 10);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾�����", "image/player/p_jump.png", 2, 1,  1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�÷��̾��", "image/player/p_body.png", 6, 1,  1000);
	SPRITEMANAGER->MakeSpriteToOnceImage("�÷��̾�ٿ�", "image/player/p_down.png");

	SPRITEMANAGER->MakeSpriteToSelfImage("�����۹���", "image/item/i_weapon.png", 4, 1,  1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�����۰���", "image/item/i_armor.png", 4, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("���������", "image/item/i_helmet.png", 4, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("�����۹���", "image/item/i_oile.png", 4, 1, 1000);

	SPRITEMANAGER->MakeSpriteToOnceImage("�ö��̴�", "image/collider/rect.png");

	// ����Ʈ
	//EFFECTMANAGER->MakeEffect ( "����Ʈ1", "����Ʈ1", Effect::KIND_REPEAT, Collider());
}

