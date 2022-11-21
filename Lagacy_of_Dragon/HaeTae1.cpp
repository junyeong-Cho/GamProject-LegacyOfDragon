#include <vector>
#include "Player.h"
#include "HaeTae1.h"


using namespace doodle;

void HaeTae1::draw()
{
	set_fill_color(HexColor{ 0x626262 });
	draw_ellipse(x, y, size, size);
}

void HaeTae1_update::HaeTae1_create(std::vector<HaeTae1*>& HaeTae1s) {
	if (H1_timer > H1_timer_check)
	{
		for (; count_HaeTae1_start < H1_tutoMax; count_HaeTae1_start++)
		{
			int r_HaeTae1_y = random(HaeTae1Min, HaeTae1Max);
			int r_HaeTae1_x = random(HaeTae1Min, HaeTae1Max);
			HaeTae1s.push_back(new HaeTae1{ r_HaeTae1_x, r_HaeTae1_y, HaeTae1Size });
		}
	}
}

void HaeTae1_update::HaeTae1_move(std::vector<HaeTae1*>& HaeTae1, Player* player)
{
	for (int i = 0; i < HaeTae1.size(); i++)
	{
		double H1_vel = 2.5;

		push_settings();
		HaeTae1[i]->draw();
		pop_settings();

		if (HaeTae1[i]->x >= player->chara_pos_x)
		{
			HaeTae1[i]->x -= H1_vel;
		}
		if (HaeTae1[i]->x <= player->chara_pos_x)
		{
			HaeTae1[i]->x += H1_vel;
		}
		if (HaeTae1[i]->y >= player->chara_pos_y)
		{
			HaeTae1[i]->y -= H1_vel;
		}
		if (HaeTae1[i]->y <= player->chara_pos_y)
		{
			HaeTae1[i]->y += H1_vel;
		}

	}
}
