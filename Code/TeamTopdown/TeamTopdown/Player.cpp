#include "stdafx.h"
#include "Player.h"

PlayerGraphic::PlayerGraphic() {
	spriteTexture.loadFromFile("sprites/character.png");
	sprite.setTexture(spriteTexture);
}

void PlayerGraphic::draw(RenderWindow& w, int x, int y) 
{
	sprite.setPosition(Vector2f(x, y));
	w.draw(sprite);
}

Player::Player(ControlsInput& inpt, Vector2f size):
	ctrlsInpt(inpt)
{
	playerShape = RectangleShape(size);
	playerX = 0;
	playerY = 0;
	playerShape.setPosition(Vector2f(playerX, playerY));
	playerShape.setFillColor(Color::Green);
}

void Player::update()
{
	if (ctrlsInpt.sKeyPressed) {
		playerY -= 10;
	}
	if (ctrlsInpt.wKeyPressed) {
		playerY += 10;
	}
	if (ctrlsInpt.aKeyPressed) {
		playerX -= 10;
	}
	if (ctrlsInpt.dKeyPressed) {
		playerX += 10;
	}
	//playerShape.setPosition(Vector2f(playerX, playerY));
	//sprite.setPosition(Vector2f(playerX, playerY));

}

void Player::draw( RenderWindow & w ) 
{
	//w.draw(playerShape);
	//w.draw(sprite);
	playerGraphic.draw(w, playerX, playerY);
}