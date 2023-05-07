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

#include "../TheDumpsterFire.hpp"

class Credit : public Scene
{
public:
	Credit()
	{
		this->name = "Credit";

		back = new Button("Back", (25), 720 - 100, 300);
		std::cout << "Trying to play music" << std::endl;

		music.openFromFile("content/music/credit.wav");
		music.setVolume(100);
		music.setLoop(true);
		music.play();
	};

	void ThisFunctionAllowTheCodeToCompileDontQuestionItPlease()
	{}

	static void BackToMain(void* userData)
	{
		Credit* creditS = static_cast<Credit*>(userData);
		creditS->music.stop();
		std::cout << "Should switch scenes" << std::endl;
		LoadAnotherScene("MainMenu");
	}

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
		std::string _name = "Special thanks to";
		sf::Text text(_name, font);
		text.setCharacterSize(80);
		text.setLetterSpacing(2);
		text.setStyle(sf::Text::Bold);
		text.setPosition((1280 / 2) - (text.getLocalBounds().width / 2), 50);
		getWindow.draw(text);

		text.setCharacterSize(40);

		_name = "@zoeyoung2563 : musics that are used in the game";
		text.setString(_name);
		text.setPosition((1280 / 2) - (text.getLocalBounds().width / 2), 200);
		getWindow.draw(text);

		_name = "Aseprite team : making an amazing";
		text.setString(_name);
		text.setPosition((1280 / 2) - (text.getLocalBounds().width / 2), 250);
		getWindow.draw(text);

		_name = "pixel art software and making it open source";
		text.setString(_name);
		text.setPosition((1280 / 2) - (text.getLocalBounds().width / 2), 290);
		getWindow.draw(text);

		back->Render(getWindow, getWindow.getSize(), &BackToMain, this);
	}

private:
	Button* back;
	sf::Music music;
	sf::RenderWindow* window;
};