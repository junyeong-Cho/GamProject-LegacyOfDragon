#ifndef METEOR_H
#define METEOR_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>

using namespace doodle;


constexpr int mevelocity = 2;
constexpr int meteorSize = 250;
inline double me_attack_timer = 0;
inline double me_attack_check = 3;
inline bool not_clicked_me = false;

inline double me_remove_timer = 0;
inline double me_remove_check = 3;

inline double me_click_timer = 0;
inline double me_click_check = 10;


struct Meteor {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int velocity = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());

	void draw();
	void FireBullet();
};

struct Meteor_update
{
	void bullet_create(std::vector<Meteor*>& bullets, Player* player);
	void bullet_draw(std::vector<Meteor*>& bullets);
	void bullet_remove(std::vector<Meteor*>& bullets);
	void coolTime(std::vector<Meteor*>& bullets, Player* player);
};



extern Meteor_update meteor_update;
#endif


