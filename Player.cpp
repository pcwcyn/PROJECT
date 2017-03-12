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
	I_Down= *SPRITEMANAGER->FindSprite("플레이어다운");
	m_Sprite.Stop();
	I_Body.Stop();
	I_Jump.Stop();
	m_Width = 25;
	m_Height = 50;
	C_Down.Init(m_X, m_Y/2, m_Width, m_Height*2 / 3);
	C_Earth.Init(0, WIN_HEIGHT - 100, 800, 100);
	C_Wall.Init(500, 400, 50, 600);
	Speed = 3.f;
	GravityPlus = ShieldTimeCount=0;
	m_Collider.Init(m_X, m_Y, m_Width, m_Height);
	IsGravity = true;
	IsJumping = IsAttacked= IsDown=false;
	JumpCount = RunFrameCount= RunFrameX=0;
	MoveX = HeadFrameX= 0;
}

void Player::Update()
{
	FrameImageForHead(); 
	Collision();
	KeySettig();
	m_Collider.Update(m_X, m_Y);
	if(KEYMANAGER->isOnceKeyDown('T'))
	{
		IsAttacked = true;
	}
	if(IsAttacked)
	Shield();
	if (IsDown)
	{
		C_Down.Update(m_X+7, m_Y+m_Height/3);
	}
}

void Player::Render()
{
	if (!IsShieldOn)
	{
		if (IsDown)
		{
		I_Down.Render(m_X, m_Y + m_Height / 3);
		m_Sprite.Render(m_X+10, m_Y+m_Height / 3);
		C_Down.Render();
		}
		else
		{
			if (IsJumping)
			{
				I_Jump.SetFrameX(0);
				I_Jump.Render(m_X - 12, m_Y + 15);
			}
			else if (IsGravity)
			{
				I_Jump.SetFrameX(1);
				I_Jump.Render(m_X - 12, m_Y + 15);
			}
			else
				I_Body.Render(m_X - 12, m_Y + 15);
			//I_Arm.Render(m_X-7, m_Y + 16);
			m_Sprite.Render(m_X, m_Y);
			m_Collider.Render();
		}
	}
	C_Earth.Render();
	C_Wall.Render();
}

void Player::KeySettig()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		RunFrameCount++;
		if (RunFrameCount % 10 == 0)RunFrameX++;
		if (RunFrameX >=6)RunFrameX = 1;
		I_Body.SetFrameX(RunFrameX);
		MoveX =1;
		m_X += Speed;
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
		MoveX =-1;
		m_X -= Speed;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		RunFrameX = 0;
		I_Body.SetFrameX(RunFrameX);
	}

	if (m_Collider.RectInRect(C_Wall.GetRect(), Speed))
	{
		m_X -= Speed*MoveX;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN)&&!IsJumping&&!IsGravity)
	{
		IsDown = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))IsDown = false;
}

void Player::Collision()
{
	if (!IsJumping)
	{
		//if (m_Collider.RectLandingRect(&C_Wall, m_Width, m_Height, GravityPlus))
		//{
		//	IsGravity = false;
		//	GravityPlus = 0;
		//	m_Y = C_Wall.GetTop() - m_Height;
		//}
		//if (!m_Collider.RectOntheRect(&C_Wall, m_Width)) IsGravity = true;
		if (m_Collider.RectLandingRect(&C_Earth, m_Width, m_Height, GravityPlus))
		{
			IsGravity = false;
			GravityPlus = 0;
			m_Y = C_Earth.GetTop() - m_Height;
		}
	 if(!m_Collider.RectOntheRect(&C_Earth, m_Width)) IsGravity = true;
	}
	if (IsGravity && !IsJumping)
	{
		GravityPlus += Gravity / 5;
		m_Y += GravityPlus;
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
		m_Y -= 5;
		JumpCount++;
		if (JumpCount > 20)
		{
			IsJumping = false;
			IsGravity = true;
			JumpCount = 0;
		}
	}
}

void Player::Shield()
{
	ShieldTimeCount++;
	if (ShieldTimeCount % 8 == 0) IsShieldOn = true;
	else if (ShieldTimeCount % 4 == 0)IsShieldOn = false;

	if (ShieldTimeCount > 60)
	{
		IsAttacked = false;
		IsShieldOn = false;
		ShieldTimeCount = 0;
	}
}

void Player::FrameImageForHead()
{
	HeadFrameX++;
	if (HeadFrameX > 100)m_Sprite.SetFrameX(1);
	if (HeadFrameX > 120)
	{
		m_Sprite.SetFrameX(0);
		HeadFrameX = 0;
	}
}
