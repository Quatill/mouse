#include <iostream>
#include "Game.h"

int main()
{	
	// Initialize Game Engine
	Game game;
	
	
	// Game loop
	while (game.running())
	{
		// Update
		game.update();
		
		// Render
		game.render();
	}

	return 0;
}