#include "Interaction.h"

void Interaction::player_enemy_interaction(std::vector<Enemy_1_1*>& enemys, Player* player)
{
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = player->chara_pos_x - enemys[j]->x;
			double b = player->chara_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < chararadius + enemyradius)
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

void Interaction::bullet_enemy_interaction(std::vector<Enemy_tuto*>& enemys, std::vector<Shooting*>& bullets) {
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			for (int j = 0; j < enemys.size(); j++)
			{
				double a = bullets[i]->bullet_pos_x - enemys[j]->x;
				double b = bullets[i]->bullet_pos_y - enemys[j]->y;
				double distance = sqrt(a * a + b * b);

				if (distance < bulletradius + enemys[j]->enemysize)
				{
					score += 1;
					delete bullets[i];
					delete enemys[j];

					bullets.erase(bullets.begin() + i);
					enemys.erase(enemys.begin() + j);
					break;
				}
			}
		}
	}
}
void Interaction::bullet_enemy_interaction(std::vector<Enemy_1_1*>& enemys, std::vector<Shooting*>& bullets) {
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			for (int j = 0; j < enemys.size(); j++)
			{
				double a = bullets[i]->bullet_pos_x - enemys[j]->x;
				double b = bullets[i]->bullet_pos_y - enemys[j]->y;
				double distance = sqrt(a * a + b * b);

				if (distance < bulletradius + enemys[j]->enemysize)
				{
					score += 1;
					delete bullets[i];
					delete enemys[j];

					bullets.erase(bullets.begin() + i);
					enemys.erase(enemys.begin() + j);
					break;
				}
			}
		}
	}
}
void Interaction::bullet_enemy_interaction(std::vector<Enemy_1_3*>& enemys, std::vector<Shooting*>& bullets) {
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			for (int j = 0; j < enemys.size(); j++)
			{
				double a = bullets[i]->bullet_pos_x - enemys[j]->x;
				double b = bullets[i]->bullet_pos_y - enemys[j]->y;
				double distance = sqrt(a * a + b * b);

				if (distance < bulletradius + enemys[j]->enemysize)
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
}
void Interaction::bullet_enemy_interaction(std::vector<Enemy_2_1*>& enemys, std::vector<Shooting*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bulletradius + enemys[j]->enemysize)
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


void bullet_s1boss_interaction(Stage1_boss* stage1_boss, std::vector<Shooting*>& bullets)
{
	{
		for (int i = 0; i < bullets.size(); i++)
		{
				double a = bullets[i]->bullet_pos_x - stage1_boss->x;
				double b = bullets[i]->bullet_pos_y - stage1_boss->y;
				double distance = sqrt(a * a + b * b);

				if (distance < bulletradius + stage1_boss->size)
				{
					if (stage1_boss->health - 1 == 0)
					{
						delete bullets[i];
						delete stage1_boss;
						bullets.erase(bullets.begin() + i);
						break;
					}
					else {
						delete bullets[i];
						bullets.erase(bullets.begin() + i);
						stage1_boss->health--;
					}
				}
			
		}
	}

}
