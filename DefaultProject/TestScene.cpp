#include "TestScene.h"
#include "GameObject.h"
#include "RectangleComponent.h"
#include "RigidBodyComponent.h"
#include "WorldManager.h"
#include "PlayerPrefab.h"
#include "TilePrefab.h"
#include "LevelLoader.h"
#include <iostream>

TestScene::TestScene()
{
	LevelLoader loader{};
	loader.LoadLevel("Resources/Levels/test2.csv", this);

	m_View.setCenter(m_pPlayer->GetTransform()->GetPosition());
	m_View.setSize(1080.0f, 720.0f);

	m_View.zoom(1.2f);
}


TestScene::~TestScene()
{
}

void TestScene::Update(float elapsedSec)
{
	m_View.setCenter(m_pPlayer->GetTransform()->GetPosition());
	WorldManager::GetInstance().GetWorld()->Step(0.020f, 6, 4);

}

void TestScene::Draw(RenderWindow* pWindow)
{
	pWindow->setView(m_View);
}
