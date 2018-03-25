#include "Scene.h"
#include "GameObject.h"


wg::Scene::Scene(){}

void wg::Scene::Update(float elapsedSec){}

void wg::Scene::Draw(RenderWindow* pWindow)
{
}

void wg::Scene::AddChild(GameObject* child)
{
	m_pGameObjects.push_back(child);
}

void wg::Scene::RootUpdate(float elapsedSec)
{
	Update(elapsedSec);
	for(auto gameObject : m_pGameObjects)
	{
		gameObject->RootUpdate(elapsedSec);
	}
}

void wg::Scene::RootDraw(RenderWindow* pWindow)
{
	Draw(pWindow);
	for (auto gameObject : m_pGameObjects)
	{
		gameObject->RootDraw(pWindow);
	}
}


wg::Scene::~Scene()
{
	for(auto gameObject : m_pGameObjects)
	{
		delete gameObject;
		gameObject = nullptr;
	}
}
