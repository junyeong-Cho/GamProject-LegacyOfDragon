//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#ifndef SHOOT_H
#define SHOOT_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
inline Image shootImage{ "attack/fireball1.png" };

using namespace doodle;

static constexpr int Pvelocity = 3;
static constexpr int Bvelocity = 10;
static constexpr int Player_r = 50;

constexpr int bulletSize = 10;
inline bool not_clicked = false;

inline double sh_click_timer = 0;
inline double sh_click_check = 0.5;

struct Shooting {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	double radius();
	void draw();
	void FireBullet();
};

struct Shooting_update
{
	void bullet_create(std::vector<Shooting*> &bullets, Player* player);
	void bullet_draw(std::vector<Shooting*> &bullets);
	void bullet_remove(std::vector<Shooting*> &bullets);
	void coolTime(Player* player);
};

extern Shooting_update shooting_update;
#endif