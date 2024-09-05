
//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Player.h"
#include "Camera.h"
#include "bomb_weapon.h"

inline double timer = 0;
inline int int_timer = 0;

inline int count_enemy_start = 0;
inline int tuto_enemy_max = 3;
inline int Max = 6;
inline int count_enemy = 0;
static constexpr int enemyMin = -800;
static constexpr int enemyMax = 800;
static constexpr int enemySize = 30;
static constexpr int avoid_gap = 200;

constexpr int attackSize = 20;

static constexpr int enemySize_1_3 = 90;
static constexpr int enemySize_2_1 = 40;

constexpr int enemy_vel_min = 1;
constexpr int enemy_vel_max = 3;

constexpr int enemy_vel_min_2_1 = 4;
constexpr int enemy_vel_max_2_1 = 6;

constexpr int remain_max_tuto = 5;
constexpr int remain_max_1_1 = 15;
constexpr int remain_max_1_2 = 7;
constexpr int remain_max_1_3 = 4;
constexpr int remain_max_2_1 = 20;
constexpr int remain_max_2_2 = 10;
constexpr int remain_max_2_3 = 5;

static constexpr int E_Bvelocity = 6;
static constexpr int attack_delay = 2;

const Image enemy1{ "enemy/enemy1.png" };
const Image enemy2{ "enemy/enemy2.png" };
const Image enemy3{ "enemy/enemy3.png" };
const Image enemy4{ "enemy/enemy4.png" };
const Image enemy5{ "enemy/enemy5.png" };
const Image enemy6{ "enemy/enemy6.png" };
const Image g3attack{ "attack/g3bullet.png" };


struct Enemy {
	float x = 0;
	float y = 0;
<<<<<<< HEAD
	double health = 2;
=======
	int health = 1;
>>>>>>> Camera_error
	int deal = 0;
	float speed = 0.5;
	int enemysize = 30;
	unsigned int color = 0xffffffff;
	int type = 0;
<<<<<<< HEAD

	Enemy(float _x, float _y, double _health, int _deal, float _speed, int _enemysize, unsigned int _color, int _type)
=======
	Enemy(float _x, float _y, int _health, int _deal, float _speed, int _enemysize, unsigned int _color, int _type)
>>>>>>> Camera_error
	{
		x = _x;
		y = _y;
		health = _health;
		deal = _deal;
		speed = _speed;
		enemysize = _enemysize;
		color = _color;
		type = _type;
	}
<<<<<<< HEAD
	void enemy1_draw();
	void enemy2_draw();
	void enemy3_draw();
	void enemy4_draw();
	void enemy5_draw();
	void enemy6_draw();

};

=======
	void draw();
};
>>>>>>> Camera_error
struct Enemy_attack {
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

struct Enemy_update {
	int timer_check = 4;
<<<<<<< HEAD
	int regen_delay = 7;
	int count_once = 0;
	virtual void enemy_remove(std::vector<Enemy*>& enemys, std::vector<BombWeapon*>& bullets);
	virtual void enemy_create(std::vector<Enemy*>& enemys, int regen);
	virtual void enemy_move(std::vector<Enemy*>& enemys, Player* player);
	virtual void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player);
	virtual void attack_create(std::vector<Enemy_attack*>& attack, std::vector<Enemy*>& enemys, Player player);
	virtual void attack_draw(std::vector<Enemy_attack*>& attack);
	virtual void attack_remove(std::vector<Enemy_attack*>& attack);

	virtual void enemy_death(std::vector<Enemy*>& enemys, int* death);
};
=======
	int regen_delay = 4;
	int count_once = 0;
	virtual void enemy_create(std::vector<Enemy*>& enemys, int regen);
	virtual void enemy_move(std::vector<Enemy*>& enemys, Player* player);
	virtual void attack_create(std::vector<Enemy_attack*>& attack, std::vector<Enemy*>& enemys, Player player);
	virtual void attack_draw(std::vector<Enemy_attack*>& attack);
	virtual void attack_remove(std::vector<Enemy_attack*>& attack);
}; 
>>>>>>> Camera_error
extern Enemy_update enemy_update;
struct Enemy_update_tuto : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
};
struct Enemy_update_1_1 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
<<<<<<< HEAD
	void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player) override;
};
struct Enemy_update_1_2 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
	void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player) override;
=======
};
struct Enemy_update_1_2 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
>>>>>>> Camera_error
};
struct Enemy_update_1_3 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
	void enemy_move(std::vector<Enemy*>& enemys, Player* player) override;
<<<<<<< HEAD
	void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player) override;
};
struct Enemy_update_2_1 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
	void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player) override;
};
struct Enemy_update_2_2 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
	void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player) override;
};
struct Enemy_update_2_3 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
	void enemy_fix_move(std::vector<Enemy*>& enemys, Player* player) override;
=======
};
struct Enemy_update_2_1 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
};
struct Enemy_update_2_2 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
};
struct Enemy_update_2_3 : public Enemy_update {
	void enemy_create(std::vector<Enemy*>& enemys, int regen) override;
>>>>>>> Camera_error
};


#endif