#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "../Entity/Player.hpp"

class Tile
{
public:
	Tile(sf::Vector2f position, std::string name)
	{
		this->name = name;
		TileShape.setSize(sf::Vector2f(64, 64));
		TileShape.setPosition(position);
	};

	Tile(sf::Vector2f position, std::string name, int side)
	{
		this->name = name;
		TileShape.setSize(sf::Vector2f(64, 64));
		TileShape.setPosition(position);
		this->side = side;
	};

	void Render(sf::RenderWindow& getWindow, Player* player)
	{
		sf::Texture tileTexture;
		tileTexture.loadFromFile("content/textures/tiles/" + name + ".png");

		TileShape.setTexture(&tileTexture);
		getWindow.draw(TileShape);

		sf::RectangleShape topCollider(sf::Vector2f(64, 2));
		topCollider.setPosition(TileShape.getPosition());

		sf::RectangleShape bottomCollider(sf::Vector2f(64, 2));
		bottomCollider.setPosition(sf::Vector2f(TileShape.getPosition().x, TileShape.getPosition().y + 64));

		sf::RectangleShape leftCollider(sf::Vector2f(2, 64));
		leftCollider.setPosition(sf::Vector2f(TileShape.getPosition().x, TileShape.getPosition().y));

		sf::RectangleShape rightCollider(sf::Vector2f(2, 64));
		rightCollider.setPosition(sf::Vector2f(TileShape.getPosition().x + 64, TileShape.getPosition().y));

		if (false) // used for debugging, ignore
		{
			getWindow.draw(topCollider);
			getWindow.draw(bottomCollider);
			getWindow.draw(rightCollider);
			getWindow.draw(leftCollider);
		}

		sf::FloatRect playerHitbox = player->getShape().getGlobalBounds();
		// note : each tile can only collide left / right or top / bottom
		// surely this wont cause any issue that will cause a fuckton of headaches (foreshadowing)

		if (side)
		{
			if (playerHitbox.intersects(topCollider.getGlobalBounds()))
			{
				// Handle collision with top collider
				player->setPosition(player->getPosition().x, topCollider.getPosition().y - playerHitbox.height);
			}
			if (playerHitbox.intersects(bottomCollider.getGlobalBounds()))
			{
				// Handle collision with bottom collider
				player->setPosition(player->getPosition().x, bottomCollider.getPosition().y);
			}
		}
		else
		{
			if (playerHitbox.intersects(leftCollider.getGlobalBounds()) && player->getVelocity().x >= 0)
			{
				// Handle collision with left collider
				player->setPosition(leftCollider.getPosition().x - playerHitbox.width, player->getPosition().y);
			}
			if (playerHitbox.intersects(rightCollider.getGlobalBounds()) && player->getVelocity().x <= 0)
			{
				// Handle collision with right collider
				player->setPosition(rightCollider.getPosition().x, player->getPosition().y);
			}
		}
	}

	sf::RectangleShape getShape()
	{
		return TileShape;
	}

private:
	int side = 0;
	std::string name;
	sf::RectangleShape TileShape;
};