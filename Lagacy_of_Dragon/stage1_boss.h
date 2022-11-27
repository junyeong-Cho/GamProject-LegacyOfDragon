#ifndef BOSS1_H
#define BOSS1_H

#include <vector>
#include "Player.h"

static constexpr int s1bossSize = 30;

constexpr int s1_boss_vel = 4;

struct Stage1_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	int health = 0;
	void draw();
	void move();
};

extern Stage1_boss stage1_boss;

#endif