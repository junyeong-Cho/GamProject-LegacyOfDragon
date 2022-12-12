#ifndef MENU_H
#define MENU_H

#include <doodle\doodle.hpp>
using namespace doodle;

constexpr int title_x = 250;
constexpr int title_y = 50;
constexpr int mainmenu_x = 1000;

constexpr int gameplay_y = 800;
constexpr int setting_y = 950;
constexpr int credit_y = 1100;
constexpr int exit_y = 1250;
constexpr int maxvolume_x = 100;
constexpr int maxvolume_y = 800;

constexpr int click_mainmenu_x = 610;
constexpr int click_gap_x = 300;

constexpr int click_gameplay_y = 500;
constexpr int click_setting_y = 570;
constexpr int click_credit_y = 650;
constexpr int click_exit_y = 730;

constexpr int click_gap_y = 50;
inline double credit_timer = 0;

const Image Title{ "UIdesign/Title.png" };
const Image Gameplay_button{ "UIdesign/GamePlay.png" };
const Image Gameplay_button_on{ "UIdesign/GamePlayon.png" };
const Image Credit_button{ "UIdesign/Credit.png" };
const Image Credit_button_on{ "UIdesign/Crediton.png" };
const Image Setting_button{ "UIdesign/Setting.png" };
const Image Setting_button_on{ "UIdesign/Settingon.png" };
const Image Exit_button{ "UIdesign/Exit.png" };
const Image Exit_button_on{ "UIdesign/Exiton.png" };
const Image Howtoplay_button{ "UIdesign/HTP.png" };
const Image Howtoplay_button_on{ "UIdesign/HTPon.png" };

const Image Credit1{ "credit/credit1.png" };
const Image Credit2{ "credit/credit2.png" };
const Image Credit3{ "credit/credit3.png" };

struct Main_menu {
	void main_UI();
	bool is_gameplay();
	bool is_setting();
	bool is_credit();
	bool is_exit();
	void in_setting();
	void in_credit();
	bool is_in_setting();
	bool is_in_credit();
};
extern Main_menu main_menu;

#endif

