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
		st_attack_check = 0;
	}
	if (MouseIsPressed && not_clicked_sto == true)
	{
		st_attack_timer += DeltaTime;
		if (st_attack_timer > st_attack_check)
		{
			storms.push_back(new Storm{ player->chara_pos_x, player->chara_pos_y, stormSize });
			 
			not_clicked_sto = false;
		}
		
	}
}

void Storm_update::bullet_draw(std::vector<Storm*>& storms) {
	/*for (int j = 0; j < enemys.size(); j++)
	{
		for (int i = 0; i < storms.size(); i++)
		{
			push_settings();
			storms[i]->draw();
			storms[i]->FireBullet();
			pop_settings();

			if (enemys[j]->x >= x)
			{
				enemys[j]->x -= 2;
			}
			if (enemys[j]->x <= x)
			{
				enemys[j]->x += 2;
			}
			if (enemys[j]->y >= y)
			{
				enemys[j]->y -= 2;
			}
			if (enemys[j]->y <= y)
			{
				enemys[j]->y += 2;
			}
		}
	}*/
}

//여기 범위 지정하는거 gam100 23일 수업에 나온거처럼 수정!!!
void Storm_update::bullet_remove(std::vector<Storm*>& storms) {
	for (int i = 0; i < storms.size(); i++)
	{
		if (storms[i]->bullet_pos_x > 1400 || storms[i]->bullet_pos_x < 100 || storms[i]->bullet_pos_y > 900 || storms[i]->bullet_pos_y < 100)
		{
			delete storms[i];
			storms.erase(storms.begin() + i);
		}
	}
}