#include "AnimatedSprite.h"

#include "Game.h"

// Construct the AnimatedSprite and set its initial position.
AnimatedSprite::AnimatedSprite(sf::Vector2f position, int msPerFrame) :
	msPerFrame_(msPerFrame),
	isPlaying_(false)
{
	setPosition(position);
}

// Sets the spritesheet texture we will use for animation frames.
void AnimatedSprite::setTexture(sf::Texture &texture)
{
	sprite_.setTexture(texture);
}

// Change the AnimatedSprite's position.
void AnimatedSprite::setPosition(sf::Vector2f position)
{
	sprite_.setPosition(position);
}

// Set the origin mode, which specifies how we draw the sprite relative to its position.
void AnimatedSprite::setOriginMode(OriginMode originMode)
{
	originMode_ = originMode;
}

// Adds a named sequence of animation frames to this AnimatedSprite,
// which can then be played.
void AnimatedSprite::addAnimation(std::string name, std::vector<sf::IntRect> frames)
{
	animations_[name] = frames;
}

// Plays the specified animation with the specified mode.
void AnimatedSprite::playAnimation(std::string name, AnimationMode mode)
{
	currentAnimation_ = name;
	currentMode_ = mode;
	isPlaying_ = true;

	// Reset the "timer" so we display the frame the right amount of time.
	msSinceLastFrame_ = 0;

	determineNumFrames();
	determineFirstFrameNum();
	setTextureRectForFrame();
}

bool AnimatedSprite::isPlaying()
{
	return isPlaying_;
}

// Determines the number of frames in the current animation.
void AnimatedSprite::determineNumFrames()
{
	numFrames_ = animations_[currentAnimation_].size();
}

// Sets the current frame number to the first frame of the
// animation, based on the animation mode.
void AnimatedSprite::determineFirstFrameNum()
{
	switch (currentMode_)
	{
	case LoopForwards:
	case OnceForwards:
	case FirstFrameOnly:
		// Forwards starts from frame 0.
		currentFrameNum_ = 0;
		break;
	case LoopBackwards:
	case OnceBackwards:
		// Backwards starts from the last frame.
		currentFrameNum_ = numFrames_ - 1;
		break;
	}
}

// Sets the next frame number based on animation mode.
void AnimatedSprite::determineNextFrameNum()
{
	// We don't need to determine the next frame if the animation is not playing.
	if (!isPlaying_)
	{
		return;
	}

	// We don't need to adjust the frame for FirstFrameOnly mode.
	if (currentMode_ == FirstFrameOnly)
	{
		return;
	}

	// Divide how much time has elapsed by the number of milliseconds per frame.
	// This tells us how many frames we should advance.
	int elapsedFrames = msSinceLastFrame_ / msPerFrame_;
	msSinceLastFrame_ = 0;

	// Add or subtract the elapsed frames based on whether we are animating
	// forwards or backwards.
	switch (currentMode_)
	{
	case LoopForwards:
	case OnceForwards:
		currentFrameNum_ += elapsedFrames;
		break;
	case LoopBackwards:
	case OnceBackwards:
		currentFrameNum_ -= elapsedFrames;
		break;
	}

	// If we've gone past the end of the animation, determine where we should be.
	if ((currentFrameNum_ >= numFrames_) || (currentFrameNum_ < 0))
	{
		switch (currentMode_)
		{
		case LoopForwards:
		case LoopBackwards:
			// Use modulo to make sure we wrap to the correct frame. For example,
			// if numFrames is 6, but currentFrameNum is 8, we should wrap around to frame 2, or
			// if numFrames is 6, but currentFrameNum is -2, we should wrap around to frame 4.
			currentFrameNum_ = currentFrameNum_ % numFrames_;

			// This compensates for the fact that in C++ -1 % 15 may equal -1,
			// whereas in math it would be 14.
			if (currentFrameNum_ < 0)
			{
				currentFrameNum_ = numFrames_ + currentFrameNum_;
			}
			break;
		case OnceForwards:
			// We never go past the last frame
			currentFrameNum_ = numFrames_ - 1;
			isPlaying_ = false;
			break;
		case OnceBackwards:
			// We never go past the first frame.
			currentFrameNum_ = 0;
			isPlaying_ = false;
			break;
		}
	}
}

// Waits until it's time to change the frame and then does so.
void AnimatedSprite::update(sf::Time& elapsed)
{
	// We don't need to update if we're not drawable.
	if (!isDrawable())
	{
		return;
	}

	// Update our "timer", and change the frame if we've waited long enough.
	msSinceLastFrame_ += elapsed.asMilliseconds();
	
	if (msSinceLastFrame_ >= msPerFrame_)
	{
		determineNextFrameNum();
		setTextureRectForFrame();
	}
}

// Sets the texture rectangle for the current frame of animation.
void AnimatedSprite::setTextureRectForFrame()
{
	// Gets the rectangle information from the animation's list of rects.
	sf::IntRect rect = animations_[currentAnimation_][currentFrameNum_];

	// Tell the sprite to use the new frame of pixel data.
	sprite_.setTextureRect(rect);

	// set the origin based on the Origin mode
	float originX = 0.0f;
	float originY = 0.0f;

	switch (originMode_)
	{
	case TopMiddle:
	case Center:
	case BottomMiddle:
		originX = (float)rect.width / 2.0f;
		break;
	case TopRight:
	case MiddleRight:
	case BottomRight:
		originX = (float)rect.width;
		break;
	};

	switch (originMode_)
	{
	case MiddleLeft:
	case Center:
	case MiddleRight:
		originY = (float)rect.width / 2.0f;
		break;
	case BottomLeft:
	case BottomMiddle:
	case BottomRight:
		originY = (float)rect.width;
		break;
	};

	sprite_.setOrigin(sf::Vector2f(originX, originY));
}

// Draw the sprite to the screen.
void AnimatedSprite::draw()
{
	// Don't draw if we're not drawable.
	if (!isDrawable())
	{
		return;
	}

	// Draw it.
	GAME.getRenderWindow().draw(sprite_);
}

// Returns our collision rectangle.
sf::FloatRect AnimatedSprite::getCollisionRect()
{
	// Just use the boundaries of the sprite.
	return sprite_.getGlobalBounds();
}

// Determines if the sprite has any animation data (frame rects) it can draw.
bool AnimatedSprite::isDrawable()
{
	// If no animations have been set, or if the current animation contains
	// no frames, then the sprite is not drawable.
	return (animations_.size() > 0 && !currentAnimation_.empty());
}