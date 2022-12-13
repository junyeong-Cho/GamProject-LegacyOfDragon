#include <Windows.h>

#include <doodle/doodle.hpp>
//#include <SFML/Audio.hpp>
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

#include "stage3_boss.h"
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
//int scene = 10;
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
S3boss_update s3boss_update;

//sf::Music background_music;
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
inline int back_color1=0;
inline int update = 0;
inline int count_once_debug = 0;

void cmd_debug_mod(Camera* camera, Player* player) {
//	int scene_controll;
	system("cls");
	cout << "width: " << Width << "\t height: " << Height << endl;
	cout << "player x: " << player->chara_pos_x << "\t player y: " << player->chara_pos_y << endl;
	cout << "camera x: " << camera->x << "\tcamera y: " << camera->y << endl;
	cout << "mouse x:" << get_mouse_x() << "\tmouse y: " << get_mouse_y() << endl;
	cout << "jewel count: "<< jewel_count << endl;
	cout << "enemy death1: " << enemy_death1 << endl;
	cout << "enemy death2: " << enemy_death2 << endl;
	cout << "enemy death3: " << enemy_death3 << endl;
	cout << "quest complite: " << quest_complite << endl;
	cout << "tile[x]: " << static_cast<int>((camera->x - camera->offsetX)/tile_size) << endl;
	cout << "tile[y]: " << static_cast<int>((camera->y - camera->offsetY)/tile_size) << endl;
	cout << "timer" <<timer << endl;
	cout << "scene :" << scene << endl;
//	cin >> scene_controll;
//	scene = scene_controll;
}

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
	vector<Enemy*> enemys_1_2;
	vector<Enemy*> enemys_1_3;
	vector<Enemy*> enemys_2_1;
	vector<Enemy*> enemys_2_2;
	vector<Enemy*> enemys_2_3;

	vector<Enemy_attack*> enemy_attack;
	vector<Boss_attack*> boss_attack;

	const vector<int> randomboxloc = { 500, 650, 800 };
	const vector<int> ultraboxloc = { 600, 750 };
	const vector<int> sixboxloc = { 450, 550, 650, 750, 850, 950};

	Player* player = new Player{ Width / 2, Height / 2, 2, 20 };
	Camera* camera = new Camera{ 0, 0 };

	Stage1_boss* stage_boss1 = new Stage1_boss{ boss1_x,boss1_y, s1bossSize, (int)boss1_hp, s1_boss_vel };
	Stage2_boss* stage_boss2 = new Stage2_boss{ boss2_x,boss2_y, s2bossSize, (int)boss2_hp };
	Stage3_boss* stage_boss3 = new Stage3_boss{ boss3_x,boss3_y, s3bossSize, (int)boss3_hp, s3_boss_vel };


	map_setting.char_pos1(camera);


	while (!is_window_closed())
	{
		timer += DeltaTime;
		int_timer += DeltaTime;
		bullet_timer += DeltaTime;
		scene_timer += DeltaTime;
		boss3_timers += DeltaTime;
		update_window();
		if (int_timer%2==1 && count_once_debug != int_timer){
		cmd_debug_mod(camera, player);
		count_once_debug = int_timer;
		}

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
				draw_image(Gameplay_button_on, mainmenu_x, gameplay_y);
				if (MouseIsPressed) {
					tutorial_scene = 1;
					scene = 7;
					player->chara_pos_x = 300;
					player->chara_pos_y = 300;
				}
			}
			//Settings
			if (main_menu.is_setting())
			{
				draw_image(Howtoplay_button_on, mainmenu_x, setting_y);
				if (MouseIsPressed)
				scene = 3;
			}
			//Credits
			if (main_menu.is_credit())
			{
				draw_image(Credit_button_on, mainmenu_x, credit_y);
				if (MouseIsPressed)
				scene = 4;
			}
			//Exit
			if (main_menu.is_exit())
			{
				draw_image(Exit_button_on, mainmenu_x, exit_y);
				if (MouseIsPressed)
				scene = 5;
			}
		}

		//Settings
		if (scene == 3)
		{
			uisetting.howtoplay(&scene);
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
		//if (scene == 6)
		//{
		//	map_setting.map_creating();
		//	if (textbox == 0)
		//	{
		//		tutorial.textbox1();
		//	}
		//	/*if (textbox == 1)
		//	{
		//		tutorial.textbox2();
		//	}*/
		//	if (textbox == 2)
		//	{
		//		tutorial.textbox3();
		//	}
		//	if (textbox == 3)
		//	{
		//		tutorial.textbox4();
		//	}
		//	if (textbox == 4)
		//	{
		//		tutorial.textbox5();
		//	}
		//	if (textbox == 5)
		//	{
		//		tutorial.textbox6();
		//	}
		//	if (textbox == 6)
		//	{
		//		tutorial.textbox7();
		//	}
		//	if (textbox == 7)
		//	{
		//		tutorial.textbox8();
		//	}
		//	if (textbox == 8)
		//	{
		//		tutorial.textbox9();
		//	}
		//	if (textbox == 1)
		//	{
		//		tutorial_scene = 1;
		//		player->chara_pos_x = 300;
		//		player->chara_pos_y = 300;
		//		scene = 7;
		//	}
		//}

		//Tutorial
		if (scene == 7)
		{
			map_setting.map_creating();
			//First Scene(Shoot)			
			if (tutorial_scene == 1)
			{

				tutorial.scene1_guideline();
				player_setting.move_limit(player);
				//player_setting.move_fix_limit(camera);

				//bullet_create
				shooting_update.bullet_create(bullets, player);
				if (bullets.size() >= 1)
				{
					tutorial_scene = 2;
				}

				//bullet draw
				shooting_update.bullet_draw(bullets);

				//Bullet Remove
				shooting_update.bullet_remove(bullets);
				player->MOVE();
				player->draw_chara();
				player->hp_chara();
			}

			//Fourth Scene (Kill Enemies)
			if (tutorial_scene == 2)
			{
				tutorial.scene2_guideline();

				//Player move limit
				player_setting.move_limit(player);
			//	player_setting.move_fix_limit(camera);

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
				interaction.bullet_enemy_interaction(enemys_tuto, bullets, &enemy_death1);

				if (count_enemy - enemys_tuto.size() == 1) {
					score++;
					count_enemy = enemys_tuto.size();
				}
				else {
					count_enemy = enemys_tuto.size();
				}
				map_setting.tuto_controll(player);
				player->MOVE();
				player->draw_chara();
				player->hp_chara();
				//Move to Tutorial_last
				
			}
		}

		//Tutorial_last
		if (scene == 8)
		{
			//Player move limit
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);

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
			enemy_update_1_1.enemy_create(enemys_1_1, 10);

			//Enemy move
			enemy_update_1_1.enemy_move(enemys_1_1, player);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death1);

			if (count_enemy - enemys_1_1.size() == 1) {
				chap1_point--;
				count_enemy = enemys_1_1.size();
			}
			else {
				count_enemy = enemys_1_1.size();
			}

			//Move next chapter
			if (chap1_point <= 0)
			{
				scene = 10;
			}

			//Draw point
			uisetting.ui_point();
			

			player->MOVE();
			player->draw_chara();
			player->hp_chara();
		}

		//How To Play   
		if (scene == 9)
		{
			
		}

		//Stage 1-1
		if (scene == 10)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;
			//Player move limit
			player_setting.move_limit(player);
			//player_setting.move_fix_limit(camera);
			//Draw Map
			clear_background(HexColor{0xc4d37dff});
			camera->camera_generate();

			//weapon_choice = 3;
			map_setting.stage1_creating(camera);
			map_setting.stage1_controll(camera);
			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 3);
			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_1_1, ice,&enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death1);

			if(jewel_count ==0){
			shooting_update.bullet_create(bullets, player);
			shooting_update.bullet_draw(bullets);
			shooting_update.bullet_remove(bullets);
			shooting_update.coolTime(player);
			}
			//Quest
			//uisetting.enemy_quest(enemy1, 5);
			uisetting.enemy_quest(enemy1, 1);

			if(jewel_count ==1){
			
			uisetting.roulette(randomboxloc);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			uisetting.RcoolTime(player);
			}
			uisetting.this_stage(1, 1);

			
			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Stage 1-2
		if (scene == 11)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;
			
		
			//Player move limit
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);

			//Draw Map
			clear_background(HexColor{ 0xc4d37dff });
			camera->camera_generate();
			map_setting.stage2_creating(camera);
			map_setting.stage2_controll(camera);

			//uisetting.enemy_quest(enemy1, 10, enemy2, 5);
			uisetting.enemy_quest(enemy1, 1, enemy2, 1);
			uisetting.this_stage(1, 2);

			//Create bullet
			
			uisetting.roulette(randomboxloc);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			uisetting.RcoolTime(player);

			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 7);
			enemy_update_1_2.enemy_create(enemys_1_2, 3);

			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);
			enemy_update_1_2.enemy_fix_move(enemys_1_2, player);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets,&enemy_death1);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets,&enemy_death2);

			interaction.ice_enemy_interaction(enemys_1_1, ice ,&enemy_death1);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death2);

			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death2);
			
			

			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Stage 1-3
		if (scene == 12)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;

			//Player move limit
			player_setting.move_limit(player);

			//Draw Map
			clear_background(HexColor{ 0x8de3ffff });
			camera->camera_generate();
			map_setting.stage3_creating(camera);
			map_setting.stage3_controll(camera);
			//Create bullet
			
			if (jewel_count == 2) {
				uisetting.roulette_six(sixboxloc);
				uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
				uisetting.ScoolTime(player);
			}
			else {
				uisetting.roulette(randomboxloc);
				uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
				uisetting.RcoolTime(player);
			}

			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 7);
			enemy_update_1_2.enemy_create(enemys_1_2, 3);
			enemy_update_1_3.enemy_create(enemys_1_3, 1);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);

			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);
			enemy_update_1_2.enemy_fix_move(enemys_1_2, player);
			enemy_update_1_3.enemy_fix_move(enemys_1_3, player);

			enemy_update_1_3.attack_create(enemy_attack,enemys_1_3, *player);
			enemy_update_1_3.attack_draw(enemy_attack);
			enemy_update_1_3.attack_remove(enemy_attack);


			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);
			interaction.player_enemy_interaction(enemys_1_3, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_1_3, bullets, &enemy_death3);

			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_1_3, ice, &enemy_death3);

			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_1_3, storm, &enemy_death3);

			uisetting.enemy_quest(enemy1, 1, enemy2, 1, enemy3, 1);
			uisetting.this_stage(1, 3);

			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Stage 2-1
		if (scene == 13)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;

			//Player move limit
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);
			//Draw Map
			clear_background(HexColor{ 0x8de3ffff });
			camera->camera_generate();
			map_setting.stage4_creating(camera);
			map_setting.stage4_controll(camera);
			//Create bullet
			if (jewel_count == 3) {
				uisetting.roulette_ult(ultraboxloc);
				uisetting.UcoolTime(player);
			}
			uisetting.roulette_six(sixboxloc);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			uisetting.ScoolTime(player);

			


			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 2);
			enemy_update_1_2.enemy_create(enemys_1_2, 2);
			enemy_update_1_3.enemy_create(enemys_1_3, 1);
			enemy_update_2_1.enemy_create(enemys_2_1, 1);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);
			enemy_update.enemy_remove(enemys_2_1);

			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);
			enemy_update_1_2.enemy_fix_move(enemys_1_2, player);
			enemy_update_1_3.enemy_fix_move(enemys_1_3, player);
			enemy_update_2_1.enemy_fix_move(enemys_2_1, player);
			
			enemy_update_1_3.attack_create(enemy_attack, enemys_1_3, *player);
			enemy_update_1_3.attack_draw(enemy_attack);
			enemy_update_1_3.attack_remove(enemy_attack);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);
			interaction.player_enemy_interaction(enemys_1_3, player);
			interaction.player_enemy_interaction(enemys_2_1, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_1_3, bullets, &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_2_1, bullets, &enemy_death3);


			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_1_3, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_2_1, ice, &enemy_death3);


			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_3, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_2_1, storm, &enemy_death3);

		
			interaction.approach_enemy_interaction(enemys_1_1, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_2, approach, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_1_3, approach, &enemy_death2);
			interaction.approach_enemy_interaction(enemys_2_1, approach, &enemy_death3);

			
			interaction.bomb_enemy_interaction(enemys_1_1, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_2, bombs, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_1_3, bombs, &enemy_death2);
			interaction.bomb_enemy_interaction(enemys_2_1, bombs, &enemy_death3);

			interaction.back_enemy_interaction(enemys_1_1, knockback, player);
			interaction.back_enemy_interaction(enemys_1_2, knockback, player);
			interaction.back_enemy_interaction(enemys_1_3, knockback, player);
			interaction.back_enemy_interaction(enemys_2_1, knockback, player);
			
			uisetting.enemy_quest(enemy2, 1, enemy3, 1, enemy4, 1);

			uisetting.this_stage(2, 1);

			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Stage 2-2
		if (scene == 14)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;

			//Player move limit
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);
			//Draw Map
			clear_background(HexColor{ 0xc4d37dff });
			camera->camera_generate();
			map_setting.stage5_creating(camera);
			map_setting.stage5_controll(camera);

			//Create bullet
			
			uisetting.roulette_six(sixboxloc);
			uisetting.ScoolTime(player);
			uisetting.roulette_ult(ultraboxloc);
			uisetting.UcoolTime(player);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			
			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 1);
			enemy_update_1_2.enemy_create(enemys_1_2, 1);
			enemy_update_1_3.enemy_create(enemys_1_3, 1);
			enemy_update_2_1.enemy_create(enemys_2_1, 1);
			enemy_update_2_2.enemy_create(enemys_2_2, 1);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);
			enemy_update.enemy_remove(enemys_2_1);
			enemy_update.enemy_remove(enemys_2_2);


			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);
			enemy_update_1_2.enemy_fix_move(enemys_1_2, player);
			enemy_update_1_3.enemy_fix_move(enemys_1_3, player);
			enemy_update_2_1.enemy_fix_move(enemys_2_1, player);
			enemy_update_2_2.enemy_fix_move(enemys_2_2, player);

			enemy_update_1_3.attack_create(enemy_attack, enemys_1_3, *player);
			enemy_update_1_3.attack_draw(enemy_attack);
			enemy_update_1_3.attack_remove(enemy_attack);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);
			interaction.player_enemy_interaction(enemys_1_3, player);
			interaction.player_enemy_interaction(enemys_2_1, player);
			interaction.player_enemy_interaction(enemys_2_2, player);


			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_3, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_2_1, bullets, &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_2_2, bullets, &enemy_death3);


			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_3, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_2_1, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_2_2, ice, &enemy_death3);


			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_3, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_2_1, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_2_2, storm, &enemy_death3);


			interaction.approach_enemy_interaction(enemys_1_1, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_2, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_3, approach, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_2_1, approach, &enemy_death2);
			interaction.approach_enemy_interaction(enemys_2_2, approach, &enemy_death3);


			interaction.bomb_enemy_interaction(enemys_1_1, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_2, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_3, bombs, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_2_1, bombs, &enemy_death2);
			interaction.bomb_enemy_interaction(enemys_2_2, bombs, &enemy_death3);


			interaction.back_enemy_interaction(enemys_1_1, knockback, player);
			interaction.back_enemy_interaction(enemys_1_2, knockback, player);
			interaction.back_enemy_interaction(enemys_1_3, knockback, player);
			interaction.back_enemy_interaction(enemys_2_1, knockback, player);
			interaction.back_enemy_interaction(enemys_2_2, knockback, player);
			
			uisetting.enemy_quest(enemy3, 1, enemy4, 1, enemy5, 1);

			uisetting.this_stage(2, 2);

			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Stage 2-3
		if (scene == 15)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;

			//Player move limit
			player_setting.move_limit(player);
			//player_setting.move_fix_limit(camera);
			//Draw Map
			clear_background(HexColor{ 0xc4d37dff });
			camera->camera_generate();
			map_setting.stage6_creating(camera);
			map_setting.stage6_controll(camera);
			
			uisetting.roulette_six(sixboxloc);
			uisetting.roulette_ult(ultraboxloc);
			uisetting.UcoolTime(player);
			uisetting.ScoolTime(player);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);


			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 4);
			enemy_update_1_2.enemy_create(enemys_1_2, 3);
			enemy_update_1_3.enemy_create(enemys_1_3, 2);
			enemy_update_2_1.enemy_create(enemys_2_1, 4);
			enemy_update_2_2.enemy_create(enemys_2_2, 2);
			enemy_update_2_3.enemy_create(enemys_2_3, 1);
			
			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);
			enemy_update.enemy_remove(enemys_2_1);
			enemy_update.enemy_remove(enemys_2_2);
			enemy_update.enemy_remove(enemys_2_3);


			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);
			enemy_update_1_2.enemy_fix_move(enemys_1_2, player);
			enemy_update_1_3.enemy_fix_move(enemys_1_3, player);
			enemy_update_2_1.enemy_fix_move(enemys_2_1, player);
			enemy_update_2_2.enemy_fix_move(enemys_2_2, player);
			enemy_update_2_3.enemy_fix_move(enemys_2_3, player);

			enemy_update_1_3.attack_create(enemy_attack, enemys_1_3, *player);
			enemy_update_1_3.attack_draw(enemy_attack);
			enemy_update_1_3.attack_remove(enemy_attack);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);
			interaction.player_enemy_interaction(enemys_1_3, player);
			interaction.player_enemy_interaction(enemys_2_1, player);
			interaction.player_enemy_interaction(enemys_2_2, player);
			interaction.player_enemy_interaction(enemys_2_3, player);



			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_3, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_2_1, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_2_2, bullets, &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_2_3, bullets, &enemy_death3);



			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_3, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_2_1, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_2_2, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_2_3, ice, &enemy_death3);



			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_3, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_2_1, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_2_2, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_2_3, storm, &enemy_death3);


			interaction.approach_enemy_interaction(enemys_1_1, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_2, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_3, approach, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_2_1, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_2_2, approach, &enemy_death2);
			interaction.approach_enemy_interaction(enemys_2_3, approach, &enemy_death3);


			interaction.bomb_enemy_interaction(enemys_1_1, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_2, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_3, bombs, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_2_1, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_2_2, bombs, &enemy_death2);
			interaction.bomb_enemy_interaction(enemys_2_3, bombs, &enemy_death3);


			interaction.back_enemy_interaction(enemys_1_1, knockback, player);
			interaction.back_enemy_interaction(enemys_1_2, knockback, player);
			interaction.back_enemy_interaction(enemys_1_3, knockback, player);
			interaction.back_enemy_interaction(enemys_2_1, knockback, player);
			interaction.back_enemy_interaction(enemys_2_2, knockback, player);
			interaction.back_enemy_interaction(enemys_2_3, knockback, player);


			interaction.meteor_enemy_interaction(enemys_1_1, meteor, &enemy_death4);
			interaction.meteor_enemy_interaction(enemys_1_2, meteor, &enemy_death4);
			interaction.meteor_enemy_interaction(enemys_1_3, meteor, &enemy_death1);
			interaction.meteor_enemy_interaction(enemys_2_1, meteor, &enemy_death4);
			interaction.meteor_enemy_interaction(enemys_2_2, meteor, &enemy_death2);
			interaction.meteor_enemy_interaction(enemys_2_3, meteor, &enemy_death3);


			interaction.breath_enemy_interaction(enemys_1_1, breath, player, &enemy_death4);
			interaction.breath_enemy_interaction(enemys_1_2, breath, player, &enemy_death4);
			interaction.breath_enemy_interaction(enemys_1_3, breath, player, &enemy_death1);
			interaction.breath_enemy_interaction(enemys_2_1, breath, player, &enemy_death4);
			interaction.breath_enemy_interaction(enemys_2_2, breath, player, &enemy_death2);
			interaction.breath_enemy_interaction(enemys_2_3, breath, player, &enemy_death3);

			uisetting.enemy_quest(enemy3, 1, enemy5, 1, enemy6, 1);

			uisetting.this_stage(2, 3);

			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Stage 3-1
		if (scene == 16)
		{
			player->chara_pos_x = Width / 2;
			player->chara_pos_y = Height / 2;

			//Player move limit
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);
			//Draw Map
			clear_background(HexColor{ 0xc4d37dff });
			camera->camera_generate();
			map_setting.stage7_creating(camera);
			map_setting.stage7_controll(camera);
			
			uisetting.roulette_six(sixboxloc);
			uisetting.roulette_ult(ultraboxloc);
			uisetting.UcoolTime(player);
			uisetting.ScoolTime(player);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);

			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 2);
			enemy_update_1_2.enemy_create(enemys_1_2, 2);
			enemy_update_1_3.enemy_create(enemys_1_3, 2);
			enemy_update_2_1.enemy_create(enemys_2_1, 2);
			enemy_update_2_2.enemy_create(enemys_2_2, 2);
			enemy_update_2_3.enemy_create(enemys_2_3, 2);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);
			enemy_update.enemy_remove(enemys_2_1);
			enemy_update.enemy_remove(enemys_2_2);
			enemy_update.enemy_remove(enemys_2_3);


			//Enemy move
			enemy_update_1_1.enemy_fix_move(enemys_1_1, player);
			enemy_update_1_2.enemy_fix_move(enemys_1_2, player);
			enemy_update_1_3.enemy_fix_move(enemys_1_3, player);
			enemy_update_2_1.enemy_fix_move(enemys_2_1, player);
			enemy_update_2_2.enemy_fix_move(enemys_2_2, player);
			enemy_update_2_3.enemy_fix_move(enemys_2_3, player);

			enemy_update_1_3.attack_create(enemy_attack, enemys_1_3, *player);
			enemy_update_1_3.attack_draw(enemy_attack);
			enemy_update_1_3.attack_remove(enemy_attack);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);
			interaction.player_enemy_interaction(enemys_1_3, player);
			interaction.player_enemy_interaction(enemys_2_1, player);
			interaction.player_enemy_interaction(enemys_2_2, player);
			interaction.player_enemy_interaction(enemys_2_3, player);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_1_3, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_2_1, bullets, &enemy_death4);
			interaction.bullet_enemy_interaction(enemys_2_2, bullets, &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_2_3, bullets, &enemy_death3);



			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_1_3, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_2_1, ice, &enemy_death4);
			interaction.ice_enemy_interaction(enemys_2_2, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_2_3, ice, &enemy_death3);



			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_1_3, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_2_1, storm, &enemy_death4);
			interaction.storm_enemy_interaction(enemys_2_2, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_2_3, storm, &enemy_death3);


			interaction.approach_enemy_interaction(enemys_1_1, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_2, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_1_3, approach, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_2_1, approach, &enemy_death4);
			interaction.approach_enemy_interaction(enemys_2_2, approach, &enemy_death2);
			interaction.approach_enemy_interaction(enemys_2_3, approach, &enemy_death3);


			interaction.bomb_enemy_interaction(enemys_1_1, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_2, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_1_3, bombs, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_2_1, bombs, &enemy_death4);
			interaction.bomb_enemy_interaction(enemys_2_2, bombs, &enemy_death2);
			interaction.bomb_enemy_interaction(enemys_2_3, bombs, &enemy_death3);


			interaction.back_enemy_interaction(enemys_1_1, knockback, player);
			interaction.back_enemy_interaction(enemys_1_2, knockback, player);
			interaction.back_enemy_interaction(enemys_1_3, knockback, player);
			interaction.back_enemy_interaction(enemys_2_1, knockback, player);
			interaction.back_enemy_interaction(enemys_2_2, knockback, player);
			interaction.back_enemy_interaction(enemys_2_3, knockback, player);


			interaction.meteor_enemy_interaction(enemys_1_1, meteor, &enemy_death4);
			interaction.meteor_enemy_interaction(enemys_1_2, meteor, &enemy_death4);
			interaction.meteor_enemy_interaction(enemys_1_3, meteor, &enemy_death1);
			interaction.meteor_enemy_interaction(enemys_2_1, meteor, &enemy_death4);
			interaction.meteor_enemy_interaction(enemys_2_2, meteor, &enemy_death2);
			interaction.meteor_enemy_interaction(enemys_2_3, meteor, &enemy_death3);


			interaction.breath_enemy_interaction(enemys_1_1, breath, player, &enemy_death4);
			interaction.breath_enemy_interaction(enemys_1_2, breath, player, &enemy_death4);
			interaction.breath_enemy_interaction(enemys_1_3, breath, player, &enemy_death1);
			interaction.breath_enemy_interaction(enemys_2_1, breath, player, &enemy_death4);
			interaction.breath_enemy_interaction(enemys_2_2, breath, player, &enemy_death2);
			interaction.breath_enemy_interaction(enemys_2_3, breath, player, &enemy_death3);

			uisetting.enemy_quest(enemy3, 1, enemy5, 1, enemy6, 1);

			uisetting.this_stage(3, 1);

			camera->camera_move();
			player->MOVE();
			player->draw_fix_chara();
			player->hp_chara();
		}
		//Boss2 
		if (scene == 17)
		{
			player_setting.move_limit(player);
			map_setting.map_creating();

			//Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 1);
			enemy_update_1_2.enemy_create(enemys_1_2, 1);
			enemy_update_1_3.enemy_create(enemys_1_3, 1);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);

			//Enemy move
			enemy_update_1_1.enemy_move(enemys_1_1, player);
			enemy_update_1_2.enemy_move(enemys_1_2, player);
			enemy_update_1_3.enemy_move(enemys_1_3, player);

			enemy_update_1_3.attack_create(enemy_attack, enemys_1_3, *player);
			enemy_update_1_3.attack_draw(enemy_attack);
			enemy_update_1_3.attack_remove(enemy_attack);

			//Me Enemy check
			interaction.player_enemy_interaction(enemys_1_1, player);
			interaction.player_enemy_interaction(enemys_1_2, player);
			interaction.player_enemy_interaction(enemys_1_3, player);


			//Create bullet
			
			uisetting.roulette(randomboxloc);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			uisetting.RcoolTime(player);


			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_1_3, bullets, &enemy_death3);

			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_1_3, ice, &enemy_death3);

			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_1_3, storm, &enemy_death3);

			stage_boss1->draw();
			stage_boss1->move();
			stage_boss1->hp();
			

			interaction.player_boss1_interaction(stage_boss1, bullets);
			interaction.ice_boss1_interaction(stage_boss1, ice);
			interaction.storm_boss1_interaction(stage_boss1, storm);
			interaction.back_boss1_interaction(stage_boss1, knockback);
			interaction.approach_boss1_interaction(stage_boss1, approach);
			interaction.bomb_boss1_interaction(stage_boss1, bombs);
			interaction.breath_boss1_interaction(stage_boss1, breath);
			interaction.meteor_boss1_interaction(stage_boss1, meteor);

			player->MOVE();
			player->draw_chara();
			player->hp_chara();
		}
		//Boss3 
		if (scene == 18)
		{
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);
			map_setting.boss2_creating();

			//Create bullet
			
			uisetting.roulette_ult(ultraboxloc);
			uisetting.roulette_six(sixboxloc);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			uisetting.ScoolTime(player);
			uisetting.UcoolTime(player);

			stage_boss2->draw();
			stage_boss2->move();
			stage_boss2->hp();

			s2boss_update.s2_boss_attack(stage_boss2, player);

			if (stage_boss2->health <= 50)
			{
				//Random enemy
				enemy_update_1_2.enemy_create(enemys_1_2, 1);
				enemy_update_2_2.enemy_create(enemys_2_2, 1);
				enemy_update_2_3.enemy_create(enemys_2_3, 3);

				//Enemy move
				enemy_update_1_2.enemy_move(enemys_1_2, player);
				enemy_update_2_2.enemy_move(enemys_2_2, player);
				enemy_update_2_3.enemy_move(enemys_2_3, player);


				//Me Enemy check
				interaction.player_enemy_interaction(enemys_1_2, player);
				interaction.player_enemy_interaction(enemys_2_2, player);
				interaction.player_enemy_interaction(enemys_2_3, player);

			}

			interaction.player_boss2_interaction(stage_boss2, bullets);
			interaction.ice_boss2_interaction(stage_boss2,ice);
			interaction.storm_boss2_interaction(stage_boss2,storm);
			interaction.back_boss2_interaction(stage_boss2,knockback);
			interaction.approach_boss2_interaction(stage_boss2,approach);
			interaction.bomb_boss2_interaction(stage_boss2,bombs);
			interaction.breath_boss2_interaction(stage_boss2,breath);
			interaction.meteor_boss2_interaction(stage_boss2,meteor);
			interaction.boss2_player_interaction(player);

			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			enemy_update.enemy_remove(enemys_1_3);

			//Bullet Enemy Check
			interaction.bullet_enemy_interaction(enemys_1_2, bullets,  &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_2_2, bullets,  &enemy_death2);
			interaction.bullet_enemy_interaction(enemys_2_3, bullets, &enemy_death3);

			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_2_2, ice, &enemy_death2);
			interaction.ice_enemy_interaction(enemys_2_3, ice, &enemy_death3);

			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_2_2, storm, &enemy_death2);
			interaction.storm_enemy_interaction(enemys_2_3, storm, &enemy_death3);

			interaction.approach_enemy_interaction(enemys_1_2, approach, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_2_2, approach, &enemy_death2);
			interaction.approach_enemy_interaction(enemys_2_3, approach, &enemy_death3);

			interaction.bomb_enemy_interaction(enemys_1_2, bombs, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_2_2, bombs, &enemy_death2);
			interaction.bomb_enemy_interaction(enemys_2_3, bombs, &enemy_death3);

			interaction.back_enemy_interaction(enemys_1_2, knockback, player);
			interaction.back_enemy_interaction(enemys_2_2, knockback, player);
			interaction.back_enemy_interaction(enemys_2_3, knockback, player);

			interaction.meteor_enemy_interaction(enemys_1_2, meteor, &enemy_death1);
			interaction.meteor_enemy_interaction(enemys_2_2, meteor, &enemy_death2);
			interaction.meteor_enemy_interaction(enemys_2_3, meteor, &enemy_death3);

			interaction.breath_enemy_interaction(enemys_1_2, breath, player, &enemy_death1);
			interaction.breath_enemy_interaction(enemys_2_2, breath, player, &enemy_death2);
			interaction.breath_enemy_interaction(enemys_2_3, breath, player, &enemy_death3);

			

			player->MOVE();
			player->draw_chara();
			player->hp_chara();
		}
		//Boss1 
		if (scene == 19)
		{
			player_setting.move_limit(player);
		//	player_setting.move_fix_limit(camera);
			map_setting.boss3_creating();

			s3boss_update.attack_create(boss_attack, stage_boss3, player);
			s3boss_update.attack_draw(boss_attack);
			s3boss_update.attack_remove(boss_attack);

			uisetting.roulette_six(sixboxloc);
			uisetting.weaponChoice(bullets, ice, bombs, storm, approach, knockback, breath, meteor, player);
			uisetting.ScoolTime(player);

			stage_boss3->draw();
			stage_boss3->move(player);
			stage_boss3->hp();

			if (stage_boss3->health <= 50)
			{
				//Random enemy
				enemy_update_1_1.enemy_create(enemys_1_1, 1);
				enemy_update_1_2.enemy_create(enemys_1_2, 1);

				//Enemy move
				enemy_update_1_1.enemy_move(enemys_1_1, player);
				enemy_update_1_2.enemy_move(enemys_1_2, player);

				//Me Enemy check
				interaction.player_enemy_interaction(enemys_1_1, player);
				interaction.player_enemy_interaction(enemys_1_2, player);
			}
			//remove enemy
			enemy_update.enemy_remove(enemys_1_1);
			enemy_update.enemy_remove(enemys_1_2);
			
			//Bullet Enemy Check
			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death1);
			interaction.ice_enemy_interaction(enemys_1_2, ice, &enemy_death2);
															 
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_1_2, bullets, &enemy_death2);

			interaction.approach_enemy_interaction(enemys_1_1, approach, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_1_2, approach, &enemy_death2);

			interaction.meteor_enemy_interaction(enemys_1_1, meteor, &enemy_death1);
			interaction.meteor_enemy_interaction(enemys_1_2, meteor, &enemy_death2);

			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_2, storm, &enemy_death2);

			interaction.bomb_enemy_interaction(enemys_1_1, bombs, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_1_2, bombs, &enemy_death2);

			interaction.breath_enemy_interaction(enemys_1_1, breath, player, &enemy_death1);
			interaction.breath_enemy_interaction(enemys_1_2, breath, player, &enemy_death2);

			interaction.back_enemy_interaction(enemys_1_1,knockback, player);
			interaction.back_enemy_interaction(enemys_1_2, knockback, player);

			interaction.player_boss3_interaction(stage_boss3, bullets);
			interaction.ice_boss3_interaction(stage_boss3, ice);
			interaction.storm_boss3_interaction(stage_boss3, storm);
				

			player->MOVE();
			player->draw_chara();
			player->hp_chara();
		}

		if (scene == 20)
		{
			player_setting.move_limit(player);
			//player_setting.move_fix_limit(camera);
			map_setting.boss3_creating();


			weapon_choice = 5;

			////Random enemy
			enemy_update_1_1.enemy_create(enemys_1_1, 20);

			////Enemy move
			enemy_update_1_1.enemy_move(enemys_1_1, player);

			//Bullet Enemy Check
			interaction.ice_enemy_interaction(enemys_1_1, ice, &enemy_death1);
			interaction.bullet_enemy_interaction(enemys_1_1, bullets, &enemy_death1);
			interaction.approach_enemy_interaction(enemys_1_1, approach, &enemy_death1);
			interaction.meteor_enemy_interaction(enemys_1_1, meteor, &enemy_death1);
			interaction.storm_enemy_interaction(enemys_1_1, storm, &enemy_death1);
			interaction.bomb_enemy_interaction(enemys_1_1, bombs, &enemy_death1);
			interaction.breath_enemy_interaction(enemys_1_1, breath, player, &enemy_death1);
			interaction.back_enemy_interaction(enemys_1_1, knockback, player);

			//back
			if (weapon_choice == 5)
			{
				back_update.bullet_create(knockback, player);
				back_update.bullet_draw(knockback);
				back_update.bullet_remove(knockback);
				back_update.coolTime(knockback, player);
			}

			//breath
			if (weapon_choice == 6)
			{
				breath_update.bullet_create(breath, player);
				breath_update.bullet_draw(breath, player);
				breath_update.coolTime(breath, player);
			}
			map_setting.boss3_creating();

			player->MOVE();
			player->draw_chara();
			player->hp_chara();
		}

	}
	return 0;
}

//브레스 그리기
//플레이어 리미트
//무기 줍기
