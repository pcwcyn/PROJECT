#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

void Item::Init(E_ITEM_KIND I_KIND, E_ITEM_ELEMENT I_ELEMENT, float x, float y)
{
	m_ITEM_KIND = I_KIND;
	m_ITEM_ELEMENT = I_ELEMENT;
	m_WorldX = x;
	m_WorldY = y;
	switch (m_ITEM_KIND)
	{
	case ITEM_WEAPON:m_Sprite = SPRITEMANAGER->InsertSpriteData("플레이어무기");
		break;
	case ITEM_HELMET:m_Sprite = SPRITEMANAGER->InsertSpriteData("플레이어헬멧");
		break;
	case ITEM_ARMOR:m_Sprite = SPRITEMANAGER->InsertSpriteData("플레이어갑옷");
		break;
	case ITEM_OILE:m_Sprite = SPRITEMANAGER->InsertSpriteData("아이템물약");
		break;
	}
	m_Sprite.Stop();
	switch (m_ITEM_ELEMENT)
	{
	case ITEM_IRON:
		break;
	case ITEM_ICE:m_Sprite.SetFrameX(1);
		break;
	case ITEM_SHEEP:m_Sprite.SetFrameX(2);
		break;
	case ITEM_GOLD:m_Sprite.SetFrameX(3);
		break;
	}
}

void Item::Update()
{
}

void Item::Render()
{
}
