#include "back_weapon.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void BackWeapon::draw()
{
    set_fill_color(HexColor{ 0x0000ffff });
    draw_ellipse(bullet_pos_x, bullet_pos_y, size, size1);
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
        pop_settings();
    }
}

void Back_update::bullet_create(std::vector<BackWeapon*>& bullets, Player* player)
{
    if (!MouseIsPressed) {
        not_clicked_back = true;
    }
    if (MouseIsPressed && not_clicked_back == true)
    {
        not_clicked_back = false;
        bullets.push_back(new BackWeapon{ player->chara_pos_x, player->chara_pos_y, backSize, backSize1 });

        //if (enemy_x < bullet_pos_x && enemy_x > bullet_pos_x + backSize)
        //{
        //    //일정 시간동안 뒤로 이동
        //}
    }
}

void Back_update::bullet_remove(std::vector<BackWeapon*>& bullets)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        back_timer += DeltaTime;

        if(back_timer > back_time_check)
        {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
            back_timer = 0;
            back_time_check = 0;
        }
    }
}