#include "meteor_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Meteor::draw()
{
	push_settings();
	set_image_mode(RectMode::Center);
	meteor_timer += DeltaTime;
	set_fill_color(HexColor{ 0xff002a55 });

	if (meteor_timer < meteor1_check) // 0.5ÃÊ
	{
		draw_image(meteorImage1, bullet_pos_x, bullet_pos_y, size, size);
	}
	if (meteor_timer >= meteor1_check && meteor_timer < meteor2_check) //0.5~ 1.0
	{
		draw_image(meteorImage2, bullet_pos_x, bullet_pos_y, size, size);

	}
	if (meteor_timer >= meteor2_check && meteor_timer < meteor3_check) //1.5~
	{
		draw_image(meteorImage3, bullet_pos_x, bullet_pos_y, size, size);
	}
	if (meteor_timer > meteor3_check)
	{
		meteor_timer = 0;
	}
	pop_settings();
}

void Meteor::FireBullet()
{
	bullet_pos_x = mouseX;
	bullet_pos_y = mouseY;
}

void Meteor_update::bullet_create(std::vector<Meteor*>& bullets, Player* player)
{
	if (me_click_timer < me_click_check)
	{
		me_click_timer += DeltaTime;
	}

	if (!MouseIsPressed) {
		not_clicked_me = true;
	}
	if (me_click_timer >= me_click_check)
	{
		if (MouseIsPressed && not_clicked_me == true)
		{
			bullets.push_back(new Meteor{ player->chara_pos_x, player->chara_pos_y, meteorSize, mevelocity });
			not_clicked_me = false;
			me_click_timer = 0;
		}
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

void Meteor_update::coolTime(std::vector<Meteor*>& bullets, Player* player)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 10);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 10 * me_click_timer, 10);
	pop_settings();
}