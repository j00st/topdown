#ifndef GameLoopObject_HPP
#define GameLoopObject_HPP

#include "stdafx.h"
#include <SFML/Graphics.hpp>


/// gamestate base class
class GameLoopObject {
protected:
	sf::RenderWindow & window;
public:
	GameLoopObject(sf::RenderWindow & w); // constructor
	virtual ~GameLoopObject(); // destructor

	/*
	* Game Loop functions
	*/
	virtual void Update();
	virtual void Draw();
	virtual void HandleInput();
	virtual void Reset();
};

#endif // GameLoopObject_HPP