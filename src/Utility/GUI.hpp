#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

class Button
{
public:
	Button(std::string name, float x, float y, float length)
	{
		this->name = name;
		this->x = x;
		this->y = y;
		this->length = length;

		font.loadFromFile("content/fonts/BebasNeue-Regular.ttf");
	}

	std::string getName()
	{
		return this->name;
	}

	bool Hover(sf::Vector2i pos, sf::Vector2u windowSize)
	{
		float heightPercentage = 0.09f;
		float buttonHeight = windowSize.y * heightPercentage;

		float xRatio = (float)windowSize.x / (float)this->initialWindowSize.x;
		float yRatio = (float)windowSize.y / (float)this->initialWindowSize.y;

		float currentX = this->x * xRatio;
		float currentY = this->y * yRatio;
		float currentWidth = this->length * xRatio;
		float currentHeight = buttonHeight * yRatio;

		return (pos.x < currentX + currentWidth && pos.x > currentX && pos.y < currentY + currentHeight && pos.y > currentY);
	}

	void Render(sf::RenderWindow& getWindow, sf::Vector2u windowSize, void (*_setup)(void*), void* userData = nullptr)
	{

		this->Render(getWindow, windowSize);

		bool isHovering = Hover(sf::Mouse::getPosition(getWindow), windowSize);

		if (isHovering && sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::isButtonPressed(sf::Mouse::Left) != mouseState)
		{
			if (_setup != nullptr)
			{
				_setup(userData);
			}
		}

		mouseState = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	void Render(sf::RenderWindow& getWindow, sf::Vector2u windowSize)
	{

		if (initialWindowSize.x == 0 || initialWindowSize.y == 0)
		{
			this->initialWindowSize = windowSize;
		}
		bool isHovering = Hover(sf::Mouse::getPosition(getWindow), windowSize);

		sf::RectangleShape b1(sf::Vector2f(length, 75));
		if (!isHovering)
		{
			static const sf::Color DarkGray(69, 69, 69);
			b1.setFillColor(DarkGray);
		}
		else
		{
			b1.setFillColor(sf::Color::Red);
		}
		b1.setPosition(x, y);
		getWindow.draw(b1);

		sf::RectangleShape b2(sf::Vector2f(length - 10, 65));
		if (!isHovering)
		{
			b2.setFillColor(sf::Color::White);
		}
		else
		{
			b2.setFillColor(sf::Color::Black);
		}

		b2.setPosition(x + 5, y + 5);
		getWindow.draw(b2);

		sf::Text text(name, font);
		text.setCharacterSize(72);
		text.setLetterSpacing(2);
		text.setStyle(sf::Text::Bold);
		if (!isHovering)
		{
			text.setFillColor(sf::Color::Black);
		}
		else
		{
			text.setFillColor(sf::Color::Red);
		}

		text.setPosition(sf::Vector2f(x + length / 2 - text.getLocalBounds().width / 2, y - 10));

		getWindow.draw(text);
	}

private:
	bool mouseState;
	std::string name;
	sf::Font font;
	float x, y, length;
	float widthPercentage, heightPercentage;
	sf::Vector2u initialWindowSize;
};