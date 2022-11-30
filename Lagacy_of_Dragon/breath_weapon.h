#ifndef BREATH_H
#define BREATH_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
using namespace doodle;


static constexpr int Brvelocity = 10;


constexpr int breathSize = 5;
constexpr int breathSize1 = 20;
constexpr int breathdamage = 5;

inline double breath_timer = 0;
inline double breath_time_check = 5;



inline bool not_clicked_breath = false;

struct BreathWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int size1 = 0;
	int damage = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	void draw();
	void FireBullet();
};

struct Breath_update
{
	void bullet_create(std::vector<BreathWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<BreathWeapon*>& bullets);
	void bullet_remove(std::vector<BreathWeapon*>& bullets);
};

extern Breath_update breath_update;

#endif
