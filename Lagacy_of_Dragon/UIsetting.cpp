#include "UIsetting.h"
#include <doodle\doodle.hpp>
#include <iostream>
using namespace std;
using namespace doodle;

void UIsetting::ui_point() {
	{
		push_settings();
		draw_text(to_string(chap1_point) + " / 20", score_width, score_height);
		pop_settings();
	}
}

void UIsetting::roulette(vector<int> randomboxloc) {

	push_settings();
	apply_scale(0.8);
	draw_text("Choose your weapon!", 100, 150);
	draw_text("Put your mouse into the roulette", 100, 250);
	draw_text("R : Initialization", 100, 350);
	draw_text("Blue Button : Next stage", 100, 450);
	pop_settings();

	//Weapon Draw
	draw_image(Fire, randomboxloc[0], randomboxh, randomboxSize, randomboxSize);
	draw_image(Water, randomboxloc[1], randomboxh, randomboxSize, randomboxSize);
	draw_image(Star, randomboxloc[2], randomboxh, randomboxSize, randomboxSize);

	for (int i = 0; i < 1; i++)
	{
		//Roulette
		push_settings();
		no_fill();
		set_outline_color(HexColor{ 0xff0000ff });
		set_outline_width(8.0);
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
		if (get_mouse_x() > randomboxloc[0] && get_mouse_x() < randomboxloc[2] + randomboxSize && get_mouse_y() > randomboxh && get_mouse_y() < randomboxh + randomboxSize)
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
				if (box_x <= 675)
				{
					box_x = randomboxloc[0];
					push_settings();
					no_fill();
					set_outline_color(HexColor{ 0xff0000ff });
					set_outline_width(8.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();

					draw_text("You select Fire weapon!", randomboxloc[0], 500);


				}//Second box
				else if (box_x > 625 || box_x < 820)
				{
					box_x = randomboxloc[1];
					push_settings();
					no_fill();
					set_outline_color(HexColor{ 0xff0000ff });
					set_outline_width(8.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					draw_text("You select Water weapon!", randomboxloc[0], 500);

				}//Third box
				else if (box_x >= 820)
				{
					box_x = randomboxloc[2];
					push_settings();
					no_fill();
					set_outline_color(HexColor{ 0xff0000ff });
					set_outline_width(8.0);
					draw_rectangle(box_x, randomboxh, randomboxSize, randomboxSize);
					pop_settings();
					draw_text("You select Dark weapon!", randomboxloc[0], 500);

				}
			}
		}
	}
	//Initialization = R
	if (KeyIsPressed && Key == KeyboardButtons::R)
	{
		skillTimer = 0;
		randomScene = 0;
	}

	//Draw Random box guard
	draw_line(700, randomboxh, 700, 700);
	draw_line(900, randomboxh, 900, 700);

	draw_rectangle(randomboxloc[0], randomboxh, randomboxSize * 3, randomboxSize);

}