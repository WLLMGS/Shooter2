#include "Entity.h"

Entity::Entity(const float width, const float height, const Vector2f& pos, int collisionGroup, bool isStatic)
{
	auto world = WorldManager::GetInstance().GetWorld();

	b2BodyDef bodyDef;
	if (!isStatic) bodyDef.type = b2_dynamicBody;
	else bodyDef.type = b2_staticBody;
	//bodyDef.type = (!isStatic) ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(pos.x, pos.y);
	//bodyDef.allowSleep = false;
	//bodyDef.active = true;
	bodyDef.linearDamping = 0.1f;
	//bodyDef.bullet = true;
	
	
	int id = 1;
	m_pBody = world->CreateBody(&bodyDef);
	m_pBody->SetUserData((void*)id);
	
	b2PolygonShape box;
	/*circle.m_p.Set(0, 0);
	circle.m_radius = halfSize;*/
	box.SetAsBox(width, height);


	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
	fixtureDef.density = .001f;
	fixtureDef.friction = 0.5f;
	fixtureDef.restitution = 0.f;
	

	fixtureDef.filter.groupIndex = collisionGroup;

	m_pBody->CreateFixture(&fixtureDef);

	//create rectangleShape;
	m_Rectangle.setPosition(pos);
	m_Rectangle.setSize(Vector2f(width * 2.0f, height * 2.0f));
	m_Rectangle.setOrigin(m_Rectangle.getSize() / 2.0f);
}

Entity::Entity(const float halfSize, const Vector2f& pos, int collisionGroup, bool isStatic) :
Entity(halfSize, halfSize, pos, collisionGroup, isStatic)
{}



void Entity::Update(float elapsedSec)
{
	auto pos = m_pBody->GetPosition();

	m_Rectangle.setPosition(pos.x, pos.y);
}

void Entity::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Rectangle);
}

Vector2f Entity::GetPosition() const
{
	return m_Rectangle.getPosition();
}

void Entity::SetPosition(const Vector2f& pos)
{
	m_pBody->SetTransform({ pos.x, pos.y }, 0.0f);
	m_Rectangle.setPosition(pos);
}

Entity::~Entity()
{
}
