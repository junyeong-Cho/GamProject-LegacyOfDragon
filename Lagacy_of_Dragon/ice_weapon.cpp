#include "ice_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void IceWeapon::draw()
{
	draw_image(iceImage,bullet_pos_x, bullet_pos_y, size, size);
}

void IceWeapon::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Ivelocity);
	float velocityY = (sin(aimAngle) * Ivelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void Ice_update::bullet_create(std::vector<IceWeapon*>& bullets, Player* player)
{
	if (ice_timer < ice_check)
	{
		ice_timer += DeltaTime;
	}

	if (!MouseIsPressed) {
		not_clicked_ice = true;
	}
	if (ice_timer >= ice_check)
	{
		if (MouseIsPressed && not_clicked_ice == true)
		{
			bullets.push_back(new IceWeapon{ player->chara_pos_x, player->chara_pos_y, iceSize, icedamage });
			not_clicked_ice = false;
			ice_timer = 0;
		}
	}
}

void Ice_update::bullet_draw(std::vector<IceWeapon*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}

void Ice_update::bullet_remove(std::vector<IceWeapon*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bullet_pos_x > 3500|| bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Ice_update::coolTime(std::vector<IceWeapon*>& bullets, Player* player)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 10);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 200 * ice_timer, 10);
	pop_settings();
}