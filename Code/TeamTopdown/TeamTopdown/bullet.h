#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Entity.h"
#include "Graphic.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet : public Entity
{
private:
	Vector2f speedVect;
	Graphic bulletSprite = Graphic("sprites/character.png", true);
	int timeAlive = 0;
	void rotate(float y, float x);
	float rotation;
public:
	Bullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid);
	~Bullet();
	void update();
	void draw(RenderWindow &window);
	int getTimeAlive();
};

