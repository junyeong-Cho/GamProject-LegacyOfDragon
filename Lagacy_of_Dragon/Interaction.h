#pragma once
#include <vector>
#include "Enemy.h"

#include "Tutorial.h"

#include "Shooting.h"
#include "ice_weapon.h"
#include "auto_weapon.h"
#include "back_weapon.h"
#include "bomb_weapon.h"
#include "breath_weapon.h"
#include "storm_weapon.h"
#include "meteor_weapon.h"


#include "approach_weapon.h"

constexpr double enemyradius = 15;
constexpr double chararadius = 25;
constexpr double bulletradius = 5;

constexpr double s1radius = 30;

inline double hp_timer = 0.0;
inline double hp_time_check = 0.7;

inline double back_timers = 0;
inline double back_time_checks = 2;


struct Interaction
{
	void player_enemy_interaction(std::vector<Enemy*>& enemys, Player* player);
	void bullet_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Shooting*>& bullets);
	void ice_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<IceWeapon*>& bullets);
	void storm_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Storm*>& bullets);
	void back_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BackWeapon*>& bullets);
	void bomb_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BombWeapon*>& bullets);
	void auto_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<AutoWeapon*>& bullets);
	void breath_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BreathWeapon*>& bullets, Player* player);
	void approach_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Approach*>& bullets);
	void meteor_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Meteor*>& bullets);

};
extern Interaction interaction;
