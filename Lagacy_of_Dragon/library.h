#pragma once
#include <doodle/doodle.hpp>

using namespace doodle;


struct Setting
{
	static constexpr int tile_size = 100;
	static constexpr int world_x = 15;
	static constexpr int world_y = 10;

	static constexpr int Pvelocity = 3;
	static constexpr int Bvelocity = 6;
	static constexpr int Player_r = 50;

	static constexpr int bullet_x = -200;
	static constexpr int bullet_y = -200;
	static constexpr int bullet_vel = 5;
	static constexpr int bullet_size = 10;

	static constexpr int enemyMin = -800;
	static constexpr int enemyMax = 800;
	static constexpr int enemySize = 30;

};
Setting setting;

struct Map_setting {
	enum Tiles {
		PLAIN = 0,
		CHARA = 1,
		SHRUB = 2,
		TREES = 3
	};

	const int world_map[setting.world_y][setting.world_x] = {
		{ TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES },
		{ TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
		{ TREES, TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, TREES },
		{ TREES, PLAIN, SHRUB, PLAIN, PLAIN, TREES, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
		{ TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, TREES },
		{ TREES, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
		{ TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, CHARA, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, TREES },
		{ TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
		{ TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES },
	};
};
Map_setting map_setting;
struct Window_setting {
	void window()
	{
		set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
		set_image_mode(RectMode::Corner);
		no_fill();
		set_outline_width(3.0);
	}
};

Window_setting window_setting;
