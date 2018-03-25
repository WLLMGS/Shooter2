#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;


namespace wg
{
	class BaseComponent
	{
	public:
		BaseComponent() = default;
		virtual ~BaseComponent() = default;
		virtual void Update(float elapsedSec);
		virtual void Draw(RenderWindow* pWindow);
	protected:
		friend class GameObject;
		GameObject* m_pGameObject = nullptr;
	};
}



