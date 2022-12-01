#ifndef BOSS1_H
#define BOSS1_H

#include <vector>
#include "Player.h"


constexpr int boss1_x = 750;
constexpr int boss1_y = 200;
constexpr int s1bossSize = 200;
constexpr int boss1_hp = 200;
constexpr int s1_boss_vel = 4;

struct Stage1_boss {
	int x = boss1_x;
	int y = boss1_y;
	int size = s1bossSize;
	int health = boss1_hp;
	void draw();
	void move();
};

extern Stage1_boss stage1_boss;

#endif