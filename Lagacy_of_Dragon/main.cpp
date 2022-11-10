#include <doodle/doodle.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "library.h"

using namespace std;
using namespace doodle;

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
constexpr int score_width = 900;
constexpr int score_height = 300;
constexpr int tuto_move_line = 1000;
constexpr int tuto_move_line2 = 1000;
constexpr int tuto_word_x = 500;
constexpr int tuto_word_y = 200;

constexpr int nest_size = 100;
constexpr int nest_loc = 300;
//--------------------------------// Scene
int scene = 0;
int tutorial_scene = 0;
//--------------------------------// Gamestate
constexpr int mainmenu_x = 600;
constexpr int gameplay_y = 300;
constexpr int settings_y = 400;
constexpr int credits_y = 500;
constexpr int exit_y = 600;
constexpr int word_leng = 50;
constexpr int maxvolume_x = 600;
constexpr int maxvolume_y = 400;

//--------------------------------// Random Enemy
int Max = 5;
int tutoMax = 6;
int timer_check = 4;
double timer = 0;
constexpr int enemy_vel_min = 1;
constexpr int enemy_vel_max = 3;

int count_enemy_start = 0;

int score = 0;
double bulletradius = 5;
double enemyradius = 15;
double chararadius = 25;
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
bool moveW = false;
bool moveA = false;
bool moveS = false;
bool moveD = false;

bool enemy_check = false;
bool bullet_draw_check = false;
bool player_die_check = false;
bool tutorial_scene3 = false;

const Image tiles[] = {
	Image{"plain.png"},      //0 = PLAIN
	Image{"chara.png"},      //1 = CHARA
	Image{"shrub.png"},      //2 = SHRUB
	Image{"trees.png"},      //3 = TREES
};

const Image DigipenLogo{ "DigipenLogo.jpg" };
const Image TeamLogo{ "TeamLogo.png" };
const Image Nest{ "nest.png" };

struct Player {
	int chara_pos_x = 0;
	int chara_pos_y = 0;
	int speed = 5;

	void draw_chara() {
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(tiles[map_setting.CHARA], chara_pos_x, chara_pos_y, setting.tile_size, setting.tile_size);
		pop_settings();
	}

	void MOVE() {
		if (moveW == true) {
			chara_pos_y -= 6;
		}
		if (moveA == true) {
			chara_pos_x -= 6;
		}
		if (moveS == true) {
			chara_pos_y += 6;
		}
		if (moveD == true) {
			chara_pos_x += 6;
		}
	}
};

struct Shooting {
	int bullet_pos_x = 0;
	int bullet_pos_y = 0;
	int size = 0;
	double radius() {
		double radius = static_cast<int>(size / 2);
		return radius;
	}

	float mouseX = static_cast<float>(get_mouse_x());
	float mouseY = static_cast<float>(get_mouse_y());
	float angleX = (mouseX - bullet_pos_x);
	float angleY = (mouseY - bullet_pos_y);

	void draw()
	{
		set_fill_color(HexColor{ 0xff002aff });
		draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
	}
	void FireBullet()
	{
		float aimAngle = atan2(angleY, angleX);
		float velocityX = (cos(aimAngle) * setting.Bvelocity);
		float velocityY = (sin(aimAngle) * setting.Bvelocity);

		bullet_pos_x += static_cast<int>(velocityX);
		bullet_pos_y += static_cast<int>(velocityY);
	}
};

void on_key_pressed(KeyboardButtons button) {
	if (button == KeyboardButtons::W) {
		moveW = true;
	}
	if (button == KeyboardButtons::A) {
		moveA = true;
	}
	if (button == KeyboardButtons::S) {
		moveS = true;
	}
	if (button == KeyboardButtons::D) {
		moveD = true;
	}
}
void on_key_released(KeyboardButtons button) {
	if (button == KeyboardButtons::W) {
		moveW = false;
	}
	if (button == KeyboardButtons::A) {
		moveA = false;
	}
	if (button == KeyboardButtons::S) {
		moveS = false;
	}
	if (button == KeyboardButtons::D) {
		moveD = false;
	}
}

struct Enemy {
	int x = 0;
	int y = 0;
	int size = 0;

