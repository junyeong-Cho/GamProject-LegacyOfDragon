#include "auto_weapon.h"
#include "Enemy.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void AutoWeapon::draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Auto_update::bullet_create(std::vector<AutoWeapon*>& bullets, Player* player)
{
	if (!MouseIsPressed) {
		not_clicked_auto = true;
	}
	if (MouseIsPressed && not_clicked_auto == true)
	{
		bullets.push_back(new AutoWeapon{ player->chara_pos_x, player->chara_pos_y, autoSize, autodamage });
		not_clicked_auto = false;
	}
}

void Auto_update::bullet_move(std::vector<AutoWeapon*>& bullets, std::vector<Enemy*> enemys, Player* player)
{
	for (int j = 0; j < enemys.size(); j++)
	{
		for (int i = 0; bullets.size(); i++)
		{
			push_settings();
			bullets[i]->draw();
			pop_settings();

			double a = player->chara_pos_x - enemys[j]->x;
			double b = player->chara_pos_y - enemys[j]->y;
			double distance = sqrt(a * a + b * b);

			if (distance < auto_range / 2 + enemys[j]->enemysize / 2)
			{
				if (bullets[i]->bullet_pos_x >= enemys[j]->x)
				{
					bullets[i]->bullet_pos_x -= auvelocity;
				}
				if (bullets[i]->bullet_pos_x <= enemys[j]->x)
				{
					bullets[i]->bullet_pos_x += auvelocity;
				}
				if (bullets[i]->bullet_pos_y >= enemys[j]->y)
				{
					bullets[i]->bullet_pos_y += auvelocity;
				}
				if (bullets[i]->bullet_pos_y <= enemys[j]->y)
				{
					bullets[i]->bullet_pos_y -= auvelocity;
				}
			}	
		}
	}
}