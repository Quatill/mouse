#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 5.f;

}

//Player parameters
void Player::initShape()
{	
	this->playerSize.x = 75.f;
	this->playerSize.y = 75.f;

	this->playerOrigin.x = this->playerSize.x/2;
	this->playerOrigin.y = this->playerSize.y/2;

	this->playerPos.x = 750.f;
	this->playerPos.y = 550.f;

	this->shape.setSize(this->playerSize);
	this->shape.setOrigin(this->playerOrigin);
	this->shape.setFillColor(sf::Color::Yellow);
	this->shape.setPosition(this->playerPos);

}

// Constructors / Destructors
Player::Player()
{
	this->initVariables();
	this->initShape();

}

Player::~Player()
{

}

// Functions

//Keyboard Inputs (movement)
void Player::inputUpdate()
{
	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	//Down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	//Left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
}


void Player::windowBoundsCollision(sf::RenderTarget* target)
{
	// Up
	if (this->shape.getPosition().y <= 40.f)
	{
		this->shape.setPosition(this->shape.getPosition().x, 40.f);
	}

	// Down
	else if (this->shape.getPosition().y >= 560.f)
	{
		this->shape.setPosition(this->shape.getPosition().x, 560.f);
	}

	// Left
	if (this->shape.getPosition().x <= 40.f)
	{
		this->shape.setPosition(40.f, this->shape.getPosition().y);
	}
	
	// Right
	else if (this->shape.getPosition().x >= 760.f)
	{
		this->shape.setPosition(760.f, this->shape.getPosition().y);
	}

}


void Player::update(sf::RenderTarget* target)
{
	this->windowBoundsCollision(target);
	this->inputUpdate();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Player::mousePosition()
{

}

