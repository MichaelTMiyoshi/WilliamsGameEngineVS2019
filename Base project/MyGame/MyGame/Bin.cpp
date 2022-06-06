/*
Name: Caroline Burrow
Program: Make the program have a ship show up when you run it
Pseudocode:Make the texture, make the ship show up
Maintenance Log: started 3/22/2022 finished 3/22/2022
*/


#include "Bin.h"
#include "Water.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

void Bin::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += SPEED * msElapsed;

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float WaterX = x + bounds.width;
		float WaterY = y + (bounds.height / 2.0f);

		WaterPtr laser = std::make_shared<Water>(sf::Vector2f(WaterX, WaterY));
		GAME.getCurrentScene().addGameObject(laser);
	}
}

Bin::Bin()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}

void Bin::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}