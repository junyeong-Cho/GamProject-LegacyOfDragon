#include <doodle/doodle.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Player.h"
#include "Map_setting.h"
#include "Shooting.h"
#include "Enemy.h"
#include "Window_setting.h"
#include "test_map.h"

using namespace std;
using namespace doodle;

static constexpr int bullet_x = -200;
static constexpr int bullet_y = -200;
static constexpr int bullet_vel = 5;
static constexpr int bullet_size = 10;

static constexpr int enemyMin = -800;
static constexpr int enemyMax = 800;
static constexpr int enemySize = 30;

//--------------------------------// First scene
constexpr int digipen_width = 1000;
constexpr int digipen_height = 700;
constexpr int teamlogo_width = 2500;
constexpr int teamlogo_height = 1500;
//--------------------------------// Timer for scene
double scene_timer = 0;
double tutorial_timer = 0;
int digipenlogo_check = 2;
int teamlogo_check = 7;
int tutorial_check = 2;
//--------------------------------// Tutorial Scene 
int clicked_check = 0;
constexpr int clicked_success = 3;
constexpr int score_width = 1000;
constexpr int score_height = 150;
constexpr int tuto_move_line = 1000;
constexpr int tuto_move_line2 = 1000;
constexpr int tuto_word_x = 500;
constexpr int tuto_word_y = 200;

constexpr int nest_size = 100;
constexpr int nest_loc = 300;
//--------------------------------// Scene
int scene = 8;
int tutorial_scene = 0;
//--------------------------------// Gamestate
constexpr int title_x = 250;
constexpr int title_y = 50;
constexpr int mainmenu_x = 1000;

constexpr int gameplay_y = 800;
constexpr int setting_y = 950;
constexpr int credit_y = 1100;
constexpr int exit_y = 1250;
constexpr int maxvolume_x = 600;
constexpr int maxvolume_y = 400;

constexpr int click_mainmenu_x = 610;
constexpr int click_gap_x = 300;

constexpr int click_gameplay_y = 500;
constexpr int click_setting_y = 570;
constexpr int click_credit_y = 650;
constexpr int click_exit_y = 730;

constexpr int click_gap_y = 50;
//--------------------------------// Player Move limit
constexpr int player_limit_x = 1400;
constexpr int player_limit_x1 = 100;
constexpr int player_limit_y = 800;
constexpr int player_limit_y1 = 100;


//--------------------------------// Random Enemy

int Max = 3;
int tutoMax = 6;
int timer_check = 4;
double timer = 0;
constexpr int enemy_vel_min = 1;
constexpr int enemy_vel_max = 3;

int count_enemy_start = 0;
int tuto_enemy_max = 3;

int score = 0;
int Chap1_Enemy = 0;
double bulletradius = 5;
double enemyradius = 15;
double chararadius = 25;

int chap1_point = 20;
//--------------------------------//Bullet
double bullet_timer = 0;
int bullet_check = 4;
int bullet_max = 5;

//--------------------------------// Enemy const
constexpr int enemyWidth = 10;
constexpr int enemyHeight = 10;
constexpr int bulletSize = 10;
//--------------------------------// bool
bool not_clicked = false;

bool enemy_check = false;
bool bullet_draw_check = false;
bool player_die_check = false;
bool tutorial_scene3 = false;

//--------------------------------// RandomSkill
int randomScene = 0;
int box_x = 500;

double box_1 = 0;
double box_2 = 0;
double box_3 = 0;

double box1Check = 0.2;
double box2Check = 0.3;
double box3Check = 0.4;


const Image Fire{ "Fire.jpg" };
const Image Water{ "Water.jpg" };
const Image Star{ "Star.jpg" };


const Image Nest{ "nest.png" };
const Image DigipenLogo{ "UIdesign/DigipenLogo.jpg" };
const Image TeamLogo{ "UIdesign/TeamLogo.png" };
const Image Title{ "UIdesign/Title.png" };
const Image Gameplay_button{ "UIdesign/GamePlay.png" };
const Image Gameplay_button_on{ "UIdesign/GamePlayon.png" };
const Image Credit_button{ "UIdesign/Credit.png" };
const Image Credit_button_on{ "UIdesign/Crediton.png" };
const Image Setting_button{ "UIdesign/Setting.png" };
const Image Setting_button_on{ "UIdesign/Settingon.png" };
const Image Exit_button{ "UIdesign/Exit.png" };
const Image Exit_button_on{ "UIdesign/Exiton.png" };


