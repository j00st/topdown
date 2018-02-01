#ifndef Hud_HEADER
#define Hud_HEADER

#include <SFML/Graphics.hpp>
#include "PlayerStats.h"
#include "Graphic.h"

using namespace sf;

/*! \class Hud
\brief Creates a hud overlay with the following:
- Ammo counters
- font
- game time
- player stamina
- graphical fluff
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
	/*! \void update()
	\brief updates the hud*/
	void update();

	/*! \void displayAmmo()
	\brief initial draw and set the current ammo display to the max bullets the player can have */
	void displayAmmo();

	/*! \void updateAmmo()
	\brief updates the current displayed ammo */
	void updateAmmo();

	/*! \void drawAmmo()
	\brief draws the ammo sprites */
	void drawAmmo(RenderWindow & w);

	/*! \void draw()
	\brief draws the following sprites on RenderWindow & w */
	void draw(RenderWindow & w);

	/*! \void createPopUp
	\brief creates a popup to be displayed, floating upward on a position */
	void createPopUp(int totalAmmoAdded,Vector2f position);

	/*! \void deletePopUp
	\brief deletes a popup to be displayed, floating upward on a position */
	void deletePopUp(std::vector<PopUp*>::iterator & popUpIt);
};

#endif