#include "SceneManager.hpp"
#include "../Scenes/Credit.hpp"
#include "../Scenes/MainMenu.hpp"
#include "../Scenes/Scene.hpp"

void SceneManager::LoadScene(Scene* _scene)
{
	scene = _scene;
	isSceneLoaded = 1;
}

void SceneManager::LoadMainMenu()
{
	MainMenu* mainMenuScene = new MainMenu();
	LoadScene(mainMenuScene);
}

void SceneManager::LoadCredits()
{
	Credit* creditScene = new Credit();
	LoadScene(creditScene);
}

void SceneManager::Update(sf::RenderWindow& getWindow)
{
	scene->Render(getWindow);
}

int SceneManager::SceneLoaded()
{
	return isSceneLoaded;
}