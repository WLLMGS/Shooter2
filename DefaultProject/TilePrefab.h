#pragma once
#include "GameObject.h"

class TilePrefab : public wg::GameObject
{
public:
	TilePrefab(const Vector2f& pos);
	~TilePrefab() = default;
protected:
	virtual void Update(float elapsedSec) override;
	virtual void Draw(sf::RenderWindow* pWindow) override;
};

