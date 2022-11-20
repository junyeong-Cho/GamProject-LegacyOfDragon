#ifndef TUTO_H
#define TUTO_H

#include <doodle\doodle.hpp>
#include <vector>
#include <string>
#include "Player.h"

using namespace doodle;

constexpr int score_width = 1000;
constexpr int score_height = 150;
constexpr int tuto_move_line = 1000;
constexpr int tuto_move_line2 = 1000;
constexpr int tuto_word_x = 500;
constexpr int tuto_word_y = 200;

constexpr int nest_size = 100;
constexpr int nest_loc = 300;

inline int score = 0;

const Image Nest{ "nest.png" };

struct Tutorial
{
public:
	void scene1_guideline();
	void scene2_guideline();
	void scene3_guideline();
	bool is_clear_scene1(Player* player);
};


extern Tutorial tutorial;

#endif
