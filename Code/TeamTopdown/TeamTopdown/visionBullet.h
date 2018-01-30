#ifndef visionBullet_HEADER
#define visionBullet_HEADER
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;

/*!  \class visionBullet
\brief Invisible bullets to detect enemy vision  */
class visionBullet : public Entity
{
private:
	Vector2f speedVect;
	int timeAlive = 0;
	bool isAlive = true;
	float rotation;
public:
	/// \details
	/// float speed speed in pixels
	///Vector2f  relativePosBul the vector with the spawn point as zero point to set the direction
	/// Vector2f position the spawn point
	/// Vector2f size size of bullet
	/// bool isSolid 
	visionBullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid = true, int state = 2);
	~visionBullet();
	/// \details
	///getter to know if bullet still is active
	bool getIsAlive();
	/// \details
	///setter to set bullet active or inactive
	void setIsAlive(bool b);
	/// \details
	/// get the direction where the bullet will be after the next update
	Vector2f getDirection();
	/// \details
	/// update the position of the bullet
	void update();
	/// \details
	/// draw the bullet
	/// RenderWindow window  window to draw in
	void draw(RenderWindow &window);
	/// \ details
	/// get the time the bullet is active
	int getTimeAlive();
};

#endif
