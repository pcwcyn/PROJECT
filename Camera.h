#pragma once
#include "Singleton.h"
class Camera :
	public Singleton<Camera>
{
public:
	const float CAMERA_MIN_Z = -1000;
	const float CAMERA_MAX_Z = 1000;
	const float MAX_SCALE = 10;
	const float MIN_SCALE = 0.1f;
public:
	Camera ();
	~Camera ();

private:
	float m_X;			// ī�޶� ��ġ
	float m_Y;			// ī�޶� ��ġ
	float m_Z;			// ī�޸� ��ġ(1~1000)
	float m_ScreenTargetX;	// ī�޶� ��� �ִ� ���� (ȭ�� ��ǥ)
	float m_ScreenTargetY;	// ī�޶� ��� �ִ� ���� (ȭ�� ��ǥ)
	float m_WorldTargetX;	// ī�޶� ��� �ִ� ���� (���� ��ǥ)
	float m_WorldTargetY;	// ī�޶� ��� �ִ� ���� (���� ��ǥ)
	float m_Speed;		// ī�޶� �ӵ�

	float m_WorldWidth; // ���� ���� ũ��
	float m_WorldHeight; // ���� ���� ũ��

public:
	void Init (float x, float y, float z, float targetX, float targetY);
	void Update ();
	void SetWorld ( float width, float height );

public:
	void WorldToScreen ( Object* object );
	void WorldToScreen ( float* screenX, float* screenY, float worldX, float worldY );
};