	void draw()
	{
		set_fill_color(HexColor{ 0xffff2aff });
		draw_ellipse(x, y, size, size);
	}
};

struct TutoEnemy {
	int x = 0;
	int y = 0;
	int size = 0;

	void draw()
	{
		set_fill_color(HexColor{ 0xffff2aff });
		draw_ellipse(x, y, size, size);
	}
};

int main()
{
	create_window(setting.world_x * setting.tile_size, setting.world_y * setting.tile_size);
	window_setting.window();

	vector<Shooting*> bullets;
	vector<Enemy*> enemys;
	vector<TutoEnemy*> tutoenemys;

	Player* player = new Player{ 0, 0 };

	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 10; y++) {
			if (map_setting.world_map[y][x] == map_setting.CHARA) {
				player->chara_pos_x = x * setting.tile_size;
				player->chara_pos_y = y * setting.tile_size;
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

		////Erase enemy
		//if(enemy_check == true)
		//{
		//	for (int i = 0; i < enemys.size(); i++)
		//	{
		//		delete enemys[i];
		//		enemys.erase(enemys.begin() + i);
		//	}
		//}

		////Erase bullet
		//if (bullet_draw_check == true)
		//{
		//	for (int i = 0; i < bullets.size(); i++)
		//	{
		//		delete bullets[i];
		//		bullets.erase(bullets.begin() + i);
		//	}
		//}

		////Erase player
		//if (player_die_check == true)
		//{
		//	scene = 2;
		//	//reset();
		//}

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
			draw_text("GamePlay", mainmenu_x, gameplay_y);
			draw_text("Settings", mainmenu_x, settings_y);
			draw_text("Credit", mainmenu_x, credits_y);
			draw_text("Exit", mainmenu_x, exit_y);

			//Gameplay
			if ((get_mouse_x() > 600 && get_mouse_x() < 920 && get_mouse_y() > 220 && get_mouse_y() < 220 + word_leng) && MouseIsPressed)
			{
				scene = 7;
			}
			//Settings
			if ((get_mouse_x() > 600 && get_mouse_x() < 880 && get_mouse_y() > 320 && get_mouse_y() < 320 + word_leng) && MouseIsPressed)
			{
				scene = 3;
			}
			//Credits
			if ((get_mouse_x() > 600 && get_mouse_x() < 800 && get_mouse_y() > 420 && get_mouse_y() < 420 + word_leng) && MouseIsPressed)
			{
				scene = 4;
			}
			//Exit
			if ((get_mouse_x() > 600 && get_mouse_x() < 730 && get_mouse_y() > 520 && get_mouse_y() < 520 + word_leng) && MouseIsPressed)
			{
				scene = 5;
			}
		}
		//Settings
		if (scene == 3)
		{
			clear_background(0x7E5873FF);
			draw_text("Back", maxvolume_x, maxvolume_y);
			if ((get_mouse_x() > 600 && get_mouse_x() < 750 && get_mouse_y() > 320 && get_mouse_y() < 330 + word_leng) && MouseIsPressed)
			{
				scene = 2;
			}


		}
		//Credits
		if (scene == 4)
		{
			clear_background(0x7E5873FF);
			draw_text("Back", maxvolume_x, maxvolume_y);
			if ((get_mouse_x() > 600 && get_mouse_x() < 750 && get_mouse_y() > 320 && get_mouse_y() < 330 + word_leng) && MouseIsPressed)
			{
				scene = 2;
			}
		}
		//Exit
		if (scene == 5)
		{
			return 0;
		}
		//GamePlay
		if (scene == 6)
		{
			if (!MouseIsPressed) {
				not_clicked = true;
			}

			if (MouseIsPressed && not_clicked == true)
			{
				//bullet_create
				bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
				not_clicked = false;
			}

			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {
					draw_image(tiles[map_setting.PLAIN], x * setting.tile_size, y * setting.tile_size, setting.tile_size, setting.tile_size);
				}
			}
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {

					int tile = map_setting.world_map[y][x];

					if (tile > 3 || tile < 0) {
						tile = map_setting.PLAIN;
					}

					if (tile == map_setting.CHARA) {
						tile = map_setting.PLAIN;
					}

					draw_image(tiles[tile], x * setting.tile_size, y * setting.tile_size, setting.tile_size, setting.tile_size);
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

				/*if (bullet_timer > bullet_check)
				{
					for (int i = 0; i < bullets.size(); i++)
					{
						bullets[i]->draw();
						bullets[i]->FireBullet();
					}
					delete bullets[i];
					bullets.erase(bullets.begin() + i);
					bullet_check += 4;
				}*/
			}

			//Random enemy
			if (timer > timer_check)
			{
				for (int i = 0; i < Max; i++)
				{
					push_settings();
					int r_enemy_y = random(setting.enemyMin, setting.enemyMax);
					int r_enemy_x = random(setting.enemyMin, setting.enemyMax);
					enemys.push_back(new Enemy{ r_enemy_x, r_enemy_y, setting.enemySize });
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
						score += 1;
						delete bullets[i];
						bullets.erase(bullets.begin() + i);

						delete enemys[j];
						enemys.erase(enemys.begin() + j);
					}
				}
			}
			player->MOVE();
			player->draw_chara();
		}
		//Tutorial
		if (scene == 7)
		{
			clear_background(255);
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {
					draw_image(tiles[map_setting.PLAIN], x * setting.tile_size, y * setting.tile_size, setting.tile_size, setting.tile_size);
				}
			}
			for (int x = 0; x < 15; x++) {
				for (int y = 0; y < 10; y++) {

					int tile = map_setting.world_map[y][x];

					if (tile > 3 || tile < 0) {
						tile = map_setting.PLAIN;
					}

					if (tile == map_setting.CHARA) {
						tile = map_setting.PLAIN;
					}

					draw_image(tiles[tile], x * setting.tile_size, y * setting.tile_size, setting.tile_size, setting.tile_size);
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
				set_outline_color(0);
				set_outline_width(4.0);
				draw_line(tuto_move_line, 0, tuto_move_line, tuto_move_line2);
				draw_text("Use W A S D", tuto_word_x, tuto_word_y);
				set_image_mode(RectMode::Center);
				draw_image(Nest, nest_loc, nest_loc, nest_size, nest_size);
				pop_settings();

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
				draw_text("Use mouse to shoot Bullet!", tuto_word_x, tuto_word_y);

				player->draw_chara();
				player->MOVE();

				if (!MouseIsPressed) {
					not_clicked = true;
				}
				if (MouseIsPressed && not_clicked == true)
				{
					//bullet_create
					bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });

					if (bullets.size() > 5)
					{
						tutorial_scene = 3;
					}
					not_clicked = false;
				}

				//bullet draw
				for (int i = 0; i < bullets.size(); i++)
				{
					bullets[i]->draw();
					bullets[i]->FireBullet();
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

			//Last Scene (Kill Enemies)
			if (tutorial_scene == 3)
			{
				draw_text("SCORE: " + to_string(score), score_width, score_height);
				player->draw_chara();
				player->MOVE();

				if (!MouseIsPressed) {
					not_clicked = true;
				}
				if (MouseIsPressed && not_clicked == true)
				{
					//bullet_create
					bullets.push_back(new Shooting{ player->chara_pos_x, player->chara_pos_y, bulletSize });
					not_clicked = false;
				}
				for (int i = 0; i < bullets.size(); i++)
				{
					bullets[i]->draw();
					bullets[i]->FireBullet();
				}
				//Create Enemy
				if (timer > timer_check)
				{
					for (; count_enemy_start < tutoMax; count_enemy_start++)
					{
						int r_enemy_y = random(setting.enemyMin, setting.enemyMax);
						int r_enemy_x = random(setting.enemyMin, setting.enemyMax);
						tutoenemys.push_back(new TutoEnemy{ r_enemy_x, r_enemy_y, setting.enemySize });
					}
				}

				//Enemy Move
				for (int i = 0; i < tutoenemys.size(); i++)
				{
					tutoenemys[i]->draw();

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
					bullets[i]->draw();
					bullets[i]->FireBullet();

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

				//Move next stage
				if (score > 5)
				{
					scene = 6;
				}
			}
		}
	}
	return 0;

	void reset();
}

void reset()
{

}
