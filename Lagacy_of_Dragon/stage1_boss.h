//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#ifndef BOSS1_H
#define BOSS1_H

#include <vector>
#include "Player.h"

const Image Boss1r{ "enemy/enemy1.png" };

inline bool boss1_move_check = false;
inline int boss1_x = 750;
inline int boss1_y = 200;
inline int s1bossSize = 100;
inline double boss1_hp = 100;
inline int s1_boss_vel = 7;

constexpr int b1_hp_x = 250;
constexpr int b1_hp_y = 800;
constexpr int b1_hp_w = 1000;
constexpr int b1_hp_h = 10;

inline Color hp_color_1 = HexColor{ 0xfff000ff };

struct Stage1_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	int health = 0;
	int velocity = 0;

	void draw();
	void move();
	void hp();
};

#endif