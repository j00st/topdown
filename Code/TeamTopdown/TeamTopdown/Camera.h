#ifndef Camera_HEADER
#define Camera_HEADER
#pragma once
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Timer.h"

using namespace sf;

class Camera
{
private:
	View & view;
	Player & objToFollow;
	RenderWindow & window;
	Vector2f sizeMap;
	Vector2f pos;
	Timer & shakeTimer = Timer();
	int shakeWeight;
public:
	/// \brief
	/// Create a Camera to follow the player
	/// \details
	/// View view the view object
	/// Window window 
	/// Vector2f sizeMap The vector of the size of the background image
	Camera(View & view,  Player & objToFollow, RenderWindow & window, const Vector2f & sizeMap);
	/// \brief
	/// set the camera at the good position
	/// \details
	/// set camera in such a postion that the player will be in the center
	/// unless the player is at a boundry of the map
	void update();
	void setTimer(Timer & t);
	View getView();
};
#endif

