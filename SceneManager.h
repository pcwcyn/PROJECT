#pragma once

#include "Scene.h"

class SceneManager : public Singleton<SceneManager>
{
private:
	map<string, Scene*> m_SceneList;
	Scene* m_CurrentScene;

public:
	void Run ();
	void ChangeScene ( string sceneName );

public:
	SceneManager ();
	~SceneManager ();
};

