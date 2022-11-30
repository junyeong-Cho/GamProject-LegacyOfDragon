#ifndef BOSS1_H
#define BOSS1_H

#include <vector>
#include "Player.h"

static constexpr int s1bossSize = 30;

constexpr int boss1_x = 750;
constexpr int boss1_y = 200;
constexpr int boss1_hp = 200;
constexpr int s1_boss_vel = 4;

struct Stage1_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	int health = 0;
	void draw();
	void move();
};

struct Stage1_update
{
	void boss1_create(std::vector<Stage1_boss*>& boss1);
};

extern Stage1_update stage1_update;

#endif