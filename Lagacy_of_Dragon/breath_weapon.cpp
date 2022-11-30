#include "breath_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void BreathWeapon::draw()
{
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(HexColor{ 0x0000ffff });
	draw_rectangle(bullet_pos_x, bullet_pos_y, size, size1);
	pop_settings();
}

void BreathWeapon::FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Brvelocity);
	float velocityY = (sin(aimAngle) * Brvelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void Breath_update::bullet_create(std::vector<BreathWeapon*>& bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_breath = true;
		breath_timer = 0;
	}
	if (MouseIsPressed && not_clicked_breath == true)
	{
		breath_timer += DeltaTime;
		if (breath_timer > breath_time_check)
		{
			bullets.push_back(new BreathWeapon{ player->chara_pos_x, player->chara_pos_y, breathSize, breathSize1, breathdamage });
			not_clicked_breath = false;
		}
	}
}

void Breath_update::bullet_draw(std::vector<BreathWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}

void Breath_update::bullet_remove(std::vector<BreathWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->bullet_pos_x > 1400 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}