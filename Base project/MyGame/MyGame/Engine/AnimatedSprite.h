#pragma once

#include <memory>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

// This controlls how fast animations are by default.
// It specifies how long each frame is displayed on the screen.
const int DEFAULT_MS_PER_FRAME = 20;

// Specifies how to play an animation.
enum AnimationMode
{
	LoopForwards,
	LoopBackwards,
	OnceForwards,
	OnceBackwards,
	FirstFrameOnly
};

// Specifies where the "orgin" of the sprite is. This determines where on the screen
// we'll draw the sprite relative to its position. For example, if the origin is
// TopLeft, all the sprite's pixels will be placed to the right of and below its
// current position:
//
//  | Sprite's position
// \./
//  --------
//  |sprite|  <-- With TopLeft, the sprite is drawn below and to the right of its position
//  --------
//
// The default value used by AnimatedSprite is Center.
enum OriginMode
{
	TopLeft,
	TopMiddle,
	TopRight,
	MiddleLeft,
	Center,
	MiddleRight,
	BottomLeft,
	BottomMiddle,
	BottomRight
};

// A sprite that can have multiple animations and play them with different AnimationModes.
class AnimatedSprite : public GameObject
{
public:
	// Constructs the sprite with a specified location and frame rate.
	// If you don't provide a frame rate, the default frame rate is used.
	AnimatedSprite(sf::Vector2f position, int msPerFrame = DEFAULT_MS_PER_FRAME);

	// Sets the spritesheet texture we will use for animation frames.
	void setTexture(sf::Texture &texture);

	// Sets the position of the sprite.
	void setPosition(sf::Vector2f position);

	// Set the origin mode, which specifies how we draw the sprite relative to its position.
	void setOriginMode(OriginMode origin);

	// Adds an animation, which is a sequence of frames associated with a name.
	void addAnimation(std::string name, std::vector<sf::IntRect> frames);

	// Plays an animation by name, with a given AnimationMode.
	void playAnimation(std::string name, AnimationMode mode);

	// Returns true if the sprite is currently playing.
	bool isPlaying();

	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();

private:
	// This map associates the name of the animation (a string) with
	// all the frames for that animation (a vector of IntRect).
	// The vector is sort of like an array that can resize itself,
	// and the IntRect is simply a rectangle that specifies where
	// in the texture that frame of animation is located.
	std::map<std::string, std::vector<sf::IntRect>> animations_;

	// The name of the animation being played.
	std::string currentAnimation_;

	// The mode the current animation is being played in.
	AnimationMode currentMode_;

	// True if we are playing the animation (changing frames over time).
	bool isPlaying_;

	// The sprite we draw to the screen.
	sf::Sprite sprite_;

	// The origin mode, which determines how we draw the sprite on the screen.
	OriginMode originMode_ = Center;

	// How many frames are in the animation.
	int numFrames_;

	// How many miliseconds each frame is shown for.
	int msPerFrame_;

	// How many miliseconds the current frame has been displayed.
	int msSinceLastFrame_;

	// The number of the current frame in the sequence of frames for
	// the current animatoin.
	int currentFrameNum_;

	// Functions to determine which frame to display.
	void determineNumFrames();
	void determineFirstFrameNum();
	void determineNextFrameNum();

	// Sets the rectangle in our texture that contains pixels for the
	// current frame of the current animation.
	void setTextureRectForFrame();

	// True if we should draw the sprite to the screen. This will be
	// false if we don't have animation frame information.
	bool isDrawable();
};