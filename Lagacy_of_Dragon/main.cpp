#include <doodle/doodle.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "library.h"

using namespace std;
using namespace doodle;

int enemy_x = 100;
int enemy_y = 0;
int Max = 5;
int Score = 0;
int timer_check = 3;
double timer = 0;

bool not_clicked = false;
bool moveW = false;
bool moveA = false;
bool moveS = false;
bool moveD = false;

const Image tiles[] = {
	Image{"plain.png"},      //0 = PLAIN
	Image{"chara.png"},      //1 = CHARA
	Image{"shrub.png"},      //2 = SHRUB
	Image{"trees.png"},      //3 = TREES
};

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

	//좀더 쉽게 보이라고 캐릭터 움직이는거 MOVE로 바꿈
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

//키보드 눌렸는지 체크하는 시스템
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

int main() {
	create_window(setting.world_x * setting.tile_size, setting.world_y * setting.tile_size);
	window_setting.window();

	vector<Shooting> bullets;
	vector<Enemy> enemys;
	//캐릭터 초기 위치 찾기
	Player player = Player{ 0, 0 };

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (map_setting.world_map[y][x] == map_setting.CHARA) {
				player.chara_pos_x = x * setting.tile_size;
				player.chara_pos_y = y * setting.tile_size;
				break;
			}
		}
	}

	while (!is_window_closed()) {
		timer += DeltaTime;
				update_window();

		if (!MouseIsPressed) {
			not_clicked = true;
		}

		if (MouseIsPressed && not_clicked == true)
		{  //bullet_create
			bullets.push_back({ player.chara_pos_x, player.chara_pos_y, 10 });
			not_clicked = false;
		}

		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				draw_image(tiles[map_setting.PLAIN], x * setting.tile_size, y * setting.tile_size, setting.tile_size, setting.tile_size);
			}
		}

		for (int x = 0; x < 10; x++) {
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

		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].draw();
			bullets[i].FireBullet();
		}

		//Random enemy
		if (timer > timer_check)
		{
			for (int j = 0; j < Max; j++)
			{
				int r_enemy_y = random(setting.enemyMin, setting.enemyMax);
				int r_enemy_x = random(setting.enemyMin, setting.enemyMax);
				enemys.push_back({ r_enemy_x, r_enemy_y, 30 });
			}
			timer_check += 3;
		}

		//Enemy draw
		for (int i = 0; i < enemys.size(); i++)
		{

			enemys[i].draw();

			if (enemys[i].x >= player.chara_pos_x)
			{
				enemys[i].x -= 2;
			}
			if (enemys[i].x <= player.chara_pos_x)
			{
				enemys[i].x += 2;
			}
			if (enemys[i].y >= player.chara_pos_y)
			{
				enemys[i].y -= 2;
			}
			if (enemys[i].y <= player.chara_pos_y)
			{
				enemys[i].y += 2;
			}

		}

		player.MOVE();
		player.draw_chara();
	}
	return 0;
}