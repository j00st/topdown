#ifndef Camera_HEADER
#define Camera_HEADER
#pragma once
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Camera
{
private:
	View & view;
	Player & objToFollow;
	RenderWindow & window;
	sf::Vector2f sizeMap;
	sf::Vector2f pos;
public:
	/// \brief
	/// Create a Camera to follow the player
	/// \details
	/// View view the view object
	/// Window window 
	/// Vector2f sizeMap The vector of the size of the background image
	Camera(View & view,  Player & objToFollow, RenderWindow & window, const sf::Vector2f & sizeMap);
	/// \brief
	/// set the camera at the good position
	/// \details
	/// set camera in such a postion that the player will be in the center
	/// unless the player is at a boundry of the map
	void update();

};
#endif

