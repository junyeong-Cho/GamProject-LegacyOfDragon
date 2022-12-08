#include "storm_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Storm::draw()
{
	set_fill_color(HexColor{ 0xff002a55 });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Storm::FireBullet()
{
	bullet_pos_x = mouseX;
	bullet_pos_y = mouseY;
}

void Storm_update::bullet_create(std::vector<Storm*>& storms, Player* player)
{
	if (st_click_timer < st_click_check)
	{
		st_click_timer += DeltaTime;
	}

	if (!MouseIsPressed) {
		not_clicked_sto = true;
	}
	if (st_click_timer > st_click_check)
	{
		if (MouseIsPressed && not_clicked_sto == true)
		{
			storms.push_back(new Storm{ player->chara_pos_x, player->chara_pos_y, stormSize, stvelocity });
			not_clicked_sto = false;
			st_click_timer = 0;
		}
	}

}

void Storm_update::bullet_draw(std::vector<Storm*>& storms) {

	for (int i = 0; i < storms.size(); i++)
	{
		push_settings();
		storms[i]->draw();
		storms[i]->FireBullet();
		pop_settings();
	}
}

void Storm_update::bullet_remove(std::vector<Storm*>& storms)
{
	for (int i = 0; i < storms.size(); i++)
	{
		st_remove_timer += DeltaTime;
		if (st_remove_timer > st_remove_check)
		{
			delete storms[i];
			storms.erase(storms.begin() + i);
			st_remove_timer = 0;
		}
	}
}

void Storm_update::coolTime(std::vector<Storm*>& bullets, Player* player)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 15);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 20 * st_click_timer, 15);
	pop_settings();
}