#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Scene
{
public:
	virtual void Render(sf::RenderWindow&) {};
	std::string name;
};