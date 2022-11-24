#ifndef BOSS_H
#define BOSS_H

#include <vector>
#include "Player.h"

static constexpr int s1bossSize = 100;

constexpr int s1_vel_min = 1;
constexpr int s1_vel_max = 3;




struct Stage1_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	void draw();
};

struct S1boss_update {
	void s1_boss_update(std::vector<Stage1_boss*>& stage1_boss);
	void s1_boss_move(std::vector<Stage1_boss*>& stage1_boss, Player* player);
};

extern S1boss_update s1boss_update;

#endif
