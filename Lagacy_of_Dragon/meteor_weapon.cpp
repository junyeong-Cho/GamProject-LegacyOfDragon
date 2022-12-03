#include "meteor_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Meteor::draw()
{
	set_fill_color(HexColor{ 0xff002a55 });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Meteor::FireBullet()
{
	bullet_pos_x = mouseX;
	bullet_pos_y = mouseY;
}

void Meteor_update::bullet_create(std::vector<Meteor*>& bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_me = true;
	}
	if (MouseIsPressed && not_clicked_me == true)
	{
		bullets.push_back(new Meteor{ player->chara_pos_x, player->chara_pos_y, meteorSize, mevelocity });
		not_clicked_me = false;
	}
}

void Meteor_update::bullet_draw(std::vector<Meteor*>& bullets) {

	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}

void Meteor_update::bullet_remove(std::vector<Meteor*>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		me_remove_timer += DeltaTime;
		if (me_remove_timer > me_remove_check)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			me_remove_timer = 0;
		}
	}
}