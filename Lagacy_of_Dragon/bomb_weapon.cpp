#include "bomb_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;


void BombWeapon::draw()
{
    set_fill_color(HexColor{ 0xffff00ff });
    draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
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
            bullets.push_back(new BombWeapon{ player->chara_pos_x, player->chara_pos_y, bombSize, bombDamage, bombrange });
            not_clicked_bomb = false;
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
    }
}

void Bomb_update::coolTime(std::vector<BombWeapon*>& bullets, Player* player)
{
    set_rectangle_mode(RectMode::Corner);
    push_settings();
    no_fill();
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 100, 15);
    pop_settings();

    push_settings();
    set_fill_color(HexColor{ 0x00FF00FF });
    draw_rectangle(player->chara_pos_x - 50, player->chara_pos_y - 50, 200 * bo_click_check, 15);
    pop_settings();
}