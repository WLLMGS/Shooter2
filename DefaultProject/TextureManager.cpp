
#include "TextureManager.h"

TextureManager* TextureManager::m_pInstance = nullptr;


TextureManager& TextureManager::GetInstance()
{
	static TextureManager instance;
	
	return instance;
}

Texture* TextureManager::GetTexture(const TextureType& type)
{
	return m_pTextures[type];
}

TextureManager::TextureManager()
{
	AddTexture(HERO_0, "Resources/HERO_0.png");
	AddTexture(ROCK_0, "Resources/rock.png");
	AddTexture(ROCK_1, "Resources/rock2.png");
	AddTexture(ROCK_2, "Resources/rock3.png");
	AddTexture(ROCK_3, "Resources/rock4.png");
}


TextureManager::~TextureManager()
{
	//delete all textures
	delete m_pInstance;
	m_pInstance = nullptr;
	for(pair<TextureType, Texture*> p : m_pTextures)
	{
		delete p.second;
		p.second = nullptr;
	}
}

void TextureManager::CreateInstance()
{
	m_pInstance = new TextureManager();
}

void TextureManager::AddTexture(const TextureType& type, string path)
{
	Texture* texture = new Texture();
	if (!texture->loadFromFile(path)) cout << "could not instantiate texture: " << path << endl;

	texture->setRepeated(true);

	m_pTextures[type] = texture;
}
