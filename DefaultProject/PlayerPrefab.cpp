#include "PlayerPrefab.h"
#include "RectangleComponent.h"
#include <iostream>

PlayerPrefab::PlayerPrefab(const Vector2f& startPos) :
GameObject(false)
{
	AddComponent(new RectangleComponent(0));

	GetTransform()->Translate(startPos.x, startPos.y);
}

void PlayerPrefab::Update(float elapsedSec)
{
	m_DashTimer -= elapsedSec;
	float forceX{0.0f};
	float forceY{0.0f};
	if(Keyboard::isKeyPressed(Keyboard::Z))
	{
		forceY = -m_MoveForce;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		forceY = m_MoveForce;
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		forceX = -m_MoveForce;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		forceX = m_MoveForce;
	}

	//dash
	if(Keyboard::isKeyPressed(Keyboard::Space) && m_DashTimer < 0.0f)
	{
		m_DashTimer = m_DashCooldown;
		forceX *= 5000.0f;
		forceY *= 5000.0f;
	}

	AddForce(forceX, forceY);
	CalculateRotation();
}

void PlayerPrefab::Draw(sf::RenderWindow* pWindow)
{
	auto pos = Mouse::getPosition();

	auto world = pWindow->mapPixelToCoords(pos);

	m_MouseWorldPos.x = world.x;
	m_MouseWorldPos.y = world.y;


}

void PlayerPrefab::CalculateRotation()
{
	auto dx = GetTransform()->GetPosition().x - m_MouseWorldPos.x;
	auto dy = GetTransform()->GetPosition().y - m_MouseWorldPos.y;

	auto angle = atan2(dy, dx);
	angle *= 180.0f / b2_pi;

	SetRotation(angle + 90.0f);
}


