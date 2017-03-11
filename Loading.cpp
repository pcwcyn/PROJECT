#include "stdafx.h"
#include "Loading.h"
#include "MakeData.h"


Loading::Loading ()
{
}


Loading::~Loading ()
{
}

void Loading::Update ()
{
	// 게임에 필요한 데이터를 제작한다
	MakeData ();

	// 데이터를 모두 로드하면 씬 변경
	SCENEMANAGER->ChangeScene ( "메인게임" );
}
