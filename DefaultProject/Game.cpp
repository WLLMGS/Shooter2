
#include "Game.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "TestScene.h"


using namespace std;
using namespace sf;

Game::Game() 
{
	m_pWindow = new RenderWindow(sf::VideoMode(1920,1080), "Default Project");

	m_pWindow->setVerticalSyncEnabled(true);

	m_pTestScene = new TestScene();
}

Game::~Game()
{
	delete m_pTestScene;
	m_pTestScene = nullptr;
}

void Game::Run()
{
	Clock clock;
	float deltaTime{};
	
	while (m_pWindow->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
		Draw();
	}
}

void Game::ProcessEvents()
{
	Event event{};
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == Event::Closed) m_pWindow->close();
	}
}
void Game::Update(float deltaTime)
{
	//testing contacts
	//for (b2Contact* c = m_pWorld->GetContactList(); c; c->GetNext())
	//{
	//	int uid = int(c->GetFixtureB()->GetBody()->GetUserData());

	//	if(uid == 12)
	//	{
	//		
	//		break;
	//	}
	//	else if (uid == 13)
	//	{
	//		c->GetFixtureB()->GetBody()->SetActive(false);
	//		//apply force to other obj later
	//		break;
	//	}
	//	break;
	//}

	m_pTestScene->RootUpdate(deltaTime);
	
}

void Game::Draw()
{
	m_pWindow->clear();
	m_pTestScene->RootDraw(m_pWindow);
	m_pWindow->display();
}