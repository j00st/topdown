#ifndef Hud_HEADER
#define Hud_HEADER

#include <SFML/Graphics.hpp>
#include "PlayerStats.h"

using namespace sf;

class Hud
{
private:
	PlayerStats & stats;
public:
	Hud(PlayerStats & stats);
	~Hud();

	void update();
	RectangleShape staminaBar = RectangleShape(Vector2f(100, 10));
	RectangleShape staminaBarBorder = RectangleShape(Vector2f(100, 10));
	Font font;
	Text gameTimeText;
	time_t gameStartTime;
	int gameTime;
	void draw(RenderWindow & w);
};

#endif