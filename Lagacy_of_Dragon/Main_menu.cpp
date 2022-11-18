#include "Main_menu.h"

void Main_menu::main_UI() {
	clear_background(255);
	draw_image(Title, title_x, title_y);

	apply_scale(0.5);
	draw_image(Gameplay_button, mainmenu_x, gameplay_y);
	draw_image(Setting_button, mainmenu_x, setting_y);
	draw_image(Credit_button, mainmenu_x, credit_y);
	draw_image(Exit_button, mainmenu_x, exit_y);
}

bool Main_menu::is_gameplay() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_gameplay_y && get_mouse_y() < click_gameplay_y + click_gap_y) && MouseIsPressed;
}
bool Main_menu::is_setting() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_setting_y && get_mouse_y() < click_setting_y + click_gap_y) && MouseIsPressed;
}
bool Main_menu::is_credit() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_credit_y && get_mouse_y() < click_credit_y + click_gap_y) && MouseIsPressed;
}
bool Main_menu::is_exit() {
	return (get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_exit_y && get_mouse_y() < click_exit_y + click_gap_y) && MouseIsPressed;
}

void Main_menu::in_setting()
{
	clear_background(0x7E5873FF);
	draw_text("Back", maxvolume_x, maxvolume_y);
}

void Main_menu::in_credit()
{
	clear_background(0x7E5873FF);
	draw_text("Back", maxvolume_x, maxvolume_y);
}

bool Main_menu::is_in_setting()
{
	return (get_mouse_x() > 600 && get_mouse_x() < 750 && get_mouse_y() > 320 && get_mouse_y() < 330 + click_gap_y) && MouseIsPressed;
}

bool Main_menu::is_in_credit()
{
	return (get_mouse_x() > 600 && get_mouse_x() < 750 && get_mouse_y() > 320 && get_mouse_y() < 330 + click_gap_y) && MouseIsPressed;
}
