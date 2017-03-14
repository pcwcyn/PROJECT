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
	I_Arm_Front =*SPRITEMANAGER->FindSprite("플레이어팔");
	I_Arm_Sword = *SPRITEMANAGER->FindSprite("플레이어팔_검");
	I_Arm_Lance= *SPRITEMANAGER->FindSprite("플레이어팔_창");
	I_Arm_Wand= *SPRITEMANAGER->FindSprite("플레이어팔_지팡이");
	I_Jump= *SPRITEMANAGER->FindSprite("플레이어점프");
	I_Down= *SPRITEMANAGER->FindSprite("플레이어다운");

	m_Sprite.Stop();
	I_Arm_Front.Stop();
	//I_Arm_Sword.Stop();
	//I_Arm_Lance.Stop();
	I_Body.Stop();
	I_Jump.Stop();
	FrontHandType = BackHandType = NONE;
	m_Width = 25;
	m_Height = 50;
	C_Down.Init(m_WorldX, m_WorldY/2, m_Width, m_Height*2 / 3);
	C_Earth.Init(0, WIN_HEIGHT - 100, 800, 100);
	C_Wall.Init(500, 400, 50, 600);
	Speed = 3.f;
	GravityPlus = ShieldTimeCount=0;
	m_Collider.Init(m_WorldX, m_WorldY, m_Width, m_Height);
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
	m_Collider.Update(m_WorldX, m_WorldY);
	if(KEYMANAGER->isOnceKeyDown('T'))
	{
		IsAttacked = true;
	}
	if(IsAttacked)
	Shield();
	if (IsDown)
	{
		C_Down.Update(m_WorldX+7, m_WorldY+m_Height/3);
	}
	if (IsFrontAttack)
		FrontAttack();
	if (KEYMANAGER->isOnceKeyDown('1'))FrontHandType = NONE;
	if (KEYMANAGER->isOnceKeyDown('2'))FrontHandType = SWORD;
	if (KEYMANAGER->isOnceKeyDown('3'))FrontHandType = LANCE;
	if (KEYMANAGER->isOnceKeyDown('4'))FrontHandType = BOOMERANG;
	if (KEYMANAGER->isOnceKeyDown('5'))FrontHandType = WAND;
}

void Player::Render()
{
	CAMERA->WorldToScreen ( this );

	// 회전 테스트
	static float angle;
	angle++;
	I_Body.SetCenterOffset ( 9, 0 );
	I_Body.Rotate ( angle );


	if (!IsShieldOn)
	{
		if (IsDown)
		{
		I_Down.Render(m_ScreenX, m_ScreenY + m_Height / 3);
		m_Sprite.Render(m_ScreenX+10, m_ScreenY+m_Height / 3);
		FrontAttackSpriteRender();
		C_Down.Render();
		}
		else
		{
			if (IsJumping)
			{
				I_Jump.SetFrameX(0);
				I_Jump.Render(m_ScreenX - 12, m_ScreenY + 15);
			}
			else if (IsGravity)
			{
				I_Jump.SetFrameX(1);
				I_Jump.Render(m_ScreenX - 12, m_ScreenY + 15);
			}
			else
				I_Body.Render(m_ScreenX - 12, m_ScreenY + 15);
			m_Sprite.Render(m_ScreenX, m_ScreenY);
			FrontAttackSpriteRender();
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
		if (RunFrameCount % 5 == 0)RunFrameX++;
		if (RunFrameX >=6)RunFrameX = 1;
		I_Body.SetFrameX(RunFrameX);
		m_WorldX += Speed;

		MoveX =1;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		RunFrameX = 0;
		I_Body.SetFrameX(RunFrameX);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		RunFrameCount++;
		if (RunFrameCount % 5 == 0)RunFrameX++;
		if (RunFrameX >= 6)RunFrameX = 1;
		I_Body.SetFrameX(RunFrameX);

		m_WorldX -= Speed;

		MoveX =-1;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		RunFrameX = 0;
		I_Body.SetFrameX(RunFrameX);
	}

	if (m_Collider.RectInRect(C_Wall.GetRect(), Speed))
	{
		m_WorldX -= Speed*MoveX;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN)&&!IsJumping&&!IsGravity)
	{
		IsDown = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))IsDown = false;

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		IsFrontAttack = true;
	}
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
			m_WorldY = C_Earth.GetTop() - m_Height;
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

void Player::FrontAttack()
{
	switch (FrontHandType)
	{
	case NONE:
		FrontAttackFrameX++;
		if (FrontAttackFrameX == I_Arm_Front.GetMaxFrameX())
		{
			I_Arm_Front.SetFrameX(0);
			FrontAttackFrameX=0;
			IsFrontAttack = false;
			break;
		}
		I_Arm_Front.SetFrameX(FrontAttackFrameX);
		break;
	case SWORD:
		FrontAttackFrameX++;
		if (FrontAttackFrameX == I_Arm_Sword.GetMaxFrameX())
		{
			I_Arm_Sword.SetFrameX(0);
			FrontAttackFrameX = 0;
			IsFrontAttack = false;
			break;
		}
		I_Arm_Sword.SetFrameX(FrontAttackFrameX);
		break;
	case LANCE: case BOOMERANG:
		FrontAttackFrameX++;
		if (FrontAttackFrameX == I_Arm_Lance.GetMaxFrameX())
		{
			I_Arm_Lance.SetFrameX(0);
			FrontAttackFrameX = 0;
			IsFrontAttack = false;
			break;
		}
		I_Arm_Lance.SetFrameX(FrontAttackFrameX);
		break;
	case WAND:
		FrontAttackFrameX++;
		if (FrontAttackFrameX == I_Arm_Wand.GetMaxFrameX())
		{
			I_Arm_Wand.SetFrameX(0);
			FrontAttackFrameX = 0;
			IsFrontAttack = false;
			break;
		}
		I_Arm_Wand.SetFrameX(FrontAttackFrameX);
		break;
	}

}

void Player::FrontAttackSpriteRender()
{
	if (IsFrontAttack)
	{
		switch (FrontHandType)
		{
		case NONE:
			if(IsDown)I_Arm_Front.Render(m_ScreenX - 5, m_ScreenY + m_Height / 3 + 10);
			else I_Arm_Front.Render(m_ScreenX - 10, m_ScreenY + 14);
			break;
		case SWORD:
			if (IsDown)I_Arm_Sword.Render(m_ScreenX - 25, m_ScreenY + m_Height / 3 -4);
			else I_Arm_Sword.Render(m_ScreenX-30 , m_ScreenY );
			break;
		case LANCE: case BOOMERANG:
			if (IsDown)I_Arm_Lance.Render(m_ScreenX - 8, m_ScreenY + m_Height / 3 -6);
			else I_Arm_Lance.Render(m_ScreenX -13, m_ScreenY-2 );
			break;
		case WAND:
			if (IsDown)I_Arm_Wand.Render(m_ScreenX - 2, m_ScreenY + m_Height / 3 -16);
			else I_Arm_Wand.Render(m_ScreenX - 7, m_ScreenY-12);
			break;
		}
	}
	else if(IsDown)I_Arm_Front.Render(m_ScreenX - 5, m_ScreenY + m_Height / 3 + 10); 
	else 	I_Arm_Front.Render(m_ScreenX - 9, m_ScreenY + 12);

}
