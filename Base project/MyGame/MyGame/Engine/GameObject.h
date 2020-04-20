#pragma once

#include <set>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

// This class represents every object in your game, such as the player, enemies, and so on.
class GameObject
{
public:
	// Tags let you annotate your objects so you can identify them later
	// (such as "player").
	void assignTag(std::string tag);
	bool hasTag(std::string tag);
	
	// "Dead" game objects will be removed from the scene.
	bool isDead();
	void makeDead();

	// update is called every frame. Use this to prepare to draw (move, perform AI, etc.).
	virtual void update(sf::Time& elapsed) {}

	// draw is called once per frame. Use this to draw your object to the screen.
	virtual void draw() {}

	// This flag indicates whether this game object should be checked for collisions.
	// The more game objects in the scene that need to be checked, the longer it takes.
	bool isCollisionCheckEnabled();
	void setCollisionCheckEnabled(bool isCollisionCheckEnabled);

	// This function lets you specify a rectangle for collision checks.
	virtual sf::FloatRect getCollisionRect() { return sf::FloatRect(); }

	// Use this to specify what happens when this object collides with another object.
	virtual void handleCollision(GameObject& otherGameObject) {}

	// Put any code here for deal with events such as mouse movement and key presses.
	virtual void handleEvent(sf::Event& event) {}

private:
	// Using a set prevents duplicates.
	std::set<std::string> tags_;

	bool isDead_ = false;
	bool isCollisionCheckEnabled_ = false;
};

typedef std::shared_ptr<GameObject> GameObjectPtr;