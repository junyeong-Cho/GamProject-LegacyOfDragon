//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "back_weapon.h"
#include "soundeffect.h"
#include <doodle\doodle.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace doodle;

#define BackS 0

SoundEffect sound_effects_back[] = {
    SoundEffect("assets/SFX/Wind.wav"),
};

//knockback
void BackWeapon::draw()
{
    push_settings();

    back1_timer += DeltaTime;
    set_image_mode(RectMode::Center);
    if (back1_timer < back1_check) // 0.5초
    {
        draw_image(backImage, bullet_pos_x, bullet_pos_y, size, size);
    }
    if (back1_timer >= back1_check && back1_timer < back2_check) //0.5~ 1.0
    {
        draw_image(backImage1, bullet_pos_x, bullet_pos_y, size, size);

    }
    if (back1_timer > back2_check)
    {
        back1_timer = 0;
    }
    pop_settings();
}

void BackWeapon::FireBullet()
{
    float aimAngle = atan2(angleY, angleX);
    float velocityX = (cos(aimAngle) * Bavelocity);
    float velocityY = (sin(aimAngle) * Bavelocity);

    bullet_pos_x += static_cast<int>(velocityX);
    bullet_pos_y += static_cast<int>(velocityY);
}

void Back_update::bullet_draw(std::vector<BackWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        push_settings();
        bullets[i]->draw();
        bullets[i]->FireBullet();
        pop_settings();
    }
}

void Back_update::bullet_create(std::vector<BackWeapon*>& bullets, Player* player)
{
    if (ba_click_timer < ba_click_check)
    {
        ba_click_timer += DeltaTime;
    }

    if (!MouseIsPressed) {
        not_clicked_back = true;
    }
    if (ba_click_timer >= ba_click_check)
    {
        if (MouseIsPressed && not_clicked_back == true)
        {
            sound_effects_back[BackS].play();
            bullets.push_back(new BackWeapon{ player->chara_pos_x, player->chara_pos_y, backSize, Ba1velocity });
            not_clicked_back = false;
            ba_click_timer = 0;
        }
    }
}

void Back_update::bullet_remove(std::vector<BackWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        back_timer += DeltaTime;
        if (back_timer >= back_time_check)
        {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
            back_timer = 0;
        }
    }
}

void Back_update::coolTime(std::vector<BackWeapon*>& bullets, Player* player)
{
    set_rectangle_mode(RectMode::Corner);
    push_settings();
    no_fill();
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 10);
    pop_settings();

    push_settings();
    set_fill_color(HexColor{ 0x00FF00FF });
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 33.3 * ba_click_timer, 10);
    pop_settings();
}