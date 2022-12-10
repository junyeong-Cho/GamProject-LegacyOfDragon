#include "Map_setting.h"
#include "Player.h"
#include "Camera.h"
#include "Window_setting.h"
#include "UIsetting.h"

void Map_setting::stage1_creating(Camera* camera)
{
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

			int tile = map_setting.stage1Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
			draw_image(tiles[tile], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
		}
	}

}

void Map_setting::stage1_controll(Camera* camera) {

	if (camera->x > -150 && camera->x < -50 && camera->y > 3500 && camera->y < 3600)
	{
		jewel_count = 1;
	}
	if (jewel_count == 1) {
		int tile = map_setting.PLAI0;
		draw_image(tiles[tile], 1 * tile_size + camera->offsetX, 34 * tile_size + camera->offsetY, tile_size, tile_size);
	}

	if (jewel_count == 0) {
		int tile = map_setting.NOPOTAL;
		draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 29 * tile_size + camera->offsetY, tile_size, tile_size);
		draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 30 * tile_size + camera->offsetY, tile_size, tile_size);
	}

	if (camera->x > 3200 && camera->x < 3300 && camera->y > 3000 && camera->y < 3300 )
	{
		if (jewel_count == 1 && quest_complite) {
			camera->camera_pos_x = -104;
			camera->camera_pos_y = 2900;
			scene = 11;
		}
		else
		{
			uisetting.talkbubble("Collect the jewels \non the map! \nand kill enemys!");
		}
	}
}

void Map_setting::char_pos1(Camera* camera)
{
	for (int x = 0; x < 36; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			if (map_setting.stage1Map[y][x] == map_setting.CHARA)
			{
				clear_background(255);
				camera->camera_pos_x = x * tile_size;
				camera->camera_pos_y = y * tile_size;
				break;
			}
		}
	}
}