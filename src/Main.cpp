#include "Platform/Platform.hpp"
#include "Scenes/Credit.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/Scene.hpp"
#include "Scenes/WalkScene.hpp"
#include "TheDumpsterFire.hpp"
#include "Utility/SceneManager.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#define DRAW_HITBOXES true

sf::RenderWindow window;

static void Exit()
{
	window.close();
}

int focus = 1;
int x = 0, y = 0;

int getWindowSizeX()
{
	return x;
}
int getWindowSizeY()
{
	return y;
}

int getWindowState()
{
	return focus;
}

int main()
{
	util::Platform platform;

	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());

	// Use the screenScalingFactor
	window.create(sf::VideoMode(1280.0f * screenScalingFactor, 720.0f * screenScalingFactor), "Pixel Plight");

	/**** Use icon ****/

	sf::Texture texture;
	texture.loadFromFile("logo.png");

	sf::Vector2u textureSize = texture.getSize();

	sf::Image image = texture.copyToImage();

	sf::Uint8* buffer = new sf::Uint8[textureSize.x * textureSize.y * 4];

	window.setIcon(64, 64, buffer);

	delete[] buffer;

	/********/

	window.setFramerateLimit(60);

	platform.setIcon(window.getSystemHandle());

	sf::RectangleShape BackGround(sf::Vector2f(1920, 1080));
	sf::Color DarkSlate(69, 69, 69);
	sf::Event event;

	new SceneManager();

	BackGround.setFillColor(DarkSlate);

	MainMenu* menu = new MainMenu();

	SceneManager::LoadScene(menu);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Exit();
			else if (event.type == sf::Event::GainedFocus)
			{
				focus = 1;
			}
			else if (event.type == sf::Event::LostFocus)
			{
				focus = 0;
			}
			else if (event.type == sf::Event::Resized)
			{
				x = event.size.width;
				y = event.size.height;
				SceneManager::RefreshUI();
				std::cout << "new window size : " << x << " / " << y << std::endl;
				float scaleX = static_cast<float>(getWindowSizeX()) / 1280.0f;
				float scaleY = static_cast<float>(getWindowSizeY()) / 720.0f;
				std::cout << scaleX << " | " << scaleY << std::endl;
			}
		}

		// dont run game update if the game is not focused
		if (getWindowState())
		{
			window.clear();
			window.draw(BackGround);

			SceneManager::Update(window);
		}
		window.display();
	}

	return 0;
}

void LoadAnotherScene(std::string name)
{
	if (name == "MainMenu")
	{
		MainMenu* menu = new MainMenu();

		SceneManager::LoadScene(menu);
	}
	else if (name == "Credits")
	{
		Credit* cred = new Credit();

		SceneManager::LoadScene(cred);
	}
	else if (name == "Walker")
	{
		Walker* walk = new Walker();

		SceneManager::LoadScene(walk);
	}
}

int getGlobalMusicVolume()
{
	return 50;
}
