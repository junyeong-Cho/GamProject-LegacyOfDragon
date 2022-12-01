#include "bomb_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;


void BombWeapon::draw()
{
    set_fill_color(HexColor{ 0xffff00ff });
    draw_ellipse(bullet_pos_x, bullet_pos_y, size, size);
}

void BombWeapon::FireBullet()
{
    float aimAngle = atan2(angleY, angleX);
    float velocityX = (cos(aimAngle) * Bovelocity);
    float velocityY = (sin(aimAngle) * Bovelocity);

    bullet_pos_x += static_cast<int>(velocityX);
    bullet_pos_y += static_cast<int>(velocityY);
}

void Bomb_update::bullet_draw(std::vector<BombWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        push_settings();
        bullets[i]->draw();
        //bullets[i]->FireBullet();
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
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets.push_back(new BombWeapon{ player->chara_pos_x, player->chara_pos_y, bombSize, bombDamage });
            not_clicked_bomb = false;
        }
    }
}