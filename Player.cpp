#include "stdafx.h"
#include "Player.h"


Player::Player ()
{
}


Player::~Player ()
{
}

void Player::Init()
{
	m_Sprite = SPRITEMANAGER->InsertSpriteData("플레이어머리");
	I_Body= *SPRITEMANAGER->FindSprite("플레이어몸");
	I_Arm=*SPRITEMANAGER->FindSprite("플레이어팔2");
	I_Jump= *SPRITEMANAGER->FindSprite("플레이어점프");
	I_Body.Stop();
	I_Jump.Stop();
	m_Width = 25;
	m_Height = 50;
	C_Earth.Init(0, WIN_HEIGHT - 100, 800, 100);
	Speed = 3.f;
	GravityPlus = 0;
	m_Collider.Init(m_WorldX, m_WorldY, m_Width, m_Height);
	RC_Player = { m_WorldX,m_WorldY,m_WorldX + m_Width,m_WorldY + m_Height };
	IsGravity = true;
	IsJumping = false;
	JumpCount = RunFrameCount= RunFrameX=0;
}

void Player::Update()
{
	RC_Player = { m_WorldX,m_WorldY,m_WorldX + m_Width,m_WorldY + m_Height };
	Collision();
	KeySettig();
	m_Collider.Update(m_WorldX, m_WorldY);

}

void Player::Render()
{
	//m_Sprite.SetAngle();
	if (IsJumping)
	{
		I_Jump.SetFrameX(0);
		I_Jump.Render(m_ScreenX -12, m_ScreenY + 15);
	}
	else if (IsGravity)
	{
		I_Jump.SetFrameX(1);
		I_Jump.Render(m_ScreenX -12, m_ScreenY + 15);
	}
	else
	I_Body.Render(m_ScreenX-12, m_ScreenY+ 15);
	//I_Arm.Render(m_WorldX-7, m_WorldY + 16);
	m_Sprite.Render(m_ScreenX, m_ScreenY);
	C_Earth.Render();
	m_Collider.Render();
}

void Player::KeySettig()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		RunFrameCount++;
		if (RunFrameCount % 10 == 0)RunFrameX++;
		if (RunFrameX >=6)RunFrameX = 1;
		I_Body.SetFrameX(RunFrameX);
		m_WorldX += Speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		RunFrameX = 0;
		I_Body.SetFrameX(RunFrameX);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		RunFrameCount++;
		if (RunFrameCount % 10 == 0)RunFrameX++;
		if (RunFrameX >= 6)RunFrameX = 1;
		I_Body.SetFrameX(RunFrameX);
		m_WorldX -= Speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		RunFrameX = 0;
		I_Body.SetFrameX(RunFrameX);
	}
}

void Player::Collision()
{
	if (!IsJumping)
	{
		if (m_Collider.RectLandingRect(&C_Earth, m_Width, m_Height, GravityPlus))
		{
			IsGravity = false;
			GravityPlus = 0;
			m_WorldY = C_Earth.GetTop() - 50;//m_Height
		}
		if(!m_Collider.RectOntheRect(&C_Earth, m_Width)) IsGravity = true;
	}

	if (IsGravity && !IsJumping)
	{
		GravityPlus += Gravity / 5;
		m_WorldY += GravityPlus;
	}
	if (!IsGravity)
	{
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			IsJumping = true;
		}
	}

	if (IsJumping)
	{
		m_WorldY -= 5;
		JumpCount++;
		if (JumpCount > 20)
		{
			IsJumping = false;
			IsGravity = true;
			JumpCount = 0;
		}
	}
}
