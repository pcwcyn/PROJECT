#include "stdafx.h"
#include "MakeData.h"

#include "SpriteManager.h"

void MakeData ()
{
	// 스프라이트

	SPRITEMANAGER->MakeSpriteToSelfImage("이펙트1", "image/effect/effect1.png", 5, 1,  10);

	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어머리", "image/player/p_head.png", 2, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어팔", "image/player/p_arm.png", 11, 1,  10);
	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어팔_검", "image/player/p_arm_sword.png",8,1,10);
	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어팔_창", "image/player/p_arm_lance.png", 10, 1, 10);
	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어팔_지팡이", "image/player/p_arm_wand.png", 8, 1, 10);
	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어점프", "image/player/p_jump.png", 2, 1,  1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("플레이어몸", "image/player/p_body.png", 6, 1,  1000);
	SPRITEMANAGER->MakeSpriteToOnceImage("플레이어다운", "image/player/p_down.png");

	SPRITEMANAGER->MakeSpriteToSelfImage("아이템무기", "image/item/i_weapon.png", 4, 1,  1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("아이템갑옷", "image/item/i_armor.png", 4, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("아이템헬멧", "image/item/i_helmet.png", 4, 1, 1000);
	SPRITEMANAGER->MakeSpriteToSelfImage("아이템물약", "image/item/i_oile.png", 4, 1, 1000);

	SPRITEMANAGER->MakeSpriteToOnceImage("컬라이더", "image/collider/rect.png");

	// 이펙트
	//EFFECTMANAGER->MakeEffect ( "이펙트1", "이펙트1", Effect::KIND_REPEAT, Collider());
}

