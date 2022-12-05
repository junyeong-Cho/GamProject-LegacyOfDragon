#ifndef MAPS_H
#define MAPS_H

#include <doodle\doodle.hpp>
#include <vector>
#include "Player.h"
#include "Camera.h"
using namespace doodle;

static constexpr int world_x = 15;
static constexpr int world_y = 10;

static constexpr int stage_x = 36;
static constexpr int stage_y = 36;


const Image tiles[] = {
	Image{"plain/plain0.png"},		  //0 = 0
	Image{"chara.png"},				  //1 = 0
	Image{"shrub/shrub1.png"},		  //2 = SHRUB
	Image{"trees/green/trees2.png"},        //3 = TREES 2
	Image{"trees/green/trees4.png"},        //4 = TREES 4
	Image{"trees/green/trees5.png"},        //5 = TREES 5
	Image{"trees/green/trees6.png"},        //6 = TREES 6
	Image{"trees/green/trees8.png"},        //7 = TREES 8
	Image{"trees/green/trees25.png"},       //8 = TREES 25
	Image{"trees/green/trees45.png"},       //9 = TREES 45
	Image{"trees/green/trees56.png"},       //10 = TREES 56
	Image{"trees/green/trees58.png"},       //11 = TREES 58
	Image{"trees/green/trees245.png"},      //12 = TREES 245
	Image{"trees/green/trees256.png"},      //13 = TREES 256
	Image{"trees/green/trees258.png"},      //14 = TREES 258
	Image{"trees/green/trees456.png"},      //15 = TREES 456
	Image{"trees/green/trees458.png"},      //16 = TREES 458
	Image{"trees/green/trees568.png"},      //17 = TREES 568
	Image{"trees/trees0.png"},        //18 = TREES 0
	Image{"shrub/shrub2.png"},		        //19 = SHRUB2

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

	Image{"cliff/cliff0.png"},		  //33 = CLIFF 0
	Image{"cliff/cliff1.png"},		  //34 = CLIFF 1
	Image{"cliff/cliff1.png"},		  //35 = CLIFF 2
		Image{"cliff/cliff3.png"},		  //36 = CLIFF 3
		Image{"cliff/cliff48.png"},		  //37 = CLIFF 48
		Image{"cliff/cliff68.png"},		  //38 = CLIFF 68
		Image{"cliff/cliff123.png"},	  //39 = CLIFF 123

		Image{"bridge/bridge1.png"},	  //40 = BRIDGE 1
		Image{"bridge/bridge2.png"},	  //41 = BRIDGE 2
		Image{"bridge/bridge3.png"},	  //42 = BRIDGE 3
		Image{"bridge/bridge4.png"},	  //43 = BRIDGE 4
		Image{"bridge/bridge5.png"},	  //44 = BRIDGE 5

		Image{"sea/sand0.png"},	          //45 = SAND 0
		Image{"sea/sand123~.png"},	      //46 = SAND 123
		Image{"sea/sand124~.png"},	      //47 = SAND 124
		Image{"sea/sand147~.png"},	      //48 = SAND 147
		Image{"sea/sand236~.png"},	      //49 = SAND 236
		Image{"sea/sand369~.png"},	      //50 = SAND 369
		Image{"sea/sand478~.png"},	      //51 = SAND 478
		Image{"sea/sand689~.png"},	      //52 = SAND 689
		Image{"sea/sand789~.png"},	      //53 = SAND 789
		Image{"sea/sea0.png"},	          //54 = SEA 0
		Image{"sea/sea123~.png"},	      //55 = SEA 123
		Image{"sea/sea124~.png"},	      //56 = SEA 124
		Image{"sea/sea147~.png"},	      //57 = SEA 147
		Image{"sea/sea236~.png"},	      //58 = SEA 236
		Image{"sea/sea369~.png"},	      //59 = SEA 369
		Image{"sea/sea478~.png"},	      //60 = SEA 478
		Image{"sea/sea689~.png"},	      //61 = SEA 689
		Image{"sea/sea789~.png"},	      //62 = SEA 789
		Image{"sea/searock.png"},	      //63 = SEA101

		Image{"shrub/shrub_brown.png"},	  //64 = SHRUB BROWN

		Image{"road/road245.png"},		  //65 = ROAD 245
		Image{"road/road256.png"},		  //66 = ROAD 256
		Image{"road/road258.png"},		  //67 = ROAD 258
		Image{"road/road456.png"},		  //68 = ROAD 456
		Image{"road/road458.png"},		  //69 = ROAD 458
		Image{"road/road568.png"},		  //70 = ROAD 568
		Image{"road/road24568.png"},      //71 = ROAD 24568

		Image{"trees/bank/ginkgo0.png"},  //72 = GINKGO 0
		Image{"trees/bank/ginkgo2.png"},  //73 = GINKGO 2
		Image{"trees/bank/ginkgo4.png"},  //74 = GINKGO 4
		Image{"trees/bank/ginkgo6.png"},  //75 = GINKGO 6
		Image{"trees/bank/ginkgo8.png"},  //76 = GINKGO 8
		Image{"trees/bank/ginkgo25.png"}, //77 = GINKGO 25
		Image{"trees/bank/ginkgo45.png"}, //78 = GINKGO 45
		Image{"trees/bank/ginkgo56.png"}, //79 = GINKGO 56
		Image{"trees/bank/ginkgo58.png"}, //80 = GINKGO 58
		Image{"trees/bank/ginkgo258.png"},//81 = GINKGO 258
		Image{"trees/bank/ginkgo456.png"},//82 = GINKGO 456

		Image{"trees/maple/maple0.png"},  //83 = MAPLE 0
		Image{"trees/maple/maple2.png"},  //84 = MAPLE 2
		Image{"trees/maple/maple4.png"},  //85 = MAPLE 3
		Image{"trees/maple/maple6.png"},  //86 = MAPLE 6
		Image{"trees/maple/maple8.png"},  //87 = MAPLE 8
		Image{"trees/maple/maple25.png"}, //88 = MAPLE 25
		Image{"trees/maple/maple45.png"}, //89 = MAPLE 45
		Image{"trees/maple/maple56.png"}, //90 = MAPLE 56
		Image{"trees/maple/maple58.png" },//91 = MAPLE 58
		Image{"trees/maple/maple258.png"},//92 = MAPLE 258
		Image{"trees/maple/maple456.png"},//93 = MAPLE 456

		Image{ "trees/mixtree/mixtree(2)58.png" },//94 = MIXTREE 258
		Image{ "trees/mixtree/mixtree(4)56.png" },//95 = MIXTREE 456
		Image{ "trees/mixtree/mixtree2(5)8.png" },//96 = MIXTREE 258
		Image{ "trees/mixtree/mixtree4(5)6.png" },//97 = MIXTREE 456
		Image{ "trees/mixtree/mixtree25(8).png" },//98 = MIXTREE 258
		Image{ "trees/mixtree/mixtree45(6).png" },//99 = MIXTREE 456

		Image{ "etc/potal.png" },                 //100 = POTAL
		Image{ "etc/rock1.png" },                 //101 = 101 1
		Image{ "etc/rock2.png" },                 //102 = 101 2
		Image{ "etc/meat.png" },                  //103 = MEAT
		Image{ "etc/redjewery.png" },             //104 = RED JEWEL
		Image{ "etc/bluejewery.png" },            //105 = BLUE JEWEL
		Image{ "etc/greenjewery.png" },           //106 = GREEN JEWEL
		Image{ "etc/nests/nest1.png" },           //107 = NEST 1
		Image{ "etc/nests/nest2.png" },           //108 = NEST 2
		Image{ "etc/nests/nest3.png" },           //109 = NEST 3
		Image{ "etc/nests/nest4.png" },           //110 = NEST 4
		Image{ "etc/nests/nest5.png" },           //111 = NEST 5
		Image{ "etc/nests/nest6.png" },           //112 = NEST 6
		Image{ "etc/nests/nest7.png" },           //113 = NEST 7
		Image{ "etc/nests/nest8.png" },           //114 = NEST 8
};



