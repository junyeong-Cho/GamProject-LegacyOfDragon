#ifndef BREATH_H
#define BREATH_H

#include <doodle\doodle.hpp>
#include "Player.h"
#include <vector>


using namespace doodle;

static constexpr int Brvelocity = 10;


constexpr int breathSize = 3600;
constexpr int breathSize1 = 100;
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

	void drawR();
	void drawL();

};

struct Breath_update
{
	void bullet_create(std::vector<BreathWeapon*>& bullets, Player* player);
	void bullet_draw(std::vector<BreathWeapon*>& bullets, Player* player);
	void bullet_remove(std::vector<BreathWeapon*>& bullets);
};

extern Breath_update breath_update;

#endif
