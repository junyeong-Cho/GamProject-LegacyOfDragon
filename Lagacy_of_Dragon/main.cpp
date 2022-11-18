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
#include "Logos.h"
#include "Main_menu.h"
#include "Tutorial.h"

using namespace std;
using namespace doodle;

static constexpr int bullet_x = -200;
static constexpr int bullet_y = -200;
static constexpr int bullet_vel = 5;
static constexpr int bullet_size = 10;

static constexpr int enemyMin = -800;
static constexpr int enemyMax = 800;
static constexpr int enemySize = 30;

//--------------------------------// Timer for scene
double scene_timer = 0;
double tutorial_timer = 0;
int digipenlogo_check = 2;
int teamlogo_check = 7;
int tutorial_check = 2;
//--------------------------------// Tutorial Scene 
int clicked_check = 0;
constexpr int clicked_success = 3;
//--------------------------------// Scene
int scene = 0;
int tutorial_scene = 0;


int score = 0;


//--------------------------------// Random Enemy

int Max = 3;
int tutoMax = 6;
int timer_check = 4;
double timer = 0;
constexpr int enemy_vel_min = 1;
constexpr int enemy_vel_max = 3;

int count_enemy_start = 0;
int tuto_enemy_max = 3;

int Chap1_Enemy = 0;
double bulletradius = 5;
double enemyradius = 15;
double chararadius = 25;

int chap1_point = 20;
//--------------------------------//Bullet
double bullet_timer = 0;
int bullet_check = 4;
int bullet_max = 5;

bool not_clicked = false;
//--------------------------------// Enemy const
constexpr int enemyWidth = 10;
constexpr int enemyHeight = 10;
//--------------------------------// bool
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

Map_setting map_setting;
Window_setting window_setting;
Logos logos;
Main_menu main_menu;
Tutorial tutorial;
Player_setting player_setting;
//Shooting_update shooting_update;

void on_key_pressed(KeyboardButtons button);
void on_key_released(KeyboardButtons button);

int main()
{
	window_setting.setting();

	vector<Shooting*> bullets;
	vector<Enemy*> enemys;
	vector<TutoEnemy*> tutoenemys;

	Player* player = new Player{ 0, 0 };

	map_setting.char_pos(player);

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
			logos.digipen_logo();
			if (scene_timer > digipenlogo_check)
			{
				scene += 1;
			}
		}

		//TEAM HATCHLING
		if (scene == 1)
		{
			logos.team_logo();
			if (scene_timer > teamlogo_check)
			{
				scene += 1;
			}
		}

		//Main Menu
		if (scene == 2)
		{
			main_menu.main_UI();

			//Gameplay
			if (main_menu.is_gameplay())
			{
				scene = 6;
			}
			//Settings
			if (main_menu.is_setting())
			{
				scene = 3;
			}
			//Credits
			if (main_menu.is_credit())
			{
				scene = 4;
			}
			//Exit
			if (main_menu.is_exit())
			{
				scene = 5;
			}
		}

		//Settings
		if (scene == 3)
		{
			main_menu.in_setting();
			if (main_menu.is_in_setting())
			{
				scene = 2;
			}
		}

		//Credits
		if (scene == 4)
		{
			main_menu.in_credit();
			if (main_menu.is_in_credit())
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
			map_setting.map_creating();

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
				tutorial.scene1_guideline();
				player_setting.move_limit(player);

				if (tutorial.is_clear_scene1(player))
				{
					tutorial_scene = 2;
				}
			}

			//Third Scene(Shoot)			
			if (tutorial_scene == 2)
			{
				tutorial.scene2_guideline();
				player_setting.move_limit(player);

				//bullet_create
				//shooting_update.bullet_create(bullets, player);
				if (!MouseIsPressed) {
					not_clicked = true;
				}
				if (MouseIsPressed && not_clicked == true)
				{
					//bullet_create
					bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
					not_clicked = false;
				}

				if (bullets.size() >= 5)
				{
					tutorial_scene = 3;
				}

				//bullet draw
				for (int i = 0; i < bullets.size(); i++)
				{
					push_settings();
					bullets[i]->draw();
					bullets[i]->FireBullet();
					doodle::pop_settings();
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
				player_setting.move_limit(player);

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
					doodle::pop_settings();

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
					doodle::pop_settings();

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
				doodle::pop_settings();
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
					doodle::pop_settings();
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
			doodle::draw_text(to_string(chap1_point) + " / 20", score_width, score_height);
			doodle::pop_settings();

			player->MOVE();
			player->draw_chara();

		}

		//Tutorial_black scene	
		if (scene == 8)
		{
			clear_background(255);

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
			
			player->MOVE();
			player->draw_chara();

			/*	if (KeyIsPressed && Key == KeyboardButtons::R)
				{
					set_rectangle_mode(RectMode::Center);
					draw_rectangle(player->chara_pos_x, player->chara_pos_y - 100, 400, 100);
				}*/



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
					doodle::pop_settings();
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
					doodle::pop_settings();
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
					doodle::pop_settings();
					box3Check += 0.3;
				}
			}

			//임시로 확인용 (멈추기/ 느려지게하기)
			if (get_mouse_x() > 500 && get_mouse_x() < 1100 && get_mouse_y() > 500 && get_mouse_y() < 700)
			{

			}

			draw_rectangle(500, 500, 600, 200);
		}
	}
	return 0;

	void reset();
}

void reset()
{

}
