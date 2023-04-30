#pragma once

#include "../Utility/GUI.hpp"
#include "Platform/Platform.hpp"
#include "Scene.hpp"

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class MainMenu : public Scene
{
public:
	MainMenu()
	{
		std::cout << "MainMenu was created" << std::endl;
		this->name = "MainMenu";

		Play = new Button("Play", ((1280 / 2) - 300), 250, 600);
		Credit = new Button("Credits", ((1280 / 2) - 300), 350, 600);
		Other = new Button("Other games", ((1280 / 2) - 300), 450, 600);
		Option = new Button("Options", ((1280 / 2) - 300), 550, 290);
		Quit = new Button("Quit", ((1280 / 2) + 10), 550, 290);
		std::cout << "Trying to play music" << std::endl;

		music.openFromFile("content/music/main.wav");
		music.setVolume(100);
		music.setLoop(true);
		music.play();
	};

	void Render(sf::RenderWindow& getWindow) override
	{
		sf::Texture BackGround_Texture;
		BackGround_Texture.loadFromFile("content/textures/mainBack.png");

		sf::RectangleShape BackGround(sf::Vector2f(1280, 720));
		BackGround.setTexture(&BackGround_Texture);

		getWindow.draw(BackGround);

		sf::Font font;
		font.loadFromFile("content/fonts/BebasNeue-Regular.ttf");
		// Create a text
		std::string _name = "{Game's title or something}";
		sf::Text text(_name, font);
		text.setCharacterSize(80);
		text.setLetterSpacing(2);
		text.setStyle(sf::Text::Bold);

		text.setPosition((1280 / 2) - (text.getLocalBounds().width / 2), 50);
		// Draw it
		getWindow.draw(text);

		Play->Render(getWindow, getWindow.getSize());
		Credit->Render(getWindow, getWindow.getSize());
		Other->Render(getWindow, getWindow.getSize());
		Option->Render(getWindow, getWindow.getSize());
		Quit->Render(getWindow, getWindow.getSize());
	}

private:
	sf::Music music;
	sf::RenderWindow* window;
	Button *Quit, *Play, *Option, *Credit, *Other;
};