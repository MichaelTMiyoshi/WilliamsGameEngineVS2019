#include "GameObject.h"

// Stores a tag in our set of tags.
void GameObject::assignTag(std::string tag)
{
	tags_.emplace(tag);
}

// Returns true if we have the provided tag.
bool GameObject::hasTag(std::string tag)
{
	return tags_.find(tag) != tags_.end();
}

// Returns true if the game object is "dead" (should be removed from the scene).
bool GameObject::isDead()
{
	return isDead_;
}

// Sets the "dead" flag to true.
void GameObject::makeDead()
{
	isDead_ = true;
}

// Returns true if this object should be checked for collisions.
bool GameObject::isCollisionCheckEnabled()
{
	return isCollisionCheckEnabled_;
}

// Sets whether this object should be checked for collisions.
void GameObject::setCollisionCheckEnabled(bool isCollisionCheckEnabled)
{
	isCollisionCheckEnabled_ = isCollisionCheckEnabled;
}