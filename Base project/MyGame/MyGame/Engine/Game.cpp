#include "Game.h"
#include "SFML\System.hpp"

// The number of frames that will be drawn to the screen in one second.
const int FRAMES_PER_SECOND = 60;

// Creates the render window to which the scene will be drawn.
void Game::initialize(int windowWidth, int windowHeight, std::string windowTitle)
{
	// Only initialize once.
	if (initialized_) return;
	initialized_ = true;

	// Create the render window.
	window_.create(sf::VideoMode(windowWidth, windowHeight), windowTitle);
	window_.setFramerateLimit(FRAMES_PER_SECOND);
}

// Returns the render window.
sf::RenderWindow& Game::getRenderWindow()
{
	return window_;
}

// Get a texture (pixels) from a file
sf::Texture& Game::getTexture(std::string fileName)
{
	auto iter = textures_.find(fileName);

	if (iter != textures_.end())
	{
		return *iter->second;
	}

	TexturePtr texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(fileName);
	textures_[fileName] = texture;
	return *texture;
}

// Get a sound from a file
sf::SoundBuffer& Game::getSoundBuffer(std::string fileName)
{
	auto iter = sounds_.find(fileName);

	if (iter != sounds_.end())
	{
		return *iter->second;
	}

	SoundBufferPtr sound = std::make_shared<sf::SoundBuffer>();
	sound->loadFromFile(fileName);
	sounds_[fileName] = sound;
	return *sound;
}

// Get a font from a file
sf::Font& Game::getFont(std::string fileName)
{
	auto iter = fonts_.find(fileName);

	if (iter != fonts_.end())
	{
		return *iter->second;
	}

	FontPtr font = std::make_shared<sf::Font>();
	font->loadFromFile(fileName);
	fonts_[fileName] = font;
	return *font;
}

// Returns the current scene.
Scene& Game::getCurrentScene()
{
	return *currentScene_;
}

// Sets the next scene.
void Game::setScene(ScenePtr scenePtr)
{
	// If we don't have a current scene, set it.
	// Otherwise, note the next scene.
	if (currentScene_ == nullptr)
	{
		currentScene_ = scenePtr;
	}
	else
	{
		nextScene_ = scenePtr;
	}
}

// Runs the game loop.
void Game::run()
{
	sf::Clock clock;
	sf::Time time;

	// Keep looping until the window closes.
	while (window_.isOpen())
	{
		// If the next scene has been set, swap it with the curren scene.
		if (nextScene_ != nullptr)
		{
			currentScene_ = nextScene_;
			nextScene_ = nullptr;
			clock.restart();
		}

		// Get the time since the last frame, then have the scene update itself.
		time = clock.restart();
		currentScene_->update(time);
	}
}
