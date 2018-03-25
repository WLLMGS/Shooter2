#pragma once
#include "SFML/Graphics.hpp"


class Entity;
class TestScene;

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	//functions
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();

	
	//members
	RenderWindow* m_pWindow = nullptr;

	TestScene* m_pTestScene = nullptr;
};

