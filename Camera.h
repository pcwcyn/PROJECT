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
	float m_X;			// 카메라 위치
	float m_Y;			// 카메라 위치
	float m_Z;			// 카메리 위치(1~1000)
	float m_ScreenTargetX;	// 카메라가 찍고 있는 지점 (화면 좌표)
	float m_ScreenTargetY;	// 카메라가 찍고 있는 지점 (화면 좌표)
	float m_WorldTargetX;	// 카메라가 찍고 있는 지점 (세계 좌표)
	float m_WorldTargetY;	// 카메라가 찍고 있는 지점 (세계 좌표)
	float m_Speed;		// 카메라 속도

	float m_WorldWidth; // 월드 가로 크기
	float m_WorldHeight; // 월드 세로 크기

public:
	void Init (float x, float y, float z, float targetX, float targetY);
	void Update ();
	void SetWorld ( float width, float height );

public:
	void WorldToScreen ( Object* object );
	void WorldToScreen ( float* screenX, float* screenY, float worldX, float worldY );
};

