#ifndef BACK_H
#define BACK_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
using namespace doodle;

inline bool not_clicked_back = false;

inline int backSize = 100;
inline int backSize1 = 500;

inline int backDamage = 1;

inline int Bavelocity = 4;
inline int Ba1velocity = 2;

inline double back_timer = 0;
inline double back_time_check = 3;
inline double ba_click_timer = 0;
inline double ba_click_check = 2.5;

struct BackWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int damage = 0;
	int size1 = 0;
	int velocity1 = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	void draw();
	void draw1();
};

struct Back_update
{
	void bullet_create(std::vector<BackWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<BackWeapon*>& bullets);
	void bullet_remove(std::vector<BackWeapon*>& bullets);
	void coolTime(std::vector<BackWeapon*>& bulllets, Player* player);

};

extern Back_update back_update;
#endif
