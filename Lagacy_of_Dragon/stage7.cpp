﻿//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "Map_setting.h"
#include "Window_setting.h"
#include "Player.h"
#include "Camera.h"
#include "UIsetting.h"

void Map_setting::stage7_creating(Camera* camera)
{
	go_next_stage = false;
	push_settings();
	set_fill_color(dawn);
	draw_rectangle(-Width, -Height, Width, Height);
	pop_settings();
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

			int tile = map_setting.stage7Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
			draw_image(tiles[tile], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
		}
	}
}

void Map_setting::stage7_controll(Camera* camera) {

	if (!quest_complite) {
		int tile = map_setting.NOPOTAL;
		draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 6 * tile_size + camera->offsetY, tile_size, tile_size);
	}

	if (camera->x > 3250 && camera->x < 3350 && camera->y > 650 && camera->y < 750)
	{
		if (quest_complite) {
			camera->camera_pos_x = 100;
			camera->camera_pos_y = 2500;

			enemy_death1 = 0;
			enemy_death2 = 0;
			enemy_death3 = 0;
			enemy_death4 = 0;

			quest_complite = false;
			go_next_stage = true;
			scene = 18;
		}
		else
		{
			uisetting.talkbubble("kill enemys!");
		}
	}
}

void Map_setting::char_pos7(Camera* camera)
{
	push_settings();
	set_fill_color(dawn);
	draw_rectangle(-Width, -Height, Width, Height);
	pop_settings();
	for (int x = 0; x < 36; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			if (map_setting.stage7Map[y][x] == map_setting.CHARA)
			{
				camera->camera_pos_x = x * tile_size;
				camera->camera_pos_y = y * tile_size;
				break;
			}
		}
	}
}