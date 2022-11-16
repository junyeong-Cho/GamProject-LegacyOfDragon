#pragma once
#include <doodle\doodle.hpp>
using namespace doodle;

static constexpr int tile_size = 100;

extern bool moveW;
extern bool moveA;
extern bool moveS;
extern bool moveD;
void on_key_pressed(KeyboardButtons button);
void on_key_released(KeyboardButtons button);

struct Player {
	int chara_pos_x = 0;
	int chara_pos_y = 0;
	double speed = 2.0;

	void draw_chara();
	void MOVE();
};

