#include "TilePrefab.h"
#include "RectangleComponent.h"
#include <iostream>


TilePrefab::TilePrefab(const Vector2f& pos) :
GameObject(true)
{
	AddComponent(new RectangleComponent(1));
	GetTransform()->Translate(pos.x, pos.y);
}

void TilePrefab::Update(float elapsedSec)
{
}

void TilePrefab::Draw(sf::RenderWindow* pWindow)
{
}


