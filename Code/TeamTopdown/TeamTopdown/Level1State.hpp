#ifndef Level1State_HPP
#define Level1State_HPP

#include "stdafx.h"
#include "GameStateManager.hpp"
#include "GameState.hpp"
#include "controlsController.h"
#include "controlsInput.h"
#include "EntityController.h"
#include "Camera.h"
#include "Cursor.h"
#include <string>

class Level1State : public GameState {
private:
	sf::RenderWindow & window;
	GameStateManager & gsm;
	ControlsInput & controlsInput;
	EntityController & entityCtrl;
	Camera & camera;
public:
	Level1State(sf::RenderWindow & w, GameStateManager & gsm, ControlsInput & ci, EntityController & ec, Camera & cm);
	void HandleInput();
	void Update();
	void Draw();
};

#endif // Level1State_HPP