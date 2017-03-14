// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

// �⺻ ���
#include <vector>
#include <list>
#include <map>

// ����� ���
#include "SpriteManager.h"
#include "EffectManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "KeyManager.h"
#include "Camera.h"
// �̸� ���� ���
using namespace std;

#define SPRITEMANAGER SpriteManager::GetInst()
#define EFFECTMANAGER EffectManager::GetInst()
#define SCENEMANAGER  SceneManager::GetInst()
#define KEYMANAGER KeyManager::GetInst()
#define PLAYER Player::GetInst()
#define CAMERA Camera::GetInst()

const int WIN_WIDTH = 960;
const int WIN_HEIGHT = 540;