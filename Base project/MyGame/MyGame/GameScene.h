#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  int getScore();
  void increaseScore();

private:
    int score_ = 0;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
