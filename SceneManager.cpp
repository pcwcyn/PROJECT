#include "stdafx.h"
#include "SceneManager.h"

#include "MainGame.h"
#include "Loading.h"
#include "Title.h"

SceneManager::SceneManager ()
{
	m_CurrentScene = NULL;

	m_SceneList.insert (make_pair ( "�ε�", new Loading () ) );
	m_SceneList.insert ( make_pair ( "���ΰ���", new MainGame () ) );
	m_SceneList.insert ( make_pair ( "Ÿ��Ʋ", new Title () ) );

	ChangeScene ("�ε�");
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
