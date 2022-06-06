#include "Laser.h"

sf::FloatRect Laser::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

const float SPEED = 1.2f;

Laser::Laser(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/Laser.png"));
	sprite_.setPosition(pos);
	assignTag("laser");
}

void Laser::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Laser::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x > GAME.getRenderWindow().getSize().x)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
}