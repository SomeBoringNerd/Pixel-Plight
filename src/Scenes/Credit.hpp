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

		std::string __name = "@zoeyoung2563 : musics that are used in the game";
		sf::Text _text(__name, font);
		_text.setCharacterSize(40);
		_text.setLetterSpacing(2);
		_text.setStyle(sf::Text::Bold);
		_text.setPosition((1280 / 2) - (_text.getLocalBounds().width / 2), 200);
		getWindow.draw(_text);

		back->Render(getWindow, getWindow.getSize(), &BackToMain, this);
	}

private:
	Button* back;
	sf::Music music;
	sf::RenderWindow* window;
};