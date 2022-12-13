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
#include "stage3_boss.h"
#include "UIsetting.h"

void Interaction::player_enemyat_interaction(std::vector<Enemy_attack*>& attack, Player* player)
{
	for (int j = 0; j < attack.size(); j++)
	{
		double a = player->chara_pos_x - attack[j]->attack_pos_x;
		double b = player->chara_pos_y - attack[j]->attack_pos_y;
		double distance = sqrt(a * a + b * b);

		if (distance < chararadius + attack[j]->attack_size)
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


void Interaction::player_enemy_interaction(std::vector<Enemy*>& enemys, Player* player)
{
	for (int j = 0; j < enemys.size(); j++)
	{
		double a = player->chara_pos_x - enemys[j]->x;
		double b = player->chara_pos_y - enemys[j]->y;
		double distance = sqrt(a * a + b * b);

		if (distance < chararadius + enemys[j]->enemysize/2)
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
void Interaction::bullet_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Shooting*>& bullets, int* death) {
	
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size/2 + enemys[j]->enemysize/2)
			{
				if (enemys[j]->health - 1 <= 0)
				{
					(* death)++;
					delete bullets[i];
					delete enemys[j];

					bullets.erase(bullets.begin() + i);
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health--;
					delete bullets[i];
					bullets.erase(bullets.begin() + i);
					break;
				}
			}
		}
	}
}
void Interaction::ice_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<IceWeapon*>& bullets, int* death) 
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size/2 + enemys[j]->enemysize/2)
			{
				if (enemys[j]->health - 1 == 0)
				{
					(*death)++;
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
void Interaction::storm_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Storm*>& bullets, int* death)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / static_cast<double>(2) + enemys[j]->enemysize/2)
			{

				if (enemys[j]->health - 0.5 == 0)
				{
					(*death)++;
					delete enemys[j];
					enemys.erase(enemys.begin() + j);
					break;
				}
				else {
					enemys[j]->health -= 0.5;
				}

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
			double a = bullets[i]->bullet_pos_x - enemys[j]->x;
			double b = bullets[i]->bullet_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size / 2 + enemys[j]->enemysize/2)
			{
				enemys[j]->speed -= DeltaTime * bullets[i]->velocity;
			}
		
		}
	}
}
void Interaction::bomb_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BombWeapon*>& bullets, int* death)
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
				is_bomb_hit = true;
				double c = bullets[i]->bullet_pos_x - enemys[j]->x;
				double d = bullets[i]->bullet_pos_y - enemys[j]->y;
				double distance1 = sqrt(c * c + d * d);

				if (distance1 < bullets[i]->range / 2 + enemys[j]->enemysize / 2)
				{
					if (enemys[j]->health - 1 == 0)
					{
						(*death)++;
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
}
void Interaction::breath_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<BreathWeapon*>& bullets, Player* player, int* death)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < enemys.size(); j++)
		{
			if (get_mouse_x() > player->chara_pos_x)
			{
				if (enemys[j]->x > player->chara_pos_x &&
					enemys[j]->y  < player->chara_pos_y + 50 &&
					enemys[j]->y  > player->chara_pos_y - 50)
				{
					if (enemys[j]->health - 1 <= 0)
					{
						(*death)++;
						delete enemys[j];
						enemys.erase(enemys.begin() + j);
						break;
					}
					else {
						enemys[j]->health--;
					}
				}
			}

			if (get_mouse_x() < player->chara_pos_x)
			{
				if (enemys[j]->x < player->chara_pos_x &&
					enemys[j]->y  < player->chara_pos_y + 50 &&
					enemys[j]->y  > player->chara_pos_y - 50)
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
}
void Interaction::approach_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Approach*>& bullets, int* death)
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
					(*death)++;
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
void Interaction::meteor_enemy_interaction(std::vector<Enemy*>& enemys, std::vector<Meteor*>& bullets, int* death)
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
					(*death)++;
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


