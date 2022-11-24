#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Player.h"

inline double timer = 0;
inline int int_timer = 0;
inline int count_once = 0;

inline int count_enemy_start = 0;
inline int tuto_enemy_max = 3;
inline int Max = 6;
inline int tutoMax = 6;
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

static constexpr int E_Bvelocity = 6;
static constexpr int attack_delay = 2;


struct Enemy {
	int x = 0;
	int y = 0;
};

struct Enemy_tuto : public Enemy {
	int health = 1;
	int deal = 0;
	float speed = 0.5;
	static const int enemysize = 30;

	void draw(std::vector<Enemy_tuto*>& enemys);
};

struct Enemy_1_1 : public Enemy {
	int health = 1;
	int deal = 0;
	float speed = 1;
	static const int enemysize = 30;

	void draw(std::vector<Enemy_1_1*>& enemys);
};

struct Enemy_1_3 : public Enemy {
	int health = 6;
	int deal = 3;
	float speed = 1.5;
	static const int enemysize = 90;

	void draw(std::vector<Enemy_1_3*>& enemys);
};

struct Enemy_2_1 : public Enemy {
	int health = 1;
	int deal = 1;
	float speed = 4;
	static const int enemysize = 30;
	
	void draw(std::vector<Enemy_2_1*>& enemys);
};

struct Enemy_2_2 : public Enemy {
	int health = 2;
	int deal = 2;
	float speed = 4;
	static const int enemysize = 30;

	void draw(std::vector<Enemy_2_2*>& enemys);
};

struct Enemy_2_3 : public Enemy {
	int health = 5;
	int deal = 3;
	float speed = 2.5;
	static const int enemysize = 30;

	void draw(std::vector<Enemy_2_3*>& enemys);
};

struct Enemy_attack {
	int attack_pos_x = 0;
	int attack_pos_y = 0;
	int attack_size = 0;
	float player_x = 0;
	float player_y = 0;
	float angleX = (player_x - attack_pos_x);
	float angleY = (player_y - attack_pos_y);

	void draw_enemy_attack_1_3();
	void fire_attack_1_3();
};

struct Enemy_update {
	int timer_check = 4;
	int regen_delay = 4;

	// tuto enemy
	void enemy_create(std::vector<Enemy_tuto*> & enemys);
	void enemy_move(std::vector<Enemy_tuto*>& enemys, Player* player);

	// enemy_1_1
	void enemy_create(std::vector<Enemy_1_1*>& enemys, int regen);
	void enemy_move(std::vector<Enemy_1_1*>& enemys, Player* player);

	// enemy_1_3
	void enemy_create(std::vector<Enemy_1_3*>& enemys, int regen);
	void enemy_move(std::vector<Enemy_1_3*>& enemys, Player* player);
	void attack_create(std::vector<Enemy_attack*>& attack, std::vector<Enemy_1_3*>& enemys, Player player);
	void attack_draw(std::vector<Enemy_attack*>& attack);
	void attack_remove(std::vector<Enemy_attack*>& attack);
	
	// enemy_2_1
	void enemy_create(std::vector<Enemy_2_1*>& enemys, int regen);
	void enemy_move(std::vector<Enemy_2_1*>& enemys, Player* player);

	// enemey_2_2
	void enemy_create(std::vector<Enemy_2_2*>& enemys, int regen);
	void enemy_move(std::vector<Enemy_2_2*>& enemys, Player* player);

	// enemey_2_3
	void enemy_create(std::vector<Enemy_2_3*>& enemys, int regen);
	void enemy_move(std::vector<Enemy_2_3*>& enemys, Player* player);

}; 
extern Enemy_update enemy_update;



#endif