#ifndef COLL_H
#define COLL_H

#include <vector>
#include "Enemy.h"

#include "Tutorial.h"

#include "Shooting.h"
#include "ice_weapon.h"
#include "auto_weapon.h"
#include "back_weapon.h"
#include "approach_weapon.h"
#include "bomb_weapon.h"
#include "breath_weapon.h"
#include "storm_weapon.h"
#include "meteor_weapon.h"
#include "stage1_boss.h"
#include "stage2_boss.h"
#include "stage3_boss.h"


constexpr double enemyradius = 15;
constexpr double chararadius = 50;
constexpr double bulletradius = 5;

constexpr double s1radius = 30;

inline double hp_timer = 0.0;
inline double hp_time_check = 0.7;

inline double boss_timer = 0.0;
inline double boss_time_check = 0.7;


struct Interaction
{
	void player_enemy_interaction(std::vector<Enemy*>& enemys, Player* player);
	void bullet_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Shooting*>& bullets);
	void ice_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<IceWeapon*>& bullets);
	void storm_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Storm*>& bullets);
	void back_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BackWeapon*>& bullets, Player* player);
	void bomb_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BombWeapon*>& bullets);
	void breath_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BreathWeapon*>& bullets, Player* player);
	void approach_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Approach*>& bullets);
	void meteor_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Meteor*>& bullets);

	void player_boss1_interaction(Stage1_boss* boss1, std::vector<Shooting*>& bullets);
	void ice_boss1_interaction(Stage1_boss* boss1, std::vector<IceWeapon*>& bullets);
	void storm_boss1_interaction(Stage1_boss* boss1, std::vector<Storm*>& bullets);

	void player_boss2_interaction(Stage2_boss* boss2, std::vector<Shooting*>& bullets);
	void ice_boss2_interaction(Stage2_boss* boss2, std::vector<IceWeapon*>& bullets);
	void storm_boss2_interaction(Stage2_boss* boss2, std::vector<Storm*>& bullets);
	void back_boss2_interaction(Stage2_boss* boss2, std::vector<BackWeapon*>& bullets);
	void approach_boss2_interaction(Stage2_boss* boss2, std::vector<Approach*>& bullets);
	void bomb_boss2_interaction(Stage2_boss* boss2, std::vector<BombWeapon*>& bullets);
	void breath_boss2_interaction(Stage2_boss* boss2, std::vector<BreathWeapon*>& bullets);
	void meteor_boss2_interaction(Stage2_boss* boss2, std::vector<Meteor*>& bullets);


	void player_boss3_interaction(Stage3_boss* boss3, std::vector<Shooting*>& bullets);

	void boss2_player_interaction(Player* player);
};
extern Interaction interaction;

#endif;