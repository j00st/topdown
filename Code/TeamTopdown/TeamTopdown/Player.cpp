#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f size, RenderWindow& w, ControlsInput& controlsInput) :
	size(size), window(w), controlsInput(controlsInput), graphic(Graphic(window, "sprites/character.png"))
{
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

float Player::calcSpeed() 
{
	if (GetAsyncKeyState(16)) {
		return sprintSpeed;
	}
	return speed;
}

void Player::update()
{
	Vector2f vector(0, 0);
	float normY = 0, normX = 0;
	bool keyPressed = false;
	if (controlsInput.wKeyPressed) { vector.y += calcSpeed(); keyPressed = true; }
	if (controlsInput.sKeyPressed) { vector.y -= calcSpeed(); keyPressed = true; }
	if (controlsInput.aKeyPressed) { vector.x -= calcSpeed(); keyPressed = true; }
	if (controlsInput.dKeyPressed) { vector.x += calcSpeed(); keyPressed = true; }

	//convert -+ naar +5/+10, dan sqrt
	float length = sqrt(vector.y * vector.y + vector.x * vector.x);
	if (length > 0 || length < 0) {
		normY += vector.y / length; if (normY < 0) { normY = normY * -1; };
		normX += vector.x / length; if (normX < 0) { normX = normX * -1; };
	}
	float angle = atan2(normX, normY);
	float deg = angle * (180.0 / 3.141592653589793238463);

	//std::cout << "length: " << length << "\n";
	//std::cout << normY << "y.x" << normX << ".ang" << angle << ".deg" << deg << "\n";
	playerPos.y += (vector.y * normY);
	playerPos.x += (vector.x * normX);
	//std::cout << "normY: " << normY << " normX: " << normX << "\n";
	std::cout << "playerY+=: " << vector.y * normY << " playerX: " << vector.x * normX << "\n";
	rotate();
}

void Player::rotate()
{
	rotation = atan2(controlsInput.mousePos.y - playerPos.y, controlsInput.mousePos.x - playerPos.x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	graphic.rotate(rotation);
}

void Player::draw() 
{
	hitbox.setPosition(playerPos - Vector2f(size.x/2, size.y/2));
	window.draw(hitbox);
	graphic.draw(playerPos);
}

Vector2f Player::getPos()
{
	return playerPos;
}