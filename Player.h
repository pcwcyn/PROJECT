#pragma once
#include "Object.h"
#include "Collider.h"
class Player : public Object,public Singleton<Player>
{
public:
	enum E_HANDTYPE
	{
		NONE=0,SWORD,LANCE,WAND,BOOMERANG
	};
	Player ();
	~Player ();

	virtual void Init();
	virtual void Update();
	virtual void Render();
public:
	void KeySettig();  //Ű ����
	void Collision(); //�߷� ,����, �浹üũ, ���� 
	void Shield();  //���ݹ޾��� �� ����
	void FrameImageForHead();  //�����¸�ǿ�
	void FrontAttack();  //���� �� ����
	void FrontAttackSpriteRender();  //�����̹��� �׷��ֱ�
private:
	Collider C_Earth; //�浹üũ�� ��
	Collider C_Wall;
	Collider C_Down; //�Ʒ������� �ö��̴�
	DXSprite I_Body; //�̹���_��
	DXSprite I_Arm_Front;  //��
	DXSprite I_Arm_Sword;  //���ֵθ��� ���
	DXSprite I_Arm_Lance;
	DXSprite I_Arm_Wand;
	DXSprite I_Jump; //������ ��
	DXSprite I_Down;

	E_HANDTYPE FrontHandType;
	E_HANDTYPE BackHandType;
private:
	float Speed;   //�÷��̾� ���ǵ�
	float MoveX;
	float GravityPlus;  //�߷°��ӵ�
	const float Gravity = 0.98;   //�߷°� ����


	int RunFrameCount;  //�޸��� ������ �ٲ��ֱ� ���� ����
	int RunFrameX;  
	int HeadFrameX;

	bool IsGravity;  //�߷¹ް��ִ� ���̳� =�����������̳�
	bool IsJumping; //�������̳�
	int JumpCount;

	bool IsDown;  //�Ʒ�Ű �������ֳ�?

	bool IsAttacked; //���ݹ޾ҳ�?
	bool IsShieldOn;  //���������ֳ�?  ���� ������
	int ShieldTimeCount; 
	
	bool IsFrontAttack;  //���� ������ �����ϳ�
	int FrontAttackFrameX;// �հ��ݿ� ������ X
};

