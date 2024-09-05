//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "Map_setting.h"
#include "Player.h"
#include "Camera.h"
#include "Window_setting.h"
#include "UIsetting.h"

<<<<<<< HEAD
//보석1
void Map_setting::stage1_creating(Camera* camera)
{
	go_next_stage = false;

	for (int x = camera->xs - 1; x < camera->xe + 4; x++)
	{
		if (x < 0 || x > 35)
=======
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
>>>>>>> Camera_error
		{
			continue;
		}

<<<<<<< HEAD
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
=======
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
>>>>>>> Camera_error
		{
			continue;
		}

<<<<<<< HEAD
		for (int y = camera->ys - 1; y < camera->ye + 1; y++)
		{
			if (y < 0 || y > 35)
=======
		for (int y = ys - 1; y < ye + 1; y++)
		{
			if (y < 0 || y > 36)
>>>>>>> Camera_error
			{
				continue;
			}

			int tile = map_setting.stage1Map[y][x];

			if (tile == map_setting.CHARA)
			{
				tile = map_setting.PLAI0;
			}
<<<<<<< HEAD
			draw_image(tiles[tile], x * tile_size + camera->offsetX, y * tile_size + camera->offsetY, tile_size, tile_size);
=======
			if (tile == NULL)
			{
				draw_image(tiles[tile], x * tile_size + offsetX, y * tile_size + offsetY, tile_size, tile_size);
				continue;
			}
				
>>>>>>> Camera_error
		}
	}

}

<<<<<<< HEAD
void Map_setting::stage1_controll(Camera* camera) {

	if (camera->x > -150 && camera->x < -50 && camera->y > 3500 && camera->y < 3600)
	{
		jewel_count = 1;
		timer = 0;
	}
	if (jewel_count == 1)
	{
		int tile = map_setting.PLAI0;
		draw_image(tiles[tile], 1 * tile_size + camera->offsetX, 34 * tile_size + camera->offsetY, tile_size, tile_size);

		if (timer < info_timer_check)
		{
			uisetting.talkbubble("You can change \nweapons by \npressing the Q key!");
		}
	}


		if (jewel_count == 0 || !quest_complite) {
			int tile = map_setting.NOPOTAL;
			draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 29 * tile_size + camera->offsetY, tile_size, tile_size);
			draw_image(tiles[tile], 35 * tile_size + camera->offsetX, 30 * tile_size + camera->offsetY, tile_size, tile_size);
		}

		if (camera->x > 3200 && camera->x < 3300 && camera->y > 3000 && camera->y < 3300)
		{
			if (jewel_count == 1 && quest_complite) {
				camera->camera_pos_x = -100;
				camera->camera_pos_y = 2900;
				enemy_death1 = 0;
				quest_complite = false;
				go_next_stage = true;
				scene = 11;
			}
			else
			{
				uisetting.talkbubble("We need to \nfind the gems! \nand kill enemys!");
			}
		}
	
}

void Map_setting::char_pos1(Camera* camera)
=======

void Map_setting::char_pos1(Player* player)
>>>>>>> Camera_error
{
	for (int x = 0; x < 36; x++)
	{
		for (int y = 0; y < 36; y++)
		{
			if (map_setting.stage1Map[y][x] == map_setting.CHARA)
			{
<<<<<<< HEAD
				clear_background(255);
				camera->camera_pos_x = x * tile_size;
				camera->camera_pos_y = y * tile_size;
=======
				player->chara_pos_x = x * tile_size;
				player->chara_pos_y = y * tile_size;
>>>>>>> Camera_error
				break;
			}
		}
	}
}
