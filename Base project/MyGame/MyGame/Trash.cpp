#include "Meteor.h"
#include "GameScene.h"
#include "Explosion.h"

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();

		scene.increaseScore();

		otherGameObject.makeDead();
		
		ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
		scene.addGameObject(explosion);
	}
	makeDead();
 }

const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();

		makeDead();
	}
	else
	{
	 (sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y)));
	}
}



