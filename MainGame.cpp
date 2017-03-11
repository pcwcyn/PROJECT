#include "stdafx.h"

#include "MainGame.h"
#include "DXApp.h"

void MainGame::Init ()
{
	EFFECTMANAGER->Init ();
}

void MainGame::Update ()
{
	EFFECTMANAGER->Update ();
}

void MainGame::Render ()
{
	EFFECTMANAGER->Render ();
}
