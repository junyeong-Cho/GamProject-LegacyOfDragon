#include <vector>
#include "Player.h"
#include "HaeTae2.h"


using namespace doodle;

void HaeTae2::draw()
{
	set_fill_color(HexColor{ 0x626262 });
	draw_ellipse(x, y, size, size);
}

void HaeTae2_update::HaeTae2_create(std::vector<HaeTae2*>& HaeTae2s) {
	if (H2_timer > H2_timer_check)
	{
		for (; count_HaeTae2_start < H2_tutoMax; count_HaeTae2_start++)
		{
			int r_HaeTae2_y = random(HaeTae2Min, HaeTae2Max);
			int r_HaeTae2_x = random(HaeTae2Min, HaeTae2Max);
			HaeTae2s.push_back(new HaeTae2{ r_HaeTae2_x, r_HaeTae2_y, HaeTae2Size });
		}
	}
}

void HaeTae2_update::HaeTae2_move(std::vector<HaeTae2*>& HaeTae2, Player* player)
{
	for (int i = 0; i < HaeTae2.size(); i++)
	{
		push_settings();
		HaeTae2[i]->draw();
		pop_settings();

		if (HaeTae2[i]->x >= player->chara_pos_x)
		{
			HaeTae2[i]->x -= random(HaeTae2_vel_min, HaeTae2_vel_max);
		}
		if (HaeTae2[i]->x <= player->chara_pos_x)
		{
			HaeTae2[i]->x += random(HaeTae2_vel_min, HaeTae2_vel_max);
		}
		if (HaeTae2[i]->y >= player->chara_pos_y)
		{
			HaeTae2[i]->y -= random(HaeTae2_vel_min, HaeTae2_vel_max);
		}
		if (HaeTae2[i]->y <= player->chara_pos_y)
		{
			HaeTae2[i]->y += random(HaeTae2_vel_min, HaeTae2_vel_max);
		}

	}
}

