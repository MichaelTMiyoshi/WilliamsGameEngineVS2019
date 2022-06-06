#pragma once

#include "Engine/GameEngine.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(int score);

};

typedef std::shared_ptr<GameOverScene> GameOverScenePtr;
