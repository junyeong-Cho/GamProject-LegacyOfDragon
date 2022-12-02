#ifndef BOMB_H
#define BOMB_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
using namespace doodle;

inline bool not_clicked_bomb = false;


inline int bombSize = 50;
inline int bombDamage = 3;
inline int bombrange = 300;

struct BombWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int damage = 0;
	int range = 0;

	void draw();
};

struct Bomb_update
{
	void bullet_create(std::vector<BombWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<BombWeapon*>& bullets);
};

extern Bomb_update bomb_update;
#endif