//------------------------------------------------------------//
int center_map_x = 300;
int center_map_y = 300;

int mov_cam_speed_x = 4;
int mov_cam_speed_y = 8;

int cam_move_speed = 3;
//------------------------------------------------------------//


Map_setting map_setting;
Window_setting window_setting;

void on_key_pressed(KeyboardButtons button);
void on_key_released(KeyboardButtons button);

int main()
{
	window_setting.setting();

	vector<Shooting*> bullets;
	vector<Enemy*> enemys;
	vector<TutoEnemy*> tutoenemys;

	Player* player = new Player{ 0, 0 };

	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 10; y++) {
			if (map_setting.world_map[y][x] == map_setting.CHARA) {
				player->chara_pos_x = x * tile_size;
				player->chara_pos_y = y * tile_size;
				break;
			}
		}
	}

	while (!is_window_closed())
	{
		timer += DeltaTime;
		bullet_timer += DeltaTime;
		scene_timer += DeltaTime;
		update_window();


		//Game_start
		//DIGIEPN LOGO

		if (scene == 0)
		{
			clear_background(255);
			push_settings();
			set_image_mode(RectMode::Center);
			apply_scale(0.7);
			draw_image(DigipenLogo, digipen_width, digipen_height);
			pop_settings();
			if (scene_timer > digipenlogo_check)
			{
				scene += 1;
			}
		}

		//TEAM HATCHLING
		if (scene == 1)
		{
			clear_background(255);
			push_settings();
			apply_scale(0.3);
			set_image_mode(RectMode::Center);
			draw_image(TeamLogo, teamlogo_width, teamlogo_height);
			pop_settings();

			if (scene_timer > teamlogo_check)
			{
				scene += 1;
			}
		}

		//Main Menu
		if (scene == 2)
		{
			clear_background(255);
			draw_image(Title, title_x, title_y);

			apply_scale(0.5);
			draw_image(Gameplay_button, mainmenu_x, gameplay_y);
			draw_image(Setting_button, mainmenu_x, setting_y);
			draw_image(Credit_button, mainmenu_x, credit_y);
			draw_image(Exit_button, mainmenu_x, exit_y);

			//Gameplay
			if ((get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x+click_gap_x && get_mouse_y() > click_gameplay_y && get_mouse_y() < click_gameplay_y + click_gap_y ) && MouseIsPressed)
			{
				scene = 6;
			}
			//Settings
			if ((get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_setting_y && get_mouse_y() < click_setting_y + click_gap_y) && MouseIsPressed)
			{
				scene = 3;
			}
			//Credits
			if ((get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_credit_y && get_mouse_y() < click_credit_y + click_gap_y) && MouseIsPressed)
			{
				scene = 4;
			}
			//Exit
			if ((get_mouse_x() > click_mainmenu_x && get_mouse_x() < click_mainmenu_x + click_gap_x && get_mouse_y() > click_exit_y && get_mouse_y() < click_exit_y + click_gap_y) && MouseIsPressed)
			{
				scene = 5;
			}
		}

		//Settings
		if (scene == 3)
		{
			clear_background(0x7E5873FF);
			draw_text("Back", maxvolume_x, maxvolume_y);
			if ((get_mouse_x() > 600 && get_mouse_x() < 750 && get_mouse_y() > 320 && get_mouse_y() < 330 + click_gap_y) && MouseIsPressed)
			{
				scene = 2;
			}
		}

		//Credits
		if (scene == 4)
		{
			clear_background(0x7E5873FF);
			draw_text("Back", maxvolume_x, maxvolume_y);
			if ((get_mouse_x() > 600 && get_mouse_x() < 750 && get_mouse_y() > 320 && get_mouse_y() < 330 + click_gap_y) && MouseIsPressed)
			{
				scene = 2;
			}
		}

		//Exit
		if (scene == 5)
		{
			return 0;
		}


		//Gameplay_start
		//Tutorial
		if (scene == 6)
		{
			clear_background(255);
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {
					draw_image(tiles[map_setting.PLAI0], x * tile_size, y * tile_size, tile_size, tile_size);
				}
			}
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {

					int tile = map_setting.world_map[y][x];

					if (tile == map_setting.CHARA) {
						tile = map_setting.PLAI0;
					}

					draw_image(tiles[tile], x * tile_size, y * tile_size, tile_size, tile_size);
				}
			}

			//First Scene
			if (tutorial_scene == 0)
			{
				not_clicked = true;
				player->chara_pos_x = 300;
				player->chara_pos_y = 300;
				player->draw_chara();

				tutorial_scene += 1;

			}

			//Second Scene(Move)
			if (tutorial_scene == 1)
			{
				push_settings();
				set_outline_color(HexColor{ 0x00ff85ff });
				set_outline_width(4.0);
				draw_line(tuto_move_line, 0, tuto_move_line, tuto_move_line2);
				draw_text("Use W A S D", tuto_word_x, tuto_word_y);
				set_image_mode(RectMode::Center);
				draw_image(Nest, nest_loc, nest_loc, nest_size, nest_size);
				pop_settings();

				//Player move limit
				if (player->chara_pos_x < player_limit_x1)
				{
					player->chara_pos_x += 6;
				}
				if (player->chara_pos_y > player_limit_y)
				{
					player->chara_pos_y -= 6;
				}
				if (player->chara_pos_x > player_limit_x)
				{
					player->chara_pos_x -= 6;
				}
				if (player->chara_pos_y < player_limit_y1)
				{
					player->chara_pos_y += 6;
				}
				player->draw_chara();
				player->MOVE();

				if (player->chara_pos_x > tuto_move_line)
				{
					tutorial_scene = 2;
				}
			}

			//Third Scene(Shoot)			
			if (tutorial_scene == 2)
			{
				push_settings();
				draw_text("Use mouse to shoot Bullet!", tuto_word_x, tuto_word_y);
				pop_settings();

				//Player move limit
				if (player->chara_pos_x < player_limit_x1)
				{
					player->chara_pos_x += 6;
				}
				if (player->chara_pos_y > player_limit_y)
				{
					player->chara_pos_y -= 6;
				}
				if (player->chara_pos_x > player_limit_x)
				{
					player->chara_pos_x -= 6;
				}
				if (player->chara_pos_y < player_limit_y1)
				{
					player->chara_pos_y += 6;
				}

				player->draw_chara();
				player->MOVE();

				if (!MouseIsPressed) {
					not_clicked = true;
				}
				if (MouseIsPressed && not_clicked == true)
				{
					//bullet_create
					bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });

					if (bullets.size() >= 5)
					{
						tutorial_scene = 3;
					}
					not_clicked = false;
				}

				//bullet draw
				for (int i = 0; i < bullets.size(); i++)
				{
					push_settings();
					bullets[i]->draw();
					bullets[i]->FireBullet();
					pop_settings();
				}

				//Bullet Remove
				for (int i = 0; i < bullets.size(); i++)
				{
					if (bullets[i]->bullet_pos_x > 1400 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
					{
						delete bullets[i];
						bullets.erase(bullets.begin() + i);
					}
				}
			}

			//Fourth Scene (Kill Enemies)
			if (tutorial_scene == 3)
			{
				push_settings();
				draw_text("Kill all the enemies!", 100, 150);
				draw_text("SCORE: " + to_string(score), score_width, score_height);
				pop_settings();

				//Player move limit
				if (player->chara_pos_x < player_limit_x1)//Right 
				{
					player->chara_pos_x += 6;
				}
				if (player->chara_pos_y > player_limit_y)//Down
				{
					player->chara_pos_y -= 6;
				}
				if (player->chara_pos_x > player_limit_x)//Left
				{
					player->chara_pos_x -= 6;
				}
				if (player->chara_pos_y < player_limit_y1)//Up
				{
					player->chara_pos_y += 6;
				}
				player->draw_chara();
				player->MOVE();

				//Bullet_shooting
				if (!MouseIsPressed) {
					not_clicked = true;
				}
				if (MouseIsPressed && not_clicked == true)
				{
					bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
					not_clicked = false;
				}


				//Create Enemy
				if (timer > timer_check)
				{
					for (; count_enemy_start < tutoMax; count_enemy_start++)
					{
						int r_enemy_y = random(enemyMin, enemyMax);
						int r_enemy_x = random(enemyMin, enemyMax);
						tutoenemys.push_back(new TutoEnemy{ r_enemy_x, r_enemy_y, enemySize });
					}
				}

				//Enemy Move
				for (int i = 0; i < tutoenemys.size(); i++)
				{
					push_settings();
					tutoenemys[i]->draw();
					pop_settings();

					if (tutoenemys[i]->x >= player->chara_pos_x)
					{
						tutoenemys[i]->x -= random(enemy_vel_min, enemy_vel_max);
					}
					if (tutoenemys[i]->x <= player->chara_pos_x)
					{
						tutoenemys[i]->x += random(enemy_vel_min, enemy_vel_max);
					}
					if (tutoenemys[i]->y >= player->chara_pos_y)
					{
						tutoenemys[i]->y -= random(enemy_vel_min, enemy_vel_max);
					}
					if (tutoenemys[i]->y <= player->chara_pos_y)
					{
						tutoenemys[i]->y += random(enemy_vel_min, enemy_vel_max);
					}

				}

				//bullet draw
				for (int i = 0; i < bullets.size(); i++)
				{
					push_settings();
					bullets[i]->draw();
					bullets[i]->FireBullet();
					pop_settings();

				}

				//Bullet Remove
				for (int i = 0; i < bullets.size(); i++)
				{
					if (bullets[i]->bullet_pos_x > 1400 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
					{
						delete bullets[i];
						bullets.erase(bullets.begin() + i);
					}
				}

				//Bullet Enemy Check
				for (int i = 0; i < bullets.size(); i++)
				{
					for (int j = 0; j < tutoenemys.size(); j++)
					{
						double a = bullets[i]->bullet_pos_x - tutoenemys[j]->x;
						double b = bullets[i]->bullet_pos_y - tutoenemys[j]->y;
						double distance = sqrt(a * a + b * b);

						if (distance < bulletradius + enemyradius)
						{
							score += 1;
							delete bullets[i];
							delete tutoenemys[j];

							bullets.erase(bullets.begin() + i);
							tutoenemys.erase(tutoenemys.begin() + j);
							break;
						}
					}
				}

				//Me Enemy check
				for (int j = 0; j < tutoenemys.size(); j++)
				{
					for (int i = 0; i < bullets.size(); i++)
					{
						double a = player->chara_pos_x - tutoenemys[j]->x;
						double b = player->chara_pos_y - tutoenemys[j]->y;
						double distance = sqrt(a * a + b * b);

						if (distance < chararadius + enemyradius)
						{
							player_die_check = true;
						}
					}
				}

				//Move to Tutorial_last
				if (score >= tuto_enemy_max)
				{
					scene = 7;
				}
			}
		}

		//Tutorial_last
		if (scene == 7)
		{
			//Bullet_shooting
			if (!MouseIsPressed) {
				not_clicked = true;
			}
			if (MouseIsPressed && not_clicked == true)
			{
				bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
				not_clicked = false;
			}

			//Draw Map
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {
					draw_image(tiles[map_setting.PLAI0], x * tile_size, y * tile_size, tile_size, tile_size);
				}
			}
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {

					int tile = map_setting.world_map[y][x];

					if (tile == map_setting.CHARA) {
						tile = map_setting.PLAI0;
					}

					draw_image(tiles[tile], x * tile_size, y * tile_size, tile_size, tile_size);
				}
			}

			//Create bullet
			for (int i = 0; i < bullets.size(); i++)
			{
				push_settings();
				bullets[i]->draw();
				bullets[i]->FireBullet();
				pop_settings();
			}

			//Bullet Remove
			for (int i = 0; i < bullets.size(); i++)
			{
				if (bullets[i]->bullet_pos_x > 1400 || bullets[i]->bullet_pos_x < 100 || bullets[i]->bullet_pos_y > 900 || bullets[i]->bullet_pos_y < 100)
				{
					delete bullets[i];
					bullets.erase(bullets.begin() + i);
				}
			}

			//Random enemy
			if (timer > timer_check)
			{
				for (int i = 0; i < Max; i++)
				{
					push_settings();
					int r_enemy_y = random(enemyMin, enemyMax);
					int r_enemy_x = random(enemyMin, enemyMax);
					enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, enemySize });
					pop_settings();
				}
				timer_check += 4;
			}

			//Enemy move
			for (int i = 0; i < enemys.size(); i++)
			{
				enemys[i]->draw();

				if (enemys[i]->x >= player->chara_pos_x)
				{
					enemys[i]->x -= random(enemy_vel_min, enemy_vel_max);
				}
				if (enemys[i]->x <= player->chara_pos_x)
				{
					enemys[i]->x += random(enemy_vel_min, enemy_vel_max);
				}
				if (enemys[i]->y >= player->chara_pos_y)
				{
					enemys[i]->y -= random(enemy_vel_min, enemy_vel_max);
				}
				if (enemys[i]->y <= player->chara_pos_y)
				{
					enemys[i]->y += random(enemy_vel_min, enemy_vel_max);
				}

			}

			//Me Enemy check
			for (int j = 0; j < enemys.size(); j++)
			{
				double a = player->chara_pos_x - enemys[j]->x;
				double b = player->chara_pos_y - enemys[j]->y;
				double distance = sqrt(a * a + b * b);

				if (distance < chararadius + enemyradius)
				{
					player_die_check = true;
				}
			}

			//Bullet Enemy Check
			for (int i = 0; i < bullets.size(); i++)
			{
				for (int j = 0; j < enemys.size(); j++)
				{
					double a = bullets[i]->bullet_pos_x - enemys[j]->x;
					double b = bullets[i]->bullet_pos_y - enemys[j]->y;
					double distance = sqrt(a * a + b * b);

					if (distance < bulletradius + enemyradius)
					{
						chap1_point--;
						delete bullets[i];
						bullets.erase(bullets.begin() + i);

						delete enemys[j];
						enemys.erase(enemys.begin() + j);
						break;
					}
				}
			}

			//Player move limit
			if (player->chara_pos_x < player_limit_x1)//Right 
			{
				player->chara_pos_x += 6;
			}
			if (player->chara_pos_y > player_limit_y)//Down
			{
				player->chara_pos_y -= 6;
			}
			if (player->chara_pos_x > player_limit_x)//Left
			{
				player->chara_pos_x -= 6;
			}
			if (player->chara_pos_y < player_limit_y1)//Up
			{
				player->chara_pos_y += 6;
			}

			//Move next chapter
			if (chap1_point == 0)
			{
				scene = 8;
			}

			//Draw point
			push_settings();
			draw_text(to_string(chap1_point) + " / 20", score_width, score_height);
			pop_settings();

			player->MOVE();
			player->draw_chara();

		}

		//Tutorial_black scene	
		if (scene == 8)
		{
			clear_background(255);

			basic_map();

			//Draw Map
			/*
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {
					draw_image(tiles[map_setting.PLAI0], x * tile_size, y * tile_size, tile_size, tile_size);
				}
			}
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {

					int tile = map_setting.world_map[y][x];

					if (tile == map_setting.CHARA) {
						tile = map_setting.PLAI0;
					}

					draw_image(tiles[tile], x * tile_size, y * tile_size, tile_size, tile_size);
				}
			}
			*/

			player->MOVE();
			player->draw_chara();

			/*	if (KeyIsPressed && Key == KeyboardButtons::R)
				{
					set_rectangle_mode(RectMode::Center);
					draw_rectangle(player->chara_pos_x, player->chara_pos_y - 100, 400, 100);
				}*/


			/*
			if (randomScene == 0)
			{

				box_1 += DeltaTime;
				box_2 += DeltaTime;
				box_3 += DeltaTime;

				draw_image(Fire, 500, 500, 200, 200);
				draw_image(Water, 700, 500, 200, 200);
				draw_image(Star, 900, 500, 200, 200);

				//Fire
				if (box_1 > box1Check)
				{
					push_settings();
					no_fill();
					set_outline_color(HexColor{ 0xff0000ff });
					set_outline_width(8.0);
					draw_rectangle(500, 500, 200, 200);
					pop_settings();
					box1Check += 0.3;
				}
				//Water
				if (box_2 > box2Check)
				{
					push_settings();
					no_fill();
					set_outline_color(HexColor{ 0xff0000ff });
					set_outline_width(8.0);
					draw_rectangle(700, 500, 200, 200);
					pop_settings();
					box2Check += 0.3;
				}
				//Star
				if (box_3 > box3Check)
				{
					push_settings();
					no_fill();
					set_outline_color(HexColor{ 0xff0000ff });
					set_outline_width(8.0);
					draw_rectangle(900, 500, 200, 200);
					pop_settings();
					box3Check += 0.3;
				}
			}
			

			//임시로 확인용 (멈추기/ 느려지게하기)
			if (get_mouse_x() > 500 && get_mouse_x() < 1100 && get_mouse_y() > 500 && get_mouse_y() < 700)
			{

			}

			draw_rectangle(500, 500, 600, 200);
			*/
		}
	}
	return 0;

	void reset();
}

void reset()
{

}
