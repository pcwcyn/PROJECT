#pragma once

#include "Scene.h"

class MainGame : public Scene
{
public:
	MainGame () {};
	~MainGame () { };

public:
	virtual void Init ();
	virtual void Update ();
	virtual void Render ();

public:
	Collider m_Collider;
};
