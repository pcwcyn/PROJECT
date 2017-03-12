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
	void KeySettig();  //Ű ����
	void Collision(); //�߷� ,�浹üũ, ����
private:
	Collider C_Earth; //�浹üũ�� ��
	DXSprite I_Body; //�̹���_��
	DXSprite I_Arm;  //��
	DXSprite I_Jump; //������ ��

	DXRECT RC_Player;  //�÷��̾� ��Ʈ
private:
	float Speed;   //�÷��̾� ���ǵ�
	float GravityPlus;  //�߷°��ӵ�
	const float Gravity = 0.98;   //�߷°� ����

	bool IsGravity;  //�߷¹ް��ִ� ���̳� =�����������̳�
	bool IsJumping; //�������̳�
	int JumpCount;

	int RunFrameCount;  //�޸��� ������ �ٲ��ֱ� ���� ����
	int RunFrameX;  
};