struct Map_setting {


	enum Tiles {
		PLAI0 = 0,
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
		TREE0 = 18,
		SHRUB2 = 19,

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
		PLAI4 = 32,

		CLIFF0 = 33,
		CLIFF1 = 34,
		CLIFF2 = 35,
		CLIFF3 = 36,
		CLIFF48 = 37,
		CLIFF68 = 38,
		CLIFF123 = 39,

		BRIDGE1 = 40,
		BRIDGE2 = 41,
		BRIDGE3 = 42,
		BRIDGE4 = 43,
		BRIDGE5 = 44,

		SAND0 = 45,
		SAND123 = 46,
		SAND124 = 47,
		SAND147 = 48,
		SAND236 = 49,
		SAND369 = 50,
		SAND478 = 51,
		SAND689 = 52,
		SAND789 = 53,

		SEA0 = 54,
		SEA123 = 55,
		SEA124 = 56,
		SEA147 = 57,
		SEA236 = 58,
		SEA369 = 59,
		SEA478 = 60,
		SEA689 = 61,
		SEA789 = 62,
		SEA101 = 63,

		BROWN = 64,
		ROAD245 = 65,
		ROAD256 = 66,
		ROAD258 = 67,
		ROAD456 = 68,
		ROAD458 = 69,
		ROAD567 = 70,
		ROAD24568 = 71,

