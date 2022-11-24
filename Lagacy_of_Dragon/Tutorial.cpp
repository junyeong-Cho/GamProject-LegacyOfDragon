#include "Tutorial.h"
#include "Player.h"
#include "UIsetting.h"
void Tutorial::scene1_guideline()
{
	push_settings();
	set_outline_color(HexColor{ 0x00ff85ff });
	set_outline_width(4.0);
	draw_line(tuto_move_line, 0, tuto_move_line, tuto_move_line2);
	draw_text("Use W A S D", tuto_word_x, tuto_word_y);
	set_image_mode(RectMode::Center);
	draw_image(Nest, nest_loc, nest_loc, nest_size, nest_size);
	pop_settings();
}

void Tutorial::scene2_guideline()
{
	push_settings();
	draw_text("Use mouse to shoot Bullet!", tuto_word_x, tuto_word_y);
	pop_settings();
}

void Tutorial::scene3_guideline() {
	push_settings();
	draw_text("Kill all the enemies!", 100, 150);
	draw_text("SCORE: " + std::to_string(score), score_width, score_height);
	pop_settings();
}

bool Tutorial::is_clear_scene1(Player* player)
{
	return player->chara_pos_x > tuto_move_line;
}

