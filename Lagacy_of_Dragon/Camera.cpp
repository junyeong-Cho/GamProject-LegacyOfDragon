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