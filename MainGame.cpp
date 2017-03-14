#include "stdafx.h"

#include "MainGame.h"
#include "DXApp.h"

void MainGame::Init ()
{
	m_Collider.Init ( 200, 100, 200, 200, Collider::COLOR_GREEN );

	CAMERA->Init ( 0, 0, 100, WIN_WIDTH / 2, WIN_HEIGHT / 2 );
	CAMERA->SetWorld ( 2000, 2000 );
	PLAYER->Init ();
	CAMERA->LinkObject ( PLAYER );
}

void MainGame::Update ()
{
	m_Collider.Update ();
	CAMERA->Update ();
	PLAYER->Update ();
}

void MainGame::Render ()
{
	static float angle;
	angle += 2.f;
	SPRITEMANAGER->FindSprite ( "컬라이더초록" )->Rotate ( angle );

	m_Collider.Render ();
	PLAYER->Render ();
}
