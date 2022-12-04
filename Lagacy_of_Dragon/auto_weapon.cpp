#include "auto_weapon.h"
#include "Enemy.h"
#include <algorithm>
#include <doodle\doodle.hpp>
using namespace doodle;

void AutoWeapon::draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void AutoWeapon::rangeDraw(Player* player)
{
	push_settings();
	no_fill();
	draw_ellipse(player->chara_pos_x, player->chara_pos_y, range, range);
	pop_settings();
}

void AutoWeapon::FireBullet(std::vector<Enemy*>& enemys, Player* player)
{
	for (int j = 0; j < enemys.size(); j++)
	{
		double a = player->chara_pos_x - enemys[j]->x;
		double b = player->chara_pos_y - enemys[j]->y;
		double distance = sqrt(a * a + b * b);
		/*discheck.push_back(distance);
		sort(discheck.begin(), discheck.end());*/

		if (bullet_pos_x >= enemys[j]->x)
		{
			bullet_pos_x -= auvelocity;
		}
		if (bullet_pos_x <= enemys[j]->x)
		{
			bullet_pos_x += auvelocity;
		}
		if (bullet_pos_y >= enemys[j]->y)
		{
			bullet_pos_y += auvelocity;
		}
		if (bullet_pos_y <= enemys[j]->y)
		{
			bullet_pos_y -= auvelocity;
		}
	}
}

void Auto_update::bullet_create(std::vector<AutoWeapon*>& bullets, std::vector<Enemy*> enemys, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_auto = true;
	}
	if (MouseIsPressed && not_clicked_auto == true)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i]->rangeDraw(player);
		}
		bullets.push_back(new AutoWeapon{ player->chara_pos_x, player->chara_pos_y, autoSize, autodamage, auto_range });
		not_clicked_auto = false;
	}
}

void Auto_update::bullet_draw(std::vector<AutoWeapon*>& bullets, std::vector<Enemy*> enemys, Player* player)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		push_settings();
		bullets[i]->draw();
		bullets[i]->FireBullet(enemys, player);
		pop_settings();

	}
}