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
	//check bounderies
	pos = objToFollow.getPos();
	////check bounds left
	//if (pos.x <= view.getSize().x / 2 ) {
	//	pos.x = view.getSize().x / 2;
	//}
	////check bounds top
	//if (pos.y <= view.getSize().y / 2 ) {
	//	pos.y = view.getSize().y / 2 ;
	//}

	////check bounds bottom
	//if ( pos.y >= (sizeMap.y - (view.getSize().y / 2  ))) {
	//	pos.y = sizeMap.y - (view.getSize().y / 2);
	//}
	////check bounds right
	//if (pos.x >= (sizeMap.x - (view.getSize().x / 2))) {
	//	pos.x = sizeMap.x - (view.getSize().x / 2);
	//}

	/*Vector2f offset = pos - (window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	offset.x = offset.x / 20;
	offset.y = offset.y / 20;

	if (!shakeTimer.done) {
		view.setCenter(Vector2f(pos.x + (rand() % shakeWeight), pos.y + (rand() % shakeWeight)) - offset);
	}
	else {
		view.setCenter(pos - offset);
	}*/

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