#include "Interaction.h"

#include "ice_weapon.h"
#include "auto_weapon.h"
#include "back_weapon.h"
#include "bomb_weapon.h"
#include "breath_weapon.h"
#include "storm_weapon.h"
#include "approach_weapon.h"
#include "meteor_weapon.h"

#include "stage1_boss.h"
#include "stage2_boss.h"


void Interaction::player_enemy_interaction(std::vector<Enemy*>& enemys, Player* player)
{
	for (int j = 0; j < enemys.size(); j++)
	{
		double a = player->chara_pos_x - enemys[j]->x;
		double b = player->chara_pos_y - enemys[j]->y;
		double distance = sqrt(a * a + b * b);

		if (distance < chararadius + enemys[j]->enemysize)
		{
			hp_timer += DeltaTime;
			if (hp_timer >= hp_time_check)
			{
				player->hp -= 1;
				hp_time_check += 0.7;
			}

			if (player->hp == 0)
			{

			}
		}
	}
}

void Interaction::bullet_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Shooting*>& bullets) {
	
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size + enemys[j]->enemysize)
			{
				if (enemys[j]->health - 1 == 0)
				{
					delete bullets[i];
					delete enemys[j];

					bullets.erase(bullets.begin() + i);
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					delete bullets[i];
					bullets.erase(bullets.begin() + i);
					enemys[j]->health--;
				}
			}
		}
	}
}

void Interaction::ice_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<IceWeapon*>& bullets) 
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size + enemys[j]->enemysize)
			{
				if (enemys[j]->health - 1 == 0)
				{
					delete bullets[i];
					delete enemys[j];

					bullets.erase(bullets.begin() + i);
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					delete bullets[i];
					bullets.erase(bullets.begin() + i);
					enemys[j]->health --;
				}
			}
		}
	}
}

void Interaction::storm_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Storm*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / static_cast<double>(2) + enemys[j]->enemysize)
			{
				if (enemys[j]->x <= bullets[i]->bullet_pos_x)
				{
					enemys[j]->x += bullets[i]->velocity;
				}
				if (enemys[j]->x >= bullets[i]->bullet_pos_x)
				{
					enemys[j]->x -= bullets[i]->velocity;
				}
				if (enemys[j]->y <= bullets[i]->bullet_pos_y)
				{
					enemys[j]->y += bullets[i]->velocity;
				}
				if (enemys[j]->y >= bullets[i]->bullet_pos_y)
				{
					enemys[j]->y -= bullets[i]->velocity;
				}
				
				if (enemys[j]->health - 0.3 == 0)
				{
					delete enemys[j];
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health -= 0.3;
				}
			}
		}
	}
}

void Interaction::back_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BackWeapon*>& bullets, Player* player)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			//Knockback
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance1 = sqrt(a * a + b * b);

			//Damage
			double c = bullets[i]->bullet_pos_x - enemys[j]->x;
			double d = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(c * c + d * d);

			if (distance1 < bullets[i]->size1 / static_cast<double>(2) + enemys[j]->enemysize / static_cast<double>(2))
			{
				back_timers += DeltaTime;
				if (back_timers < back_time_checks)
				{
					if (enemys[i]->x >= player->chara_pos_x)
					{
						enemys[i]->x += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed * bullets[i]->velocity1;
					}
					if (enemys[i]->x <= player->chara_pos_x)
					{
						enemys[i]->x -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed * bullets[i]->velocity1;
					}
					if (enemys[i]->y >= player->chara_pos_y)
					{
						enemys[i]->y += random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed * bullets[i]->velocity1;
					}
					if (enemys[i]->y <= player->chara_pos_y)
					{
						enemys[i]->y -= random(enemy_vel_min, enemy_vel_max) * enemys[i]->speed * bullets[i]->velocity1;
					}
				}
				else if (back_timers >= back_time_checks)
				{
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
				back_time_checks += 1;
			}

			if (distance < bullets[i]->size / static_cast<double>(2) + enemys[j]->enemysize / static_cast<double>(2))
			{
				if (enemys[j]->health - 1 == 0)
				{
					delete enemys[j];
					enemys.erase(enemys.begin() + j);
					break;
				}
				else
				{
					enemys[j]->health--;
				}
			}

			if (back_timer == 0)
			{
				back_timers = 0;
			}
		}
	}
}

void Interaction::bomb_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BombWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / static_cast<double>(2) + enemys[j]->enemysize / static_cast<double>(2))
			{
				double c = bullets[i]->bullet_pos_x + bullets[i]->range - enemys[j]->x;
				double d = bullets[i]->bullet_pos_y + bullets[i]->range - enemys[j]->y;
				double disrange = sqrt(c * c + d * d);

				if (disrange < enemys[j]->enemysize + bullets[i]->range)
				{
					if (enemys[j]->health - 1 == 0)
					{
						delete bullets[i];
						delete enemys[j];

						bullets.erase(bullets.begin() + i);
						enemys.erase(enemys.begin() + j);
						break;
					}
					else
					{
						delete bullets[i];
						bullets.erase(bullets.begin() + i);
						enemys[j]->health--;
					}
				}
			}
		}
	}
}

void Interaction::breath_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BreathWeapon*>& bullets, Player* player)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size1 / static_cast<double>(2) + enemys[j]->enemysize / static_cast<double>(2))
			{
				if (enemys[j]->health - 1 == 0)
				{
					delete enemys[j];				
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health--;
				}
			}
		}
	}
}

void Interaction::approach_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Approach*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->x - enemys[j]->x;
			double b = bullets[i]->y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / static_cast<double>(2) + enemys[j]->enemysize / static_cast<double>(2))
			{
				if (enemys[j]->health - 1 == 0)
				{
					delete enemys[j];
	                enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health--;
				}
			}
		}
	}
}

void Interaction::meteor_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Meteor*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / static_cast<double>(2) + enemys[j]->enemysize / static_cast<double>(2))
			{
				if (enemys[j]->health - 1 == 0)
				{
					delete enemys[j];
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health--;
				}
			}
		}
	}
}

void Interaction::player_boss1_interaction(Stage1_boss* boss1, std::vector<Shooting*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss1->size / static_cast<double>(2))
		{
			if (boss1->health == 0)
			{
				delete bullets[i];
				delete boss1;
				bullets.erase(bullets.begin() + i);
				break;
			}
			else {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				boss1->health--;
				break;
			}
		}	
	}
}

void Interaction::player_boss2_interaction(Stage2_boss* boss2, std::vector<Shooting*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{	
		double a = bullets[i]->bullet_pos_x - boss2->x;
		double b = bullets[i]->bullet_pos_y - boss2->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss2->size)
		{
			if (boss2->health - 1 == 0)
			{
				delete bullets[i];
				delete boss2;
				bullets.erase(bullets.begin() + i);
				break;
			}
			else 
			{
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				boss2->health--;
				break;
			}
		}
	}
}

void Interaction::boss2_player_interaction(Player* player)
{
	if (is_b2_hit == true)
	{
		hp_timer += DeltaTime;
		if (hp_timer >= hp_time_check)
		{
			player->hp -= 1;
			hp_time_check += 0.7;
		}

		if (player->hp == 0)
		{

		}
	}
}
