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
	// ���ӿ� �ʿ��� �����͸� �����Ѵ�
	MakeData ();

	// �����͸� ��� �ε��ϸ� �� ����
	SCENEMANAGER->ChangeScene ( "���ΰ���" );
}
