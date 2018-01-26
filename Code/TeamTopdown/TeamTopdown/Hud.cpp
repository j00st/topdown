#include "stdafx.h"
#include "Hud.h"


Hud::Hud(PlayerStats & stats):
	stats(stats)
{
	gameStartTime = time(0);
	font.loadFromFile("sprites/C64_Pro_Mono-STYLE.ttf");
	gameTimeText.setFont(font);
	gameTimeText.setCharacterSize(25);
	gameTimeText.setScale(0.5, 0.5);
}


Hud::~Hud()
{
}

void Hud::update()
{
	Vector2f offset = Vector2f(50, -40);
	//-- game time --//
	gameTime = 60 - (int(time(0)) - int(gameStartTime));
	gameTimeText.setString("time remaining: " + std::to_string(gameTime));

	//-- stamina bar --//
	if (stats.stamina < 99) {
		staminaBar.setFillColor(Color::Yellow);
		staminaBarBorder.setFillColor(Color::Transparent);
		staminaBarBorder.setOutlineColor(Color::Black);
		staminaBarBorder.setOutlineThickness(2);

		staminaBar.setPosition(stats.position - offset);
		staminaBarBorder.setPosition(stats.position - offset);
		staminaBar.setSize(Vector2f(float(stats.stamina), 10));
	}
	else {
		staminaBar.setFillColor(Color::Transparent);
		staminaBarBorder.setFillColor(Color::Transparent);
		staminaBarBorder.setOutlineColor(Color::Black);
		staminaBarBorder.setOutlineThickness(0);
	}

	Vector2f gameTimeTextOffset = Vector2f(-250, -150);
	gameTimeText.setPosition( stats.position + gameTimeTextOffset ); // gameTimeText.getPosition()
	//std::cout << "x" << gameTimeText.getPosition
	//std::cout << "x" << stats.position.x << "y" << stats.position.y << "\n";
}

void Hud::draw(RenderWindow & w) {
	update();
	w.draw(gameTimeText);
	w.draw(staminaBarBorder);
	w.draw(staminaBar);
}
