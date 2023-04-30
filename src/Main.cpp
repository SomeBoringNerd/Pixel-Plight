#include "Platform/Platform.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/Scene.hpp"
#include "Utility/SceneManager.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

sf::RenderWindow window;

static void Exit()
{
	window.close();
}

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1280.0f * screenScalingFactor, 720.0f * screenScalingFactor),
		"Walking Simulator | SFML Edition");
	platform.setIcon(window.getSystemHandle());

	sf::RectangleShape BackGround(sf::Vector2f(1920, 1080));
	sf::Color DarkSlate(69, 69, 69);
	sf::Event event;

	BackGround.setFillColor(DarkSlate);

	MainMenu* menu = new MainMenu();

	SceneManager::LoadScene(menu);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Exit();
		}

		window.clear();
		window.draw(BackGround);

		SceneManager::Update(window);

		window.display();
	}

	return 0;
}
