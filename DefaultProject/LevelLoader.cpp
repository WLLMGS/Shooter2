#include "LevelLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Scene.h"
#include "TilePrefab.h"

using namespace std;

LevelLoader::~LevelLoader()
{
	for(Entity* e : m_pEntities)
	{
		delete e;
		e = nullptr;
	}
}

void LevelLoader::LoadLevel(const std::string path, wg::Scene* scene)
{
	//csv
	ifstream file;
	
	file.open(path);

	string line{};
	
	int x{}, y{};

	const float tilesize = 64.0f;

	while(file.good())
	{
		while (getline(file, line))
		{
			stringstream stream(line);
			string element;

			while(getline(stream, element, ','))
			{
				if(element == "E")
				{
					cout << "E";
				}
				else if (element == "P")
				{
					cout << "P";
					//auto e = new Entity(tilesize / 2.0f, { x * tilesize, y * tilesize }, 1, true);
					//m_pEntities.push_back(e);
					scene->AddChild(new TilePrefab({ x * 64.f, y * 64.f }));
				}
				else if (element == "S")
				{
					scene->m_pPlayer = new PlayerPrefab({x * 64.0f, y * 64.0f});
					scene->AddChild(scene->m_pPlayer);
				}
				++x;
			}
			x = 0;
			++y;
			cout << endl;
		}
	}

}
