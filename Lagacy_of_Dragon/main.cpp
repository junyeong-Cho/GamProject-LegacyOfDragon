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
#include "Camera.h"


#include "bomb_weapon.h"
#include "back_weapon.h"
#include "ice_weapon.h"
#include "breath_weapon.h"
#include "approach_weapon.h"
#include "storm_weapon.h"
#include "meteor_weapon.h"

#include "stage2_boss.h"
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
int scene = 1;
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

//-------------------------------// Roulette

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
Breath_update breath_update; 

Storm_update storm_update;
Ice_update ice_update;
Shooting_update shooting_update;
Approach_update approach_update; 
Meteor_update meteor_update;
Bomb_update bomb_update;
Back_update back_update;

Enemy_update_tuto enemy_update_tuto;
Enemy_update_1_1 enemy_update_1_1;
Enemy_update_1_2 enemy_update_1_2;
Enemy_update_1_3 enemy_update_1_3;
Enemy_update_2_1 enemy_update_2_1;
Enemy_update_2_2 enemy_update_2_2;
Enemy_update_2_3 enemy_update_2_3;


S2boss_update s2boss_update;

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
	vector<Meteor*> meteor;


	vector<Enemy*> enemys_tuto;
	vector<Enemy*> enemys_1_1;
	vector<Enemy*> enemys_1_3;
	vector<Enemy*> enemys_2_1;
	vector<Enemy_attack*> enemy_attack;

	const vector<int> randomboxloc = { 500, 650, 800 };
	const vector<int> ultraboxloc = { 600, 750 };
	const vector<int> sixboxloc = { 450, 550, 650, 750, 850, 950};

	Player* player = new Player{ Width / 2, Height / 2, 0, 0 };
	Camera* camera = new Camera{ 0, 0 };

	Stage1_boss* stage_boss1 = new Stage1_boss{ boss1_x,boss1_y, s1bossSize, boss1_hp, s1_boss_vel };
	Stage2_boss* stage_boss2 = new Stage2_boss{ boss2_x,boss2_y, s2bossSize, boss2_hp };

	map_setting.char_pos1(camera);


	while (!is_window_closed())
	{
		timer += DeltaTime;
		int_timer += DeltaTime;
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

				enemy_update_tuto.enemy_move(enemys_tuto, player);

				//bullet draw
				shooting_update.bullet_draw(bullets);

				//Bullet Remove
				shooting_update.bullet_remove(bullets);

				//Bullet Enemy Check
				interaction.bullet_enemy_interaction(enemys_tuto, bullets);

				if (count_enemy - enemys_tuto.size() == 1) {
					score++;
					count_enemy = enemys_tuto.size();
				}
				else {
					count_enemy = enemys_tuto.size();
				}

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

			if (count_enemy - enemys_1_1.size() == 1) {
				chap1_point--;
				count_enemy = enemys_1_1.size();
			}
			else {
				count_enemy = enemys_1_1.size();
			}

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

		//Stage 1-1
		if (scene == 10)
		{

		}
		//Stage 1-2
		if (scene == 11)
		{

		}
		//Stage 1-2
		if (scene == 12)
		{

		}
		//Stage 1-3
		if (scene == 13)
		{

		}
		//Stage 2-1
		if (scene == 14)
		{

		}
		//Stage 2-2
		if (scene == 15)
		{

		}
		//Stage 2-3
		if (scene == 16)
		{

		}
		//Stage 3-1
		if (scene == 17)
		{

		}
		//Stage 3-2
		if (scene == 18)
		{

		}
		//Stage 3-3
		if (scene == 19)
		{

		}



		//BigSize Map 36 * 36 (Its lagging ,its under development) -- Try to Release Mod 

		if (scene == 30)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;
			
			//Player move limit
			player_setting.move_limit(player);

			//Bullet_shooting
			shooting_update.bullet_create(bullets, player);

			//Draw Map
			clear_background(255);
			camera->camera_generate();
			map_setting.stage1_creating(camera);

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

			camera->camera_move();

			player->MOVE();
			player->draw_fix_chara();
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

		/*	approach_update.bullet_create(approach, player);
			approach_update.bullet_draw(approach);
			approach_update.bullet_remove(approach);*/

			/*breath_update.bullet_create(breath, player);
			breath_update.bullet_draw(breath, player);
			breath_update.bullet_remove(breath);*/

		/*	storm_update.bullet_create(storm, player);
			storm_update.bullet_draw(storm);
			storm_update.bullet_remove(storm);*/

			back_update.bullet_create(knockback, player);
			back_update.bullet_draw(knockback);
			back_update.bullet_remove(knockback);
			back_update.coolTime(knockback, player);

		/*	ice_update.bullet_create(ice, player);
			ice_update.bullet_draw(ice);
			ice_update.bullet_remove(ice);*/
			
			/*ice_update.bullet_create(ice, player);
			ice_update.bullet_draw(ice);
			ice_update.bullet_remove(ice);
			ice_update.coolTime(ice, player);*/

			//uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			//uisetting.roulette(randomboxloc);
			//uisetting.roulette_ult(ultraboxloc);
			//uisetting.roulette_six(sixboxloc);

			interaction.storm_enemy_interaction(enemys_1_1,storm);
			interaction.ice_enemy_interaction(enemys_1_1, ice);
			interaction.back_enemy_interaction(enemys_1_1, knockback, player);
			interaction.breath_enemy_interaction(enemys_1_1, breath, player);
			interaction.bomb_enemy_interaction(enemys_1_1, bombs);
			interaction.approach_enemy_interaction(enemys_1_1, approach);
			interaction.meteor_enemy_interaction(enemys_1_1, meteor);

			player->MOVE();
			player->draw_chara();
			player->hp_chara(&scene);
		}

		if (scene == 21)
		{
			player_setting.move_limit(player);
			map_setting.map_creating();

			shooting_update.bullet_create(bullets, player);
			shooting_update.bullet_create(bullets, player);
			shooting_update.bullet_draw(bullets);

			/*stage_boss1->draw();
			stage_boss1->move();
			stage_boss1->hp(&scene);
			*/

			stage_boss2->draw();
			stage_boss2->move();
			stage_boss2->hp(&scene);

		    s2boss_update.s2_boss_attack(stage_boss2, player);

			interaction.player_boss1_interaction(stage_boss1, bullets);
			interaction.player_boss2_interaction(stage_boss2, bullets);
			interaction.boss2_player_interaction(stage_boss2, player);

			player->MOVE();
			player->draw_chara();
			player->hp_chara(&scene);
		}
	}
	return 0;
}

//브레스 그리기
//조립하기
//룰렛고치기
//넉백 고치기
//무기 줍기

