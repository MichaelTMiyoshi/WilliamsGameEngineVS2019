#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();
};

typedef std::shared_ptr<GameScene> GameScenePtr;
