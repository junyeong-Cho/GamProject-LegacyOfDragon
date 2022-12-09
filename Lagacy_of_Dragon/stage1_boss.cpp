#include "stage1_boss.h"
#include <doodle\doodle.hpp>
#include "Window_setting.h"

using namespace doodle;

void Stage1_boss::draw()
{
	if (boss1_move_check == false)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(Boss1r, x, y, size, size);
		pop_settings();
	}
	if (boss1_move_check == true)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(Boss1r, x, y, -size, size);
		pop_settings();
	}
}

void Stage1_boss::move()
{
	x += velocity;

	if (x <= 100)
	{
		velocity *= -1;
		boss1_move_check = true;
	}
	if (x >= 1400)
	{
		velocity *= -1;
		boss1_move_check = false;
	}
}

void Stage1_boss::hp()
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(b1_hp_x, b1_hp_y, b1_hp_w, b1_hp_h);
	pop_settings();

	push_settings();
	set_fill_color(hp_color_1);
	draw_rectangle(b1_hp_x, b1_hp_y, 10 * health, b1_hp_h);
	pop_settings();
	if (health <= 0)
	{
		scene = 15;
	}
}
