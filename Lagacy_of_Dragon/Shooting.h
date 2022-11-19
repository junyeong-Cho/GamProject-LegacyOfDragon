#pragma once
#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
using namespace doodle;

static constexpr int Pvelocity = 3;
static constexpr int Bvelocity = 6;
static constexpr int Player_r = 50;

constexpr int bulletSize = 10;

inline bool not_clicked = false;

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
};