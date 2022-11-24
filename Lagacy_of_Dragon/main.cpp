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
#include "Interaction.h"
#include "UIsetting.h"

using namespace std;
using namespace doodle;

//--------------------------------// Timer for scene
double scene_timer = 0;
double tutorial_timer = 0;
int digipenlogo_check = 2;
int teamlogo_check = 7;
int tutorial_check = 2;
//--------------------------------// Tutorial Scene 
int clicked_check = 0;
//--------------------------------// Scene
int scene = 0;
int tutorial_scene = 0;
//--------------------------------//Bullet
double bullet_timer = 0;
int bullet_check = 4;
int bullet_max = 5;
//--------------------------------// Enemy const
constexpr int enemyWidth = 10;
constexpr int enemyHeight = 10;
//--------------------------------// bool
bool enemy_check = false;
bool bullet_draw_check = false;
bool player_die_check = false;
bool tutorial_scene3 = false;
//--------------------------------// MeEnemyCollision
bool player_enemy_check = false;



Map_setting map_setting;
Window_setting window_setting;
Logos logos;
Main_menu main_menu;
Tutorial tutorial;
Player_setting player_setting;
Shooting_update shooting_update;
Enemy_update enemy_update;
Interaction interaction;
UIsetting uisetting;

//Diagonal move
void on_key_pressed(KeyboardButtons button);
void on_key_released(KeyboardButtons button);

int main()
{
	window_setting.setting();

	vector<Shooting*> bullets;
	vector<Enemy_tuto*> enemys_tuto;
	vector<Enemy_1_1*> enemys_1_1;
	vector<Enemy_1_3*> enemys_1_3;
	vector<Enemy_2_1*> enemys_2_1;
	vector<Enemy_attack*> enemy_attack;

	vector<int> randomboxloc = { 500, 700, 900 };

	Player* player = new Player{ 0, 0 };

	map_setting.char_pos(player);

	while (!is_window_closed())
	{
		timer += DeltaTime;
		int_timer = +DeltaTime;
		bullet_timer += DeltaTime;
		scene_timer += DeltaTime;
		update_window();

		//cout << scene << endl;

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
				shooting_update.bullet_create(bullets, player);
				if (bullets.size() >= 5)
				{
					tutorial_scene = 3;
				}

				//bullet draw
				shooting_update.bullet_draw(bullets);

				//Bullet Remove
				shooting_update.bullet_remove(bullets);
			}

			//Fourth Scene (Kill Enemies)
			if (tutorial_scene == 3)
			{
				tutorial.scene3_guideline();

				//Player move limit
				player_setting.move_limit(player);

				//Bullet_shooting
				shooting_update.bullet_create(bullets, player);


				//Create Enemy
				enemy_update.enemy_create(enemys_tuto);
				enemy_update.enemy_create(enemys_1_3, 3);
				enemy_update.enemy_create(enemys_2_1, 5);


				//Enemy Move
				enemy_update.enemy_move(enemys_tuto, player);
				enemy_update.enemy_move(enemys_1_3, player);
				enemy_update.enemy_move(enemys_2_1, player);

				//Enemy attack
				enemy_update.attack_create(enemy_attack, enemys_1_3, *player);
				enemy_update.attack_draw(enemy_attack);
				enemy_update.attack_remove(enemy_attack);

				//bullet draw
				shooting_update.bullet_draw(bullets);

				//Bullet Remove
				shooting_update.bullet_remove(bullets);

				//Bullet Enemy Check
				interaction.bullet_enemy_interaction(enemys_tuto, bullets);
				interaction.bullet_enemy_interaction(enemys_1_3, bullets);
				interaction.bullet_enemy_interaction(enemys_2_1, bullets);

				//Me Enemy check
				interaction.player_enemy_interaction(enemys_1_1, player);

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

			//Player move limit
			player_setting.move_limit(player);

			//Bullet_shooting
			shooting_update.bullet_create(bullets, player);

			//Draw Map
			map_setting.map_creating();

			//Create bullet
			shooting_update.bullet_create(bullets, player);
			shooting_update.bullet_draw(bullets);

			//Bullet Remove
			shooting_update.bullet_remove(bullets);

			//Random enemy
			enemy_update.enemy_create(enemys_1_1, 10);

			//Enemy move
			enemy_update.enemy_move(enemys_1_1, player);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);


			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets);

			//Move next chapter
			if (chap1_point == 0)
			{
				scene = 8;
			}

			//Draw point
			uisetting.ui_point();

			player->MOVE();
			player->draw_chara();
			player->hp_chara(&scene);
		}

		//Tutorial_black scene   
		if (scene == 8)
		{
			clear_background(255);

			//Draw Map
			map_setting.map_creating();

			player->MOVE();
			player->draw_chara();
			if (randomScene == 0)
			{
				uisetting.roulette(randomboxloc);
			}

			//Next stage
			push_settings();
			set_fill_color(HexColor{ 0x0000FFFF });
			draw_rectangle(1200, 700, 100, 50);
			pop_settings();

			//Next stage 
			if (get_mouse_x() > 1200 && get_mouse_x() < 1300 + randomboxSize && get_mouse_y() > 700 && get_mouse_y() < 750 && MouseIsPressed)
			{
				scene = 9;
			}
		}

		//BigSize Map 36 * 36 (Its lagging ,its under development) -- Try to Release Mod 
		if (scene == 9)
		{
			//Player move limit
			player_setting.move_limit(player);

			//Bullet_shooting
			shooting_update.bullet_create(bullets, player);

			//Draw Map
			map_setting.stage1_creating();

			//Create bullet
			shooting_update.bullet_create(bullets, player);

			shooting_update.bullet_draw(bullets);

			//Bullet Remove
			shooting_update.bullet_remove(bullets);

			//Random enemy
			enemy_update.enemy_create(enemys_1_1, 20);

			//Enemy move
			enemy_update.enemy_move(enemys_1_1, player);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets);

			player->MOVE();
			player->draw_chara();
			player->hp_chara(&scene);

		}
	}
	return 0;

	void reset();
}

void reset()
{

}
