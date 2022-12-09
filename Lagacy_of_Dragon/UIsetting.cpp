#include "UIsetting.h"
#include "Player.h"

#include <doodle\doodle.hpp>
#include <iostream>

bool something = false;
bool not_click = false;

using namespace std;
using namespace doodle;

void UIsetting::ui_point() {
	{
		push_settings();
		draw_text(to_string(chap1_point) + " / 20", score_width, score_height);
		pop_settings();
	}
}

void UIsetting::roulette(vector<int> randomboxloc)
{
	readyRoulette = false;

	if (KeyIsPressed && Key != KeyboardButtons::Q)
	{
		is_random = true;
	}

	if (KeyIsPressed && Key == KeyboardButtons::Q)
	{
		is_random = true;
		randomScene = 1;
		readyRoulette = 1;
		rouletteflag = 1;
	}

	if (randomScene == 1 && is_random == true)
	{
		push_settings();
		set_outline_width(8.0);
		set_outline_color(box_color1);
		set_fill_color(255);
		draw_line(draw_roulette_line_x1, randomboxh, draw_roulette_line_x1, randomboxh + randomboxSize);
		draw_line(draw_roulette_line_x2, randomboxh, draw_roulette_line_x2, randomboxh + randomboxSize);
		draw_rectangle(randomboxloc[0], randomboxh, randomboxSize * 3, randomboxSize);
		pop_settings();
		;
		//Weapon Draw
		draw_image(IceW, randomboxloc[0], randomboxh, randomboxSize, randomboxSize);
		draw_image(StormW, randomboxloc[1], randomboxh, randomboxSize, randomboxSize);
		draw_image(BackW, randomboxloc[2], randomboxh, randomboxSize, randomboxSize);


		//Roulette
		push_settings();
		no_fill();
		set_outline_color(box_color);
		set_outline_width(6.0);
		draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
		pop_settings();

		//Speed
		acc_x = 30;
		if (choice_box_once == 0)
		{
			box_x += acc_x;
		}


		//Range
		if (box_x < randomboxloc[0] || box_x > randomboxloc[2])
		{
			box_x = randomboxloc[0];
		}


		if (roulette_count_once != readyRoulette) {
			readyRoulette2++;
			roulette_count_once = readyRoulette;
			box_count_once = 0;
		}

		//Operator
		if (readyRoulette2 > 2 && rouletteflag)
		{
			skillTimer += DeltaTime;
			//Speed is on proportion with Time (현재 속도는 30이라 skillTimer = 5, 속도 6곱해줌
			if (skillTimer < SkillTimeCheck)
			{
				box_x -= skillTimer * 5.7; // Same as acc_x
			}
			else if (skillTimer > SkillTimeCheck)
			{

				if (box_x <= 600 || box_x == randomboxloc[0] && box_x != randomboxloc[1] && box_x != randomboxloc[2])
				{
					box_x = randomboxloc[0];//500
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 0;
					choice_box_once = 1;
				}//Second box
				else if (box_x > 600 && box_x < 700 || box_x == randomboxloc[1] && box_x != randomboxloc[0] && box_x != randomboxloc[2])
				{
					box_x = randomboxloc[1];//650
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 1;
					choice_box_once = 1;


				}//Third box
				else if (box_x >= 700 || box_x == randomboxloc[2] && box_x != randomboxloc[0] && box_x != randomboxloc[1])
				{
					box_x = randomboxloc[2];//800
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 2;
					choice_box_once = 1;

				}

				if (skillTimer > random_initial_check)
				{
					skillTimer = 0;
					randomScene = 0;
					readyRoulette = 0;
					rouletteflag = 0;
					is_random = false;
					readyRoulette2 = 0;
					roulette_count_once = 0;
					choice_box_once = 0;
				}

			}
		}
	}
}

