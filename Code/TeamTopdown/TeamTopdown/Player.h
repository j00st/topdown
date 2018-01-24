#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include "controlsInput.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "Entity.h"
#include "EntityController.h"
#include "PlayerStats.h"
#include <SFML/Graphics.hpp>
#include "Cursor.h"

/*! \class Player
\brief Handles player movement, interaction, animations and art*/
class Player : public Entity
{
private:
	Cursor & cursor;
	ControlsInput & controlsInput; /*!< Reference to cursor location used to rotate sprite */
	EntityController & entityController;
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	Graphic playerSprite = Graphic("sprites/character.png", true);
	RectangleShape hitbox;
public:
	PlayerStats stats;
	Player(sf::Vector2f position, sf::Vector2f size, Cursor & c, ControlsInput & ci, EntityController & ec, bool isSolid = false);
	void HandleInput();
	void update() override;
	void rotate(); /*!< Rotates the player sprite */
	void draw(sf::RenderWindow &window) override; /*!< Draws the player on window */
	sf::Vector2f getPos(); /*!< Returns position of the player */
	void TriggerDeath();
	void TriggerLife();
	void playerFire();
	float calcSpeed();
	bool playerColliding(sf::Vector2f direction);
};

#endif