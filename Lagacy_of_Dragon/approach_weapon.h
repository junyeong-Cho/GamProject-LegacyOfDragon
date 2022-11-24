#ifndef APPROACH_H
#define APPROaCH_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>

using namespace doodle;

constexpr int approachSize = 30;

inline double attack_timer = 0;
inline double attack_check = 1.5;
inline bool not_clicked_app = false;


struct Approach {
	int x = 0;
	int y = 0;
	int size = 0;

	void draw();
};

struct Approach_update
{
	void approach_create(std::vector<Approach*>& approachs, Player* player);
	void approach_draw(std::vector<Approach*>& approachs);
};
#endif
