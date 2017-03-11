#include "stdafx.h"
#include "MakeData.h"

#include "SpriteManager.h"

void MakeData ()
{
	// 스프라이트
	SPRITEMANAGER->MakeSpriteToOnceImage ( "컬라이더", "image/collider/rect.png" );
	SPRITEMANAGER->MakeSpriteToSelfImage ( "이펙트1", "image/effect/effect1.png", 5, 1, 40, 39, 10 );

	// 이펙트
	EFFECTMANAGER->MakeEffect ( "이펙트1", "이펙트1", Effect::KIND_REPEAT, Collider());
}
// 조명성
// ㅎㅇ 테스트
