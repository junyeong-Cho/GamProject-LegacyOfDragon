#include "UIsetting.h"
#include "Player.h"

#include <doodle\doodle.hpp>
#include <iostream>

bool something = false;

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
	if (KeyIsPressed && Key != KeyboardButtons::Q)
	{
		is_random = false;
	}

	if (KeyIsPressed && Key == KeyboardButtons::Q)
	{
		is_random = true;
		randomScene += 1;
		readyRoulette = 1;
	}

	if (is_random == true && readyRoulette == 1)
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
		draw_image(StormW, randomboxloc[1]  , randomboxh, randomboxSize, randomboxSize);
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
		box_x += acc_x;

		//Range
		if (box_x < randomboxloc[0] || box_x > randomboxloc[2])
		{
			box_x = randomboxloc[0];
		}


		//Operator
		if (randomScene == 2 && is_random == true)
		{

			skillTimer += DeltaTime;
			//Speed is on proportion with Time (현재 속도는 30이라 skillTimer = 5, 속도 6곱해줌
			if (skillTimer < SkillTimeCheck)
			{
				
				box_x -= skillTimer * 5.7; // Same as acc_x
			}
			else if (skillTimer > SkillTimeCheck)
			{
				//First box
				if (box_x <= 575)
				{
					box_x = randomboxloc[0];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 0;

				}//Second box
				else if (box_x > 575 || box_x < 675)
				{
					box_x = randomboxloc[1];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 1;

				}//Third box
				else if (box_x >= 675)
				{
					box_x = randomboxloc[2];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 2;
				}
				if (skillTimer > random_initial_check)
				{
					skillTimer = 0;
					randomScene = 0;
					readyRoulette = 0;
					is_random = false;
				}
			}
		}

	}

}

void UIsetting::roulette_ult(vector<int> ultraboxloc) {

	if (KeyIsPressed && Key != KeyboardButtons::E)
	{
		is_random_ul = false;
	}
	if (KeyIsPressed && Key == KeyboardButtons::E)
	{
		randomScene_ul = 1;
		readyRoulette_ul = 1;
		is_random_ul = true;
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
		ultra_box_x += acc_ul_x;

		//Range
		if (ultra_box_x < ultraboxloc[0] || ultra_box_x > ultraboxloc[1])
		{
			ultra_box_x = ultraboxloc[0];
		}

		//Operator
		if (Key == KeyboardButtons::E && readyRoulette_ul == 1)
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
				if (ultra_box_x < 650)
				{
					ultra_box_x = ultraboxloc[0];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(ultra_box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 6;

				}//Second box
				if (ultra_box_x >= 650)
				{
					ultra_box_x = ultraboxloc[1];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(6.0);
					draw_rectangle(ultra_box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					weapon_choice = 7;
				}
				if (skillTimer_ul > randomul_initial_check)
				{
					skillTimer_ul = 0;
					randomScene_ul = 0;
					readyRoulette_ul = 0;
					is_random_ul = false;
				}
			}
		}
	}
}

void UIsetting::roulette_six(vector<int> sixboxloc) {

	if (KeyIsPressed && Key != KeyboardButtons::T)
	{
		is_random_six = false;
	}
	if (KeyIsPressed && Key == KeyboardButtons::T)
	{
		randomScene_six = 1;
		readyRoulette_six = 1;
		is_random_six = true;
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
		acc_six_x = 30;
		six_box_x += acc_six_x;

		//Range
		if (six_box_x < sixboxloc[0] || six_box_x > sixboxloc[5])
		{
			six_box_x = sixboxloc[0];
		}

		//Operator
		if (Key == KeyboardButtons::T && readyRoulette_six == 1)
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
				if (six_box_x < 500)
				{
					six_box_x = sixboxloc[0];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 0;

				}//Second box
				else if (six_box_x >= 500 || six_box_x < 600)
				{
					six_box_x = sixboxloc[1];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 1;

				}//Third box
				else if (six_box_x >= 600 || six_box_x < 700)
				{
					six_box_x = sixboxloc[2];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 2;

				}
				else if (six_box_x >= 700 || six_box_x < 800)
				{
					six_box_x = sixboxloc[3];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 3;

				}
				else if (six_box_x >= 800 || six_box_x < 900)
				{
					six_box_x = sixboxloc[4];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 4;

				}
				else if (six_box_x >= 900)
				{
					six_box_x = sixboxloc[5];
					push_settings();
					no_fill();
					set_outline_color(box_color);
					set_outline_width(8.0);
					draw_rectangle(six_box_x, randomboxh, sixboxSize, sixboxSize);
					pop_settings();
					weapon_choice = 5;

				}


				if (skillTimer_six > randomsix_initial_check)
				{
					skillTimer_six = 0;
					randomScene_six = 0;
					readyRoulette_six = 0;
					is_random_six = false;
				}
			}
		}
	}
}


void UIsetting::weaponChoice(vector<Shooting*>& bullets, vector<IceWeapon*>& ice, vector<BombWeapon*>& bombs, vector<Storm*>& storm, vector<Approach*>& approach, vector<BackWeapon*>& knockback, vector<BreathWeapon*>& breath, vector<Meteor*>& meteor, Player* player)
{
	//Bullets
	if (weapon_choice == 1)
	{
		shooting_update.bullet_create(bullets, player);
		shooting_update.bullet_draw(bullets);
		shooting_update.bullet_remove(bullets);
		shooting_update.coolTime(player);

	}

	//Ice
	if (weapon_choice == 0)
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
