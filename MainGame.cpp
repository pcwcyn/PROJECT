#include "stdafx.h"

#include "MainGame.h"
#include "DXApp.h"

void MainGame::Init ()
{
	PLAYER->Init ();
}

void MainGame::Update ()
{
	PLAYER->Update ();
}

void MainGame::Render ()
{
	PLAYER->Render ();
}
