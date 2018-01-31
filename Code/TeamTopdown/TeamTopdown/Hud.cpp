#include "stdafx.h"
#include "Hud.h"


Hud::Hud(PlayerStats & stats):
	stats(stats)
{
	gameStartTime = time(0);
	font.loadFromFile("sprites/C64_Pro_Mono-STYLE.ttf");
	gameTimeText.setFont(font);
	gameTimeText.setCharacterSize(25);
	gameTimeText.setScale(0.4, 0.4);
	AmmoClips.setFont(font);
	AmmoClips.setCharacterSize(25);
	AmmoClips.setScale(0.4, 0.4);
	displayAmmo();
}

Hud::~Hud()
{
}

void Hud::displayAmmo()
{
	for (int i = 0; i < stats.maxAmmo; i++) {
		bullets.push_back(new Graphic("sprites/hud_bullet1.png"));
	}
}

void Hud::updateAmmo()
{
	Vector2f offset = stats.position + Vector2f(-190, 110);
	int i = 0;
	if (stats.reload.done && stats.ammo >= 1) {
		reloadFill.setScale(Vector2f(0, 1));
		for (auto bullet : bullets) {
			if (i >= stats.ammo) {
				bullet->SetSprite("sprites/hud_bullet0.png");
			}
			else {
				bullet->SetSprite("sprites/hud_bullet1.png");
			}
			bullet->setPosition(offset);
			offset.x += 10;
			i++;
		}
	}
	else {
		for (auto bullet : bullets) {
			bullet->SetSprite("sprites/hud_bullet0.png");
			bullet->setPosition(offset);
			offset.x += 10;
		}
		reloadFill.setScale(Vector2f(stats.reload.timer / stats.reload.start * -1, 1));
	}
}

void Hud::drawAmmo(RenderWindow & w)
{
	for (auto bullet : bullets) {
		bullet->draw(w);
	}
}

void Hud::update()
{
	//-- ammo --//
	updateAmmo();
	Vector2f offset = Vector2f(16, -16);

	//-- game time --//
	gameTime = 0 + (int(time(0)) - int(gameStartTime));
	int mod = gameTime % 60;
	String minutes;
	String seconds;
	if (mod < 10) { seconds = "0" + std::to_string(mod); }
	else { seconds = std::to_string(mod); }
	if ((gameTime - mod) / 60 < 10) { minutes = "0" + std::to_string((gameTime - mod) / 60); }
	else { minutes = std::to_string((gameTime - mod) / 60); }
	gameTimeText.setString("time:\n" + minutes + ":" + seconds);
	AmmoClips.setString("/" + std::to_string(stats.maxAmmo));
	//-- stamina bar --//
	if (stats.stamina < 99) {
		staminaFill.setPosition(stats.position - offset);
		staminaFill.setScale(Vector2f(float(stats.stamina) / 100, 1));
	}
	else {
		staminaFill.setPosition(Vector2f(-900, -900));
	}

	Vector2f gameTimeTextOffset = Vector2f(-250, 58);
	Vector2f portraitOffset = Vector2f(-256, 75);
	Vector2f reloadFillOffset = Vector2f(-159, 127);
	Vector2f AmmoClipsOffset = Vector2f(-140, 115);
	gameTimeText.setPosition(stats.position + gameTimeTextOffset);
	portrait.setPosition(stats.position + portraitOffset);
	reloadFill.setPosition(stats.position + reloadFillOffset);
	AmmoClips.setPosition(stats.position + AmmoClipsOffset);
}

void Hud::draw(RenderWindow & w) {
	update();
	w.draw(gameTimeText);
	w.draw(AmmoClips);
	for (auto pupUp : popUps) {
		w.draw(pupUp->ammoPickUpText);
	}	
	staminaFill.draw(w);
	portrait.draw(w);
	reloadFill.draw(w);
	drawAmmo(w);
}

void Hud::createPopUp(int totalAmmoAdded, Vector2f position)
{
	Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setScale(0.4, 0.4);
	text.setString("Ammo+ " + std::to_string(totalAmmoAdded));
	PopUp* popUp= new PopUp;
	popUp->ammoPickUpText = text;
	popUp->ammoPickUpText.setPosition(position);
	popUps.push_back(popUp);
}
