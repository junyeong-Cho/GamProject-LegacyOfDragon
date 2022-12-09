#include "approach_weapon.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Approach::draw()
{
	push_settings();
	set_image_mode(RectMode::Center);
	set_fill_color(HexColor{ 0xff002aff });
	draw_image(appImage, x, y, size, size);
	pop_settings();
}

void Approach_update::bullet_create(std::vector<Approach*>& bullets, Player* player)
{

	if (ap_click_timer < ap_click_check)
	{
		ap_click_timer += DeltaTime;
	}

	if (!MouseIsPressed) {
		not_clicked_app = true;
	}

	if (ap_click_timer >= ap_click_check)
	{
		if (MouseIsPressed && not_clicked_app == true)
		{
			bullets.push_back(new Approach{ player->chara_pos_x, player->chara_pos_y, approachSize });
			not_clicked_app = false;
			ap_click_timer = 0;
		}
	}
	
}

void Approach_update::bullet_draw(std::vector<Approach*>& bullets) {
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		pop_settings();
	}
}

void Approach_update::bullet_remove(std::vector<Approach*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (not_clicked_app == true)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Approach_update::coolTime(std::vector<Approach*>& bullets, Player* player)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 40, 100, 10);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 40, 33.3 * ap_click_timer, 10);
	pop_settings();
}