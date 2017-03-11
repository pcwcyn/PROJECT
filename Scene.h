#pragma once
class Scene
{
public:
	Scene ();
	~Scene ();

public:
	virtual void Init () {};
	virtual void Update () {};
	virtual void Render () {};
};