		GINKGO0 = 72,
		GINKGO2 = 73,
		GINKGO4 = 74,
		GINKGO6 = 75,
		GINKGO8 = 76,
		GINKGO25 = 77,
		GINKGO45 = 78,
		GINKGO56 = 79,
		GINKGO58 = 80,
		GINKGO258 = 81,
		GINKGO456 = 82,

		MAPLE0 = 83,
		MAPLE2 = 84,
		MAPLE3 = 85,
		MAPLE6 = 86,
		MAPLE8 = 87,
		MAPLE25 = 88,
		MAPLE45 = 89,
		MAPLE56 = 90,
		MAPLE58 = 91,
		MAPLE258 = 92,
		MAPLE456 = 93,

		MIX58 = 94,
		MIX56 = 95,
		MIXTREE28 = 96,
		MIXTREE46 = 97,
		MIXTREE25 = 98,
		MIXTREE45 = 99,

		POTAL = 100,
		ROCK1 = 101,
		ROCK2 = 102,
		MEAT = 103,
		RED = 104,
		BLUE = 105,
		GREEN = 106,
		NEST1 = 107,
		NEST2 = 108,
		NEST3 = 109,
		NEST4 = 110,
		NEST5 = 111,
		NEST6 = 112,
		NEST7 = 113,
		NEST8 = 114,

	};

	//BUSH, ROAD, NEST, 100,101, JEWEL Ãß°¡

	//SEA , SAND, MIX

	//UPST, REEF

	//MAPLE, BANK, BROWN

	const int world_map[world_y][world_x] = {
		{ 13, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12 },
		{ 14, 1,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 0,  14 },
		{ 14, 0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 29, 0,  0,  0,  0,  0,  0,  32, 0,  19, 0,  30, 0,  14 },
		{ 14, 0,  32, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32, 14 },
		{ 14, 30, 0,  29, 30, 30, 0,  30, 0,  32, 30, 0,  19, 0,  14 },
		{ 14, 0,  31, 0,  0,  31, 0,  0,  31, 0,  0,  0,  0,  30, 14 },
		{ 17, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16 },
	};

