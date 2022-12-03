#include "Player.h"
#include "Map_setting.h"
#include <doodle\doodle.hpp>
using namespace std;
#include <iostream>
using namespace doodle;

bool moveW = false;
bool moveA = false;
bool moveS = false;
bool moveD = false;


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

void Player::draw_chara() {

	if (get_mouse_x() >= chara_pos_x)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(tiles[map_setting.CHARA], chara_pos_x, chara_pos_y, -tile_size, tile_size);
		pop_settings();
	}
	else if (get_mouse_x() < chara_pos_x)
	{
		push_settings();
		set_image_mode(RectMode::Center);
		draw_image(tiles[map_setting.CHARA], chara_pos_x, chara_pos_y, tile_size, tile_size);
		pop_settings();
	}
}

void Player::MOVE() {
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
	//마우스 방향보고 캐릭터 좌우반전
}

void Player_setting::move_limit(Player* player)
{
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
}

void Player::hp_chara(int* scene)
{
	set_rectangle_mode(RectMode::Corner);
	push_settings();
	no_fill();
	draw_rectangle(100, 100, 300, 40);
	pop_settings();

	push_settings();
	set_fill_color(HexColor{ 0xFF0000FF });
	draw_rectangle(100, 100, 60 * hp, 40);
	pop_settings();
	if (hp <= 0)
	{
		scene = 0;
		close_window();
	}
}