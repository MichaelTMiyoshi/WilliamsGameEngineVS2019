#pragma once

#include <list>
#include <memory>
#include "GameObject.h"

// The Scene manages all the GameObjects currently in the game.
class Scene
{
public:
	// Called by the Game instance once per frame.
	void update(sf::Time& time);

	// Puts a GameObject into the scene.
	void addGameObject(GameObjectPtr gameObjectPtr);

private:
	// This holds our game objects.
	std::list<GameObjectPtr> gameObjects_;

	// These are the functions we run each iteration of the game loop.
	void handleEvents();
	void handleCollisions();
	void updateGameObjects(sf::Time& time);
	void drawGameObjects();
	void removeDeadGameObjects();
};

typedef std::shared_ptr<Scene> ScenePtr;