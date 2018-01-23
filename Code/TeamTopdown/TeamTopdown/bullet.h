#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Entity.h"
#include "Graphic.h"
#include <SFML/Graphics.hpp>
using namespace sf;

/*!  \class Bullet
\brief a Bullet object is a entity that`s always moving  */
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
	/// \details
	/// float speed speed in pixels
	///Vector2f  relativePosBul the vector with the spawn point as zero point to set the direction
	/// Vector2f position the spawn point
	/// Vector2f size size of bullet
	/// bool isSolid 
	Bullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid = true);
	~Bullet();
	bool getIsAlive();
	void setIsAlive(bool b);
	Vector2f getDirection();
	void update();
	void draw(RenderWindow &window);
	int getTimeAlive();
};

