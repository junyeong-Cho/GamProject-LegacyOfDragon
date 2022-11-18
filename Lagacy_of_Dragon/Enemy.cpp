#include "Enemy.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Enemy::draw()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, size, size);
}

void Enemy_update::tuto_enemy_create(std::vector<Enemy*>& tutoenemys){
	if (timer > timer_check)
	{
		for (; count_enemy_start < tutoMax; count_enemy_start++)
		{
			int r_enemy_y = random(enemyMin, enemyMax);
			int r_enemy_x = random(enemyMin, enemyMax);
			tutoenemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, enemySize });
		}
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
