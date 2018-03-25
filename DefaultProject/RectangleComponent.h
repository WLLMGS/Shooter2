#pragma once
#include "BaseComponent.h"

class RectangleComponent : public wg::BaseComponent
{
public:
	RectangleComponent();
	RectangleComponent(int textName);
	~RectangleComponent();
	virtual void Update(float elapsedSec) override;
	virtual void Draw(RenderWindow* pWindow) override;
private:
	RectangleShape m_Shape;
};

