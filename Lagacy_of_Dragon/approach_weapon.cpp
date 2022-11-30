#include "Player.h"
#include "approach_weapon.h"
#include <doodle\doodle.hpp>

using namespace doodle;

void Approach::draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(x, y, size, size);
}

void Approach_update::approach_create(std::vector<Approach*>& approachs, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_app = true;
		attack_timer = 0;
	}
	if (MouseIsPressed && not_clicked_app == true)
	{
		attack_timer += DeltaTime;
		if (attack_timer > attack_check)
		{
			approachs.push_back(new Approach{ player->chara_pos_x, player->chara_pos_y, approachSize });
			not_clicked_app = false;
		}
	}
}

void Approach_update::approach_draw(std::vector<Approach*>& approachs) {
	for (int i = 0; i < approachs.size(); i++)
	{
		push_settings();
		approachs[i]->draw();
		pop_settings();
	}
}