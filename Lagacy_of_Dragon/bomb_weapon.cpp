#include "bomb_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;


void BombWeapon::draw()
{
    draw_ellipse(x, y, size, size);
}

void Bomb_update::bullet_draw(std::vector<BombWeapon*>& bullets) {
    for (int i = 0; i < bullets.size(); i++)
    {
        push_settings();
        bullets[i]->draw();
        pop_settings();
    }
}

void Bomb_update::bullet_create(std::vector<BombWeapon*>& bullets, Player* player)
{
    if (!MouseIsPressed) {
        not_clicked_bomb = true;
    }
    if (MouseIsPressed && not_clicked_bomb == true)
    {   
        not_clicked_bomb = false;

        for (int i = 0; i < bullets.size(); i++)
        {
            bullets.push_back(new BombWeapon{ player->chara_pos_x - 10, player->chara_pos_y, bombSize, bombDamage });
        }
    }
}