#include "stage1_boss.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Stage1_boss::draw()
{
	set_fill_color(HexColor{ 0x0000FFFF });
	draw_ellipse(x, y, size, size);
}

void Stage1_boss::move()
{
	if (x >= 0)
	{
		x += s1_boss_vel;
	}
	if (x < 1300)
	{
		x -= s1_boss_vel;
	}
}

void Stage1_update::boss1_create(std::vector<Stage1_boss*>& boss1)
{
	boss1.push_back(new Stage1_boss{ boss1_x, boss1_y, s1bossSize, boss1_hp});
}