#pragma once

#include "Engine/GameEngine.h"

class Meteor : public GameObject
{
public:
	Meteor(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Meteor>MeteorPtr;
