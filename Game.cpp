
#include "Game.h"

// Private Functions
void Game::initializeVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

// Constructors / Destructors
Game::Game()
{
	this->initializeVariables();
	this->initWindow();

}

Game::~Game()
{
	delete this->window;


}


// Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}




// Functions


void Game::pollEvents()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (this->evnt.type)
		{
		
		case sf::Event::Closed:
			this->window->close();
			break;
		
		case sf::Event::KeyPressed:
			if (this->evnt.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}

	}
}


void Game::update()
{
	this->pollEvents();

	this->player.update(this->window);

}

void Game::render()
{
	// Clearing old frame with color
	this->window->clear(sf::Color(128, 0, 128, 255));
	
	// Draw Game objects
	this->player.render(this->window);
	
	this->window->display();

}
