#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"

// Game Engine Class

class Game
{

private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event evnt;

	//Player
	Player player;
	
	// Functions
	void initializeVariables();
	void initWindow();

public:

	// Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	// Functions
	void pollEvents();
	void update();
	void render();

};
