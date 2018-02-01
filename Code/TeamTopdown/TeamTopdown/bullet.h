#ifndef Bullet_HEADER
#define Bullet_HEADER
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Entity.h"
#include "Graphic.h"
#include <SFML/Graphics.hpp>
using namespace sf;

/*!  \class Bullet
\brief
A bullet object is an entity that`s always moving  in one direction.
\details
the buller class contains the item graphic and overrides the necessary functions from Entity.
the direction, speed and rotation will be calculated in the constructur.
when the bullet is inactive it will stop drawing and calculating the next position.
if the bullet exist longer than 15 seconds it will go automaticly inActive
*/
class Bullet : public Entity
{
private:
	Vector2f speedVect;
	Graphic bulletSprite = Graphic("sprites/bullet_med1.png", true);
	int timeAlive = 0;
	bool isAlive = true;
	void rotate(float x, float y);
	float rotation;
public:
	/*! \details
	/// float speed speed in pixels
	///Vector2f  relativePosBul the vector with the spawn point as zero point to set the direction
	/// Vector2f position the spawn point
	/// Vector2f size size of bullet
	/// bool isSolid */
	Bullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid = true, int state = 2);
	~Bullet();
	/*! bool getIsAlive();
	\brief
	///getter to know if bullet still is active*/
	bool getIsAlive();
	/*! void setIsAlive(bool b);
	\brief
	setter to set bullet active or inactive*/
	void setIsAlive(bool b);
	/*! Vector2f getDirection();
	\brief get the direction where the bullet will be after the next update */
	Vector2f getDirection();
	/*! void update()
	\brief
	update the position of the bullet */
	void update();
	/*!
	\brief draws the bullet on the window
	\details
	RenderWindow window  window to draw in */
	void draw(RenderWindow &window);
	/*! \ brief
	get the time the bullet is active */
	int getTimeAlive();
};

#endif

