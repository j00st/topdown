#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include "controlsInput.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "bullet.h"
#include "Entity.h"
#include "PlayerStats.h"
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include "Hud.h"

using namespace sf;

/*! \class Player
\brief Handles player movement, interaction, animations and art*/
class Player : public Entity
{
private:
	enum states { alive, dead };
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	ControlsInput & controlsInput; /*!< Reference to cursor location used to rotate sprite */
	Graphic playerSprite = Graphic("sprites/character.png", true);
	RectangleShape hitbox;
	Cursor &cursor;
public:
	PlayerStats stats;
	Player( Vector2f position, Vector2f size, Cursor &c, ControlsInput& controlsInput, bool isSolid = false, int state = 0);
	Hud hud = Hud(stats);
	void HandleInput();
	void update() override;
	void rotate(); /*!< Rotates the player sprite */
	void draw(RenderWindow &window) override; /*!< Draws the player on window */
	Entity* hit() override;
	Vector2f getPos(); /*!< Returns position of the player */
	void TriggerDeath();
	void TriggerLife();
	bool collidesWith(Entity* other);
};

#endif