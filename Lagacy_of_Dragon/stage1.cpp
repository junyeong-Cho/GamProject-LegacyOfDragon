#include "Map_setting.h"
#include "Player.h"

class Camera
{
public:
	static inline int x;
	static inline int y;
};

void Map_setting::stage1_creating(Player *player)
{

	clear_background(255);

	Camera::x = player->chara_pos_x;
	Camera::y = player->chara_pos_y;

	int offsetX = 500 - player->chara_pos_x;
	int offsetY = 500 - player->chara_pos_y;

	int xs = (Camera::x - Width / 2) / tile_size;
	int ys = (Camera::y - Height / 2) / tile_size;

	int xe = (Camera::x + Width / 2) / tile_size;
	int ye = (Camera::y + Height / 2) / tile_size;



	for (int x = xs - 1; x < xe + 1; x++)
	{
		if (x < 0 || x > 36) 
		{
			continue;
		}

		for (int y = ys - 1; y < ye + 1; y++)
		{
			if (y < 0 || y > 36) 
			{
				continue;
			}
			draw_image(tiles[map_setting.PLAI0], x * tile_size + offsetX, y * tile_size + offsetY, tile_size, tile_size);
		}
	}

	for (int x = xs - 1; x < xe + 1; x++)
	{
		if (x < 0 || x > 36)
		{
			continue;
		}

		for (int y = ys - 1; y < ye + 1; y++)
		{
			if (y < 0 || y > 36)
			{
				continue;
			}

			int tile = map_setting.stage1Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
			if (tile == NULL)
			{
				draw_image(tiles[tile], x * tile_size + offsetX, y * tile_size + offsetY, tile_size, tile_size);
				continue;
			}
				
		}
	}
}


void Map_setting::char_pos1(Player* player)
{
	for (int x = 0; x < 36; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			if (map_setting.stage1Map[y][x] == map_setting.CHARA)
			{
				player->chara_pos_x = x * tile_size;
				player->chara_pos_y = y * tile_size;
				break;
			}
		}
	}
}
