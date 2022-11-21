#ifndef HAETAE1_H
#define HAETAE1_H

#include <vector>
#include "Player.h"


inline double H1_timer = 0;
inline int H1_timer_check = 4;
inline int count_HaeTae1_start = 0;
inline int HaeTae1_max = 3;
inline int H1_Max = 3;
inline int H1_tutoMax = 6;
static constexpr int HaeTae1Min = -800;
static constexpr int HaeTae1Max = 800;
static constexpr int HaeTae1Size = 30;

constexpr int HaeTae1_vel_min = 1;
constexpr int HaeTae1_vel_max = 3;


struct HaeTae1 {
	int x = 0;
	int y = 0;
	int size = 0;
	int hp = 2;
	void draw();
};

struct HaeTae1_update {
	void HaeTae1_create(std::vector<HaeTae1*>& HaeTae1s);
	void HaeTae1_move(std::vector<HaeTae1*>& HaeTae1, Player* player);
};


extern HaeTae1_update haetae1_update;

#endif