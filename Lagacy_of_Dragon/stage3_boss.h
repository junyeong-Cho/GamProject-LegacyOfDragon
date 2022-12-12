#ifndef BOSS3_H
#define BOSS3_H

#include <vector>
#include "Player.h"

using namespace doodle;
using namespace std;

const Image Boss3r{ "enemy/enemy6.png" };

inline bool boss3_move_check = false;
inline float boss3_x = 750;
inline float boss3_y = 500;
inline int s3bossSize = 150;
inline int boss3_hp = 100;
inline int s3_boss_vel = 2;
inline int s3_bullet_v = 10;

constexpr int b3_hp_x = 250;
constexpr int b3_hp_y = 800;
constexpr int b3_hp_w = 1000;
constexpr int b3_hp_h = 10;

constexpr int b3_attackSize = 20;
inline int boss3_timer = 0;
inline double boss3_timers = 0;
static constexpr int b3_attack_delay = 2;


inline bool b3_attack_on = false;

struct Boss_dead;

inline Color hp_color_3 = HexColor{ 0xfff000ff };

struct Stage3_boss {
	float x = 0;
	float y = 0;
	int size = 0;
	int health = 100;
	int velocity = 0;

	void draw();
	void move(Player* player);
	void hp();
};

struct Boss_attack {
	float attack_pos_x = 0;
	float attack_pos_y = 0;
	int attack_size = 0;
	float player_x = 0;
	float player_y = 0;
	float angleX = (player_x - attack_pos_x);
	float angleY = (player_y - attack_pos_y);

	void draw_enemy_attack();
	void fire_attack();
};

struct Boss_dead
{
	int x = 0;
	int y = 0;
	int size = 0;
	int health = 0;

	void draw();
};

struct S3boss_update {
	int timer_check = 4;
	int regen_delay = 4;
	int count_once = 0;

	
	void attack_create(std::vector<Boss_attack*>& attack, Stage3_boss* stage3_boss, Player* player);
	void attack_draw(std::vector<Boss_attack*>& attack);
	void attack_remove(std::vector<Boss_attack*>& attack);

};


extern S3boss_update s3boss_update;


#endif