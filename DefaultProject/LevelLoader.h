#pragma once
#include <string>
#include "Entity.h"

namespace wg {
	class Scene;
}

class LevelLoader
{
public:
	LevelLoader() = default;
	~LevelLoader();
	void LoadLevel(const std::string path, wg::Scene* scene);

	vector<Entity*> m_pEntities;
private:
	
};

