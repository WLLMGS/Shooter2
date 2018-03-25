#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "TransformComponent.h"
#include "RigidBodyComponent.h"

using namespace sf;
using namespace std;


namespace wg
{
	class BaseComponent;
	class GameObject
	{
	public:
		explicit GameObject(bool isStatic = false);
		virtual ~GameObject();
		void RootUpdate(float elapsedSec);
		void RootDraw(RenderWindow* pWindow);
		TransformComponent* GetTransform();
		void AddComponent(BaseComponent* comp);
		void AddForce(float x, float y);
		float GetRotation() const { return m_Rotation; }
		void SetRotation(const float rotation = 0.0f) { m_Rotation = rotation; }
	protected:
		virtual void Update(float elapsedSec);
		virtual void Draw(sf::RenderWindow* pWindow);
	protected:
		friend class TransformComponent;
		vector<BaseComponent*> m_pComponents;
		TransformComponent m_Transform;
		RigidBodyComponent* m_pRigidBody;
		float m_Rotation = 0.0f;
	};
}


