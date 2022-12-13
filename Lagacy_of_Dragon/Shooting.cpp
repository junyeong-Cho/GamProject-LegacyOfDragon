//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "Shooting.h"
#include "UIsetting.h"
#include "soundeffect.h"
#include <doodle\doodle.hpp>
#include <SFML/Audio.hpp>
using namespace doodle;
using namespace sf;


#define Fireball 0

SoundEffect sound_effects_shoot[] = {
	SoundEffect("assets/SFX/Fireball.wav"),
};

double Shooting::radius() {
	double radius = static_cast<int>(size / static_cast<double>(2));
	return radius;
}

void Shooting::draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Shooting::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Bvelocity);
	float velocityY = (sin(aimAngle) * Bvelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void Shooting_update::bullet_create(std::vector<Shooting*> &bullets, Player* player)
{

	if (sh_click_timer < sh_click_check)
	{
		sh_click_timer += DeltaTime;
	}

	if (!MouseIsPressed) {
		not_clicked = true;
	}
	if (sh_click_timer >= sh_click_check)
	{
		if (MouseIsPressed && not_clicked == true)
		{
			sound_effects_shoot[Fireball].play();
			bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });

			not_clicked = false;
			sh_click_timer = 0;
		}
	}

}

void Shooting_update::bullet_draw(std::vector<Shooting*> &bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}

void Shooting_update::bullet_remove(std::vector<Shooting*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bullet_pos_x > 3500 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Shooting_update::coolTime(Player* player)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 10);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 200 * sh_click_timer, 10);
	pop_settings();
}