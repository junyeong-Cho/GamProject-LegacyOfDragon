#include "Interaction.h"

#include "ice_weapon.h"
#include "auto_weapon.h"
#include "back_weapon.h"
#include "bomb_weapon.h"
#include "breath_weapon.h"
#include "storm_weapon.h"
#include "approach_weapon.h"
#include "meteor_weapon.h"

void Interaction::player_enemy_interaction(std::vector<Enemy*>& enemys, Player* player)
{
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
				if (enemys[j]->health == 0)
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
					break;
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
					break;
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
				
				/*if (enemys[j]->health - 1 == 0)
				{
					delete enemys[j];
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health--;
				}*/
			}
		}
	}
}

void Interaction::back_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BackWeapon*>& bullets)
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
				back_timers += DeltaTime;
				if (back_timers < back_time_checks)
				{
					enemys[j]->speed -= DeltaTime * bullets[i]->velocity1;
				}
				else if (back_timers > back_time_checks)
				{
					back_timers = 0;
				}

				
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

			if (distance < bullets[i]->size / 2 + enemys[j]->enemysize / 2)
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
						break;
					}
				}
			}
		}
	}
}

void Interaction::auto_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<AutoWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / 2 + enemys[j]->enemysize / 2)
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
					break;
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
			/*double a = enemys[j]->x;
			double b = enemys[j]->y;
			double distance = sqrt(a * a + b * b);*/

			if (enemys[j]->x < player->chara_pos_x
				&& enemys[j]->y  < player->chara_pos_y + bullets[i]->size1
				&& enemys[j]->y  > player->chara_pos_y - bullets[i]->size1)
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

			if (enemys[j]->x > player->chara_pos_x
				&& enemys[j]->y  < player->chara_pos_y + bullets[i]->size1
				&& enemys[j]->y  > player->chara_pos_y - bullets[i]->size1)
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

			if (distance < bullets[i]->size / 2 + enemys[j]->enemysize / 2)
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

			if (distance < bullets[i]->size / 2 + enemys[j]->enemysize / 2)
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


