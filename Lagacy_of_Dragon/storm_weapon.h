#ifndef STORM_H
#define STORM_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>

using namespace doodle;


constexpr int stvelocity = 2;
constexpr int stormSize = 200;
inline double st_attack_timer = 0;
inline double st_attack_check = 3;
inline bool not_clicked_sto = false;

inline double st_remove_timer = 0;
inline double st_remove_check = 5;


struct Storm {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int velocity = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	
	void draw();
	void FireBullet();
};

struct Storm_update
{
	void bullet_create(std::vector<Storm*>& storms, Player* player);
	void bullet_draw(std::vector<Storm*>& storms);
	void bullet_remove(std::vector<Storm*>& storms);
};
#endif

