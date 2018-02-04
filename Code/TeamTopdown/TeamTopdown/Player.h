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
#include "SFML/Audio.hpp"

using namespace sf;

/*! \class Player
\brief Handles player movement, interaction, animations and art*/
class Player : public Entity
{
private:
	enum states { alive, dead };
	ControlsInput & controlsInput; /*!< Reference to cursor location used to rotate sprite */
	Graphic playerSprite = Graphic("sprites/character.png", true);
	Cursor &cursor;

	sf::SoundBuffer SBplayerDeath;
	sf::Sound SEplayerDeath;
public:
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	PlayerStats stats;
	Player( Vector2f position, Vector2f size, Cursor &c, ControlsInput& controlsInput, bool isSolid = false, int state = 0);
	Hud hud = Hud(stats);

	/*! \void update()
	\brief updates player position and rotation */
	void update() override;

	/*! \void rotate()
	\brief rotates player */
	void rotate();

	/*! \void draw()
	\brief draws player */
	void draw(RenderWindow &window) override;

	/*! \Entity hit()
	\brief checks whether the player has been hit */
	Entity* hit() override;

	/*! \Vector2f getPos()
	\brief returns vector2f position of player*/
	Vector2f getPos() override; 

	/*! \void TriggerDeath()
	\brief kills the player */
	void TriggerDeath();

	/*! \void TriggerLife()
	\brief revives the player */
	void TriggerLife();

	/*! \void collidesWith(Entity* other)
	\brief checks whether the player is colliding */
	bool collidesWith(Entity* other);

	void setSprite(std::string path);
};

#endif