//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#ifndef TUTO_H
#define TUTO_H

#include <doodle\doodle.hpp>
#include <vector>
#include <map>
#include <string>
#include "Player.h"

using namespace doodle;
using namespace std;

constexpr int tuto_move_line = 1000;
constexpr int tuto_move_line2 = 1000;
constexpr int tuto_word_x = 500;
constexpr int tuto_word_y = 200;
inline int score = 0;
inline int textbox = 9;
constexpr int dragons_vel = 5;

constexpr int tuto_size = 100;
constexpr int nest_loc = 200;
inline int text_scene = 0;

//----------------------------// Dragon
inline int dragon_x = 200;
inline int dragon_y = 200;

inline int rdragon_x = 400;
inline int rdragon_y = 700;

//---------------------------//meat
inline int meat_x = 400;
constexpr int meat_y = 200;

//----------------------------// Imoticon chicken
inline int chicken_x = 0;
inline int chicken_y = 0;

inline double chicken_to_happy = 0;
inline double chicken_to_happy_check = 2;
//----------------------------// Imoticon happy
inline double happy_to_bad = 0;
inline double happy_to_bad_check = 3;

inline double happy_timer = 0;
inline double happy_check1 = 0.1;
inline double happy_check2 = 0.2;
//---------------------------// Immoticon bad
inline double bad_to_angry = 0;
inline double bad_to_angry_check = 2;

inline double bad_timer = 0;
inline double bad_check1 = 0.1;
inline double bad_check2 = 0.2;
//--------------------------// Imoticon angry
inline double angry_to_move = 0;
inline double angry_to_move_check = 2;

inline double angry_timer = 0;
inline double angry_check1 = 0.1;
inline double angry_check2 = 0.2;

//--------------------------// Imoticon smile
inline double smile_to_angry = 0;
inline double smile_to_angry_check = 2;

inline double smile_timer = 0;
inline double smile_check1 = 0.1;
inline double smile_check2 = 0.2;
//--------------------------// Imoticon sweat
inline double ddam_to_jewel = 0;
inline double ddam_to_jewel_check = 2;

inline double ddam_timer = 0;
inline double ddam_check1 = 0.1;
inline double ddam_check2 = 0.2;
inline int sweat_x = 0;
inline int sweat_y = 0;

//-------------------------// Imoticon ddiyong
inline double ddi_to_shoot = 0;
inline double ddi_to_jewel = 0;
inline double ddi_to_shoot_check = 4;
inline double ddi_to_jewel_check = 2;

inline double ddiyong_timer = 0;
inline double ddiyong_check1 = 0.1;
inline double ddiyong_check2 = 0.2;
//-------------------------// Imoticon jewel
inline double jewel_to_ddi = 0;
inline double jewel_to_ddi_check = 2;
constexpr int jewel_x = 1300;
constexpr int jewel_y = 200;


inline double jewel_timer = 0;
inline double jewel_check1 = 0.1;
inline double jewel_check2 = 0.2;
//------------------------//

const Image meat{ "etc/meat.png" };
const Image Nest{ "etc/nest.png" };
const Image green_dragon{ "chara.png" };
const Image red_dragon{ "red_dragon.png" };

const Image chicken1{ "tutorial_dot/chicken1.png" };
const Image chicken2{ "tutorial_dot/chicken2.png" };
const Image happy1{ "tutorial_dot/happyface1.png" };
const Image happy2{ "tutorial_dot/happyface2.png" };
const Image bad1{ "tutorial_dot/BadFace1.png" };
const Image bad2{ "tutorial_dot/BadFace2.png" };
const Image angry1{ "tutorial_dot/angry.png" };
const Image angry2{ "tutorial_dot/angry2.png" };
const Image ddam1{ "tutorial_dot/DDAM1.png" };
const Image ddam2{ "tutorial_dot/DDAM2.png" };
const Image ddiyong1{ "tutorial_dot/ddiyong1.png" };
const Image ddiyong2{ "tutorial_dot/ddiyong2.png" };
const Image smile1{ "tutorial_dot/Smile1.png" };
const Image smile2{ "tutorial_dot/Smile2.png" };
const Image jewel1{ "tutorial_dot/jewel1.png" };
const Image jewel2{ "tutorial_dot/jewel2.png" };
const Image balloon{ "tutorial_dot/malpugsun.png" };


struct Tutorial
{
public:

	void textbox1(); 
	void textbox2();
	void textbox3(); 
	void textbox4(); 
	void textbox5();
	void textbox6();
	void textbox7();
	void textbox8();
	void textbox9();


	void scene1_guideline();//wasd
	void scene2_guideline();
};

extern Tutorial tutorial;

#endif
