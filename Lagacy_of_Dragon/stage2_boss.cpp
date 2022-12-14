//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "stage2_boss.h"
#include "Window_setting.h"
#include "Map_setting.h"

#include <doodle\doodle.hpp>

using namespace doodle;

void Stage2_boss::draw()
{
	push_settings();
	set_fill_color(HexColor{ 0xffff2aff });
	draw_image(Boss2r,x, y, size, size);
	pop_settings();
}
void Stage2_boss::move()
{
	b2_move_timer += DeltaTime;

	if (b2_move_timer > b2_move_check)
	{
		int r_boss_x = random(100, 1400) * DeltaTime * 50;
		int r_boss_y = random(100, 900) * DeltaTime * 50;

		x = r_boss_x;
		y = r_boss_y;

		b2_move_timer = 0;
	}
}
void Stage2_boss::hp()
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(b2_hp_x, b2_hp_y, b2_hp_w, b2_hp_h);
	pop_settings();

	push_settings();
	set_fill_color(hp_color_2);
	draw_rectangle(b2_hp_x, b2_hp_y, 5 * health, b2_hp_h);
	pop_settings();
	if (health <= 0)
	{
		map_setting.fade_out();
	}
}

void S2boss_update::s2_boss_attack(Stage2_boss* boss2, Player* player)
{
	push_settings();
	set_outline_color(attack_color);
	
	b2_change_timer += DeltaTime;

	if (b2_change_timer > b2_change_check) //3.5초 뒤에
	{
		if (boss2->health < 200 && boss2->health > 100)

		b2_change_random = random(0, 6);
		b2_blink_timer = 0;
		blink_color = blink_color_1;
		b2_blink_check = b2_blink_time;
		b2_change_check += 5; // 

		if (boss2->health <= 100 && boss2->health > 0)
		{
			b2_change_random = random(2, 9);
			b2_blink_timer = 0;
			blink_color = blink_color_1;
			b2_blink_check = b2_blink_time;
			b2_change_check += 5;
		}
	}

	r_attack = b2_change_random;

	if (r_attack == 0)
	{
		// 가로
		b2_blink_timer += DeltaTime;

		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}	
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(0, 200, Width, 550);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}
		

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_hori, 0, 200, Width, 550);
			pop_settings();

			if (player->chara_pos_y > 200 && player->chara_pos_y < 750)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 1)
	{
		// 세로
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(350, 0, 850, Height);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_ver1,350, 0, 850, Height);
			pop_settings();

			if (player->chara_pos_x > 350 && player->chara_pos_x < 1150)
			{
				b2_blink_timer = 0;
				b2_blink_check = b2_blink_time;
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 2)
	{
		// 왼쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(0, 0, Width / 2, Height);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_ver1, 0, 0, Width / 2, Height);
			pop_settings();
			if (player->chara_pos_x > 0 && player->chara_pos_x < Width / 2)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 3)
	{
		// 오른쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(Width / 2, 0, Width / 2, Height);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_ver1, Width / 2, 0, Width / 2, Height);
			pop_settings();
			if (player->chara_pos_x > Width / 2 && player->chara_pos_x < Width)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 4)
	{
		// 위쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(0, 0, Width + 100, Height / 2);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_hori, 0, 0, Width + 100, Height / 2);
			pop_settings();
			if (player->chara_pos_y > 100 && player->chara_pos_x < Height / 2 + 100)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 5)
	{
		// 아래쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(0, Height/2, Width, Height / 2);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_hori, 0, Height / 2, Width, Height / 2);
			pop_settings();
			if (player->chara_pos_y > Height / 2 && player->chara_pos_x < Height)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 6)
	{
		// 중앙
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				blink_color = attack_color;
				draw_rectangle(300, 150, 900, 600);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_mid,300, 150, 900, 600);
			pop_settings();
			if (player->chara_pos_x > 300 && player->chara_pos_x < 1200 && player->chara_pos_y > 150 && player->chara_pos_y < 750)
			{
				is_b2_hit = true;
			}
		}
	}
	
	if (r_attack == 7)
	{
		// 세로 3줄
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				blink_color = attack_color;
				draw_rectangle(200, 0, 200, Height);
				draw_rectangle(600, 0, 300, Height);
				draw_rectangle(1100, 0, 300, Height);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_ver, 200, 0, 200, Height);
			draw_image(razer_ver1, 600, 0, 300, Height);
			draw_image(razer_ver, 1100, 0, 200, Height);
			pop_settings();

			if (player->chara_pos_x > 200 && player->chara_pos_x < 400 ||
				player->chara_pos_x > 600 && player->chara_pos_x < 900 ||
				player->chara_pos_x > 1100 && player->chara_pos_x < 1300)
			{
				is_b2_hit = true;
			}
		}

	}

	if (r_attack == 8)
	{
		// 가로 3줄
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				blink_color = attack_color;
				draw_rectangle(0, 125, Width, 125);
				draw_rectangle(0, 375, Width, 250);
				draw_rectangle(0, 750, Width, 125);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}

		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_hori, 0, 125, Width, 125);
			draw_image(razer_hori, 0, 375, Width, 250);
			draw_image(razer_hori, 0, 750, Width, 125);
			pop_settings();


			if (player->chara_pos_y > 125 && player->chara_pos_y < 250 ||
				player->chara_pos_y > 375 && player->chara_pos_y < 625 ||
				player->chara_pos_y > 750 && player->chara_pos_y < 875)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 9)
	{
		// 기본
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			if (b2_blink_timer < b2_attack_checked)
			{
				is_b2_draw = true;
			}
			if (is_b2_draw == true)
			{
				push_settings();
				set_fill_color(blink_color);
				draw_rectangle(200, 0, 200, Height);
				draw_rectangle(600, 0, 300, Height);
				draw_rectangle(1100, 0, 200, Height);
				draw_rectangle(0, 125, Width, 125);
				draw_rectangle(0, 375, Width, 250);
				draw_rectangle(0, 750, Width, 125);
				pop_settings();
				b2_blink_check += b2_blink_time;
				is_b2_hit = false;
			}
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			is_b2_draw = false;
			push_settings();
			draw_image(razer_ver, 200, 0, 200, Height);//세로
			draw_image(razer_ver1, 600, 0, 300, Height);
			draw_image(razer_ver, 1100, 0, 200, Height);
			draw_image(razer_hori, 0, 125, Width, 125);//가로
			draw_image(razer_hori, 0, 375, Width, 250);
			draw_image(razer_hori, 0, 750, Width, 125);
			pop_settings();
			if (player->chara_pos_y > 125 && player->chara_pos_y < 250 ||
				player->chara_pos_y > 375 && player->chara_pos_y < 625 ||
				player->chara_pos_y > 750 && player->chara_pos_y < 875 ||
				player->chara_pos_x > 200 && player->chara_pos_x < 400 ||
				player->chara_pos_x > 600 && player->chara_pos_x < 900 ||
				player->chara_pos_x > 1100 && player->chara_pos_x < 1300)
			{
				is_b2_hit = true;
			}
		}

	}

	pop_settings();
}
extern S2boss_update s2boss_update;
