#include "stdafx.h"
#include "Camera.h"

Camera::Camera(View & view,  Player & objToFollow ,RenderWindow & window,const Vector2f & sizeMap) :
	view(view),
	window(window),
	sizeMap(sizeMap),
	objToFollow(objToFollow)
{
}


void Camera::update(){
	//check bounderies
	int posX = objToFollow.getX();
	int posY = objToFollow.getY();
	//check bounds left
	if (posX <= view.getSize().x / 2 ) {
		posX = view.getSize().x / 2;
	}
	//check bounds top
	if (posY <= view.getSize().y / 2 ) {
		posY = view.getSize().y / 2 ;
	}

	//check bounds bottom
	if ( posY >= (sizeMap.y - (view.getSize().y / 2  ))) {
		posY = sizeMap.y - (view.getSize().y / 2);
	}
	//check bounds right
	if (posX >= (sizeMap.x - (view.getSize().x / 2))) {
		posX = sizeMap.x - (view.getSize().x / 2);
	}

	view.setCenter(Vector2f(posX, posY));
	window.setView(view);
	window.display();
}
