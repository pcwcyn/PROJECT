// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

// 기본 헤더
#include <vector>
#include <list>
#include <map>

// 사용자 헤더
#include "SpriteManager.h"
#include "EffectManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "KeyManager.h"
#include "Camera.h"
// 이름 공간 사용
using namespace std;

#define SPRITEMANAGER SpriteManager::GetInst()
#define EFFECTMANAGER EffectManager::GetInst()
#define SCENEMANAGER  SceneManager::GetInst()
#define KEYMANAGER KeyManager::GetInst()
#define PLAYER Player::GetInst()
#define CAMERA Camera::GetInst()

const int WIN_WIDTH = 960;
const int WIN_HEIGHT = 540;