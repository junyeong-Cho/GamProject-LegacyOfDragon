#include "Player.h"
#include "approach_weapon.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Approach::draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(x, y, size, size);
}

void Approach_update::bullet_create(std::vector<Approach*>& approachs, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_app = true;
	}
	if (MouseIsPressed && not_clicked_app == true)
	{
		approachs.push_back(new Approach{ player->chara_pos_x, player->chara_pos_y, approachSize });
		not_clicked_app = false;
	}
}

void Approach_update::bullet_draw(std::vector<Approach*>& approachs) {
	for (int i = 0; i < approachs.size(); i++)
	{
		push_settings();
		approachs[i]->draw();
		pop_settings();
	}
}

void Approach_update::bullet_remove(std::vector<Approach*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (not_clicked_app = true)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}