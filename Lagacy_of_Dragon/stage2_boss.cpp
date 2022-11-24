#include "stage2_boss.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Stage2_boss::draw()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, size, size);
}

void S2boss_update::s2_boss_update(std::vector<Stage2_boss*>& stage2_boss) {
	
	int r_enemy_y = 0;
	int r_enemy_x = 300;
	stage2_boss.push_back(new Stage2_boss{ r_enemy_x, r_enemy_y, s2bossSize });
}

void S2boss_update::s2_boss_move(std::vector<Stage2_boss*>& stage2_boss, Player* player)
{
	for (int i = 0; i < stage2_boss.size(); i++)
	{
		push_settings();
		stage2_boss[i]->draw();
		pop_settings();

		if (stage2_boss[i]->x >= 0)
		{
			stage2_boss[i]->x += s2_boss_vel;
		}
		if (stage2_boss[i]->x < 900)
		{
			stage2_boss[i]->x -= s2_boss_vel;
		}
	}
}
