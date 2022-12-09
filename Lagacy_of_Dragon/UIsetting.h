#ifndef UI_H
#define UI_H

#include <vector>
#include <doodle\doodle.hpp>

#include "Shooting.h"
#include "ice_weapon.h"
#include "auto_weapon.h"
#include "back_weapon.h"
#include "approach_weapon.h"
#include "bomb_weapon.h"
#include "breath_weapon.h"
#include "storm_weapon.h"
#include "meteor_weapon.h"


using namespace doodle;
using namespace std;

inline int chap1_point = 20;
constexpr int score_width = 1000;
constexpr int score_height = 150;
//---------------------------------//
inline double skillTimer = 0;
inline double SkillTimeCheck = 5;

inline double skillTimer_ul = 0;
inline double SkillTimeCheck_ul = 3;
inline double skillTimer_six = 0;
inline double SkillTimeCheck_six = 5;
//---------------------------------//
inline int rouletteCheck = 0;
inline int readyRoulette = 0;
inline int readyRoulette2 = 0;
inline int rouletteflag = 0;


inline int rouletteCheck_ul = 0;
inline int readyRoulette_ul = 0;
inline int readyRoulette2_ul = 0;
inline int roulette_count_once_ul = 0;
inline int box_count_once_ul = 0;
inline int rouletteCheck_six = 0;
inline int readyRoulette_six = 0;
inline int choice_box_once_six = 0;
inline int readyRoulette2_six = 0;
inline int roulette_count_once_six = 0;
inline int box_count_once_six = 0;
inline int rouletteflag_six = 0;
//---------------------------------//
inline int randomScene = 0;
inline int randomScene_ul = 0;
inline int randomScene_six= 0;
//---------------------------------//
inline int acc_x = 0;
inline int acc_ul_x = 0;
inline int acc_six_x = 0;
//---------------------------------//
inline int draw_roulette_line_x1 = 600;
inline int draw_roulette_line_x2 = 850;
//---------------------------------//
inline double box_x = 500;
inline int randomboxh = 100;
inline double randomboxSize = 150;
inline double ultra_box_x = 700;
inline int choice_box_once_ul = 0;
inline double sixboxSize = 100;
inline double six_box_x = 450;
constexpr int specific_six_gap = 85;
//---------------------------------//
inline bool is_random = false;
inline bool is_random_ul = false;
inline bool is_random_six = false;
inline int rouletteflag_ul = 0;
//---------------------------------//
inline double randomul_initial_check = 4;
inline double random_initial_check = 6;
inline double randomsix_initial_check = 6;
//---------------------------------//
inline int box_count_once = 0;
inline int roulette_count_once = 0;
inline int choice_box_once = 0;

inline int random_choices = 0;
inline int weapon_choice = 0;

inline int howtoplay_scene = 0;

inline double slide_timer = 0;
inline double slide_check1 = 0.5;
inline double slide_check2 = 1;

inline Color box_color = HexColor{ 0xff0000ff };
inline Color box_color1 = HexColor{ 0xffb7b7ff };


const Image Fire{ "etc/redjewery.png" };
const Image Water{ "etc/bluejewery.png" };
const Image Wind{ "etc/greenjewery.png" };

const Image IceW{ "weapon/ice.png" };
const Image StormW{ "weapon/storm.png" };
const Image BombW{ "weapon/bomb.png" };
const Image BackW{ "weapon/knockback.png" };

const Image rtwo{ "etc/randomtwo.png" };
const Image rthree{ "etc/randomthree.png" };
const Image rsix{ "etc/randomsix.png" };

const Image howtoplay1_1{ "howtoplay/howtoplay1-1.png" };
const Image howtoplay1_2{ "howtoplay/howtoplay1-2.png" };
const Image howtoplay2_1{ "howtoplay/howtoplay2-1.png" };
const Image howtoplay2_2{ "howtoplay/howtoplay2-2.png" };
const Image howtoplay3{ "howtoplay/howtoplay3.png" };
const Image howtoplay4{ "howtoplay/howtoplay4.png" };
const Image howtoplay5{ "howtoplay/howtoplay5.png" };


struct UIsetting
{
	void ui_point();
	void roulette(std::vector<int> randomboxloc);
	void roulette_ult(std::vector<int> ultraboxloc);
	void roulette_six(std::vector<int> sixboxloc);
	void coolTime();
	void weaponChoice(vector<Shooting*>& bullets, vector<IceWeapon*>& ice, vector<BombWeapon*>& bombs, vector<Storm*>& storm, vector<Approach*>& approach, vector<BackWeapon*>& knockback, vector<BreathWeapon*>& breath, vector<Meteor*>& meteor, Player* player);
	void howtoplay(int* scene);

};
extern UIsetting uisetting;
#endif