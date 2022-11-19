#pragma once
#include <doodle\doodle.hpp>
#include <vector>
using namespace doodle;

static constexpr int tile_size = 100;

extern bool moveW;
extern bool moveA;
extern bool moveS;
extern bool moveD;
void on_key_pressed(KeyboardButtons button);
void on_key_released(KeyboardButtons button);

constexpr int player_limit_x = 1400;
constexpr int player_limit_x1 = 100;
constexpr int player_limit_y = 800;
constexpr int player_limit_y1 = 100;

struct Player {
	int chara_pos_x = 0;
	int chara_pos_y = 0;
	double speed = 2.0;

	void draw_chara();
	void MOVE();
};

struct Player_setting
{
	void move_limit(Player* player);
};
extern Player_setting player_setting;

