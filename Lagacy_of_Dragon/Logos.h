#pragma once
#include <doodle\doodle.hpp>
using namespace doodle;

constexpr int digipen_width = 1000;
constexpr int digipen_height = 700;
constexpr int teamlogo_width = 2500;
constexpr int teamlogo_height = 1500;

const Image DigipenLogo{ "UIdesign/DigipenLogo.jpg" };
const Image TeamLogo{ "UIdesign/TeamLogo.png" };

struct Logos {
	void digipen_logo();
	void team_logo();
};
extern Logos logos;