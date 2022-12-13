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

inline double back_timers = 0;
inline double back_checks = 1;
inline double back_init = 2.5;


inline double hp_b2_timer = 0;
inline double hp_b2_check = 0.7;

inline double hp_b1_timer = 0;
inline double hp_b1_check = 0.7;

inline double hp_b3_timer = 0;
inline double hp_b3_check = 0;

struct Interaction
{
	void player_enemyat_interaction(std::vector<Enemy_attack*>& attack, Player* player);
	void player_enemy_interaction(std::vector<Enemy*>& enemys, Player* player);
	void bullet_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Shooting*>& bullets, int* death);
	void ice_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<IceWeapon*>& bullets, int* death);
	void storm_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Storm*>& bullets, int* death);
	void back_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BackWeapon*>& bullets, Player* player);
	void bomb_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BombWeapon*>& bullets, int* death);
	void breath_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BreathWeapon*>& bullets, Player* player, int* death);
	void approach_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Approach*>& bullets, int* death);
	void meteor_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Meteor*>& bullets, int* death);

	// 날라다니는놈 얘도 충돌체크 필ㅇㅅ옶음?
	void player_boss3_interaction(Stage3_boss* boss3, std::vector<Shooting*>& bullets);
	void ice_boss3_interaction(Stage3_boss* boss3, std::vector<IceWeapon*>& bullets);
	void storm_boss3_interaction(Stage3_boss* boss3, std::vector<Storm*>& bullets);

	// 좌우 움직이는놈 2 얘도 충돌체크 필요없음
	void player_boss1_interaction(Stage1_boss* boss1, std::vector<Shooting*>& bullets);
	void ice_boss1_interaction(Stage1_boss* boss1, std::vector<IceWeapon*>& bullets);
	void storm_boss1_interaction(Stage1_boss* boss1, std::vector<Storm*>& bullets);
	void back_boss1_interaction(Stage1_boss* boss1, std::vector<BackWeapon*>& bullets);
	void approach_boss1_interaction(Stage1_boss* boss1, std::vector<Approach*>& bullets);
	void bomb_boss1_interaction(Stage1_boss* boss1, std::vector<BombWeapon*>& bullets);
	void breath_boss1_interaction(Stage1_boss* boss1, std::vector<BreathWeapon*>& bullets);
	void meteor_boss1_interaction(Stage1_boss* boss1, std::vector<Meteor*>& bullets);


	// 빨갱이 3
	void player_boss2_interaction(Stage2_boss* boss2, std::vector<Shooting*>& bullets);
	void ice_boss2_interaction(Stage2_boss* boss2, std::vector<IceWeapon*>& bullets);
	void storm_boss2_interaction(Stage2_boss* boss2, std::vector<Storm*>& bullets);
	void back_boss2_interaction(Stage2_boss* boss2, std::vector<BackWeapon*>& bullets);
	void approach_boss2_interaction(Stage2_boss* boss2, std::vector<Approach*>& bullets);
	void bomb_boss2_interaction(Stage2_boss* boss2, std::vector<BombWeapon*>& bullets);
	void breath_boss2_interaction(Stage2_boss* boss2, std::vector<BreathWeapon*>& bullets);
	void meteor_boss2_interaction(Stage2_boss* boss2, std::vector<Meteor*>& bullets);
	void boss2_player_interaction(Player* player);

};
extern Interaction interaction;

#endif;