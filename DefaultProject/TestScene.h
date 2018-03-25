#pragma once
#include "Scene.h"

class PlayerPrefab;

class TestScene : public wg::Scene
{
	
public:
	TestScene();
	~TestScene();
	virtual void Update(float elapsedSec) override;
	virtual void Draw(RenderWindow* pWindow) override;
	

private:
	wg::GameObject* m_pObj;
	sf::View m_View;
};

