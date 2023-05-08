#pragma once

#include "../TheDumpsterFire.hpp"
#include "Entity.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

class Player : public Entity
{
public:
	using Entity::Entity;

	sf::Texture sprites[4][5], Reference;

	int FACING = 0, intAnim = 0, frame = 0;

	void Start() override
	{
		Reference.loadFromFile("content/textures/characters/MainCharacter/main_T_Pose.png");
		sprites[0][0].loadFromFile("content/textures/characters/MainCharacter/main_front_idle.png");
		sprites[0][1].loadFromFile("content/textures/characters/MainCharacter/main_front_walk.png");
		sprites[0][2].loadFromFile("content/textures/characters/MainCharacter/main_front_walk2.png");

		sprites[1][0].loadFromFile("content/textures/characters/MainCharacter/main_back_idle.png");
		sprites[1][1].loadFromFile("content/textures/characters/MainCharacter/main_back_walk.png");
		sprites[1][2].loadFromFile("content/textures/characters/MainCharacter/main_back_walk2.png");

		sprites[2][0].loadFromFile("content/textures/characters/MainCharacter/main_left_idle.png");
		sprites[2][1].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_001.png");
		sprites[2][2].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_002.png");
		sprites[2][3].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_003.png");
		sprites[2][4].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_004.png");

		sprites[3][0].loadFromFile("content/textures/characters/MainCharacter/main_right_idle.png");
		sprites[3][1].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_right_001.png");
		sprites[3][2].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_right_002.png");
		sprites[3][3].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_right_003.png");
		sprites[3][4].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_right_004.png");

		PlayerShape.setSize(sf::Vector2f(64, 128));
		setPosition(500, 500);
	}

	void Revert()
	{
		std::cout << "Reverting player position" << std::endl;
		setPosition(prevX, prevY);
	}

	void Revert(std::string flag)
	{
		std::cout << "Reverting player position" << std::endl;
		if (flag == "onlyX")
		{
			setPosition(prevX, getPosition().y);
		}
		else if (flag == "onlyY")
		{
			setPosition(getPosition().x, prevY);
		}
	}

	void Update(sf::RenderWindow& getWindow) override
	{
		prevX = getPosition().x;
		prevY = getPosition().y;
		int x = 0, y = 0;

		switch (FACING)
		{
			default:
				FACING = 0;
				break;
			case 1:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					y -= 4;
					FACING = 1;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						x -= 4;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						x += 4;
					}
				}
				else
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						x -= 4;
						FACING = 2;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						x += 4;
						FACING = 3;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						y -= 4;
						FACING = 0;
					}
				}
				break;
			case 0:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					y += 4;
					FACING = 0;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						x -= 4;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						x += 4;
					}
				}
				else
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						x += 4;
						FACING = 2;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						x -= 4;
						FACING = 3;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						y -= 4;
						FACING = 1;
					}
				}
				break;
			case 2:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					x -= 4;
					FACING = 2;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						y += 4;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						y -= 4;
					}
				}
				else
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						y += 4;
						FACING = 0;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						y -= 4;
						FACING = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						x -= 4;
						FACING = 3;
					}
				}
				break;
			case 3:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					x += 4;
					FACING = 3;

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						y += 4;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						y -= 4;
					}
				}
				else
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						y += 4;
						FACING = 0;
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						y -= 4;
						FACING = 1;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						x += 4;
						FACING = 2;
					}
				}
				break;
		}

		if (x == 0 && y == 0)
		{
			intAnim = 0;
		}

		if (frame >= 10 && (x != 0 || y != 0))
		{
			if (FACING == 0 || FACING == 1)
			{
				if (intAnim < 2)
				{
					intAnim++;
				}
				else
				{
					intAnim = 1;
				}
			}
			else if (FACING == 2 || FACING == 3)
			{
				if (intAnim < 4)
				{
					intAnim++;
				}
				else
				{
					intAnim = 1;
				}
			}
			else
			{
				if (intAnim < 1)
				{
					intAnim++;
				}
				else
				{
					intAnim = 0;
				}
			}

			frame = 0;
		}
		else
		{
			frame++;
		}
		setPosition(getPosition().x + x, getPosition().y + y);
		//setPosition(getPosition().x, getPosition().y);

		PlayerShape.setTexture(&sprites[FACING][intAnim]);

		// Instead of showing a white box we show nothing, meh, work too (should load a T-pose)
		if (sprites[FACING][intAnim].getSize().x == 0)
		{
			PlayerShape.setTexture(&Reference);
		}

		PlayerShape.setPosition(getPosition());
		sf::Vector2f position = PlayerShape.getPosition();
		position += getVelocity();
		PlayerShape.setPosition(position);

		getWindow.draw(PlayerShape);
	}

	sf::Vector2f getVelocity()
	{
		return velocity;
	}

	sf::RectangleShape getShape()
	{
		return PlayerShape;
	}

	void setVelocity(sf::Vector2f velocity)
	{
		this->velocity = velocity;
	}

private:
	int prevX, prevY;
	sf::Vector2f velocity;
	sf::RectangleShape PlayerShape;
};