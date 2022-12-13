#include "stage3_boss.h"
#include <doodle\doodle.hpp>
#include "Window_setting.h"
#include <iostream>
#include "Enemy.h"

using namespace doodle;

void Stage3_boss::draw()
{
	push_settings();
	set_image_mode(RectMode::Center);
	draw_image(Boss3r, x, y, size, size);
	pop_settings();
	
}
void Stage3_boss::move(Player* player)
{

	if (x >= player->chara_pos_x- avoid_gap)
	{
		x -= velocity * DeltaTime * 50;
	}
	if (x <= player->chara_pos_x + avoid_gap)
	{
		x += velocity * DeltaTime * 50;
	}
	if (y >= player->chara_pos_y - avoid_gap)
	{
		y -= velocity * DeltaTime * 50;
	}
	if (y <= player->chara_pos_y + avoid_gap)
	{
		y += velocity * DeltaTime * 50;
	}
}
void Stage3_boss::hp()
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(b3_hp_x, b3_hp_y, b3_hp_w, b3_hp_h);
	pop_settings();

	push_settings();
	set_fill_color(hp_color_3);
	draw_rectangle(b3_hp_x, b3_hp_y, 10 * health, b3_hp_h);
	pop_settings();

	if (health <=0 )
	{
		scene = 13;
	}
}
void Boss_dead::draw()
{
	set_fill_color(HexColor{ 0xff6a00ff });
	draw_ellipse(x, y, size, size);
}

void Boss_attack::draw_enemy_attack()
{
	set_fill_color(HexColor{ 0xff6a00ff });
	draw_ellipse(attack_pos_x, attack_pos_y, attack_size, attack_size);
}

void Boss_attack::fire_attack()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * s3_bullet_v);
	float velocityY = (sin(aimAngle) * s3_bullet_v);

	attack_pos_x += static_cast<int>(velocityX);
	attack_pos_y += static_cast<int>(velocityY);
}

void S3boss_update::attack_create(std::vector<Boss_attack*>& attack, Stage3_boss* stage3_boss,Player* player)
{
	boss3_timer = static_cast<int>(boss3_timers);
	if (boss3_timer % b3_attack_delay == 0 && count_once != boss3_timer) {
		
		attack.push_back(new Boss_attack{ stage3_boss->x , stage3_boss->y, b3_attackSize, static_cast<float>(player->chara_pos_x), static_cast<float>(player->chara_pos_y) });
		
		count_once = boss3_timer;
	}
}

void S3boss_update::attack_draw(std::vector<Boss_attack*>& attack)
{
	for (int i = 0; i < attack.size(); i++)
	{
		push_settings();
		attack[i]->draw_enemy_attack();
		attack[i]->fire_attack();
		pop_settings();
	}
}
void S3boss_update::attack_remove(std::vector<Boss_attack*>& attack)
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

