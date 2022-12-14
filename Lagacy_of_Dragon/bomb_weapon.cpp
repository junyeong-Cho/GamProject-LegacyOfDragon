//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "bomb_weapon.h"
#include "soundeffect.h"
#include <SFML/Audio.hpp>
#include <doodle\doodle.hpp>

using namespace doodle;
using namespace sf;

#define BombS 0

SoundEffect sound_effects_bomb[] = {
    SoundEffect("assets/SFX/Bomb.wav"),
};

void BombWeapon::draw()
{
    draw_image(bombImage1, bullet_pos_x, bullet_pos_y, size, size);
}

void Bomb_update::bullet_create(std::vector<BombWeapon*>& bullets, Player* player)
{
    if (bo_click_timer < bo_click_check)
    {
        bo_click_timer += DeltaTime;
    }

    if (!MouseIsPressed) {
        not_clicked_bomb = true;
    }

    if (bo_click_timer >= bo_click_check)
    {
        if (MouseIsPressed && not_clicked_bomb == true)
        {
            not_clicked_bomb = false;
            bullets.push_back(new BombWeapon{ player->chara_pos_x, player->chara_pos_y, bombSize, bombDamage, bombrange });            
            bo_click_timer = 0;
        }
    }
   
}

void Bomb_update::bullet_draw(std::vector<BombWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        push_settings();
        bullets[i]->draw();
        pop_settings();
        if (moveW == true) {
            bullets[i]->bullet_pos_y += DeltaTime * 150 * 2;
        }
        if (moveA == true) {
            bullets[i]->bullet_pos_x += DeltaTime * 150 * 2;
        }
        if (moveS == true) {
            bullets[i]->bullet_pos_y -= DeltaTime * 150 * 2;
        }
        if (moveD == true) {
            bullets[i]->bullet_pos_x -= DeltaTime * 150 * 2;
        }
    }
}

void Bomb_update::bullet_remove(std::vector<BombWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (is_bomb_hit == true)
        {
            sound_effects_bomb[BombS].play();
            bo_remove_timer += DeltaTime;
            draw_image(bombImage2, bullets[i]->bullet_pos_x, bullets[i]->bullet_pos_y, bullets[i]->size, bullets[i]->size);

            if (bo_remove_timer > bo_remove_check)
            {
                delete bullets[i];
                bullets.erase(bullets.begin() + i);
                is_bomb_hit = false;
                bo_remove_timer = 0;
            }
        }    
    }
}

void Bomb_update::coolTime(std::vector<BombWeapon*>& bullets, Player* player)
{
    set_rectangle_mode(RectMode::Corner);
    push_settings();
    no_fill();
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 10);
    pop_settings();

    push_settings();
    set_fill_color(HexColor{ 0x00FF00FF });
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 200 * bo_click_check, 10);
    pop_settings();
}