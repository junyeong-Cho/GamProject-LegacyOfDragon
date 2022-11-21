#ifndef HAETAE2_H
#define HAETAE2_H

#include <vector>
#include "Player.h"


inline double H2_timer = 0;
inline int H2_timer_check = 4;
inline int count_HaeTae2_start = 0;
inline int HaeTae2_max = 3;
inline int H2_Max = 3;
inline int H2_tutoMax = 6;
static constexpr int HaeTae2Min = -800;
static constexpr int HaeTae2Max = 800;
static constexpr int HaeTae2Size = 30;

constexpr int HaeTae2_vel_min = 1;
constexpr int HaeTae2_vel_max = 3;


struct HaeTae2 {
	int x = 0;
	int y = 0;
	int size = 0;
	int hp = 3;
	void draw();
};

struct HaeTae2_update {
	void HaeTae2_create(std::vector<HaeTae2*>& HaeTae2s);
	void HaeTae2_move(std::vector<HaeTae2*>& HaeTae2, Player* player);
};


extern HaeTae2_update haetae2_update;

#endif