	const int stage1Map[stage_y][stage_x] = {

		{ 13, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  111,112,113,114,0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  107,108,109,110,30, 19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  0,  1,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, RED,0,  32, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0,  30, 5,  30, 19, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 65, 30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  67, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  0,  67, 0,  0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  0  },
		{ 14, 0,  19, 0,  30, 5, 30,  19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  0,  67, 30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  67, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  0,  67, 29, 0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  0,  67, 30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  67, 0,  0,  0,  0,  0,  66, 68, 68, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  0,  67, 29, 0,  0,  0,  0,  67, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  0,  67, 30, 19, 0,  0,  0,  67, 0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  67, 0,  0,  0,  0,  0,  67, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  0,  67, 29, 0,  0,  0,  0,  67, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  0,  67, 30, 19, 0,  0,  0,  67, 0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  29, 0,  67, 0,  0,  0,  0,  0,  67, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 66, 68, 68, 68, 68, 68, 71, 68, 68, 68, 68, 68, 69, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0, 30,  5,  30, 19, 0,  0,  0,  0,  67, 0,  0,  19, 0,  0,  67, 30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  67, 0,  0,  0,  29, 0,  67, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 67, 19, 0,  29, 0,  0,  67, 29, 0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0, 30,  5,  30, 19, 0,  0,  0,  0,  67, 0,  0,  19, 0,  0,  67, 30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 0,  0,  0,  0,  101,0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  67, 0,  0,  0,  29, 0,  67, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  101,0,  0,  14 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  67, 0,  0,  29, 29, 0,  67, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  101,0,  0,  0,  29, 29, 32, 67, 19, 29, 32, 0,  0,  70, 68, 68, 68, 68, 68, 68, 68, 68, 0,  29, 0,  0,  0,  0,  31, 0, 100 },
		{ 14, 0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  67, 0,  0,  0,  29, 0,  32, 0,  0,  0,  0,  0,  29, 0,  32, 0,  0,  2,  0,  0,  0,  0,  0, 100 },
		{ 14, 5,  0,  30, 0,  31, 0,  68, 68, 68, 68, 68, 69, 19, 0,  32, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  32 },
		{ 14, 0,  19, 0, 30,  5,  30, 19, 0,  0,  0,  0,  0,  0,  0,  19, 0,  30, 5,  30, 19, 0,  0,  0,  0,  0,  0,  30, 19, 101,0,  0,  0,  0,  0,  14 },
		{ 14, 5,  0,  30, 0,  31, 0,  0,  0,  29, 29, 32, 31, 19, 0,  32, 0,  2,  0,  29, 0,  0,  0,  0,  31, 0,  2,  101,101,0,  0,  0,  0,  31, 0,  32 },
		{ 17, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16 },
	};
	//
	//const int stage2Map[stage_y][stage_x] = {

