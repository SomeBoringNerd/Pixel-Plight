#pragma once

#include "../Utility/GUI.hpp"
#include "Platform/Platform.hpp"
#include "Scene.hpp"

#include <iostream>

#include "../Entity/Player.hpp"
#include "../Tiles/Tile.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../TheDumpsterFire.hpp"

class Walker : public Scene
{
public:
	Walker()
	{
		this->name = "Walker";
		this->player = new Player(20, 0, 0, "Player");

		if (true)
		{
			for (int x = 0; x < 1280; x += 64)
			{
				tileset.insert(tileset.begin(), new Tile(sf::Vector2f(x, 720 - 64), "debug_tile", 1));
				tileset.insert(tileset.begin(), new Tile(sf::Vector2f(x, 0), "debug_tile", 1));
			}

			for (int y = 0; y < 720; y += 64)
			{
				tileset.insert(tileset.begin(), new Tile(sf::Vector2f(0, y), "debug_tile"));
				tileset.insert(tileset.begin(), new Tile(sf::Vector2f(1280 - 64, y), "debug_tile"));
			}
		}

		music.openFromFile("content/music/gameloop.wav");
		music.setVolume(getGlobalMusicVolume());
		music.setLoop(true);
		music.play();
	}

	void Render(sf::RenderWindow& getWindow) override
	{
		for (Tile* tile : tileset)
		{
			tile->DrawHitBoxes(getWindow, player);
		}

		for (Tile* tile : tileset)
		{
			tile->Render(getWindow, player);
		}
		player->Render(getWindow);

		sf::RectangleShape behindTextBox;
		behindTextBox.setFillColor(sf::Color::Black);

		sf::Font font;
		font.loadFromFile("content/fonts/BebasNeue-Regular.ttf");
		// Create a text
		std::string _name = "Pixel Pligt dev mode (collision test)";
		sf::Text text(_name, font);
		text.setCharacterSize(40);
		text.setLetterSpacing(2);
		text.setStyle(sf::Text::Bold);

		text.setPosition(10, 10);
		behindTextBox.setSize(sf::Vector2f(text.getGlobalBounds().width + 32, 64));
		// Draw it
		getWindow.draw(behindTextBox);
		getWindow.draw(text);
	}

private:
	sf::Music music;
	Player* player;
	std::vector<Tile*> tileset;
};