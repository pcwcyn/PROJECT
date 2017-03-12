#pragma once
#include "Object.h"
class Item:public Object
{
public:
	enum E_ITEM_KIND
	{
		ITEM_WEAPON=0,
		ITEM_HELMET,
		ITEM_ARMOR,
		ITEM_OILE
	};
	enum E_ITEM_ELEMENT
	{
		ITEM_IRON = 0,
		ITEM_ICE,
		ITEM_SHEEP,
		ITEM_GOLD
	};
public:
	Item();
	~Item();

	void Init(E_ITEM_KIND I_KIND, E_ITEM_ELEMENT I_ELEMENT,float x,float y);
	void Update();
	void Render();
private:
	E_ITEM_KIND m_ITEM_KIND;
	E_ITEM_ELEMENT m_ITEM_ELEMENT;

	
};

