#include "stage1_boss.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Stage1_boss::draw()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, size, size);
}

void S1boss_update::s1_boss_update(std::vector<Stage1_boss*>& stage1_boss) {

	int r_boss_x = 500;
	int r_boss_y = 500;

	stage1_boss.push_back(new Stage1_boss{ r_boss_x, r_boss_y, s1bossSize });

	
}

void S1boss_attack::s1_boss_attack(std::vector<Stage1_boss*>& stage1_boss, Player* player, B1attack attack)
{
	switch (attack)
	{
	case B1attack::at_attack1: // 가로
		b1_blink_timer += DeltaTime;
		if (b1_blink_timer > b1_blink_check)
		{
			HexColor({ 0xff0000ff });
			draw_rectangle(0, 300, Width, 400);
			b1_blink_check += 0.7;

			if (b1_blink_timer > b1_attack_checked)
			{
				b1_attack_timer += DeltaTime;
				if (b1_attack_timer > b1_attack_check)
				{
					if (player->chara_pos_y > 300 && player->chara_pos_y < 700)
					{
						//hp_timer += DeltaTime;
						//if (hp_timer >= hp_time_check)
						//{
							player->hp -= 3;
					  //	hp_time_check += 0.7;
					  //  }

						if (player->hp == 0)
						{
							return 0;
						}
					}
				}
			}
		}
	
	case B1attack::at_attack2: // 세로
		draw_rectangle(300, 0, 700, Height);
		if(player->chara_pos_x > 300 && player->chara_pos_x < 700)

	case B1attack::at_attack3: // 중앙
		draw_rectangle(200, 200, 600, 600);
		if(player->chara_pos_x > 200 && player->chara_pos_x < 800 && player->chara_pos_y > 200 && player->chara_pos_y < 800)

	case B1attack::at_attack4: // 세로 3줄
		draw_rectangle(200, 0, 100, Height);
		draw_rectangle(450, 0, 100, Height);
		draw_rectangle(700, 0, 100, Height);
		if (player->chara_pos_x > 200 && player->chara_pos_x < 300)
		if (player->chara_pos_x > 450 && player->chara_pos_x < 550)
		if (player->chara_pos_x > 700 && player->chara_pos_x < 800)


	case B1attack::at_attack5: // 가로 3줄
		draw_rectangle(0, 200, , 100);
		draw_rectangle(0, 450, 100, 100);
		draw_rectangle(0, 700, 100, 100);
		if (player->chara_pos_y > 200 && player->chara_pos_y < 300)
		if (player->chara_pos_y > 450 && player->chara_pos_y < 550)
		if (player->chara_pos_y > 700 && player->chara_pos_y < 800)

	case B1attack::at_attack0: // 기본
		break;
	}
}

void S1boss_update::s1_boss_move(std::vector<Stage1_boss*>& stage1_boss, Player* player )
{
	for (int i = 0; i < stage1_boss.size(); i++)
	{
		push_settings();
		stage1_boss[i]->draw();
		pop_settings();

		if (stage1_boss[i]->x >= player->chara_pos_x)
		{
			stage1_boss[i]->x -= random(s1_vel_min, s1_vel_max);
		}
		if (stage1_boss[i]->x <= player->chara_pos_x)
		{
			stage1_boss[i]->x += random(s1_vel_min, s1_vel_max);
		}
		if (stage1_boss[i]->y >= player->chara_pos_y)
		{
			stage1_boss[i]->y -= random(s1_vel_min, s1_vel_max);
		}
		if (stage1_boss[i]->y <= player->chara_pos_y)
		{
			stage1_boss[i]->y += random(s1_vel_min, s1_vel_max);
		}

	}
}
