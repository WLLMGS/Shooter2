#include "RigidBodyComponent.h"
#include "WorldManager.h"
#include "GameObject.h"
#include <iostream>

wg::RigidBodyComponent::RigidBodyComponent(bool isStatic)
{
	
	auto world = WorldManager::GetInstance().GetWorld();
	b2BodyDef bodyDef;
	bodyDef.type = (isStatic) ? b2_staticBody : b2_dynamicBody;
	bodyDef.position.Set(0,0);
	bodyDef.allowSleep = false;
	bodyDef.active = true;
	bodyDef.linearDamping = 0.5f;

	m_pBody = world->CreateBody(&bodyDef);

	b2PolygonShape box;
	box.SetAsBox(32, 32);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
	fixtureDef.density = 0.5f;
	fixtureDef.friction = 0.4f;
	fixtureDef.restitution = 0.0f;

	//fixtureDef.filter.groupIndex = collisionGroup;

	m_pBody->CreateFixture(&fixtureDef);
	//m_pBody->SetGravityScale(100.f);


}

wg::RigidBodyComponent::~RigidBodyComponent()
{
}

void wg::RigidBodyComponent::Update(float elapsedSec)
{
	m_pGameObject->GetTransform()->SetPosition(m_pBody->GetPosition().x, m_pBody->GetPosition().y);
}

void wg::RigidBodyComponent::Draw(RenderWindow* pWindow)
{
}

void wg::RigidBodyComponent::Translate(float x, float y)
{
	auto newPos = m_pBody->GetPosition();
	newPos.x += x;
	newPos.y += y;
	m_pBody->SetTransform(newPos, m_pBody->GetAngle());

}

void wg::RigidBodyComponent::AddForce(float x, float y)
{
	//m_pBody->ApplyForceToCenter({x,y}, true);
	m_pBody->ApplyLinearImpulseToCenter({ x, y }, true);
}
