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


#include "bomb_weapon.h"
#include "back_weapon.h"
#include "ice_weapon.h"
#include "breath_weapon.h"
#include "approach_weapon.h"
#include "storm_weapon.h"
#include "auto_weapon.h"


#include "stage1_boss.h"

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
int scene = 20;
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

Enemy_update enemy_update;
Interaction interaction;
UIsetting uisetting;


//미완성
Bomb_update bomb_update; // 여러마리 죽이는 방법 찾는중
Auto_update auto_update; // 벡터 범위 문제

Breath_update breath_update; //충돌체크

Back_update back_update; // 밀려나고 다시 속도가 안바뀜


//완성
Storm_update storm_update;
Ice_update ice_update;
Shooting_update shooting_update;
Approach_update approach_update; 


Enemy_update_tuto enemy_update_tuto;
Enemy_update_1_1 enemy_update_1_1;
Enemy_update_1_2 enemy_update_1_2;
Enemy_update_1_3 enemy_update_1_3;
Enemy_update_2_1 enemy_update_2_1;
Enemy_update_2_2 enemy_update_2_2;
Enemy_update_2_3 enemy_update_2_3;


Stage1_boss stage1_boss;
//
//enum Weapons
//{
//	Shootings = 0,
//	Storms = 1,
//	Ices = 2,
//	Knockbacks = 3,
//	Bombs = 4,
//	Approachs = 5,
//	Autos = 6,
//	Breaths = 7,
//};
//
//Weapons state = Weapons::Breaths;

//Diagonal move
void on_key_pressed(KeyboardButtons button);
void on_key_released(KeyboardButtons button);

int main()
{
	window_setting.setting();

	vector<Shooting*> bullets;
	vector<BombWeapon*> bombs;
	vector<BackWeapon*> knockback;
	vector<IceWeapon*> ice;
	vector<BreathWeapon*> breath;
	vector<Storm*> storm;
	vector<Approach*> approach;
	vector<AutoWeapon*> autos;

	vector<Stage1_boss*> boss1;
	vector<Enemy*> enemys_tuto;
	vector<Enemy*> enemys_1_1;
	vector<Enemy*> enemys_1_3;
	vector<Enemy*> enemys_2_1;
	vector<Enemy_attack*> enemy_attack;

	vector<int> randomboxloc = { 500, 700, 900 };

	Player* player = new Player{ 0, 0 };
	

	map_setting.char_pos(player);

	while (!is_window_closed())
	{
		timer += DeltaTime;
		int_timer += DeltaTime;
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

		//Tutorial with story telling
		if (scene == 6)
		{
			map_setting.map_creating();
			if (textbox == 0)
			{
				tutorial.textbox1();
			}
			if (textbox == 1)
			{
				tutorial.textbox2();
			}
			if (textbox == 2)
			{
				tutorial.textbox3();
			}
			if (textbox == 3)
			{
				tutorial.textbox4();
			}
			if (textbox == 4)
			{
				tutorial.textbox5();
			}
			if (textbox == 5)
			{
				tutorial.textbox6();
			}
			if (textbox == 6)
			{
				tutorial.textbox7();
			}
			if (textbox == 7)
			{
				tutorial.textbox8();
			}
			if (textbox == 8)
			{
				tutorial.textbox9();
			}
			if (textbox == 9)
			{
				tutorial_scene = 1;
				scene = 7;
			}
		}

		//Tutorial
		if (scene == 7)
		{
			map_setting.map_creating();

			//First Scene(Shoot)			
			if (tutorial_scene == 1)
			{
				player->chara_pos_x = 300;
				player->chara_pos_y = 300;

				tutorial.scene1_guideline();
				player_setting.move_limit(player);

				//bullet_create
				shooting_update.bullet_create(bullets, player);
				if (bullets.size() >= 5)
				{
					tutorial_scene = 2;
				}

				//bullet draw
				shooting_update.bullet_draw(bullets);

				//Bullet Remove
				shooting_update.bullet_remove(bullets);
			}

			//Fourth Scene (Kill Enemies)
			if (tutorial_scene == 2)
			{
				tutorial.scene2_guideline();

				//Player move limit
				player_setting.move_limit(player);

				//Bullet_shooting
				shooting_update.bullet_create(bullets, player);

				//Create Enemy
				enemy_update_tuto.enemy_create(enemys_tuto, 5);
				enemy_update_1_3.enemy_create(enemys_1_3, 3);
				enemy_update_2_1.enemy_create(enemys_2_1, 5);

				//Enemy Move
				enemy_update_tuto.enemy_move(enemys_tuto, player);
				enemy_update_1_3.enemy_move(enemys_1_3, player);
				enemy_update_2_1.enemy_move(enemys_2_1, player);

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
					scene = 8;
				}
			}
		}

		//Tutorial_last
		if (scene == 8)
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
				scene = 9;
			}

			//Draw point
			uisetting.ui_point();

			player->MOVE();
			player->draw_chara();
			player->hp_chara(&scene);
		}

		//Tutorial_black scene   
		if (scene == 9)
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
				scene = 10;
			}
		}

		//BigSize Map 36 * 36 (Its lagging ,its under development) -- Try to Release Mod 
		if (scene == 10)
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

		//Experiment boss
		if (scene == 20)
		{
			//Player move limit
			player_setting.move_limit(player);

			//Bullet_shooting
			//bomb_update.bullet_create(bombs, player);

			//Draw Map
			map_setting.map_creating();
			enemy_update.enemy_move(enemys_1_1, player);

			enemy_update.enemy_create(enemys_1_1, 20);

			draw_rectangle(player->chara_pos_x - 100, player->chara_pos_y, 100, 100);

		
			breath_update.bullet_create(breath, player);
			breath_update.bullet_draw(breath, player);
			breath_update.bullet_remove(breath);

		/*	storm_update.bullet_create(storm, player);
			storm_update.bullet_draw(storm);
			storm_update.bullet_remove(storm);*/

			
			/*auto_update.bullet_create(autos, player);
			auto_update.bullet_move(autos, enemys_1_1, player);*/

		    //bomb_update.bullet_draw(bombs);
			//bomb_update.bullet_create(bombs, player);
			
			
			/*approach_update.bullet_create(approach,player);
			approach_update.bullet_draw(approach);
			approach_update.bullet_remove(approach);*/


			//interaction.approach_enemy_interaction(enemys_1_1, approach);
			interaction.storm_enemy_interaction(enemys_1_1,storm);
			interaction.ice_enemy_interaction(enemys_1_1, ice);
			interaction.back_enemy_interaction(enemys_1_1, knockback);
			interaction.breath_enemy_interaction(enemys_1_1, breath, player);
			interaction.auto_enemy_interaction(enemys_1_1, autos);
			interaction.bomb_enemy_interaction(enemys_1_1, bombs);
			interaction.approach_enemy_interaction(enemys_1_1, approach);



			//Boss move
		    //stage1_boss.draw();
			//stage1_boss.move();


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
