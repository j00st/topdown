#ifndef GameState_HPP
#define GameState_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include <string>

/// gamestate base class
class GameState : public GameLoopObject {
public:
	GameState(); //: GameLoopObject(w) {}; // constructor
	virtual ~GameState(); // destructor

	/*
	 * Game Loop functions
	 */
	virtual void Update();
	virtual void Draw();
	virtual void HandleInput();
	virtual void Reset();
	virtual std::string Print();
};

#endif //GameState_HPP