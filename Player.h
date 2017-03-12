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
	void Collision(); //중력 ,점프, 충돌체크, 공격 
	void Shield();  //공격받았을 때 무적
	void FrameImageForHead();  //눈감는모션용
private:
	Collider C_Earth; //충돌체크용 땅
	Collider C_Wall;
	Collider C_Down; //아래볼때용 컬라이더
	DXSprite I_Body; //이미지_몸
	DXSprite I_Arm;  //팔
	DXSprite I_Jump; //점프중 몸
	DXSprite I_Down;

private:
	float Speed;   //플레이어 스피드
	float MoveX;
	float GravityPlus;  //중력가속도
	const float Gravity = 0.98;   //중력값 고정


	int RunFrameCount;  //달릴때 프레임 바꿔주기 위한 변수
	int RunFrameX;  
	int HeadFrameX;

	bool IsGravity;  //중력받고있는 중이냐 =떨어지는중이냐
	bool IsJumping; //점프중이냐
	int JumpCount;

	bool IsDown;  //아래키 누르고있냐?

	bool IsAttacked; //공격받았냐?
	bool IsShieldOn;  //쉴드켜져있냐?  렌더 깜빡임
	int ShieldTimeCount; 
	

};

