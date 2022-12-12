#ifndef ICE_H
#define ICE_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>
using namespace doodle;

inline Image iceImage { "attack/iceweapon.png" };

static constexpr int Ivelocity = 12;

constexpr int iceSize = 25;
constexpr int icedamage = 1;

inline double ice_timer = 0;
inline double ice_check = 0.5;

inline bool not_clicked_ice = false;

struct IceWeapon {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	int damage = 0;

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	void draw();
	void FireBullet();
};

struct Ice_update
{
	void bullet_create(std::vector<IceWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<IceWeapon*>& bullets);
	void bullet_remove(std::vector<IceWeapon*>& bullets);
	void coolTime(std::vector<IceWeapon*>& bullets, Player* player);
};

extern Ice_update ice_update;

#endif