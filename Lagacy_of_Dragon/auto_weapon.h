#ifndef AUTO_H
#define AUTO_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <algorithm>
using namespace doodle;

constexpr int auto_range = 800;
static constexpr int auvelocity = 2;
constexpr int autoSize = 10;
constexpr int autodamage = 1;
inline bool not_clicked_auto = false;
inline bool is_auto_shoot = false;

std::vector<int> discheck = {};

struct AutoWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int damage = 0;
	int range = 0;

	void draw();
	void rangeDraw(Player* player);
	void FireBullet(std::vector<Enemy*>& enemys, Player* player);

};

struct Auto_update
{
	void bullet_create(std::vector<AutoWeapon*>& bullets, std::vector<Enemy*> enemys, Player* player);
	void bullet_draw(std::vector<AutoWeapon*>& bullets, std::vector<Enemy*> enemys, Player* player);
};
#endif
