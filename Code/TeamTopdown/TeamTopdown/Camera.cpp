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

	view.setCenter(Vector2f(pos.x, pos.y));
	window.setView(view);
}
