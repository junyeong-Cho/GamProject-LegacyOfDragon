#include "Tutorial.h"
#include "Player.h"
#include "UIsetting.h"
#include "Map_setting.h"

//Chicken
void Tutorial::textbox1() 
{
	chicken_to_happy += DeltaTime;
	draw_image(Nest, nest_loc, nest_loc, tuto_size, tuto_size);//둥지
	draw_image(green_dragon, dragon_x, dragon_y, tuto_size, tuto_size);//플레이어
	draw_image(meat, meat_x, meat_y, tuto_size, tuto_size);//치킨

	chicken_x = dragon_x + 50;
	chicken_y = dragon_y - 50;

	draw_image(chicken1, chicken_x, chicken_y, tuto_size, tuto_size);

	if (chicken_to_happy >= chicken_to_happy_check)
	{
		textbox = 1;
	}
}

//Happy
void Tutorial::textbox2() 
{
	happy_to_bad += DeltaTime;
	happy_timer += DeltaTime;

	draw_image(Nest, nest_loc, nest_loc, tuto_size, tuto_size);//둥지
	draw_image(green_dragon, dragon_x, dragon_y, tuto_size, tuto_size);//플레이어
	draw_image(meat, meat_x, meat_y, tuto_size, tuto_size);//치킨

	chicken_x = dragon_x + 30;
	chicken_y = dragon_y - 50;

	if (happy_timer >= happy_check1 && happy_timer <= happy_check2)
	{
		draw_image(happy1, chicken_x, chicken_y, tuto_size, tuto_size);
	}
	else if (happy_timer >= happy_check2)
	{
		draw_image(happy2, chicken_x, chicken_y, tuto_size, tuto_size); 
		happy_timer = 0;
	}

	if (happy_to_bad >= happy_to_bad_check)
	{
		textbox = 2;
	}
}

//Red dragon
void Tutorial::textbox3()
{
	bad_to_angry += DeltaTime;
	draw_image(Nest, nest_loc, nest_loc, tuto_size, tuto_size);//둥지
	draw_image(green_dragon, dragon_x, dragon_y, tuto_size, tuto_size);//플레이어
	draw_image(red_dragon, rdragon_x, rdragon_y, tuto_size, tuto_size);//빨갱이
	draw_image(meat, meat_x, meat_y, tuto_size, tuto_size);//치킨

	chicken_x = dragon_x + 30;
	chicken_y = dragon_y - 50;

	draw_image(bad1, rdragon_x + 50, rdragon_y - 50, tuto_size - 50, tuto_size - 50);
	
	if (bad_to_angry >= bad_to_angry_check)
	{
		textbox = 3;
	}
}

//steel and smile
void Tutorial::textbox4()
{
	draw_image(Nest, nest_loc, nest_loc, tuto_size, tuto_size);//둥지
	draw_image(green_dragon, dragon_x, dragon_y, tuto_size, tuto_size);//플레이어
	draw_image(red_dragon, rdragon_x, rdragon_y, tuto_size, tuto_size);//빨갱이
	draw_image(meat, meat_x, meat_y, tuto_size, tuto_size);//치킨
	rdragon_y -= dragons_vel;
	
	if (rdragon_y <= 200)
	{
		rdragon_y += dragons_vel;
		rdragon_x += dragons_vel;
		meat_x += dragons_vel;
	}
	if (rdragon_x > 1300)
	{
		rdragon_x -= dragons_vel;
		meat_x -= dragons_vel;

		smile_to_angry += DeltaTime;
		smile_timer += DeltaTime;

		if (smile_timer >= smile_check1 && smile_timer <= smile_check2)
		{
			draw_image(smile1, rdragon_x - 50, rdragon_y - 50, tuto_size - 10, tuto_size - 10);
		}
		else if (smile_timer >= smile_check2)
		{
			draw_image(smile2, rdragon_x - 50, rdragon_y - 50, tuto_size - 10, tuto_size - 10);
			smile_timer = 0;
		}

		if (smile_to_angry >= smile_to_angry_check)
		{
			textbox  = 4;
		}
	}
}

//angry
void Tutorial::textbox5()
{
	draw_image(Nest, nest_loc, nest_loc, tuto_size, tuto_size);//둥지
	draw_image(green_dragon, dragon_x, dragon_y, tuto_size, tuto_size);//플레이어
	draw_image(red_dragon, rdragon_x, rdragon_y, tuto_size, tuto_size);//빨갱이
	draw_image(meat, meat_x, meat_y, tuto_size, tuto_size);//치킨

	angry_to_move += DeltaTime;
	angry_timer += DeltaTime;

	chicken_x = dragon_x + 30;
	chicken_y = dragon_y - 50;

	if (angry_timer >= angry_check1 && angry_timer <= angry_check2)
	{
		draw_image(angry1, chicken_x, chicken_y, tuto_size, tuto_size);
	}
	else if (angry_timer >= angry_check2)
	{
		draw_image(angry2, chicken_x, chicken_y, tuto_size, tuto_size);
		angry_timer = 0;
	}

	if (angry_to_move >= angry_to_move_check)
	{
		rdragon_x = 100;
		textbox = 5;
	}
	
}

