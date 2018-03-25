#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "PlayerPrefab.h"

using namespace sf;
using namespace std;

namespace wg
{
	class GameObject;

	class Scene
	{
	public:
		explicit Scene();
		~Scene();
		virtual void Update(float elapsedSec);
		virtual void Draw(RenderWindow* pWindow);
		void AddChild(GameObject* child);
		void RootUpdate(float elapsedSec);
		void RootDraw(RenderWindow* pWindow);
		PlayerPrefab* m_pPlayer;
	protected:
		vector<GameObject*> m_pGameObjects;

	private:


	};
}



