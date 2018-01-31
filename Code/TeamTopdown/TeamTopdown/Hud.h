#ifndef Hud_HEADER
#define Hud_HEADER

#include <SFML/Graphics.hpp>
#include "PlayerStats.h"
#include "Graphic.h"

using namespace sf;

/*! \class Hud
\brief Creates an entity list based on a collision map
This class creates a list of entities based on the red value of a .png-file.
We loop through the pixels to determine a position. The tile size is constant and set.
Once we find a pixel with a red-value of 0, we make it our spawnpoint.
If it's a 1, we spawn a wall at that position with the standard tilesize and add it to the entity list.
A red-value of 2 indicates an enemy waypoint. This will either create a new enemy from that waypoint, or add the waypoint to an already existing enemy.
In creating such a waypoint, the green-value of the pixel determines the enemy by ID and the blue-value determines the order of waypoints. In that way, we only have to loop through the pixel map once.
A red-value of 3 is a crate, and a red-value of 4 is a set of spikes. In this case, the green value represents the starting state (down, rising or up).
*/
class Hud
{
private:
	Font font;
	Text gameTimeText;
	Text AmmoClips;
	time_t gameStartTime;
	int gameTime;
	PlayerStats & stats;
	//Graphic staminaBorder = Graphic("sprites/staminabarborder.png");
	Graphic staminaFill = Graphic("sprites/staminabarfill.png");
	Graphic portrait = Graphic("sprites/portrait.png");
	Graphic reloadFill = Graphic("sprites/staminabarfill.png");
	std::vector<Graphic*> bullets;
	struct PopUp { Text ammoPickUpText; int timmer = 30;};
	std::vector<PopUp*> popUps;

public:
	Hud(PlayerStats & stats = PlayerStats());
	~Hud();
	void update();
	void displayAmmo();
	void updateAmmo();
	void drawAmmo(RenderWindow & w);
	void draw(RenderWindow & w);
	void createPopUp(int totalAmmoAdded,Vector2f position);
	void deletePopUp(std::vector<PopUp*>::iterator & popUpIt);
};

#endif