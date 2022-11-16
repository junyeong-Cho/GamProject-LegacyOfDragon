#include "Enemy.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Enemy::draw()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, size, size);
}

void TutoEnemy::draw()
{
	set_fill_color(HexColor{ 0xffff2aff });
	draw_ellipse(x, y, size, size);
}