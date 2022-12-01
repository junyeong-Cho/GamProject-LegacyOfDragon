#ifndef BOMB_H
#define BOMB_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
using namespace doodle;

inline bool not_clicked_bomb = false;
inline double bomb_timer = 0;
inline double bomb_time_check = 4;

inline int Bovelocity = 3;
inline int bombSize = 50;
inline int bombDamage = 3;

struct BombWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int damage = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	void draw();
	void FireBullet();
};

struct Bomb_update
{
	void bullet_create(std::vector<BombWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<BombWeapon*>& bullets);
};

extern Bomb_update bomb_update;
#endif