//³¯¶ó´Ù´Ï´Â³ð 
void Interaction::player_boss3_interaction(Stage3_boss* boss3, std::vector<Shooting*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss3->x;
		double b = bullets[i]->bullet_pos_y - boss3->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss3->size / static_cast<double>(2))
		{
			if (boss3->health == 0)
			{
				delete bullets[i];
				delete boss3;
				bullets.erase(bullets.begin() + i);
				break;
			}
			else {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				boss3->health--;
				break;
			}
		}	
	}
}
void Interaction::ice_boss3_interaction(Stage3_boss* boss3, std::vector<IceWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss3->x;
		double b = bullets[i]->bullet_pos_y - boss3->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss3->size / static_cast<double>(2))
		{
			if (boss3->health == 0)
			{
				delete bullets[i];
				delete boss3;
				bullets.erase(bullets.begin() + i);
				break;
			}
			else {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				boss3->health--;
				break;
			}
		}
	}
}
void Interaction::storm_boss3_interaction(Stage3_boss* boss3, std::vector<Storm*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss3->x;
		double b = bullets[i]->bullet_pos_y - boss3->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss3->size / static_cast<double>(2))
		{
			hp_b3_timer += DeltaTime;
			if (hp_b3_timer >= hp_b3_check)
			{			
				if (boss3->health - 0.3 == 0)
				{
					delete boss3;
					hp_b3_timer = 0;
					hp_b3_check = 0.7;
					break;
				}
				else 
				{
					boss3->health -= 0.3;
					hp_b3_check +=0.7;
				}
		    }
			
		}
	}
}


//ÁÂ¿ì ¿òÁ÷ÀÌ´Â ³ð

void Interaction::player_boss1_interaction(Stage1_boss* boss1, std::vector<Shooting*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss1->size)
		{
			if (boss1->health - 1 == 0)
			{
				delete bullets[i];
				delete boss1;
				bullets.erase(bullets.begin() + i);
				break;
			}
			else
			{
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				boss1->health--;
				break;
			}
		}
	}
}
void Interaction::ice_boss1_interaction(Stage1_boss* boss1, std::vector<IceWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss1->size)
		{
			if (boss1->health - 1 == 0)
			{
				delete bullets[i];
				delete boss1;
				bullets.erase(bullets.begin() + i);
				break;
			}
			else
			{
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				boss1->health--;
				break;
			}
		}
	}
}
void Interaction::storm_boss1_interaction(Stage1_boss* boss1, std::vector<Storm*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{

		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss1->size)
		{
			hp_b1_timer += DeltaTime;
			if (hp_b1_timer >= hp_b1_check)
			{
				if (boss1->health - 0.3 == 0)
				{
					delete boss1;
					hp_b1_timer = 0;
					hp_b1_check = 0.7;
					break;
				}
				else
				{
					boss1->health -= 0.3;
					hp_b1_check += 0.7;
				}
			}
		}
	}
}
void Interaction::back_boss1_interaction(Stage1_boss* boss1, std::vector<BackWeapon*>& bullets) {}
void Interaction::approach_boss1_interaction(Stage1_boss* boss1, std::vector<Approach*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->x - boss1->x;
		double b = bullets[i]->y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss1->size)
		{
			if (boss1->health - 1 == 0)
			{
				delete boss1;
				break;
			}
			else
			{
				boss1->health--;
				break;
			}
		}
	}
}
void Interaction::bomb_boss1_interaction(Stage1_boss* boss1, std::vector<BombWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);
		if (distance < bullets[i]->size / 2 + boss1->size / 2)
		{
			is_bomb_hit = true;
			double c = bullets[i]->bullet_pos_x - boss1->x;
			double d = bullets[i]->bullet_pos_y - boss1->y;
			double distance1 = sqrt(c * c + d * d);

			if (distance1 < bullets[i]->range / 2 + boss1->size / 2)
			{
				if (boss1->health - 1 == 0)
				{
					delete boss1;
					break;
				}
				else {
					boss1->health--;
				}
			}
		}
	}
}
void Interaction::breath_boss1_interaction(Stage1_boss* boss1, std::vector<BreathWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{

		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size1 / static_cast<double>(2) + boss1->size / static_cast<double>(2))
		{
			hp_b1_timer += DeltaTime;
			if (hp_b1_timer >= hp_b1_check)
			{
				if (boss1->health - 2 == 0)
				{
					delete boss1;
					hp_b1_timer = 0;
					hp_b1_check = 0.7;
					break;
				}
				else
				{
					boss1->health -= 2;
					hp_b1_check += 0.7;
				}
			}
		}

	}
}
void Interaction::meteor_boss1_interaction(Stage1_boss* boss1, std::vector<Meteor*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss1->x;
		double b = bullets[i]->bullet_pos_y - boss1->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss1->size)
		{
			hp_b1_timer += DeltaTime;
			if (hp_b1_timer >= hp_b1_check)
			{
				if (boss1->health - 2 == 0)
				{
					delete boss1;
					hp_b1_timer = 0;
					hp_b1_check = 0.7;
					break;
				}
				else
				{
					boss1->health -= 2;
					hp_b1_check += 0.7;
				}
			}
		}
	}
}




