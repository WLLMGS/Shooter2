#include "GameObject.h"
#include "BaseComponent.h"
#include <iostream>

wg::GameObject::GameObject(bool isStatic) :
m_Transform()
{
	m_pRigidBody = new RigidBodyComponent(isStatic);
	m_pRigidBody->m_pGameObject = this;
	m_pComponents.push_back(m_pRigidBody);

	m_Transform.m_pGameObject = this;
}

wg::GameObject::~GameObject()
{
	for(auto comp : m_pComponents)
	{
		delete comp;
		comp = nullptr;
	}
}

void wg::GameObject::RootUpdate(float elapsedSec)
{
	Update(elapsedSec);
	for (auto comp : m_pComponents) comp->Update(elapsedSec);
}

void wg::GameObject::RootDraw(RenderWindow* pWindow)
{
	Draw(pWindow);
	for (auto comp : m_pComponents) comp->Draw(pWindow);
}

void wg::GameObject::Update(float elapsedSec)
{
	for (auto baseComp : m_pComponents) baseComp->Update(elapsedSec);
}

void wg::GameObject::Draw(sf::RenderWindow* pWindow)
{
	for (auto baseComp : m_pComponents) baseComp->Draw(pWindow);
}

wg::TransformComponent* wg::GameObject::GetTransform()
{
	return &m_Transform;
}

void wg::GameObject::AddComponent(BaseComponent* comp)
{
	m_pComponents.push_back(comp);
	comp->m_pGameObject = this;
}

void wg::GameObject::AddForce(float x, float y)
{
	m_pRigidBody->AddForce(x, y);
}
