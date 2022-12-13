#include "storm_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Storm::draw()
{
	push_settings();

	storm_timer += DeltaTime;
	set_image_mode(RectMode::Center);

	if (storm_timer < storm1_check) // 0.5ÃÊ
	{
		draw_image(stormImage1, bullet_pos_x, bullet_pos_y, size, size);
	}
	if (storm_timer >= storm1_check && storm_timer < storm2_check) //0.5~ 1.0
	{
		draw_image(stormImage2, bullet_pos_x, bullet_pos_y, size, size);

	}
	if (storm_timer >= storm2_check && storm_timer < storm3_check) //1.5~
	{
		draw_image(stormImage3, bullet_pos_x, bullet_pos_y, size, size);
	}
	if (storm_timer > storm3_check)
	{
		storm_timer = 0;
	}
	pop_settings();
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

		if (moveW == true) {
			storms[i]->bullet_pos_x += DeltaTime * 150 * 2;
		}
		if (moveA == true) {
			storms[i]->bullet_pos_x += DeltaTime * 150 * 2;
		}
		if (moveS == true) {
			storms[i]->bullet_pos_y -= DeltaTime * 150 * 2;
		}
		if (moveD == true) {
			storms[i]->bullet_pos_x -= DeltaTime * 150 * 2;
		}

	}
}

void Storm_update::bullet_remove(std::vector<Storm*>& storms)
{
	for (int i = 0; i < storms.size(); i++)
	{
		st_remove_timer += DeltaTime;
		if (st_remove_timer > st_remove_check)
		{
			not_clicked_sto = false;
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
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 10);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 20 * st_click_timer, 10);
	pop_settings();
}