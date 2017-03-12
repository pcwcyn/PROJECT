#pragma once
#include "Object.h"
#include "Collider.h"
class Player : public Object,public Singleton<Player>
{
public:
	Player ();
	~Player ();

	virtual void Init();
	virtual void Update();
	virtual void Render();
public:
	void KeySettig();  //키 셋팅
	void Collision(); //중력 ,충돌체크, 공격
private:
	Collider C_Earth; //충돌체크용 땅
	DXSprite I_Body; //이미지_몸
	DXSprite I_Arm;  //팔
	DXSprite I_Jump; //점프중 몸

	DXRECT RC_Player;  //플레이어 렉트
private:
	float Speed;   //플레이어 스피드
	float GravityPlus;  //중력가속도
	const float Gravity = 0.98;   //중력값 고정

	bool IsGravity;  //중력받고있는 중이냐 =떨어지는중이냐
	bool IsJumping; //점프중이냐
	int JumpCount;

	int RunFrameCount;  //달릴때 프레임 바꿔주기 위한 변수
	int RunFrameX;  
};

