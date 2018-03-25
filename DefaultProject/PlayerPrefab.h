#pragma once
#include "GameObject.h"

class PlayerPrefab : public wg::GameObject
{
public:
	PlayerPrefab(const Vector2f& startPos);
	~PlayerPrefab() = default;
protected:
	virtual void Update(float elapsedSec) override;
	virtual void Draw(sf::RenderWindow* pWindow) override;
private:
	const float m_MoveForce = 500.0f;
	Vector2f m_MouseWorldPos;
	const float m_DashCooldown = 0.5f;
	float m_DashTimer = 0.0f;
private:
	void CalculateRotation();
};

