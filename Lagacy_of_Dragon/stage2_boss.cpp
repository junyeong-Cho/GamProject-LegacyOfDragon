#include "stage2_boss.h"

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
		int r_boss_x = random(100, 1400);
		int r_boss_y = random(100, 900);

		x = r_boss_x;
		y = r_boss_y;

		b2_move_timer = 0;
	}
}
void Stage2_boss::hp(int* scene)
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
		scene = 0;
	}
}


void S2boss_update::s2_boss_attack(Stage2_boss* boss2, Player* player)
{
	
	b2_change_timer += DeltaTime;

	if (b2_change_timer > b2_change_check)
	{
		if (boss2->health < 200 && boss2->health > 100)

		b2_change_random = random(0, 6);
		b2_blink_timer = 0;
		b2_blink_check = b2_blink_time;
		b2_change_check += 5;

		if (boss2->health <= 100)
		{
			b2_change_random = random(0, 10);
			b2_blink_timer = 0;
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
			push_settings();		
			set_fill_color(blink_color);
			draw_rectangle(0, 200, Width, 550);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(0, 200, Width, 550);
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
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(350, 0, 850, Height);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(350, 0, 850, Height);
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
		// 중앙
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(300, 150, 900, 600);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(300, 150, 900, 600);
			pop_settings();
			if (player->chara_pos_x > 300 && player->chara_pos_x < 1200 && player->chara_pos_y > 150 && player->chara_pos_y < 750)
			{
				is_b2_hit = true;
			}
		}
	}
	
	if (r_attack == 3)
	{
		// 세로 3줄
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(200, 0, 200, Height);
			draw_rectangle(600, 0, 300, Height);
			draw_rectangle(1100, 0, 300, Height);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(200, 0, 200, Height);
			draw_rectangle(600, 0, 300, Height);
			draw_rectangle(1100, 0, 200, Height);
			pop_settings();

			if (player->chara_pos_x > 200 && player->chara_pos_x < 400 ||
				player->chara_pos_x > 600 && player->chara_pos_x < 900 ||
				player->chara_pos_x > 1100 && player->chara_pos_x < 1300)
			{
				is_b2_hit = true;
			}
		}

	}

	if (r_attack == 4)
	{
		// 가로 3줄
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(0, 125, Width, 125);
			draw_rectangle(0, 375, Width, 250);
			draw_rectangle(0, 750, Width, 125);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;

		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(0, 125, Width, 125);
			draw_rectangle(0, 375, Width, 250);
			draw_rectangle(0, 750, Width, 125);
			pop_settings();


			if (player->chara_pos_y > 125 && player->chara_pos_y < 250 ||
				player->chara_pos_y > 375 && player->chara_pos_y < 625 ||
				player->chara_pos_y > 750 && player->chara_pos_y < 875)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 5)
	{
		// 기본
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
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

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(200, 0, 200, Height);
			draw_rectangle(600, 0, 300, Height);
			draw_rectangle(1100, 0, 200, Height);
			draw_rectangle(0, 125, Width, 125);
			draw_rectangle(0, 375, Width, 250);
			draw_rectangle(0, 750, Width, 125);
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

	if (r_attack == 6)
	{
		// 왼쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(0, 0, Width / 2, Height);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(0, 0, Width / 2, Height);
			pop_settings();
			if (player->chara_pos_x > 0 && player->chara_pos_x < Width / 2)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 7)
	{
		// 오른쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(Width / 2, 0, Width / 2, Height);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(Width / 2, 0, Width / 2, Height);
			pop_settings();
			if (player->chara_pos_x > Width / 2 && player->chara_pos_x < Width)
			{
				is_b2_hit = true;
			}
		}
	}

	if (r_attack == 8)
	{
		// 위쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(0, 0, Width, Height / 2);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(0, 0, Width, Height / 2);
			pop_settings();
			if (player->chara_pos_y > 0 && player->chara_pos_x < Height / 2)
			{
				is_b2_hit = true;
			}
		}
	}
	
	if (r_attack == 9)
	{
		// 아래쪽 반
		b2_blink_timer += DeltaTime;
		if (b2_blink_timer > b2_blink_check)
		{
			push_settings();
			set_fill_color(blink_color);
			draw_rectangle(Height/2, 0, Width, Height / 2);
			pop_settings();
			b2_blink_check += b2_blink_time;
			is_b2_hit = false;
		}

		if (b2_blink_timer > b2_attack_checked)
		{
			push_settings();
			set_fill_color(attack_color);
			draw_rectangle(Height / 2, 0, Width, Height / 2);
			pop_settings();
			if (player->chara_pos_y > Height / 2 && player->chara_pos_x < Height)
			{
				is_b2_hit = true;
			}
		}
	}


}

extern S2boss_update s2boss_update;
