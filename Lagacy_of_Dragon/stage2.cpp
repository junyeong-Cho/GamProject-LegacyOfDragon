#include "Map_setting.h"
#include "Window_setting.h"
#include "Player.h"
#include "Camera.h"
#include "UIsetting.h"

void Map_setting::stage2_creating(Camera* camera)
{
	go_next_stage = false;
	for (int x = camera->xs - 1; x < camera->xe + 4; x++)
	{
		if (x < 0 || x > 35)
		{
			continue;
		}

		for (int y = camera->ys - 1; y < camera->ye + 1; y++)
		{
			if (y < 0 || y > 35)
			{
				continue;
			}
			draw_image(tiles[map_setting.PLAI0], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
		}
	}

	for (int x = camera->xs - 1; x < camera->xe + 4; x++)
	{
		if (x < 0 || x > 35)
		{
			continue;
		}

		for (int y = camera->ys - 1; y < camera->ye + 1; y++)
		{
			if (y < 0 || y > 35)
			{
				continue;
			}

			int tile = map_setting.stage2Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
			draw_image(tiles[tile], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
		}
	}
}
void Map_setting::stage2_controll(Camera* camera) {

	if (!quest_complite) {
		int tile = map_setting.NOPOTAL;
		draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 4 * tile_size + camera->offsetY, tile_size, tile_size);
		draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 5 * tile_size + camera->offsetY, tile_size, tile_size);
	}

	if (camera->x > 3200 && camera->x < 3300 && camera->y > 500 && camera->y < 700)
	{
		if (quest_complite) {
			camera->camera_pos_x = -20;
			camera->camera_pos_y = 3300;
			enemy_death1 = 0;
			enemy_death2 = 0;
			enemy_death3 = 0;
			enemy_death4 = 0;
			go_next_stage = true;

			quest_complite = false;
			scene = 12;
		}
		else
		{
			uisetting.talkbubble("kill enemys!");
		}
	}
}

void Map_setting::char_pos2(Camera* camera)
{
	for (int x = 0; x < 36; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			if (map_setting.stage2Map[y][x] == map_setting.CHARA)
			{
				camera->camera_pos_x = x * tile_size;
				camera->camera_pos_y = y * tile_size;
				break;
			}
		}
	}
}