#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Scene.h"

// This is a convenience that lets us type "GAME" instead of "Game::instance()" everywhere.
#define GAME Game::instance()

typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::shared_ptr<sf::SoundBuffer> SoundBufferPtr;
typedef std::shared_ptr<sf::Font> FontPtr;

// The Game manages scenes and runs the main game loop.
class Game
{
public:
	// This method returns the one and only instance of Game in our program.
	// Since there can only be one instance of game, we call it a singleton.
	static Game& instance()
	{
		static Game game;
		return game;
	}

	// Creates our render window. Must be called once at startup.
	void initialize(int windowWidth, int windowHeight, std::string windowTitle);

	// Returns a reference to the game's RenderWindow.
	sf::RenderWindow& getRenderWindow();

	// Get a texture (pixels) from a file
	sf::Texture& getTexture(std::string fileName);

	// Get a sound from a file
	sf::SoundBuffer& getSoundBuffer(std::string fileName);

	// Get a font from a file
	sf::Font& getFont(std::string fileName);

	// Returns the active running scene.
	Scene& getCurrentScene();

	// Specifies the next Scene to run.
	void setScene(ScenePtr scenePtr);

	// Begins the main game loop with the initial scene.
	void run();

private:
	// We keep a current and next scene so the scene can be changed mid-frame.
	std::shared_ptr<Scene> currentScene_;
	std::shared_ptr<Scene> nextScene_;

	// Cached textures
	std::map<std::string, TexturePtr> textures_;

	// Cached sounds
	std::map<std::string, SoundBufferPtr> sounds_;

	// Cached fonts
	std::map<std::string, FontPtr> fonts_;

	// The window we will draw to.
	sf::RenderWindow window_;

	// A flag to prevent being initialized twice.
	bool initialized_;

	// C++ singleton stuff (you can safely ignore it).
	Game() {};
	Game(Game const&);
	void operator=(Game const&);
};
