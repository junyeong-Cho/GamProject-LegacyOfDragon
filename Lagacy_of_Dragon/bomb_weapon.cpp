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
    if (!MouseIsPressed) {
        not_clicked_bomb = true;
    }
    if (MouseIsPressed && not_clicked_bomb == true)
    {
        bullets.push_back(new BombWeapon{ player->chara_pos_x, player->chara_pos_y, bombSize, bombDamage, bombrange });
        not_clicked_bomb = false;
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

