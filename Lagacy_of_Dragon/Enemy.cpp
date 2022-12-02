#include "Enemy.h"
#include <doodle\doodle.hpp>
#include <iostream>
using namespace std;
using namespace doodle;

void Enemy::draw()
{
	set_fill_color(HexColor{ color });
	draw_ellipse(x, y, enemysize, enemysize);
}

void Enemy_attack::draw_enemy_attack()
{
	set_fill_color(HexColor{ 0xff6a00ff });
	draw_ellipse(attack_pos_x, attack_pos_y, attack_size, attack_size);
}
void Enemy_attack::fire_attack()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * E_Bvelocity);
	float velocityY = (sin(aimAngle) * E_Bvelocity);

	attack_pos_x += static_cast<int>(velocityX);
	attack_pos_y += static_cast<int>(velocityY);
}

void Enemy_update::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 0, 0.5, 30, 0xffffffff, 0 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update::enemy_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw();
		pop_settings();

		if (enemys[i]->x >= player->chara_pos_x)
		{
			enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->x <= player->chara_pos_x)
		{
			enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y >= player->chara_pos_y)
		{
			enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
		if (enemys[i]->y <= player->chara_pos_y)
		{
			enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed;
		}
	}
}
void Enemy_update_1_3::enemy_move(std::vector<Enemy*>& enemys, Player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		push_settings();
		enemys[i]->draw();
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

void Enemy_update_tuto::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 0, 0.5, 30, 0xffffffff, 0 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_1_1::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 5, 1, 0.5, 30, 0xffffffff, 1 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_1_2::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 0, 0.5, 30, 0xffffffff, 2 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_1_3::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);
	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 6, 3, 1.5, 90, 0xfff00fff, 3 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_2_1::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 1, 1, 4, 30, 0xf00fffff, 4 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_2_2::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 2, 2, 4, 30, 0xff00ffff , 5 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update_2_3::enemy_create(std::vector<Enemy*>& enemys, int regen)
{
	int_timer = static_cast<int>(timer);

	if (int_timer % regen_delay == 1 && count_once != int_timer)
	{
		for (int i = 0; i < regen; i++)
		{
			push_settings();
			float r_enemy_y = static_cast<float>(random(enemyMin, enemyMax));
			float r_enemy_x = static_cast<float>(random(enemyMin, enemyMax));
			enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, 5, 3, 2.5, 30, 0xf000ffff, 6 });
			pop_settings();
		}
		count_once = int_timer;
	}
}
void Enemy_update::attack_create(std::vector<Enemy_attack*>& attack, std::vector<Enemy*>& enemys, Player player)
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
			attack[i]->draw_enemy_attack();
			attack[i]->fire_attack();
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

