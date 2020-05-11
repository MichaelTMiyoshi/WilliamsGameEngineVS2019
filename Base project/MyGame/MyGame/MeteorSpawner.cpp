#include "MeteorSpawner.h"

const int SPAWN_DELAY = 1000;

void MeteorSpawner::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	if (timer_ < 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		float meteorX = (float)(size.x + 100);
		float meteorY = (float)(rand() % (int)(size.y));
		//float meteorY = (float)(rand() % (int)(size.y * .80f) + (int)(0.5f * size.y));	// check rounding errors

		MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY));
		GAME.getCurrentScene().addGameObject(meteor);
	}
}