 //          // 1   2      3      4      5       6       7     8       9    10       11  12       13     14    15    16       17    18    19       20    21     22    23       24    25    26      27      28      29   30     31      32    33     34     35      36
	//	{ 13, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 12 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, NEST,  NEST,  NEST,   NEST, 0, 0, 0, 29, 29, 32, 31, 19, 0, 32, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, NEST,  NEST,  NEST,   NEST, 30, 19, 0, 0, 0, 0, 0, 0, 0, 19, 0, 30, 5, 30, 19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 0, NEST,  NEST,  NEST,   NEST, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 100 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, 0, 29, 29, 32, 31, JEWEL, 0, 32, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 100 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, 0, 0, 0, 0, 0, 0, 0, 19, 0, 30, 5, 30, 19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 2,  ROAD,  ROAD, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, 0, 29, 29, 32, 31, 19, 0, 32, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0,  ROAD,  ROAD, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,   ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD, 0, 0, 0, 14 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,   ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, ROAD,  ROAD, 29, 32, 31, 19, 0, 32, 0, 0,  30, 29,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, ROAD,  ROAD, 0, 0, 0, 0, 0, 19, 0, 29,  29, 30,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, ROAD,  ROAD, 0, 0, 0, 0, 0, 0, 29, 29,  30, 0,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, ROAD,  ROAD, 29, 32, 31, 19, 0, 32, 0, 0,  29, 29,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, ROAD,  ROAD, 0, 0, 0, 0, 0, 19, 0, 30,  0, 30,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, ROAD,  ROAD, 29, 32, 31, 19, 0, 32, 0, 30,  30, 29,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, ROAD,  ROAD, 0, 0, 0, 0, 0, 19, 0, 0,  0, 30,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, ROAD,  ROAD, 0, 0, 0, 0, 0, 0, 29, 29,  29, 0,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, ROAD,  ROAD, 29, 32, 31, 19, 0, 32, 0, 29,  29, 29,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, ROAD,  ROAD, 0, 0, 0, 0, 0, 19, 0, 0,  0, 30,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, ROAD,  ROAD, 0, 0, 0, 0, 0, 0, 29, 29,  29, 0,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, ROAD,  ROAD, 29, 32, 31, 19, 0, 32, 0, 29,  0, 29,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, ROAD,  ROAD, 0, 0, 0, 0, 0, 19, 0, 30,  30, 30,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, ROAD,  ROAD, 0, 0, 0, 0, 0, 0, 29, 29,  0, 30,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 31, 0, 0, ROAD,  ROAD, 29, 32, 31, 19, 0, 0,  0, 30,  30, 29,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 32 },
	//	{ 14, 0, 19, 0, ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD, 0, 0, 0, 0, 0, 19, 0, 29,  0, 30,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 101,  0, 14 },
	//	{ 100, 0, 0, 0, ROAD, ROAD,  ROAD,  ROAD,  ROAD,  ROAD, 0, 0, 0, 0, 0, 0, 29, 30,  29, 0,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 101,  0, 0, 14 },
	//	{ 100, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 29, 29, 30, 0,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 14 },
	//	{ 14, 5, 0, 30, 0, 101,  0, 0, 0, 29, 29, 32, 31, 19, 0, 32, 0, 29, 30, 0,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 100 },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, 100},
	//	{ 14, MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,  MIX,    MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,   MIX,  MIX },
	//	{ SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  MIX,   MIX,   SAND,  SAND,  SAND,  SAND,  SAND,   SAND,  SAND,  SAND,  SAND,  SAND,  SAND, SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND },
	//	{ SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SEA,   SEA,   SEA,   SEA,   SEA,   SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,   SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SEA,   SAND,  SAND,  SAND,  SAND },
	//	{ SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SAND,  SEA,   SEA,   SAND,  SAND,  SEA,   SEA,   SEA,   SEA,   SEA,   SAND,  SAND,  SAND,  SAND },
	//	{ SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SAND,  SAND }
	//};
	//
	//const int stage3Map[stage_y][stage_x] = {
	//	// 1   2      3      4      5       6       7     8       9    10       11  12       13     14    15    16       17    18    19       20    21     22    23       24    25    26      27      28      29   30     31      32    33     34     35      36
	//	{ UPST,  UPST,  UPST,  15, 15, 15, 15, 15, 15, 15, 15, 15, 101,  100,100,101,  15, 15, 15, 15, 15, 15, 15, 15, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  0, 32, 0, 0, 2, 101,  0, 101,  0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST, 0,  0, 0, 0, 0, 29, 29, 32, 31, ROAD,  0, 32, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 2, 0, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  0, 30, 19, 0, 0, 0, 0, 0, ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD , 19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, ROAD,  0, 0, 0, 0, 29, 0, 32, 0, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 29, 29, 32, 31, JEWEL, 0, 32, 0, 2, 0, ROAD,  0, 0, 0, 0, 31, 0, 2, 0, 29, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 0, 0, 19, 0, 30, 5, ROAD,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 0, 29, 0, 32, ROAD,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, 0, SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 32, 31, 19, 0, 32, 0, 2, ROAD,  29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,   29, 29, 31, 29, 29, 32, 29, 29, ROAD,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  31, 0, 29, 31, 29, 32, 29, 0, ROAD,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, SEA,   SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  32, 31, 19, 0, 32, 0, 29, 29, ROAD,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 19, 0, 29, 29, ROAD,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 0, 0, 29, 29, 29, ROAD,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  29, 29, 32, 31, 19, 0, 32, 0, 29, 29, ROAD,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 0, 19, 0, 29, 29, ROAD,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 0, 0, 29, 29, 29, ROAD,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 29, 29, 32, 31, 19, 0, 32, 0, 29, 29, ROAD,  0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 0, 0, 0, 0, 19, 0, 29, 29, ROAD,  19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 2, 0, 0, ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  ROAD,  0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, 0, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  UPST,  0, 0, 0, 29, 29, ROAD,  31, 19, 0, 32, 0, 29, 29, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  5, 30, 19, 0, 0, 0, ROAD,  0, 0, 0, 19, 0, 0, 0, 30, 19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 30, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  32, 0, 0, 2, 0, 0, ROAD,  0, 0, 0, 0, 29, 29, 0, 0, 0, 0, 0, 0, 29, 0, 32, 30, 0, 30, 0, 0, 0, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  UPST,  31, 0, 0, 0, 29, 29, ROAD,  31, 19, 0, 32, 0, 0, 31, 29, 0, 0, 0, 30, 31, 0, 2, 0, 29, 0, 0, 0, 0, 31, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  UPST,  30, 5, 30, 19, 0, 0, 0, ROAD,  0, 0, 0, 19, 0, 29, 0, 31, 19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 30, 0, 0, 0, SEA,   SEA },
	//	{ UPST,  UPST,  UPST,  29, 0, 32, 0, 0, 2, 0, 0, ROAD,  0, 0, 0, 0, 29, 0, 30, 0, 0, 0, 0, 30, 29, 0, 32, 0, 0, 2, 0, 0, 30, SEA,   SEA,   SEA },
	//	{ UPST,  UPST,  0, 30, 0, 31, 0, 0, 0, 29, 29, ROAD,  31, 19, 0, 0,  0, 29, 31, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, 0, 30, SEA,   SEA,   SEA },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, 0, 0, 0, ROAD,  0, 0, 0, 19, 0, 0, 31, 31, 19, 0, 0, 0, 0, 0, 0, 30, 19, 0, 0, 0, 0, SEA,   SEA,   SEA },
	//	{ 14, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, ROAD,  0, 0, 0, 0, 29, 29, 0, 31, 0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, 0, SEA,   SEA,   SEA,   SEA },
	//	{ 101,  0, 0, 29, 0, 32, 0, 0, 2, 0, 0, ROAD,  0, 0, 0, 0,  29, 29, 31, 29, 29, 29, 29, 0, 29, 0, 32, 0, 0, 2, 0, SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ 14, 5, 0, 30, 0, 101,  0, 0, 0, 29, 29, ROAD,  31, 19, 0,  32, 0, 0, 29, 31, 29, 29, 29, 0, 31, 0, 2, 0, 29, 0, 0, SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ 100,0, 0, 29, 0, 32, 0, 0, 2, 0, 0, ROAD,  0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 2, 0, SEA,   SEA,   SEA,   SEA,   SEA},
	//	{ 100,5, 0, ROAD,  ROAD,  ROAD,  ROAD,  ROAD , ROAD,  ROAD,  ROAD , ROAD,  31, 19, 0, 32, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ 14, 0, 19, 0, 30, 5, 30, 19, 0, 0, 0, 0, 0, 0, 0, 19, 0, 30, 5, 30, 19, 0, 0, 0, 0, 0, 0, 30, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ 14, 5, 0, 30, 0, 101,  0, 0, 0, 29, 101,  101,  31, 19, 0, 32, 0, 2, 0, 29, 0, 0, 0, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//	{ 17, 15, 15, 15, 101, 15,  15, 15, 101, 15,  15, 15, 101,  15, 15, 15, 15, 15, 15, 15, SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA,   SEA },
	//};

