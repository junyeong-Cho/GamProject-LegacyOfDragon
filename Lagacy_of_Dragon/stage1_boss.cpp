#include "stage1_boss.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Stage1_boss::draw()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, size, size);
}

void S1boss_update::s1_boss_update(std::vector<Stage1_boss*>& stage1_boss) {

	int r_boss_x = 600;
	int r_boss_y = 600;

	stage1_boss.push_back(new Stage1_boss{ r_boss_x, r_boss_y, s1bossSize });

}

void S1boss_update::s1_boss_move(std::vector<Stage1_boss*>& stage1_boss, Player* player)
{
	for (int i = 0; i < stage1_boss.size(); i++)
	{
		push_settings();
		stage1_boss[i]->draw();
		pop_settings();

		if (stage1_boss[i]->x >= player->chara_pos_x)
		{
			stage1_boss[i]->x -= random(s1_vel_min, s1_vel_max);
		}
		if (stage1_boss[i]->x <= player->chara_pos_x)
		{
			stage1_boss[i]->x += random(s1_vel_min, s1_vel_max);
		}
		if (stage1_boss[i]->y >= player->chara_pos_y)
		{
			stage1_boss[i]->y -= random(s1_vel_min, s1_vel_max);
		}
		if (stage1_boss[i]->y <= player->chara_pos_y)
		{
			stage1_boss[i]->y += random(s1_vel_min, s1_vel_max);
		}

	}
}