//sweating
void Tutorial::textbox6()
{
	
	draw_image(red_dragon, rdragon_x, rdragon_y, tuto_size, tuto_size);//빨갱이
	
	rdragon_x += dragons_vel;

	if (rdragon_x > 1300)
	{
		rdragon_x -= dragons_vel;
		ddam_to_jewel += DeltaTime;
		ddam_timer += DeltaTime;

		sweat_x = rdragon_x + 30;
		sweat_y = rdragon_y - 50;

		if (ddam_timer >= ddam_check1 && ddam_timer <= ddam_check2)
		{
			draw_image(ddam1, sweat_x, sweat_y, tuto_size, tuto_size);
		}
		else if (ddam_timer >= ddam_check2)
		{
			draw_image(ddam2, sweat_x, sweat_y, tuto_size, tuto_size);
			ddam_timer = 0;
		}

		if (ddam_to_jewel >= ddam_to_jewel_check)
		{
			textbox = 6;
		}
	}
}

//surprise
void Tutorial::textbox7()
{
	ddi_to_jewel += DeltaTime;
	ddiyong_timer += DeltaTime;

	draw_image(red_dragon, rdragon_x, rdragon_y, tuto_size, tuto_size);//빨갱이

	chicken_x = rdragon_x + 30;
	chicken_y = rdragon_y - 50;

	if (ddiyong_timer >= ddiyong_check1 && ddiyong_timer <= ddiyong_check2)
	{
		draw_image(ddiyong1, chicken_x, chicken_y, tuto_size, tuto_size);
	}

	else if (ddiyong_timer >= ddiyong_check2)
	{
		draw_image(ddiyong2, chicken_x, chicken_y, tuto_size, tuto_size);
		ddiyong_timer = 0;
	}

	if (ddi_to_jewel >= ddi_to_jewel_check)
	{
		textbox = 7;
	}
}

//jewel 
void Tutorial::textbox8()
{
	jewel_to_ddi += DeltaTime;
	jewel_timer += DeltaTime;
	draw_image(red_dragon, rdragon_x, rdragon_y, tuto_size, tuto_size);//빨갱이

	chicken_x = rdragon_x + 30;
	chicken_y = rdragon_y - 50;

	if (jewel_timer >= jewel_check1 && jewel_timer <= jewel_check2)
	{
		draw_image(jewel1, chicken_x, chicken_y, tuto_size, tuto_size);
	}
	else if (jewel_timer >= jewel_check2)
	{
		draw_image(jewel2, chicken_x, chicken_y, tuto_size, tuto_size);
		jewel_timer = 0;
	}

	if (jewel_to_ddi >= jewel_to_ddi_check)
	{
		textbox = 8;
	}
}

// Green surprise
void Tutorial::textbox9()
{
	ddi_to_shoot += DeltaTime;
	ddiyong_timer += DeltaTime;

	draw_image(green_dragon, dragon_x, dragon_y, tuto_size, tuto_size);//플레이어
	draw_image(jewel1, jewel_x, jewel_y, tuto_size, tuto_size);//보석

	chicken_x = dragon_x + 30;
	chicken_y = dragon_y - 50;

	if (ddiyong_timer >= ddiyong_check1 && ddiyong_timer <= ddiyong_check2)
	{
		draw_image(ddiyong1, chicken_x, chicken_y, tuto_size, tuto_size);
	}
	else if (ddiyong_timer >= ddiyong_check2)
	{
		draw_image(ddiyong2, chicken_x, chicken_y, tuto_size, tuto_size);
		ddiyong_timer = 0;
	}

	dragon_x += dragons_vel;
	if (dragon_x > 1300)
	{
		dragon_x -= dragons_vel;
	}

	if (ddi_to_shoot >= ddi_to_shoot_check)
	{
		textbox = 9;
	}
}

void Tutorial::scene1_guideline()
{
	push_settings();
	draw_text("Move : W A S D", tuto_word_x, tuto_word_y);
	draw_text("Shoot: Mouse Click", tuto_word_x, tuto_word_y + 100);
	pop_settings();
}

void Tutorial::scene2_guideline()
{
	push_settings();
	draw_text("Kill all the enemies!", 100, 150);
	draw_text("SCORE: " + std::to_string(score), score_width, score_height);
	pop_settings();
}
