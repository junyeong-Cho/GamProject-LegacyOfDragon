//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include <SFML/Audio.hpp>
#include "soundeffect.h"
#include "breath_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;
using namespace sf;

#define BreathS 0

SoundEffect sound_effects_laser[] = {
    SoundEffect("assets/SFX/Ultimate_laser.wav"),
};

void BreathWeapon::drawR()
{
    push_settings();
    set_image_mode(RectMode::Center);
    draw_image(razerImage, bullet_pos_x, bullet_pos_y, -size, size1);
    pop_settings();
}
void BreathWeapon::drawL()
{
    push_settings();
    set_image_mode(RectMode::Center);
    draw_image(razerImage, bullet_pos_x - breathSize, bullet_pos_y, size, size1);
    pop_settings();
}

void Breath_update::bullet_create(std::vector<BreathWeapon*>& bullets, Player* player)
{
    if (br_click_timer < br_click_check)
    {
        br_click_timer += DeltaTime;
    }

    if (!MouseIsPressed) {
        not_clicked_breath = true;
        is_breath = false;
    }

    if (br_click_timer >= br_click_check)
    {
        if (MouseIsPressed && not_clicked_breath == true)
        {
            sound_effects_laser[BreathS].play();
            bullets.push_back(new BreathWeapon{ player->chara_pos_x + breathSize / 2, player->chara_pos_y, breathSize, breathSize1, breathdamage });
            not_clicked_breath = false;
            br_click_timer = 0;
            breath_timer += DeltaTime;
        }
    }
}

void Breath_update::bullet_draw(std::vector<BreathWeapon*>& bullets, Player* player)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        push_settings();
        if (get_mouse_x() > player->chara_pos_x)
        {
            bullets[i]->drawR();
        }
        else if (get_mouse_y() < player->chara_pos_x)
        {
            bullets[i]->drawL();
        }
        pop_settings();
    }
}

void Breath_update::bullet_remove(std::vector<BreathWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (not_clicked_breath == true)
        {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
        }
    }
}
void Breath_update::coolTime(std::vector<BreathWeapon*>& bullets, Player* player)
{
    set_rectangle_mode(RectMode::Corner);
    push_settings();
    no_fill();
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 15);
    pop_settings();

    push_settings();
    set_fill_color(HexColor{ 0x00FF00FF });
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 20 * br_click_timer, 15);
    pop_settings();
}