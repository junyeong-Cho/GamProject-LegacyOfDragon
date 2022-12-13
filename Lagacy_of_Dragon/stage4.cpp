//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------#include "Map_setting.h"
#include "Window_setting.h"
#include "Player.h"
#include "Camera.h"
#include "UIsetting.h"
//2-1
//보석3
void Map_setting::stage4_creating(Camera* camera)
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

			int tile = map_setting.stage4Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
			draw_image(tiles[tile], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
		}
	}
}

void Map_setting::stage4_controll(Camera* camera) {
	if (camera->x > -50 && camera->x < 50 && camera->y > 3400 && camera->y < 3450)
	{
		jewel_count = 3;
		timer = 0;
	}
	if (jewel_count == 3) {
		int tile = map_setting.PLAI0;
		draw_image(tiles[tile], 2 * tile_size + camera->offsetX, 33 * tile_size + camera->offsetY, tile_size, tile_size);
		if (timer < info_timer_check)
		{
			uisetting.talkbubble("Now you can use \nyour ultimate weapons \nby pressing the R key!");
		}
	}

	if (!quest_complite || jewel_count != 3) 
	{
		int tile = map_setting.NOPOTAL;
		draw_image(tiles[tile], 0 * tile_size + camera->offsetX, 4 * tile_size + camera->offsetY, tile_size, tile_size);
		draw_image(tiles[tile], 0 * tile_size + camera->offsetX, 5 * tile_size + camera->offsetY, tile_size, tile_size);
	}

	if (camera->x > -300 && camera->x < -150 && camera->y > 400 && camera->y < 700)
	{
		if (quest_complite && jewel_count == 3) {
			camera->camera_pos_x = -120;
			camera->camera_pos_y = 1900;
			
			enemy_death1 = 0;
			enemy_death2 = 0;
			enemy_death3 = 0;
			enemy_death4 = 0;

			quest_complite = false;
			go_next_stage = true;
			scene = 14;
		}
		else
		{
			uisetting.talkbubble("We need to \nfind the gems! \nand kill enemys!");
		}
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