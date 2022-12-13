//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "camera.h"

void Camera::camera_generate()
{
	Camera::x = camera_pos_x;
	Camera::y = camera_pos_y;

	offsetX = 500 - camera_pos_x;
	offsetY = 500 - camera_pos_y;

	xs = (Camera::x - Width / 2) / tile_size;
	ys = (Camera::y - Height / 2) / tile_size;

	xe = (Camera::x + Width / 2) / tile_size;
	ye = (Camera::y + Height / 2) / tile_size;
}

void Camera::camera_move()
{
	if (moveW == true) {
		camera_pos_y -= DeltaTime * 150 * 2;
	}
	if (moveA == true) {
		camera_pos_x -= DeltaTime * 150 * 2;
	}
	if (moveS == true) {
		camera_pos_y += DeltaTime * 150 * 2;
	}
	if (moveD == true) {
		camera_pos_x += DeltaTime * 150 * 2;
	}
}

void Camera::move_fix_limit(Camera* camera)
{
	//Player move limit
	if (camera->camera_pos_x < -200)
	{
		camera->camera_pos_x += DeltaTime * 150 * 2;
	}
	if (camera->camera_pos_y > 3600)
	{
		camera->camera_pos_y -= DeltaTime * 150 * 2;
	}
	if (camera->camera_pos_x > 3300)
	{
		camera->camera_pos_x -= DeltaTime * 150 * 2;
	}
	if (camera->camera_pos_y < 100)
	{
		camera->camera_pos_y += DeltaTime * 150 * 2;
	}
	//player->draw_chara();
	//player->MOVE();
}