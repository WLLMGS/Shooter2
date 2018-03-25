#pragma once
#include "Entity.h"

class Animator;

class Player : public Entity
{
public:
	Player(const float halfSize, const Vector2f& pos);
	~Player();
	virtual void Update(float elapsedSec) override;
	virtual void Draw(RenderWindow* pWindow) override;

private:
	void HandlePosition();
	void HandleControls();

private:
	const float m_Speed = 300.f;

	const float m_JumpCooldown = .5f;
	float m_JumpTimer = 0.f;

	Animator* m_pAnimator = nullptr;
};

