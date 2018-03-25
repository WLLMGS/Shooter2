#include "RectangleComponent.h"
#include "GameObject.h"
#include <iostream>
#include "TextureManager.h"


RectangleComponent::RectangleComponent()
{
	m_Shape.setPosition({0,0});
	m_Shape.setSize({ 64.0f, 64.0f});
	m_Shape.setOrigin({ 32.0f,32.0f });
}

RectangleComponent::RectangleComponent(int textName) :
RectangleComponent()
{
	m_Shape.setTexture(TextureManager::GetInstance().GetTexture(TextureType(textName)));
}


RectangleComponent::~RectangleComponent()
{
}

void RectangleComponent::Update(float elapsedSec)
{
	m_Shape.setRotation(m_pGameObject->GetRotation());
	m_Shape.setPosition(m_pGameObject->GetTransform()->GetPosition());
}

void RectangleComponent::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Shape);
}
