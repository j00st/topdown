#ifndef Graphic_HEADER
#define Graphic_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "controlsInput.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Graphic
\brief Creates a graphic object*/
class Graphic
{
private:
	Sprite sprite; /*!< the virtual sprite */
	Texture spriteTexture; /*!< the texture path & load */
	//Entity& entity, to call for position without needing to refer to it in draw()

public:
	Graphic(String path, bool centerSprite = false);

	void rotate(float rotation);
	void setPosition(Vector2f pos);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	void setSize(Vector2f size);
=======
	void setScale(Vector2f scale);
>>>>>>> refs/remotes/origin/master
=======
	void setSize(Vector2f size);
>>>>>>> parent of 79a6ac8... Merge remote-tracking branch 'refs/remotes/origin/mapCollision' into Bullet
=======
	void setSize(Vector2f size);
>>>>>>> parent of 79a6ac8... Merge remote-tracking branch 'refs/remotes/origin/mapCollision' into Bullet
	void draw(RenderWindow & w);
};

#endif