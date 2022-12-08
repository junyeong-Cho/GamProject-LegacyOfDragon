#include "stage1_boss.h"
#include <doodle\doodle.hpp>

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

void Stage1_boss::hp(int* scene)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(b1_hp_x, b1_hp_y, b1_hp_w, b1_hp_h);
	pop_settings();

	push_settings();
	set_fill_color(hp_color_1);
	draw_rectangle(b1_hp_x, b1_hp_y, 100 * health, b1_hp_h);
	pop_settings();
	if (health <= 0)
	{
		scene = 0;
	}
}
//void Stage1_update::boss_create(std::vector<Stage1_boss*>& boss1)
//{
//	boss1.push_back(new Stage1_boss{ boss1_x, boss1_y, s1bossSize, s1_boss_vel, boss1_hp });
//}
//
//void Stage1_update::boss_move(std::vector<Stage1_boss*>& boss1)
//{
//	for (int i = 0; i < boss1.size(); i++)
//	{
//		boss1[i]->x += boss1[i]->velocity;
//
//		if (boss1[i]->x <= 100)
//		{
//			boss1[i]->velocity *= -1;
//		}
//		if (boss1[i]->x >= 1400)
//		{
//			boss1[i]->velocity *= -1;
//		}
//	}
//}
//
//void Stage1_update::boss_draw(std::vector<Stage1_boss*>& boss1)
//{
//	push_settings();
//	for (int i = 0; i < boss1.size(); i++)
//	{
//		boss1[i]->draw();
//	}
//	pop_settings();
//}

