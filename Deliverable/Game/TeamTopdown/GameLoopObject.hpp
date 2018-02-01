#ifndef GameLoopObject_HPP
#define GameLoopObject_HPP

#include "stdafx.h"
#include <SFML/Graphics.hpp>

/// The base class for all objects used in a game loop.
//
/// This class is abstract, only having the virtual methods HandleInput, Update,
/// Draw and Reset. Currently, both GameStateManager and GameState inherit this
/// class, while GameState doesn't add anything new, so it is basically the same
/// class under a different name. We should decide if we merge GameLoopObject
/// and GameState or if we add more functionality to GameState.
class GameLoopObject {
public:
	/// Constructor method
	//
	/// Empty constructor method taking no arguments.
	GameLoopObject();
	/// Destructor method
	//
	/// Empty destructor.
	virtual ~GameLoopObject();
	/// virtual update method to be used in a game loop.
	//
	/// a virtual method. child class should implement its own functionality.
	virtual void Update();
	/// virtual draw method to be used in a game loop.
	//
	/// a virtual method. child class should implement its own functionality.
	virtual void Draw(sf::RenderWindow & window);
	/// virtual HandleInput method to be used in a game loop.
	//
	/// a virtual method. child class should implement its own functionality.
	virtual void HandleInput();
	/// virtual reset method to reset the object to default startup parameters.
	//
	/// a virtual method. child class should implement its own functionality.
	virtual void Reset();
};

#endif // GameLoopObject_HPP