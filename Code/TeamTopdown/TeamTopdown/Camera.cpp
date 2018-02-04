#include "stdafx.h"
#include "Camera.h"

Camera::Camera(View & view, Player & objToFollow, RenderWindow & window, const Vector2f & sizeMap) :
	view(view),
	window(window),
	sizeMap(sizeMap),
	objToFollow(objToFollow)
{
	shakeWeight = 4; 
}


void Camera::update(){
	pos = objToFollow.getPos();
	if (!shakeTimer.done) {
		view.setCenter(Vector2f(pos.x + (rand() % shakeWeight), pos.y));// +(rand() % shakeWeight)));
	}
	else {
		view.setCenter(pos);
	}
	window.setView(view);
}

void Camera::setTimer(Timer & t) {
	shakeTimer = t;
}

View Camera::GetView()
{
	return view;
}

Vector2f Camera::getPosition()
{
	return view.getCenter();
}