//»¡°»ÀÌ
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
void Interaction::player_boss2_interaction(Stage2_boss* boss2, std::vector<Shooting*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{	
		double a = bullets[i]->bullet_pos_x - boss2->x;
		double b = bullets[i]->bullet_pos_y - boss2->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss2->size)
		{
			if (boss2->health - 1 <= 0)
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
void Interaction::ice_boss2_interaction(Stage2_boss* boss2, std::vector<IceWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss2->x;
		double b = bullets[i]->bullet_pos_y - boss2->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss2->size)
		{
			if (boss2->health - 1 <= 0)
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
void Interaction::storm_boss2_interaction(Stage2_boss* boss2, std::vector<Storm*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{

		double a = bullets[i]->bullet_pos_x - boss2->x;
		double b = bullets[i]->bullet_pos_y - boss2->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss2->size)
		{

			hp_b2_timer += DeltaTime;
			if (hp_b2_timer >= hp_b2_check)
			{
				if (boss2->health - 0.5 <= 0)
				{
					delete boss2;
					hp_b2_timer = 0;
					hp_b2_check = 0.7;
					break;
				}
				else
				{
					boss2->health -= 0.5;
					hp_b2_check += 0.7;
				}
			}
		}
	}
}
void Interaction::back_boss2_interaction(Stage2_boss* boss2, std::vector<BackWeapon*>& bullets){}
void Interaction::approach_boss2_interaction(Stage2_boss* boss2, std::vector<Approach*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->x - boss2->x;
		double b = bullets[i]->y - boss2->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss2->size)
		{
			if (boss2->health - 1 <= 0)
			{
				delete boss2;
				break;
			}
			else
			{
				boss2->health--;
				break;
			}
		}
	}
}
void Interaction::bomb_boss2_interaction(Stage2_boss* boss2, std::vector<BombWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss2->x;
		double b = bullets[i]->bullet_pos_y - boss2->y;
		double distance = sqrt(a * a + b * b);
		if (distance < bullets[i]->size / 2 + boss2->size / 2)
		{
			is_bomb_hit = true;
			double c = bullets[i]->bullet_pos_x - boss2->x;
			double d = bullets[i]->bullet_pos_y - boss2->y;
			double distance1 = sqrt(c * c + d * d);

			if (distance1 < bullets[i]->range / 2 + boss2->size / 2)
			{
				if (boss2->health - 1 <= 0)
				{
					delete boss2;
					break;
				}
				else {
					boss2->health--;
				}
			}
		}
	}
}
void Interaction::breath_boss2_interaction(Stage2_boss* boss2, std::vector<BreathWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		
			double a = bullets[i]->bullet_pos_x - boss2->x;
			double b = bullets[i]->bullet_pos_y - boss2->y;
			double distance = sqrt(a * a + b * b);

			if (distance < bullets[i]->size1 / static_cast<double>(2) + boss2->size / static_cast<double>(2))
			{
				hp_b2_timer += DeltaTime;
				if (hp_b2_timer >= hp_b2_check)
				{
					if (boss2->health - 2 <= 0)
					{
						delete boss2;
						hp_b2_timer = 0;
						hp_b2_check = 0.7;
						break;
					}
					else
					{
						boss2->health -= 2;
						hp_b2_check += 0.7;
					}
				}
			}
		
	}
}
void Interaction::meteor_boss2_interaction(Stage2_boss* boss2, std::vector<Meteor*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		double a = bullets[i]->bullet_pos_x - boss2->x;
		double b = bullets[i]->bullet_pos_y - boss2->y;
		double distance = sqrt(a * a + b * b);

		if (distance < bullets[i]->size / static_cast<double>(2) + boss2->size)
		{
			hp_b2_timer += DeltaTime;
			if (hp_b2_timer >= hp_b2_check)
			{
				if (boss2->health - 2 <= 0)
				{
					delete boss2;
					hp_b2_timer = 0;
					hp_b2_check = 0.7;
					break;
				}
				else
				{
					boss2->health -= 2;
					hp_b2_check += 0.7;
				}
			}
		}
	}
}
