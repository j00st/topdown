#ifndef GameState_HPP
#define GameState_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include <string>

/// The base class for all gamestates.
//
/// This class is abstract. This class is a GameLoopObject and adds nothing new.
/// It is basically the same class under a different name. Eventually it should
/// be decided if more functionality is to be added to this class or if it is
/// going to be merged with GameLoopObject.
//
/// GameState has the following virtual methods:
/// - Update()
/// - Draw()
/// - HandleInput()
/// - Reset()
//
/// An implementation of a gamestate must implement all of these methods so that
/// the GameStateManager can call update, draw and handleinput 60 times per
/// second in the game loop and reset the gamestate when necessary.
//
/// The GameStateManager can only run one gamestate at a time and each gamestate
/// must be designed with this in mind. When one gamestate is running, all other
/// gamestates are paused as they are not updated.
class GameState : public GameLoopObject {
public:
	/// Constructor method
	//
	/// Empty constructor method taking no arguments.
	GameState();
	/// Destructor method.
	//
	/// Empty destructor method taking no arguments.
	virtual ~GameState();
	/// Virtual update method to be used in a game loop.
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
	/// virtual reset method to reset the gamestate to default.
	//
	/// A virtual method. Child class should implement its own functionality.
	/// This method should be called whenever it is needed to reset an entire
	/// gamestate to its default values. All the reset functions of the objects
	/// used in this gamestate should be called here.
	virtual void Reset();
};

#endif //GameState_HPP