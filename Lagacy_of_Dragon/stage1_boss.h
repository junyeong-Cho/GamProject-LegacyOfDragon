#ifndef BOSS_H
#define BOSS_H

#include <vector>
#include "Player.h"

static constexpr int s1bossSize = 100;

constexpr int s1_vel_min = 1;
constexpr int s1_vel_max = 3;

inline double b1_change_check = 0;
inline double b1_change_timer = 8;
inline int b1_change_random = 0;



inline double b1_attack_check = 2.5;
inline double b1_attack_timer = 0;

inline double b1_blink_timer = 0;
inline double b1_blink_check = 0.7;
inline double b1_attack_checked = 3.5;


enum B1attack
{
	at_pattern0 = 0, // 기본 상태
	at_pattern1 = 1, // 가로로 공격
	at_pattern2 = 2, // 세로로 공격
	at_pattern3 = 3, // 중앙으로 공격
	at_pattern4 = 4, // 세로 3줄로 공격
	at_pattern5 = 5, // 가로 3줄로 공격
};

struct Stage1_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	void draw();

	B1attack attack = B1attack::at_pattern0;
};

struct S1boss_update {
	void s1_boss_update(std::vector<Stage1_boss*>& stage1_boss);
	void s1_boss_attack(std::vector<Stage1_boss*>& stage1_boss, Player* player, B1attack attack);
};

extern S1boss_update s1boss_update;

#endif
