#include "Weapons.h"
#include "auto_weapon.h"
#include "back_weapon.h"
#include "breath_weapon.h"
#include "ice_weapon.h"

void Weapons::approch_draw()
{
	set_fill_color(HexColor{ 0xff002aff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::auto_draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::auto_rangeDraw(Player* player)
{
	push_settings();
	no_fill();
	draw_ellipse(player->chara_pos_x, player->chara_pos_y, range, range);
	pop_settings();
}

void Weapons::auto_FireBullet(std::vector<Enemy*>& enemys, Player* player)
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

void Weapons::back_draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::back_FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Bavelocity);
	float velocityY = (sin(aimAngle) * Bavelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void Weapons::bomb_draw()
{
	set_fill_color(HexColor{ 0xffff00ff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::breath_drawR()
{
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(HexColor{ 0x0000ffff });
	draw_rectangle(bullet_pos_x, bullet_pos_y, -range, size);
	pop_settings();
}

void Weapons::breath_drawL()
{
	push_settings();
	set_rectangle_mode(RectMode::Center);
	set_fill_color(HexColor{ 0x0000ffff });
	draw_rectangle(bullet_pos_x - breathSize, bullet_pos_y, range, size);
	pop_settings();
}

void Weapons::ice_draw()
{
	set_fill_color(HexColor{ 0x0000ffff });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::ice_FireBullet()
{
	float aimAngle = atan2(angleY, angleX);
	float velocityX = (cos(aimAngle) * Ivelocity);
	float velocityY = (sin(aimAngle) * Ivelocity);

	bullet_pos_x += static_cast<int>(velocityX);
	bullet_pos_y += static_cast<int>(velocityY);
}

void Weapons::meteor_draw()
{
	set_fill_color(HexColor{ 0xff002a55 });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::meteor_FireBullet()
{
	bullet_pos_x = mouseX;
	bullet_pos_y = mouseY;
}

void Weapons::storm_draw()
{
	set_fill_color(HexColor{ 0xff002a55 });
	draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void Weapons::storm_FireBullet()
{
	bullet_pos_x = mouseX;
	bullet_pos_y = mouseY;
}
