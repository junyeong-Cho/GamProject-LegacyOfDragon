#include "Shooting.h"
#include <doodle\doodle.hpp>
using namespace doodle;

//bool not_clicked = false;

double Shooting::radius() {
	double radius = static_cast<int>(size / 2);
	return radius;
}

void Shooting::draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Shooting::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Bvelocity);
	float velocityY = (sin(aimAngle) * Bvelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

//void Shooting_update::bullet_create(Shooting* bullets, Player* player)
//{
//	if (!MouseIsPressed) {
//		not_clicked = true;
//	}
//	if (MouseIsPressed && not_clicked == true)
//	{
//		//bullet_create
//		bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
//		not_clicked = false;
//	}
//}
