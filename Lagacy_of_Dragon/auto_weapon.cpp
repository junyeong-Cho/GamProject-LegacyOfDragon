#include "auto_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void AutoWeapon::draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void AutoWeapon::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Ivelocity);
	float velocityY = (sin(aimAngle) * Ivelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void auto_update::bullet_create(std::vector<AutoWeapon*>& bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_ice = true;
	}
	if (MouseIsPressed && not_clicked_ice == true)
	{
		bullets.push_back(new AutoWeapon{ player->chara_pos_x, player->chara_pos_y, backSize, backdamage });
		not_clicked_ice = false;
	}
}

void auto_update::bullet_draw(std::vector<AutoWeapon*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}