void UIsetting::roulette_ult(vector<int> ultraboxloc) {

	readyRoulette_ul = false;

	if (KeyIsPressed && Key != KeyboardButtons::E)
	{
		is_random_ul = true;
	}
	if (KeyIsPressed && Key == KeyboardButtons::E)
	{
		randomScene_ul = 1;
		readyRoulette_ul = 1;
		is_random_ul = true;
		rouletteflag_ul = 1;
	}
	if (randomScene_ul == 1 && is_random_ul == true)
	{
		push_settings();
		set_outline_width(8.0);
		set_outline_color(box_color1);
		set_fill_color(255);
		draw_line(draw_roulette_line_x1, randomboxh, draw_roulette_line_x1, randomboxh + randomboxSize);
		draw_line(draw_roulette_line_x2, randomboxh, draw_roulette_line_x2, randomboxh + randomboxSize);
		draw_rectangle(ultraboxloc[0], randomboxh, randomboxSize * 2, randomboxSize);
		pop_settings();

		draw_image(IceW, ultraboxloc[0], randomboxh, randomboxSize, randomboxSize);
		draw_image(StormW, ultraboxloc[1], randomboxh, randomboxSize, randomboxSize);

		//Roulette
		push_settings();
		no_fill();
		set_outline_color(box_color);
		set_outline_width(6.0);
		draw_rectangle(ultra_box_x, randomboxh, randomboxSize, randomboxSize);
		pop_settings();

		//Speed
		acc_ul_x = 15;

		if (choice_box_once_ul == 0)
		{
			ultra_box_x += acc_ul_x;
		}

		//Range
		if (ultra_box_x < ultraboxloc[0] || ultra_box_x > ultraboxloc[1])
		{
			ultra_box_x = ultraboxloc[0];
		}

		if (roulette_count_once_ul != readyRoulette_ul) {
			readyRoulette2_ul++;
			roulette_count_once_ul = readyRoulette_ul;
			box_count_once_ul = 0;
		}

		//Operator
		if (readyRoulette2_ul > 2 && rouletteflag_ul)
		{

			skillTimer_ul += DeltaTime;
			//Speed is on proportion with Time (현재 속도는 15이라 skillTimer = 5, 속도 5곱해줌
			if (skillTimer_ul < SkillTimeCheck_ul)
			{
				ultra_box_x -= skillTimer_ul * 4.7; // Same as acc_x
			}
			if (skillTimer_ul > SkillTimeCheck_ul)
			{

				//First box
				if (ultra_box_x < 675 && ultra_box_x != 750)
				{
					ultra_box_x = ultraboxloc[0];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(ultra_box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 6;
					choice_box_once_ul = 1;

				}//Second box
				if (ultra_box_x >= 675 && ultra_box_x != 600)
				{
					ultra_box_x = ultraboxloc[1];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(ultra_box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 7;
					choice_box_once_ul = 1;
				}
				if (skillTimer_ul > randomul_initial_check)
				{
					skillTimer_ul = 0;
					randomScene_ul = 0;
					readyRoulette_ul = 0;
					readyRoulette2_ul = 0;
					roulette_count_once_ul = 0;
					is_random_ul = false;
					choice_box_once_ul = 0;
				}
			}
		}
	}
}

void UIsetting::roulette_six(vector<int> sixboxloc) {

	readyRoulette_six = false;

	if (KeyIsPressed && Key != KeyboardButtons::T)
	{
		is_random_six = true;
	}
	if (KeyIsPressed && Key == KeyboardButtons::T)
	{
		randomScene_six = 1;
		readyRoulette_six = 1;
		is_random_six = true;
		rouletteflag_six = 1;
	}
	if (randomScene_six == 1 && is_random_six == true)
	{
		push_settings();
		set_outline_width(8.0);
		set_outline_color(box_color1);
		set_fill_color(255);
		draw_rectangle(sixboxloc[0], randomboxh, sixboxSize * 6, sixboxSize);
		pop_settings();

		//Weapon Draw
		draw_image(IceW, sixboxloc[0], randomboxh, sixboxSize, sixboxSize);
		draw_image(StormW, sixboxloc[1], randomboxh, sixboxSize, sixboxSize);
		draw_image(BombW, sixboxloc[2], randomboxh, sixboxSize, sixboxSize);
		draw_image(BackW, sixboxloc[3], randomboxh, sixboxSize, sixboxSize);
		draw_image(Wind, sixboxloc[4], randomboxh, sixboxSize, sixboxSize);
		draw_image(Fire, sixboxloc[5], randomboxh, sixboxSize, sixboxSize);


		//Roulette
		push_settings();
		no_fill();
		set_outline_color(box_color);
		set_outline_width(8.0);
		draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
		pop_settings();

		//Speed
		acc_six_x = 40;
		if (choice_box_once_six == 0)
		{
			six_box_x += acc_six_x;
		}

		//Range
		if (six_box_x < sixboxloc[0] || six_box_x > sixboxloc[5])
		{
			six_box_x = sixboxloc[0];
		}
		if (roulette_count_once_six != readyRoulette_six) {
			readyRoulette2_six++;
			roulette_count_once_six = readyRoulette_six;
			box_count_once_six = 0;
		}
		//Operator
		if (readyRoulette2_six > 2 && rouletteflag_six)
		{

			skillTimer_six += DeltaTime;
			//Speed is on proportion with Time (현재 속도는 30이라 skillTimer = 5, 속도 5곱해줌
			if (skillTimer_six < SkillTimeCheck_six)
			{
				six_box_x -= skillTimer_six * 5.8; // Same as acc_x
			}
			else if (skillTimer_six > SkillTimeCheck_six)
			{
				//First box
				if (six_box_x < 450 + specific_six_gap)
				{
					six_box_x = sixboxloc[0];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 0;
					choice_box_once_six = 1;

				}//Second box
				else if (six_box_x >= 450 + specific_six_gap && six_box_x < 450 + specific_six_gap * 2)
				{
					six_box_x = sixboxloc[1];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 1;
					choice_box_once_six = 1;


				}//Third box
				else if (six_box_x >= 450 + specific_six_gap * 2 && six_box_x < 450 + specific_six_gap * 3)
				{
					six_box_x = sixboxloc[2];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 2;
					choice_box_once_six = 1;

				}
				else if (six_box_x >= 450 + specific_six_gap * 3 && six_box_x < 450 + specific_six_gap * 4)
				{
					six_box_x = sixboxloc[3];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 3;
					choice_box_once_six = 1;

				}
				else if (six_box_x >= 450 + specific_six_gap * 4 || six_box_x < 450 + specific_six_gap * 5)
				{
					six_box_x = sixboxloc[4];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 4;
					choice_box_once_six = 1;

				}
				else if (six_box_x >= 450 + specific_six_gap * 5)
				{
					six_box_x = sixboxloc[5];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 5;
					choice_box_once_six = 1;

				}


				if (skillTimer_six > randomsix_initial_check)
				{
					skillTimer_six = 0;
					randomScene_six = 0;
					readyRoulette_six = 0;
					readyRoulette2_six = 0;
					roulette_count_once_six = 0;
					is_random_six = false;
					choice_box_once_six = 0;
				}
			}
		}
	}
}

void UIsetting::weaponChoice(vector<Shooting*>& bullets, vector<IceWeapon*>& ice, vector<BombWeapon*>& bombs, vector<Storm*>& storm, vector<Approach*>& approach, vector<BackWeapon*>& knockback, vector<BreathWeapon*>& breath, vector<Meteor*>& meteor, Player* player)
{
	//Bullets
	if (weapon_choice == 0)
	{
		shooting_update.bullet_create(bullets, player);
		shooting_update.bullet_draw(bullets);
		shooting_update.bullet_remove(bullets);
		shooting_update.coolTime(player);

	}

	//Ice
	if (weapon_choice == 1)
	{
		ice_update.bullet_create(ice, player);
		ice_update.bullet_draw(ice);
		ice_update.bullet_remove(ice);
		ice_update.coolTime(ice, player);
	}

	//bomb
	if (weapon_choice == 2)
	{
		bomb_update.bullet_draw(bombs);
		bomb_update.bullet_create(bombs, player);
		bomb_update.coolTime(bombs, player);
	}

	//storm
	if (weapon_choice == 3)
	{
		storm_update.bullet_create(storm, player);
		storm_update.bullet_draw(storm);
		storm_update.bullet_remove(storm);
		storm_update.coolTime(storm, player);
	}

	//app
	if (weapon_choice == 4)
	{
		approach_update.bullet_create(approach, player);
		approach_update.bullet_draw(approach);
		approach_update.bullet_remove(approach);
		approach_update.coolTime(approach, player);
	}

	//back
	if (weapon_choice == 5)
	{
		back_update.bullet_create(knockback, player);
		back_update.bullet_draw(knockback);
		back_update.bullet_remove(knockback);
		back_update.coolTime(knockback, player);
	}

	//breath
	if (weapon_choice == 6)
	{
		breath_update.bullet_create(breath, player);
		breath_update.bullet_draw(breath, player);
		breath_update.coolTime(breath, player);
	}

	//meteor
	if (weapon_choice == 7)
	{
		meteor_update.bullet_create(meteor, player);
		meteor_update.bullet_draw(meteor);
		meteor_update.bullet_remove(meteor);
		meteor_update.coolTime(meteor, player);

	}
}

void UIsetting::howtoplay(int* scene) {
	clear_background(255);
	push_settings();
	set_image_mode(RectMode::Center);

	if (!MouseIsPressed) {
		not_click = true;
	}
	switch (howtoplay_scene)
	{
	case 0:
		slide_timer += DeltaTime;
		if (slide_timer >= slide_check1)
		{
			draw_image(howtoplay1_1, Width / 2, Height / 2, Width, Height);
			if (slide_timer >= slide_check2)
				slide_timer = 0;
		}
		else
		{
			draw_image(howtoplay1_2, Width / 2, Height / 2, Width, Height);
		}

		if ((get_mouse_x() > 990 && get_mouse_x() < 1420 && get_mouse_y() > 720 && get_mouse_y() < 810) && (MouseIsPressed && not_click))
		{
			howtoplay_scene++;
			not_click = false;
		}

		break;
	case 1:
		draw_image(howtoplay2_1, Width / 2, Height / 2, Width, Height);
		if ((get_mouse_x() > 990 && get_mouse_x() < 1420 && get_mouse_y() > 720 && get_mouse_y() < 810) && (MouseIsPressed && not_click))
		{
			howtoplay_scene++;
			not_click = false;
		}

		break;
	case 2:
		draw_image(howtoplay3, Width / 2, Height / 2, Width, Height);
		if ((get_mouse_x() > 990 && get_mouse_x() < 1420 && get_mouse_y() > 720 && get_mouse_y() < 810) && (MouseIsPressed && not_click))
		{
			howtoplay_scene++;
			not_click = false;
		}

		break;
	case 3:
		draw_image(howtoplay4, Width / 2, Height / 2, Width, Height);
		if ((get_mouse_x() > 990 && get_mouse_x() < 1420 && get_mouse_y() > 720 && get_mouse_y() < 810) && (MouseIsPressed && not_click))
		{
			howtoplay_scene++;
			not_click = false;
		}

		break;
	case 4:
		draw_image(howtoplay5, Width / 2, Height / 2, Width, Height);
		if ((get_mouse_x() > 990 && get_mouse_x() < 1420 && get_mouse_y() > 720 && get_mouse_y() < 810) && (MouseIsPressed && not_click))
		{
			*scene = 2;
			howtoplay_scene = 0;
			not_click = false;
		}
		if ((get_mouse_x() > 990 && get_mouse_x() < 1420 && get_mouse_y() > 620 && get_mouse_y() < 710) && (MouseIsPressed && not_click))
		{
			*scene = 6;
			howtoplay_scene = 0;
			not_click = false;
		}

		break;
	default:
		break;


	}

	pop_settings();
}

void UIsetting::gameover(int* scene)
{
	clear_background(255);
	push_settings();
	set_image_mode(RectMode::Center);
	draw_image(Game_over, Width / 2, Height / 2, Width, Height);
	apply_scale(0.5);
	draw_image(Home, 1500, 1150);
	draw_image(Retry, 1500, 1350);
	pop_settings();

	if (!MouseIsPressed) {
		not_click = true;
	}

	if ((get_mouse_x() > 600 && get_mouse_x() < 900 && get_mouse_y() > 540 && get_mouse_y() < 610) && (MouseIsPressed && not_click)) {
		*scene = 2;
	} else if ((get_mouse_x() > 600 && get_mouse_x() < 900 && get_mouse_y() > 640 && get_mouse_y() < 710) && (MouseIsPressed && not_click)) {
		*scene = 6;
	}

}