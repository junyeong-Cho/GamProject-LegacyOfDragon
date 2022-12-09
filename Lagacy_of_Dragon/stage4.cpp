#include "Map_setting.h"
#include "Window_setting.h"
#include "Player.h"
#include "Camera.h"
//2-1
void Map_setting::stage4_creating(Camera* camera)
{
	for (int x = camera->xs - 1; x < camera->xe + 1; x++)
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

	for (int x = camera->xs - 1; x < camera->xe + 1; x++)
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

			int tile = map_setting.stage4Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
			draw_image(tiles[tile], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
		}
	}
	if (camera->x > -300 && camera->x < -150 && camera->y > 400 && camera->y < 700)
	{
		camera->camera_pos_x = -120;
		camera->camera_pos_y = 1900;
		scene = 14;
	}
	if (camera->x > -50 && camera->x < 50 && camera->y > 3400 && camera->y < 3450)
	{
		//·ê·¿ È°¼ºÈ­
	}
}


void Map_setting::char_pos4(Camera* camera)
{
	for (int x = 0; x < 36; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			if (map_setting.stage4Map[y][x] == map_setting.CHARA)
			{
				camera->camera_pos_x = x * tile_size;
				camera->camera_pos_y = y * tile_size;
				break;
			}
		}
	}
}