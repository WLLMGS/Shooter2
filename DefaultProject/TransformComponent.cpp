#include "TransformComponent.h"
#include <iostream>
#include "GameObject.h"

wg::TransformComponent::TransformComponent()
{
	
}

wg::TransformComponent::~TransformComponent()
{
}

void wg::TransformComponent::Update(float elapsedSec)
{
}

void wg::TransformComponent::Draw(RenderWindow* pWindow)
{
}

void wg::TransformComponent::Translate(float x, float y)
{
	m_pGameObject->m_pRigidBody->Translate(x, y);
}

Vector2f wg::TransformComponent::GetPosition() const
{
	return m_Position;
}

void wg::TransformComponent::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;

	
}
