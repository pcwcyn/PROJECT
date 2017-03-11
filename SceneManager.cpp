#include "stdafx.h"
#include "SceneManager.h"

#include "MainGame.h"
#include "Loading.h"
#include "Title.h"

SceneManager::SceneManager ()
{
	m_CurrentScene = NULL;

	m_SceneList.insert (make_pair ( "로딩", new Loading () ) );
	m_SceneList.insert ( make_pair ( "메인게임", new MainGame () ) );
	m_SceneList.insert ( make_pair ( "타이틀", new Title () ) );

	ChangeScene ("로딩");
}


SceneManager::~SceneManager ()
{
	for (map<string, Scene*>::iterator iter = m_SceneList.begin ();
		iter != m_SceneList.end ();
		++iter)
	{
		delete iter->second;
		iter->second = NULL;
	}
}

void SceneManager::Run ()
{
	if (m_CurrentScene)
	{
		m_CurrentScene->Update ();
		m_CurrentScene->Render ();
	}
}

void SceneManager::ChangeScene ( string sceneName )
{
	m_CurrentScene = m_SceneList.find ( sceneName )->second;
	m_CurrentScene->Init ();
}
