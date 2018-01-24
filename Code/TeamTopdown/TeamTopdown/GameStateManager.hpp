#ifndef GameStateManager_HPP
#define GameStateManager_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "GameState.hpp"
#include<string>
#include<map>

/// The game's GameStateManager. Handles most of the game loop.
//
/// The GameStateManager is created once and holds a list (map actually) of all
/// gamestates the game has. All gamestates are loaded on startup, which is not
/// memory efficiënt. The GameStateManager calls its current gamestate's update,
/// draw and handleinput methods 60 times per second during the game loop. When
/// switching gamestates, the new gamestate is first set with the SetNext method
/// and eventually switched to with the SwitchState method. For this, this class
/// holds two GameState pointers that point to gamestates in the list. One to
/// the current state that is now running and one to the next state to which the
/// GameStateManager will soon switch.
//
/// As soon as the GameStateManager is made, gamestates should be added to it
/// using the AddGameState method and immediately after, the SetNext and
/// SwitchState methods should be called.
class GameStateManager : public GameLoopObject {
private:
	GameState * currentState;
	GameState * nextState;
public:
	std::map<std::string, GameState *> gameStates{};
	/// GameStateManager constructor method. Sets its pointers to be empty.
	//
	/// When the GameStateManager is made, the gameStates list is empty and its
	/// current state and next state pointers will be initialized to be empty.
	GameStateManager();
	/// Method used to store new gamestates into the manager's list, to be used.
	//
	/// This method asks for a string and a gamestate and then stores the
	/// gamestate using the chosen string as its key.
	/// This method currently has no protection against entering undefined data.
	void AddGameState(std::string name, GameState * state);
	/// Method used to set the next gamestate.
	//
	/// This method asks for a gamestate name and then checks if it exists in
	/// the GameStateManager's list of gamestates. If so, the inserted state is
	/// set. If not, nothing happens.
	void SetNext(std::string name);
	/// Method used to switch to the next state, that was previously set.
	//
	/// This method checks if a new state has been set. If not, nothing happens.
	/// But if a next state has been previously set, the GameStateManager 
	/// will then proceed to switch the current state to the next state, which
	/// from then on will be run in the game loop. The 'nextState' pointer will
	/// be cleared and stay empty until a new state is set.
	void SwitchState();
	/// Calls the currently selected gamestate's HandleInput method.
	//
	/// This method should be called in each iteration of the game loop. It will
	/// then proceed to call the currently selected gamestate's HandleInput
	/// method and do only that.
	void HandleInput();	
	/// Calls the currently selected gamestate's Update method.
	//
	/// This method should be called in each iteration of the game loop. It will
	/// then proceed to call the currently selected gamestate's Update method
	/// and do only that.
	void Update();
	/// Calls the currently selected gamestate's Draw method.
	//
	/// This method should be called in each iteration of the game loop. It will
	/// then proceed to call the currently selected gamestate's Draw method and
	/// do only that.
	void Draw(sf::RenderWindow & window);
	/// Calls the currently selected gamestate's Reset method.
	//
	/// This method will call the currently selected gamestate's Reset method
	/// and do only that.
	void Reset();
	// implement this state:
	// void ResetAllStates();
	// for each state in map, ->Reset();
};

#endif //GameStateManager_HPP