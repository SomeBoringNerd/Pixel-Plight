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

	sf::Texture sprites[4][9], Reference;

	int FACING = 0, intAnim = 0, frame = 0;

	void Start() override
	{
		std::cout << "Player has been instanciated with " << getHealth() << " hp" << std::endl;
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
		sprites[2][5].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_005.png");
		sprites[2][6].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_006.png");
		sprites[2][7].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_007.png");
		sprites[2][8].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_008.png");

		sprites[3][0].loadFromFile("content/textures/characters/MainCharacter/main_left_idle.png");
		sprites[3][1].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_001.png");
		sprites[3][2].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_002.png");
		sprites[3][3].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_003.png");
		sprites[3][4].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_004.png");
		sprites[3][5].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_005.png");
		sprites[3][6].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_006.png");
		sprites[3][7].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_007.png");
		sprites[3][8].loadFromFile("content/textures/characters/MainCharacter/main_side_animated_left_008.png");
	}

	void Update(sf::RenderWindow& getWindow) override
	{
		sf::RectangleShape Player(sf::Vector2f(32, 64));
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

		if (frame >= 15 && (x != 0 || y != 0))
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
				if (intAnim < 8)
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

		Player.setTexture(&sprites[FACING][intAnim]);

		if (FACING == 3)
		{
			Player.setScale(-1.0f, 1.0f);
		}
		else
		{
			Player.setScale(1.0f, 1.0f);
		}

		// Instead of showing a white box we show nothing, meh, work too (should load a T-pose)
		if (sprites[FACING][intAnim].getSize().x == 0)
		{
			Player.setTexture(&Reference);
		}

		Player.setPosition(getPosition());

		getWindow.draw(Player);
	}
};