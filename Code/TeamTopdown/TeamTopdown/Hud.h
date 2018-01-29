#ifndef Hud_HEADER
#define Hud_HEADER

#include <SFML/Graphics.hpp>
#include "PlayerStats.h"
#include "Graphic.h"

using namespace sf;

class Hud
{
private:
	Font font;
	Text gameTimeText;
	time_t gameStartTime;
	int gameTime;
	PlayerStats & stats;
	//Graphic staminaBorder = Graphic("sprites/staminabarborder.png");
	Graphic staminaFill = Graphic("sprites/staminabarfill.png");
	Graphic portrait = Graphic("sprites/portrait.png");
	Graphic reloadFill = Graphic("sprites/staminabarfill.png");
	std::vector<Graphic*> bullets;

public:
	Hud(PlayerStats & stats = PlayerStats());
	~Hud();
	void update();
	void displayAmmo();
	void updateAmmo();
	void drawAmmo(RenderWindow & w);
	void draw(RenderWindow & w);
};

#endif