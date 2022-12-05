#pragma once
#include "Player.h"
class Camera
{
public:
	int camera_pos_x = 0;
	int camera_pos_y = 0;
	static inline int x;
	static inline int y;
	int xs;
	int ys;
	int xe;
	int ye;
	int offsetX;
	int offsetY;
	
	void camera_generate();
	void camera_move();
};
