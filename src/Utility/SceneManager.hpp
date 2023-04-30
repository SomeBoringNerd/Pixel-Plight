#pragma once

#include "../Scenes/Scene.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class SceneManager
{
public:
	static void LoadScene(Scene* _scene)
	{
		scene = _scene;
		isSceneLoaded = 1;
	};

	static void Update(sf::RenderWindow& getWindow)
	{
		scene->Render(getWindow);
	};

	static int SceneLoaded()
	{
		return isSceneLoaded;
	};

private:
	inline static int isSceneLoaded;
	inline static Scene* scene;
};