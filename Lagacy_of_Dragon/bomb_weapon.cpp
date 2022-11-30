#include "bomb_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;


void BombWeapon::draw()
{
    draw_ellipse(mouseX, mouseY, size, size);
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
        bomb_timer = 0;
    }
    if (MouseIsPressed && not_clicked_bomb == true)
    {   
        bomb_timer += DeltaTime;
        not_clicked_bomb = false;

        for (int i = 0; i < bullets.size(); i++)
        {
            if (bomb_timer > bomb_time_check)
            {
                bullets.push_back(new BombWeapon{ player->chara_pos_x, player->chara_pos_y, bombSize, bombDamage });
                bomb_time_check += 4;
            }
        }
    }
}