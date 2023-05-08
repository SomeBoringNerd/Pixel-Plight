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

		music.openFromFile("content/music/gameloop.wav");
		music.setVolume(getGlobalMusicVolume());
		music.setLoop(true);
		music.play();
	}

	void Render(sf::RenderWindow& getWindow) override
	{
		for (Tile* tile : tileset)
		{
			tile->Render(getWindow, player);
		}
		player->Render(getWindow);
	}

private:
	sf::Music music;
	Player* player;
	std::vector<Tile*> tileset;
};