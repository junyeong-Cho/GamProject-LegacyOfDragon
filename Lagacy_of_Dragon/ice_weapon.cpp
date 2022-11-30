#include "ice_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void IceWeapon::draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void IceWeapon::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Ivelocity);
	float velocityY = (sin(aimAngle) * Ivelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void ice_update::bullet_create(std::vector<IceWeapon*>& bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_ice = true;
	}
	if (MouseIsPressed && not_clicked_ice == true)
	{
		bullets.push_back(new IceWeapon{ player->chara_pos_x, player->chara_pos_y, iceSize, icedamage });
		not_clicked_ice = false;
	}
}
void ice_update::bullet_draw(std::vector<IceWeapon*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}
void ice_update::bullet_remove(std::vector<IceWeapon*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bullet_pos_x > 1400 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}