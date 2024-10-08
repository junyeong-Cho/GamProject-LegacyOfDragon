﻿//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#ifndef BREATH_H
#define BREATH_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>

const Image razerImage{ "attack/razer.png" };
const Image razerImage1{ "attack/razer1.png" };
const Image razerImage2{ "attack/razer2.png" };


using namespace doodle;
static constexpr int Brvelocity = 15;

constexpr int breathSize = 3600;
constexpr int breathSize1 = 100;
constexpr int breathdamage = 5;

inline bool is_breath_draw = false;
inline bool is_breath = false;
inline double breath_timer = 0;
inline double breath_time_check = 2;
inline double br_click_timer = 0;
inline double br_click_check = 5;


inline bool not_clicked_breath = false;


struct BreathWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int size1 = 0;
	int damage = 0;
	int rect_x = 0;
	int rect_y = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	void drawR();
	void drawL();
	/*void draw();
	void drawrect(std::vector<BreathWeapon*>& bullets, Player* player);
	void FireBullet();*/
};

struct Breath_update
{
	void bullet_create(std::vector<BreathWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<BreathWeapon*>& bullets, Player* player);
	void coolTime(std::vector<BreathWeapon*>& bullets, Player* player);
	void bullet_remove(std::vector<BreathWeapon*>& bullets);

};

extern Breath_update breath_update;

#endif