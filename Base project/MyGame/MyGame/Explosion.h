#pragma once

#include "Engine/GameEngine.h"

class Explosion : public AnimatedSprite
{
public:

	Explosion(sf::Vector2f pos);

	void update(sf::Time& elapsed);

private:
	void SetUpExplosionAnimation();

	sf::Sound boom_;
};

typedef std::shared_ptr<Explosion>ExplosionPtr;
