#include "storm_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Storm::draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Storm::FireBullet()
{
	bullet_pos_x = mouseX;
	bullet_pos_y = mouseY;
}

void Storm_update::bullet_create(std::vector<Storm*>& storms, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_sto = true;
	}
	if (MouseIsPressed && not_clicked_sto == true)
	{
		storms.push_back(new Storm{ player->chara_pos_x, player->chara_pos_y, stormSize});
		not_clicked_sto = false;
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