	//const int stage4Map[stage_y][stage_x] = {

	//  { 0, MAPLE, 29, 31, 30, 30, 29, 31, 0, 32, 30, 32, 29, 0, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, 30 ,29, 0, 0, 0, 0, 0, 0, 0, 29, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA },
	//  { MAPLE, 0, 29, 0, 31, 0, 0, 0, 0, 29, 29, 32, 31, 29, 0, 32, 0, 0, 0, 29, 0, 0, 0, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA },
	//  { BANK, 0, 30, 29, 0, 31, MAPLE, 29, 0, 0, 0, 0, 0, 0, 0, 29, 0, 30, 0, 30, 29, 0, 0, 0, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, },
	//  { 100, 0, 0, 29, 0, 32, 0, 29, BANK, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA, SEA },
	//  { 100, 0, 0, ROAD,ROAD,ROAD,ROAD,ROAD,ROAD, 29, 29, 32, 31, 29, 0, 32, 0, 0, 0, 29, 0, 0, 0, 0, 31, 0, 0, 0, 29, SEA, SEA, SEA, SEA, SEA, SEA, SEA },
	//  { MAPLE, 0, 29, 0, 30, 30, 30, 30, ROAD, 0, 0, 0, 0, 0, 0, 29, 0, 30, 31, 30, 101, 0, 0, 0, 0, 0, 0, 30, 30, 0, SEA, SEA, SEA, SEA, SEA, SEA },
	//  { BANK, 0, 0, 29, 0, 32, BROWN, 0, ROAD, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, SEA, SEA, SEA, SEA, SEA },
	//  { BANK, 31, 0, 30, 0, 31, 0, BROWN, ROAD, 29, 29,MAPLE, 31, 19, 0, 32, 0, 2, 0, 29, 0, 0, 0, 0, 31, 0, 2, 0, 29, 0, 0, SEA, SEA, SEA, SEA, SEA, },
	//  { MAPLE, 0, 29, 0, 30, 31, 30, 30, ROAD, 0, 31, 0, 0, 0, 0, 29, BANK, 30, 30, 30, 29, 0, 0, 0, 0, 101, 0, 30, 29, 0, 0, SEA, SEA, SEA, SEA, SEA },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, ROAD, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 30, 0, 0,  SEA, SEA, SEA, SEA },
	//  { BANK, 30, 0, 30, 0, 31, 0, 0, ROAD, 29, 29, 32, 31, 29, 0, 32, 0, 0, 0, 29, BROWN, 0, 0, 0, 31, 0, BROWN, 0, 29, 0, 0, 0, 0, SEA, SEA, SEA },
	//  { MAPLE, 0, 29, 0, 30, 30, 30, 29, ROAD, 0, 0, 0, 0, 0, MAPLE, 32, 0, 30, 29, BROWN, 29, 0, 0, 0, 0, 0, 0, 30, 29, 0, 0, 0, 0, 0,  SEA, SEA },
	//  { 29, BANK, 0, 29, 0, 32, 0, 0, ROAD, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 0, 0, SEA, SEA },
	//  { MAPLE, 30, 0, 30, 0, 31, 0, 0, ROAD, 29, 29, 32, 31, 29, 0, 32, 0, 0, 0, 29, 0, BANK, 0, 0, 31, 0, 0, BANK, 29, 0, 0, 0, 0, 101, 0, SEA },
	//  { BANK, 0, 29, 101, 30, 29, 30, 29, ROAD, 0, 0, 0, 0, 0, 0, 29, 0, 30, 0, 30, 29, 0, 0, 0, 0, BANK, 0, 30, 29, 0, 0, 0, 0, 0, 101, 31 },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, ROAD, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 0, 101, 0, 31 },
	//  { BANK, 31, 0, 30, 0, 31, 0, 0, ROAD, 29, 29, 32, 31, 29, 0, 32, 0, 0, 0, 29, 0, 0, 0, 0, 31, 0, 0, 0, BANK, 0, 0, 0, 101, 31, 0, 32 },
	//  { BANK, 0, 29, 0, 30, 31, 30, 29, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD, 31, 31, 0, 0, 0, 5, 0, 29 },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, ROAD, 31, 0, 0, 0, 0, BANK, 31 },
	//  { BANK, 30, 0, 30, 0, 31, 0, 0, 0, 29, BROWN, 32, 31, 29, 0, 32, 0, 0, 0, 29, 0, 0, 0, 0, 31, 0, 0, ROAD, 30, 0, 0, 0, 0, 31, MAPLE, 32 },
	//  { BANK, 0, 29, 0, 30, 30, 30, 29, 0, BROWN, 0, 0, 0, 0, 0, 29, 0, 30, 30, 30, 29, 0, 0, 0, 0, 0, 0, ROAD, 29, 0, 0, 0, 0, 0, BANK, 31 },
	//  { BANK, 0, 0, 29, 0, MAPLE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, ROAD, 0, 0, 0, 0, 0, 0, BANK, 32 },
	//  { MAPLE, 31, 0, 30, 0, 31, 0, 0, 0, 29, 29, 32, 31, 31, 0, 32, 0, 31, 0, 29, 0, 0, 0, 0, 31, 0, 31, ROAD, 29, 0, 0, 0, 0, 31, 0, MAPLE },
	//  { BANK, 0, 31, 0, 30, 31, 30, 31, 0, 0, 0, 0, 0, 0, 0, 31, 0, 30, 31, 30, 31, 0, 0, 0, 0, 0, 0, ROAD, 31, 0, 0, 0, 0, 0, MAPLE, 31 },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, BANK, 0, 0, 0, 29, 0, 32, ROAD, 0, 31, 0, 0, 0, 0, BANK, 31 },
	//  { BANK, 31, 0, 30, 0, 31, 0, 0, 0, 29, 29, 32, 31, BANK, 0, 32, 0, 31, 0, 29, 0, 0, 0, 0, 31, 0, 31, ROAD, 29, 0, 0, 0, 0, 31, 0, BANK },
	//  { BANK, 0, 31, 0, 30, 31, 30, 31, 0, 0, 0, 0, 0, 0, 0, 31, 0, 30, 31, 30, 31, 0, 0, 0, BROWN, 0, 0, ROAD, 31, 0, 0, 0, 0, 0, 0, BANK },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, 32, 0, MAPLE, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, BROWN, 32, ROAD, 0, 32, 0, 0, 0, 0, 0, BANK },
	//  { BANK, 0, 0, 29, 0, 32, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, ROAD, 0, 32, 0, 0, 0, 0, 0, MAPLE },
	//  { MAPLE, 32, 0, 30, 0, 31, 0, 0, 0, 29, 29, 32, 31, 32, 0, 32, 0, 32, 0, 29, 0, 0, 0, 0, 31, 0, 32, ROAD, 29, 0, 0, 0, 0, 31, 0, BANK },
	//  { BANK, 0, 0, 29, BROWN, 32, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 0, 0, 0, 29, 0, 32, 0, 0, 32, 0, 0, 0, BROWN, 0, BANK },
	//  { MAPLE, 32, 0, 30, 0, BROWN, 0, 0, 0, 29, 29, 32, 31, 32, 0, 32, 0, 32, 0, 29, 0, 0, 0, 0, 31, 0, 32, 0, 0, 0, 0, 0, BROWN, 29, 0, MAPLE },
	//  { BANK, 0, 32, 0, 30, 32, 30, 32, 0, 0, 0, 0, 0, 0, 0, 32, 0, 30, 32, 30, 32, 0, 0, 0, 0, 0, 0, 30, 32, 0, 0, 0, 0, 0, 0, BANK },
	//  { MAPLE, 32, 0, 30, 0, 31, 0, 0, 0, 29, 29, 32, 31, 32, 0, 32, 0, 101, 0, 29, 0, 0, 0, 0, 31, 0, 32, 0, 29, 0, 0, 0, 0, 31, 0, BANK },
	//  { BANK, BANK, BANK, MAPLE, BANK, BANK, BANK, BANK, MAPLE, BANK, BANK, BANK, BANK, MAPLE, BANK, BANK, BANK, BANK, BANK, MAPLE, BANK, MAPLE, BANK, BANK, BANK, BANK, BANK, BANK, MAPLE, BANK, BANK, BANK, BANK, MAPLE, BANK, MAPLE },
	//};

	void map_creating();
	void stage1_creating(Camera* camera);
	//void stage2_creating();
	//void stage3_creating();
	//void stage4_creating();

	void char_pos(Player* player);
	void char_pos1(Camera* camera);
	//void char_pos2(Player* player);
	//void char_pos3(Player* player);
	//void char_pos4(Player* player);


};

extern Map_setting map_setting;

#endif