#include "SceneManager.hpp"
#include "../Scenes/Credit.hpp"
#include "../Scenes/MainMenu.hpp"
#include "../Scenes/Scene.hpp"

void SceneManager::LoadScene(Scene* _scene)
{
	scene = _scene;
	isSceneLoaded = 1;
}

void SceneManager::Update(sf::RenderWindow& getWindow)
{
	scene->Render(getWindow);
}

void SceneManager::RefreshUI()
{
	scene->ReloadUI();
}

int SceneManager::SceneLoaded()
{
	return isSceneLoaded;
}