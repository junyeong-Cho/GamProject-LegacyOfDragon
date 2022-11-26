#include "Enemy.h"
#include <doodle\doodle.hpp>
#include <iostream>
using namespace std;
using namespace doodle;


void Enemy_tuto::draw_tuto()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, enemysize, enemysize);
}
void Enemy_1_1::draw_1_1()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, enemysize, enemysize);
}
void Enemy_1_3::draw_1_3()
{
	set_fill_color(HexColor{ 0xff0000ff });
	draw_ellipse(x, y, enemysize, enemysize);
}
void Enemy_2_1::draw_2_1()
{
	set_fill_color(HexColor{ 0x888888ff });
	draw_ellipse(x, y, enemysize, enemysize);
}
void Enemy_2_2::draw_2_2()
{
	set_fill_color(HexColor{ 0x888888ff });
	draw_ellipse(x, y, enemysize, enemysize);
}
void Enemy_2_3::draw_2_3()
{
	set_fill_color(HexColor{ 0x888888ff });
	draw_ellipse(x, y, enemysize, enemysize);
}

void Enemy_attack::draw_enemy_attack_1_3()
{
	set_fill_color(HexColor{ 0xff6a00ff });
	draw_ellipse(attack_pos_x, attack_pos_y, attack_size, attack_size);
}
void Enemy_attack::fire_attack_1_3()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * E_Bvelocity);
	float velocityY = (sin(aimAngle) * E_Bvelocity);

	attack_pos_x += static_cast<int>(velocityX);
	attack_pos_y += static_cast<int>(velocityY);
}

void Enemy_update::enemy_create(std::vector<Enemy_tuto*>& enemys) {
	if (timer > timer_check)
	{
		for (; count_enemy_start < tutoMax; count_enemy_start++)
		{
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			enemys.push_back(new Enemy_tuto{ r_enemy_x, r_enemy_y});
		}
	}
}
void Enemy_update::enemy_create(std::vector<Enemy_1_1*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			enemys.push_back(new Enemy_1_1{ r_enemy_x, r_enemy_y});
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update::enemy_create(std::vector<Enemy_1_3*>& enemys, int regen) {
	if (timer > timer_check)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			enemys.push_back(new Enemy_1_3{ r_enemy_x, r_enemy_y });
			pop_settings();
		}
	}
	timer_check += 4;
}
void Enemy_update::enemy_create(std::vector<Enemy_2_1*>& enemys, int regen) {
	int_timer = static_cast<int>(timer);
	if (int_timer % regen_delay == 0 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			enemys.push_back(new Enemy_2_1{ r_enemy_x, r_enemy_y });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update::enemy_create(std::vector<Enemy_2_2*>& enemys, int regen) {
	int_timer = static_cast<int>(timer);
	if (int_timer % regen_delay == 0 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			enemys.push_back(new Enemy_2_2{ r_enemy_x, r_enemy_y });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update::enemy_create(std::vector<Enemy_2_3*>& enemys, int regen) {
	int_timer = static_cast<int>(timer);
	if (int_timer % regen_delay == 0 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			enemys.push_back(new Enemy_2_3{ r_enemy_x, r_enemy_y });
			pop_settings();
		}
		count_once = int_timer;
	}
}

void Enemy_update::enemy_move(std::vector<Enemy_tuto*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw_tuto();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max);
		}

	}
}
void Enemy_update::enemy_move(std::vector<Enemy_1_1*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw_1_1();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max);
		}

	}
}
void Enemy_update::enemy_move(std::vector<Enemy_1_3*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw_1_3();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x - avoid_gap)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->x <= player->chara_pos_x + avoid_gap)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y >= player->chara_pos_y - avoid_gap)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max);
		}
		if (enemys[i]->y <= player->chara_pos_y + avoid_gap)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max);
		}

	}
}
void Enemy_update::enemy_move(std::vector<Enemy_2_1*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw_2_1();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}

	}
}
void Enemy_update::enemy_move(std::vector<Enemy_2_2*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw_2_2();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}

	}
}
void Enemy_update::enemy_move(std::vector<Enemy_2_3*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw_2_3();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min_2_1, enemy_vel_max_2_1);
		}

	}
}

void Enemy_update::attack_create(std::vector<Enemy_attack*>& attack, std::vector<Enemy_1_3*>& enemys, Player player)
{
	int_timer = static_cast<int>(timer);
	if (int_timer % attack_delay == 0 && count_once != int_timer) {
		for (int i = 0; i < enemys.size(); i++) {
			attack.push_back(new Enemy_attack{ enemys[i]->x , enemys[i]->y, attackSize, static_cast<float>(player.chara_pos_x), static_cast<float>(player.chara_pos_y) });
		}
		count_once = int_timer;
	}
}
void Enemy_update::attack_draw(std::vector<Enemy_attack*>& attack)
{
	{
		for (int i = 0; i < attack.size(); i++)
		{
			push_settings();
			attack[i]->draw_enemy_attack_1_3();
			attack[i]->fire_attack_1_3();
			pop_settings();
		}
	}
}
void Enemy_update::attack_remove(std::vector<Enemy_attack*>& attack)
{
	for (int i = 0; i < attack.size(); i++)
	{
		if (attack[i]->attack_pos_x > 1400 || attack[i]->attack_pos_x < 100 || attack[i]->attack_pos_y > 900 || attack[i]->attack_pos_y < 100)
		{
			delete attack[i];
			attack.erase(attack.begin() + i);
		}
	}
}

