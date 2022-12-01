#ifndef AUTO_H
#define AUTO_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include "Enemy.h"
#include <vector>
using namespace doodle;

constexpr int auto_range = 200;
static constexpr int auvelocity = 10;
constexpr int autoSize = 10;
constexpr int autodamage = 1;
inline bool not_clicked_auto = false;

struct AutoWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int damage = 0;

	void draw();
};

struct Auto_update
{
	void bullet_create(std::vector<AutoWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<AutoWeapon*>& bullets);
	void bullet_move(std::vector<AutoWeapon*>& bullets, std::vector<Enemy*> enemys, Player* player);
};
#endif
