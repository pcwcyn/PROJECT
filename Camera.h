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

	static bool m_isRenderingCollider;

public:
	Camera ();
	~Camera ();

private:
	float m_X;			// 카메라 세계 좌표 X
	float m_Y;			// 카메라 세계 좌표 Y
	float m_Z;			// 카메라 세계 좌표 Z
	float m_ScreenTargetX;	// 카메라 화면이 찍는 윈도우 화면의 지점 X
	float m_ScreenTargetY;	// 카메라 화면이 찍는 윈도우 화면의 지점 Y
	float m_WorldTargetX;	// 카메라 화면이 찍는 세계의 지점 X
	float m_WorldTargetY;	// 카메라 화면이 찍는 세계의 지점 Y

	float m_Speed;		// 카메라 수동 조작 속도

	float m_WorldWidth; // 카메라가 존재하고 있는 세계의 폭
	float m_WorldHeight; // 카메라가 존재하고 있는 세계의 너비

	Object* m_LinkObject;	// 3인칭 카메라를 위한 연결 오브젝트.

public:
	void Init ( float x, float y, float z, float targetX, float targetY );
	void Update ();
	void SetWorld ( float width, float height );

public:
	// 오브젝트 스크린 변환
	void WorldToScreen ( Object* object );

	// 오브젝트 외 객체의 스크린 변한
	void WorldToScreen ( float* screenX, float* screenY, float worldX, float worldY );

	// 오브젝트와 카메라를 연결
	void LinkObject ( Object* object );
};
