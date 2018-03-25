#pragma once
#include "BaseComponent.h"
#include <Box2D/Dynamics/b2Body.h>

namespace wg
{
	class RigidBodyComponent : public BaseComponent
	{
	public:
		RigidBodyComponent(bool isStatic);
		virtual ~RigidBodyComponent();
		virtual void Update(float elapsedSec) override;
		virtual void Draw(RenderWindow* pWindow) override;
		void Translate(float x, float y);
		void AddForce(float x, float y);
	private:
		b2Body* m_pBody = nullptr;
	};
}

