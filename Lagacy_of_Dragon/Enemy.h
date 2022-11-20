#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Player.h"

inline double timer = 0;
inline int timer_check = 4;
inline int count_enemy_start = 0;
inline int tuto_enemy_max = 3;
inline int Max = 3;
inline int tutoMax = 6;
static constexpr int enemyMin = -800;
static constexpr int enemyMax = 800;
static constexpr int enemySize = 30;

constexpr int enemy_vel_min = 1;
constexpr int enemy_vel_max = 3;


struct Enemy {
	int x = 0;
	int y = 0;
	int size = 0;
	void draw();
};

struct Enemy_update {
	void tuto_enemy_create(std::vector<Enemy*> & tutoenemys);
	void enemy_move(std::vector<Enemy*>& enemys, Player* player);
}; 
extern Enemy_update enemy_update;

#endif