#include "breath_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void BreathWeapon::draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size1, size1);
}

void BreathWeapon::drawrect(Player* player)
{
	float aimAngle = atan2(angleY, angleX);
	push_settings();
	set_fill_color(HexColor{ 0x0000ffff });
	set_rectangle_mode(RectMode::Center);
	apply_translate(player->chara_pos_x, player->chara_pos_y);
	apply_rotate(aimAngle);
	draw_rectangle(rect_x - breathSize / 2, rect_y, size, size1);
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
	if (br_click_timer < br_click_check)
	{
		br_click_timer += DeltaTime;
	}

	if (!MouseIsPressed) {
		not_clicked_breath = true;
		is_breath = false;
	}

	if (br_click_timer >= br_click_check)
	{
		if (MouseIsPressed && not_clicked_breath == true)
		{
			bullets.push_back(new BreathWeapon{ player->chara_pos_x, player->chara_pos_y, breathSize, breathSize1, breathdamage, player->chara_pos_x - breathSize1 / 2,player->chara_pos_y });
			not_clicked_breath = false;
			br_click_timer = 0;
			breath_timer += DeltaTime;
		}	
	}

	if (breath_timer < breath_time_check)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i]->drawrect(player);
		}
	}
	if (breath_timer > breath_time_check)
	{
		is_breath = false;
		breath_timer = 0;
	}
}

void Breath_update::bullet_draw(std::vector<BreathWeapon*>& bullets, Player* player)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet();
		pop_settings();
	}
}

void Breath_update::coolTime(std::vector<BreathWeapon*>& bullets, Player* player)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 15);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0x00FF00FF });
	draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 20 * br_click_timer, 15);
	pop_settings();
}