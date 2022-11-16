#pragma once
#include <doodle\doodle.hpp>
using namespace doodle;

static constexpr int world_x = 15;
static constexpr int world_y = 10;

const Image tiles[] = {
	Image{"plain/plain0.png"},		  //0 = PLAI0
	Image{"chara.png"},				  //1 = CHARA
	Image{"shrub/shrub1.png"},		  //2 = SHRUB
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
	Image{"trees/trees0.png"},        //18 = TREES 0
	Image{"shrub/shrub2.png"},		  //19 = SHRUB2
	Image{"road/road0.png"},		  //20 = ROAD 0
	Image{"road/road1.png"},		  //21 = ROAD 1
	Image{"road/road3.png"},		  //22 = ROAD 3
	Image{"road/road7.png"},		  //23 = ROAD 7
	Image{"road/road9.png"},		  //24 = ROAD 9
	Image{"road/road123.png"},		  //25 = ROAD 123
	Image{"road/road147.png"},		  //26 = ROAD 147
	Image{"road/road369.png"},		  //27 = ROAD 369
	Image{"road/road789.png"},		  //28 = ROAD 789
	Image{"plain/plain1.png"},		  //29 = PLAIN 1
	Image{"plain/plain2.png"},		  //30 = PLAIN 2
	Image{"plain/plain3.png"},		  //31 = PLAIN 3
	Image{"plain/plain4.png"},		  //32 = PLAIN 4
};

struct Map_setting {
	enum Tiles {
		PLAI0 = 0,
		CHARA = 1,
		SHRU0 = 2,
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
		TREE0 = 18,
		SHRU1 = 19,
		ROAD0 = 20,
		ROAD1 = 21,
		ROAD3 = 22,
		ROAD7 = 23,
		ROAD9 = 24,
		RO123 = 25,
		RO147 = 26,
		RO369 = 27,
		RO789 = 28,
		PLAI1 = 29,
		PLAI2 = 30,
		PLAI3 = 31,
		PLAI4 = 32
	};

	const int world_map[world_y][world_x] = {
		{ TR256, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR245 },
		{ TR258, PLAI0, PLAI0, PLAI1, PLAI0, PLAI4, PLAI0, PLAI0, SHRU0, PLAI0, PLAI0, PLAI0, PLAI0, PLAI0, TR258 },
		{ TR258, TREE5, PLAI0, PLAI2, PLAI0, PLAI3, PLAI0, PLAI0, PLAI0, PLAI1, PLAI1, PLAI4, PLAI3, SHRU1, TR258 },
		{ TR258, PLAI0, SHRU1, PLAI0, PLAI2, TREE5, PLAI2, SHRU1, PLAI0, PLAI0, PLAI0, PLAI0, PLAI0, PLAI0, TR258 },
		{ TR258, PLAI1, PLAI0, PLAI0, PLAI0, PLAI0, PLAI0, PLAI0, PLAI4, PLAI0, SHRU1, PLAI0, PLAI2, PLAI0, TR258 },
		{ TR258, PLAI0, PLAI4, PLAI0, SHRU0, PLAI0, PLAI1, PLAI0, PLAI0, PLAI0, PLAI0, PLAI3, PLAI0, PLAI4, TR258 },
		{ TR258, PLAI2, PLAI0, PLAI1, PLAI2, PLAI2, CHARA, PLAI2, PLAI0, PLAI4, PLAI2, PLAI0, SHRU1, PLAI0, TR258 },
		{ TR258, PLAI0, PLAI3, PLAI0, PLAI0, PLAI3, PLAI0, PLAI0, PLAI3, PLAI0, PLAI0, PLAI0, PLAI0, PLAI2, TR258 },
		{ TR568, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR456, TR458 },
	};
};

extern Map_setting map_setting;