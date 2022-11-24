#ifndef UI_H
#define UI_H

#include <vector>
#include <doodle\doodle.hpp>
using namespace doodle;

inline int chap1_point = 20;
constexpr int score_width = 1000;
constexpr int score_height = 150;

inline double skillTimer = 0;
inline double SkillTimeCheck = 5;

inline int randomScene = 0;
inline int acc_x = 0;

inline double box_x = 500;
inline int randomboxh = 500;
inline int randomboxSize = 200;

const Image Fire{ "Fire.jpg" };
const Image Water{ "Water.jpg" };
const Image Star{ "Star.jpg" };

struct UIsetting
{
	void ui_point();
	void roulette(std::vector<int> randomboxloc);
};
extern UIsetting uisetting;
#endif