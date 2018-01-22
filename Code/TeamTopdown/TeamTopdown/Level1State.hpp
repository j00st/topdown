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
	ControlsController & controlsCtrl;
	ControlsInput & controlsInput;
	EntityController & entityCtrl;
	Camera & camera;
	Cursor & cursor;
	sf::Font font1;
	sf::Text text1;
public:
	Level1State(sf::RenderWindow & w, GameStateManager & gsm, ControlsController & cc, ControlsInput & ci, EntityController & ec, Camera & cm, Cursor cr);
	void HandleInput();
	void Update();
	void Draw();
};

#endif // Level1State_HPP