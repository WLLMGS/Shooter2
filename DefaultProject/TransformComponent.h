#pragma once
#include "BaseComponent.h"

namespace wg
{
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent();
		~TransformComponent();
		virtual void Update(float elapsedSec) override;
		virtual void Draw(RenderWindow* pWindow) override;
		void Translate(float x, float y);
		Vector2f GetPosition() const;
		void SetPosition(float x, float y);
	private:
		
		Vector2f m_Position{};
	};
}


