#pragma once

#include "../Utility/GUI.hpp"
#include "Platform/Platform.hpp"
#include "Scene.hpp"

#include <iostream>

#include "../Entity/Player.hpp"

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

		music.openFromFile("content/music/gameloop.wav");
		music.setVolume(100);
		music.setLoop(true);
		music.play();
	}

	void Render(sf::RenderWindow& getWindow) override
	{
		player->Render(getWindow);
	}

private:
	sf::Music music;
	Player* player;
};