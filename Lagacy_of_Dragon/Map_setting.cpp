#include "Map_setting.h"
#include "Player.h"

void Map_setting::map_creating()
{
	clear_background(255);
	for (int x = 0; x < 18; x++) {
		for (int y = 0; y < 10; y++) {
			draw_image(tiles[map_setting.PLAI0], x * tile_size, y * tile_size, tile_size, tile_size);
		}
	}
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 10; y++) {

			int tile = map_setting.world_map[y][x];

			if (tile == map_setting.CHARA) {
				tile = map_setting.PLAI0;
			}

			draw_image(tiles[tile], x * tile_size, y * tile_size, tile_size, tile_size);
		}
	}
}
void Map_setting::char_pos(Player* player)
{
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 10; y++) {
			if (map_setting.world_map[y][x] == map_setting.CHARA) {
				player->chara_pos_x = x * tile_size;
				player->chara_pos_y = y * tile_size;
				break;
			}
		}
	}
}
