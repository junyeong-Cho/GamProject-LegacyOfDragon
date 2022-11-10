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
			TREE2 = 3,
			TREE4 = 4,
			TREE5 = 5,
			TREE6 = 6,
			TREE8 = 7,
			TRE25 = 8,
			TRE45 = 9,
			TRE56 = 10,
			TRE58 = 11,
			TR245 = 12,
			TR256 = 13,
			TR258 = 14,
			TR456 = 15,
			TR458 = 16,
			TR568 = 17,
		};

	const int world_map[setting.world_y][setting.world_x] = {
		{ TR256, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR245 },
		{ TR258, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TR258 },
		{ TR258, TREE5, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, TR258 },
		{ TR258, PLAIN, SHRUB, PLAIN, PLAIN, TREE5, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TR258 },
		{ TR258, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, TR258 },
		{ TR258, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TR258 },
		{ TR258, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, CHARA, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, TR258 },
		{ TR258, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TR258 },
		{ TR568, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR458 },
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

const Image DigipenLogo{ "DigipenLogo.jpg" };
const Image TeamLogo{ "TeamLogo.png" };
const Image Nest{ "nest.png" };

const Image tiles[] = {
	Image{"plain.png"},      //0 = PLAIN
	Image{"chara.png"},      //1 = CHARA
	Image{"shrub.png"},      //2 = SHRUB
	Image{"trees/trees2.png"},        //3 = TREES 2
	Image{"trees/trees4.png"},        //4 = TREES 4
	Image{"trees/trees5.png"},        //5 = TREES 5
	Image{"trees/trees6.png"},        //6 = TREES 6
	Image{"trees/trees8.png"},        //7 = TREES 8
	Image{"trees/trees25.png"},       //8 = TREES 25
	Image{"trees/trees45.png"},       //9 = TREES 45
	Image{"trees/trees56.png"},       //10 = TREES 56
	Image{"trees/trees58.png"},       //11 = TREES 58
	Image{"trees/trees245.png"},      //12 = TREES 245
	Image{"trees/trees256.png"},      //13 = TREES 256
	Image{"trees/trees258.png"},      //14 = TREES 258
	Image{"trees/trees456.png"},      //15 = TREES 456
	Image{"trees/trees458.png"},      //16 = TREES 458
	Image{"trees/trees568.png"},      //17 = TREES 568

};