#include <doodle/doodle.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace doodle;

constexpr int tile_size = 100;
constexpr int world_x = 10;
constexpr int world_y = 10;

const Image tiles[] = {
    Image{"plain.png"},      //0 = PLAIN
    Image{"chara.png"},      //1 = CHARA
    Image{"shrub.png"},      //2 = SHRUB
    Image{"trees.png"},      //3 = TREES
};

#define PLAIN    0
#define CHARA    1
#define SHRUB    2
#define TREES    3

const int world_map[world_x][world_y] = {
    { TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES },
    { TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES, TREES },
    { TREES, TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
    { TREES, PLAIN, SHRUB, PLAIN, PLAIN, TREES, PLAIN, SHRUB, PLAIN, TREES },
    { TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
    { TREES, PLAIN, PLAIN, PLAIN, SHRUB, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
    { TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, CHARA, PLAIN, PLAIN, TREES },
    { TREES, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, PLAIN, TREES },
    { TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES, TREES },
};

struct Player {
    int chara_pos_x = 0;
    int chara_pos_y = 0;
    int speed = 5;

    void draw() {
        draw_image(tiles[CHARA], chara_pos_x, chara_pos_y, tile_size, tile_size);
    }

    void pos_update() {
        if (KeyIsPressed)
        {
            switch (Key)
            {
            case KeyboardButtons::W:
                chara_pos_y -= speed;
                break;
            case KeyboardButtons::A:
                chara_pos_x -= speed;
                break;
            case KeyboardButtons::S:
                chara_pos_y += speed;
                break;
            case KeyboardButtons::D:
                chara_pos_x += speed;
                break;
            default:
                break;
            }
        }
    }
};

struct Shooting {
    int bullet_pos_x = 0;
    int bullet_pos_y = 0;
    int bullet_speed = 5;
    int bullet_delay = 5;

    void draw_bullet() {
        draw_ellipse(bullet_pos_x, bullet_pos_y, 5, 5);
    }

    void bullet_update() {
        if (MouseIsPressed == true)
        {
            //&& mouse_hold == false
            //mouse_hold = true;
            bullet_pos_x += bullet_speed * get_mouse_x();
            bullet_pos_y += bullet_speed * get_mouse_y();
        }
    }
};

int main() {
    create_window(world_x * tile_size, world_y * tile_size);

    set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
    set_image_mode(RectMode::Corner);
    no_fill();
    set_outline_width(3.0);


    Player player = Player{ 0, 0 };
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (world_map[y][x] == CHARA) {
                player.chara_pos_x = x * tile_size;
                player.chara_pos_y = y * tile_size;
                break;
            }
        }
    }

    while (!is_window_closed()) {
        update_window();
        clear_background(255);

        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                int tile = world_map[y][x];
                if (tile > 3 || tile < 0) {
                    tile = PLAIN;
                }
                if (tile == CHARA) {
                    tile = PLAIN;
                }
                draw_image(tiles[tile], x * tile_size, y * tile_size, tile_size, tile_size);
            }
        }

        player.pos_update();
        player.draw();
    }

    return 0;
}
