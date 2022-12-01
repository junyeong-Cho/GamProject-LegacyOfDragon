#include "breath_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void BreathWeapon::drawR()
{
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(HexColor{ 0x0000ffff });
	draw_rectangle(bullet_pos_x, bullet_pos_y, -size, size1);
	pop_settings();
}
void BreathWeapon::drawL()
{
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(HexColor{ 0x0000ffff });
	draw_rectangle(bullet_pos_x - breathSize, bullet_pos_y, size, size1);
	pop_settings();
}

void Breath_update::bullet_create(std::vector<BreathWeapon*>& bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_breath = true;
	}
	if (MouseIsPressed && not_clicked_breath == true)
	{
		bullets.push_back(new BreathWeapon{ player->chara_pos_x + 250, player->chara_pos_y, breathSize, breathSize1, breathdamage });
	}
}

void Breath_update::bullet_draw(std::vector<BreathWeapon*>& bullets, Player* player)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		if (get_mouse_x() > player->chara_pos_x)
		{
			bullets[i]->drawR();
		}
		else if (get_mouse_y() < player->chara_pos_x)
		{
			bullets[i]->drawL();
		}
		pop_settings();
	}
}

void Breath_update::bullet_remove(std::vector<BreathWeapon*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (not_clicked_breath = true)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}