#include "Player.h"
#include <iostream>
#include "Animator.h"
#include "TextureManager.h"

Player::Player(const float halfSize, const Vector2f& pos) :
Entity(halfSize, halfSize, pos)
{
	m_pBody->SetGravityScale(100.f);
	m_pBody->SetLinearDamping(0.5f);

	m_pAnimator = new Animator(12, 6);

	//m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(HERO_0));
	m_Rectangle.setTextureRect({ 32, 0, 32, 32 });

}

Player::~Player()
{
}

void Player::Update(float elapsedSec)
{
	m_pAnimator->Update(elapsedSec);
	m_JumpTimer -= elapsedSec;

	//update texture
	m_Rectangle.setTextureRect({ 32 * m_pAnimator->CurrentFrame(), 64, 32, 32 });

	HandlePosition();
	HandleControls();
}

void Player::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Rectangle);
}

void Player::HandlePosition()
{
	auto pos = m_pBody->GetPosition();
	m_Rectangle.setPosition({ pos.x, pos.y });
}

void Player::HandleControls()
{
	b2Vec2 velocity{};

	velocity.x = m_pBody->GetLinearVelocity().x;
	velocity.y = m_pBody->GetLinearVelocity().y;

	if(Keyboard::isKeyPressed(Keyboard::Q))
	{
		velocity.x = -m_Speed;
		m_Rectangle.setScale(-1, 1);
	}
	if(Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x = m_Speed;
		m_Rectangle.setScale(1, 1);
	}

	if(Keyboard::isKeyPressed(Keyboard::Space))
	{
		if(m_JumpTimer < 0.0f)
		{
			m_JumpTimer = m_JumpCooldown;
			velocity.y = -m_Speed * 100.f;
		}
	}

	

	m_pBody->SetLinearVelocity({ velocity.x, velocity.y });
	
}
