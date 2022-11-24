#ifndef BOSS2_H
#define BOSS2_H

#include <vector>
#include "Player.h"

static constexpr int s2bossSize = 20;

constexpr int s2_boss_vel = 3;

struct Stage2_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	void draw();
};

struct S2boss_update {
	void s2_boss_update(std::vector<Stage2_boss*>& stage2_boss);
	void s2_boss_move(std::vector<Stage2_boss*>& stage2_boss, Player* player);
};

extern S2boss_update s2boss_update;

#endif