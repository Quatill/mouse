#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Game.h"
class Player
{
private:
	Game window;

	sf::RectangleShape shape;
	sf::Vector2f playerSize;
	sf::Vector2f playerOrigin;
	sf::Vector2f playerPos;

	float movementSpeed;

	void initVariables();
	void initShape();

public:
	
	// Constructors / Destructors
	Player();
	virtual ~Player();

	// Functions
	void inputUpdate();
	void windowBoundsCollision(sf::RenderTarget* target);
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

	void mousePosition();

};

