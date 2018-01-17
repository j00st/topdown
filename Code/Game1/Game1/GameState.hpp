#ifndef GameState_HPP
#define GameState_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"

/// gamestate base class
class GameState : GameLoopObject {
public:
	GameState(); // constructor
	virtual ~GameState(); // destructor

	/*
	 * Game Loop functions
	 */
	virtual void Update();
	virtual void Draw();
	virtual void HandleInput();
	virtual void Reset();
};

#endif //GameState_HPP