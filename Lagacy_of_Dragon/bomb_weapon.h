#ifndef BOMB_H
#define BOMB_H

#include <doodle\doodle.hpp>
#include "Player.h"

#include <vector>
using namespace doodle;

inline Image shoot{ "attack/fireball.png" };

inline bool is_bomb_hit = false;
inline bool not_clicked_bomb = false;

inline double bo_click_timer = 0;
inline double bo_click_check = 0.5;

inline double bo_remove_timer = 0;
inline double bo_remove_check = 0.2;

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
	void bullet_remove(std::vector<BombWeapon*>& bullets);
	void coolTime(std::vector<BombWeapon*>& bullets, Player* player);
};

extern Bomb_update bomb_update;
#endif