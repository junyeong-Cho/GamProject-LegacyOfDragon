#ifndef APPROACH_H
#define APPROACH_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>

using namespace doodle;

inline int approachSize = 160;

inline bool not_clicked_app = false;
inline double ap_click_timer = 0;
inline double ap_click_check = 3;

struct Approach {
	int x = 0;
	int y = 0;
	int size = 0;

	void draw();
};

struct Approach_update
{
	void bullet_create(std::vector<Approach*>& bullets, Player* player);
	void bullet_draw(std::vector<Approach*>& bullets);
	void bullet_remove(std::vector<Approach*>& bullets);
	void coolTime(std::vector<Approach*>& bullets, Player* player);
};

extern Approach_update approach_update;
#endif