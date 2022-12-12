#include "Map_setting.h"
#include "Player.h"
#include "Tutorial.h"
#include "Enemy.h"
#include "UIsetting.h"
#include "Window_setting.h"

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

void Map_setting::tuto_controll(Player* player) {

	if (score >= tuto_enemy_max) {
		int tile = map_setting.POTAL;
		draw_image(tiles[tile], 13 * tile_size, 5 * tile_size, tile_size, tile_size);
		draw_image(tiles[tile], 13 * tile_size, 6 * tile_size, tile_size, tile_size);
		if (player->chara_pos_x>13 * tile_size&& player->chara_pos_y> 5 * tile_size&& player->chara_pos_y < 7 * tile_size)
		{
			enemy_death1 = 0;
			scene = 10;
		}

		uisetting.movebubble("Now let's go to the \nmain game!", player);
	}
}

