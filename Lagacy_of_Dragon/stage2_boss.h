//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#ifndef BOSS2_H
#define BOSS2_H

#include <vector>
#include "Player.h"
const Image Boss2r{ "red_dragon.png" };
const Image razer_ver{ "attack/bossrazer1.png" };
const Image razer_ver1{ "attack/bossrazer2.png" }; 
const Image razer_hori{ "attack/bossrazer3.png" }; // thick
const Image razer_mid{ "attack/bossbomb.png" };

inline double b2_change_check = 6;
inline double b2_change_timer = 0;
inline int b2_change_random = 0;

inline double b2_move_timer = 0;
inline double b2_move_check = 4;

inline bool is_b2_hit = false;
inline bool is_b2_draw = false;

inline double b2_blink_timer = 0;
inline double b2_blink_check = 0.1;
inline double b2_blink_time = 0.1;
inline double b2_attack_checked = 3.5;

inline Color blink_color = HexColor{ 0xff000022 };
inline Color blink_color_1 = HexColor{ 0xff000022 };
inline Color attack_color = HexColor{ 0xffffff00 };
inline Color hp_color_2 = HexColor{ 0xfff000ff };


inline int boss2_x = 750;
inline int boss2_y = 500;
inline int s2bossSize = 100;
inline double boss2_hp = 200;
inline int s2_boss_vel = 5;
inline int r_attack = 0;

constexpr int b2_hp_x = 250;
constexpr int b2_hp_y = 800;
constexpr int b2_hp_w = 1000;
constexpr int b2_hp_h = 10;



struct Stage2_boss {
	int x = 0;
	int y = 0;
	int size = 0;
	int health = 0;

	void draw();
	void move();
	void hp();
};

struct S2boss_update {
	void s2_boss_attack(Stage2_boss* boss2, Player* player);
};

extern S2boss_update s2boss_update;

#endif
