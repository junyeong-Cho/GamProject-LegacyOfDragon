//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "Main_menu.h"
#include <iostream>
#include "Window_setting.h"

void Main_menu::main_UI() {
	clear_background(HexColor{0xffcf69ff});
	draw_image(Title, title_x, title_y);

	apply_scale(0.5);
	draw_image(Gameplay_button, mainmenu_x, gameplay_y);
	draw_image(Howtoplay_button, mainmenu_x, setting_y);
	draw_image(Credit_button, mainmenu_x, credit_y);
	draw_image(Exit_button, mainmenu_x, exit_y);
}

bool Main_menu::is_gameplay() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_gameplay_y && get_mouse_y() < click_gameplay_y + click_gap_y);
}
bool Main_menu::is_setting() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_setting_y && get_mouse_y() < click_setting_y + click_gap_y);
}
bool Main_menu::is_credit() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_credit_y && get_mouse_y() < click_credit_y + click_gap_y);
}
bool Main_menu::is_exit() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_exit_y && get_mouse_y() < click_exit_y + click_gap_y);
}
void Main_menu::in_setting()
{
	clear_background(0x7E5873FF);
	draw_text("Back", maxvolume_x, maxvolume_y);
}
void Main_menu::in_credit()
{
	credit_timer += DeltaTime;
	clear_background(HexColor{0x000000ff});
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(Credit1, Width/2, Height/2+700-credit_timer*100);
		draw_image(Credit2, Width/2, Height/2+1600-credit_timer*100);
		std::cout << credit_timer << std::endl;
		if (credit_timer > 23)
		{
			draw_image(Credit3, Width / 2, Height / 2);
		}
		if (credit_timer > 27)
		{
			credit_timer = 0;
			scene = 2;
		}
		pop_settings();
}
bool Main_menu::is_in_setting()
{
	return (get_mouse_x() > maxvolume_x && get_mouse_x() < maxvolume_x + 150 && get_mouse_y() > maxvolume_y && get_mouse_y() < maxvolume_y + click_gap_y + 10) && MouseIsPressed;
}
bool Main_menu::is_in_credit()
{
	return (get_mouse_x() > maxvolume_x && get_mouse_x() < maxvolume_x + 150 && get_mouse_y() > maxvolume_y && get_mouse_y() < maxvolume_y + click_gap_y + 10) && MouseIsPressed;
}
