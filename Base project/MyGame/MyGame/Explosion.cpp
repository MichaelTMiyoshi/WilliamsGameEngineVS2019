#include "Explosion.h"

Explosion::Explosion(sf::Vector2f pos) : AnimatedSprite(pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/explosion-spritesheet.png"));
	SetUpExplosionAnimation();
	playAnimation("explosion", AnimationMode::OnceForwards);

	boom_.setBuffer(GAME.getSoundBuffer("Resources/boom.wav"));
	boom_.play();
}

void Explosion::SetUpExplosionAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(  0, 0, 64, 64));	// frame 1
	frames.push_back(sf::IntRect( 64, 0, 64, 64));	// frame 2
	frames.push_back(sf::IntRect(128, 0, 64, 64));	// frame 3
	frames.push_back(sf::IntRect(192, 0, 64, 64));	// frame 4
	frames.push_back(sf::IntRect(256, 0, 64, 64));	// frame 5
	frames.push_back(sf::IntRect(320, 0, 64, 64));	// frame 6
	frames.push_back(sf::IntRect(384, 0, 64, 64));	// frame 7
	frames.push_back(sf::IntRect(448, 0, 64, 64));	// frame 8
	frames.push_back(sf::IntRect(512, 0, 64, 64));	// frame 9

	addAnimation("explosion", frames);
}

void Explosion::update(sf::Time& elapsed)
{
	AnimatedSprite::update(elapsed);

	if (!isPlaying())
	{
		makeDead();
	}
}