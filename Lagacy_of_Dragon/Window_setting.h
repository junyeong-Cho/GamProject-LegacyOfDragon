//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------

#ifndef WINS_H
#define WINS_H

#include <doodle\doodle.hpp>
using namespace doodle;

// 1-1 10
// 1-2 11
// 1-3 12
//
inline int scene = 0;
inline int jewel_count = 0;


struct Window_setting {
	void setting();
};
extern Window_setting window_setting;

#endif