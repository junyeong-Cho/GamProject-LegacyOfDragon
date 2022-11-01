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

enum Tiles {
    PLAIN = 0,
    CHARA = 1,
    SHRUB = 2,
    TREES = 3
};

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

    void draw_chara() {
        draw_image(tiles[CHARA], chara_pos_x, chara_pos_y, tile_size, tile_size);
    }

    void pos_update() {
        bool moveW = Key == KeyboardButtons::W;
        bool moveA = Key == KeyboardButtons::A;
        bool moveS = Key == KeyboardButtons::S;
        bool moveD = Key == KeyboardButtons::D;

        if (KeyIsPressed)
        {
            if (chara_pos_x < 0) {
                chara_pos_x = 0;
            }
            if (chara_pos_x > Width - tile_size) {
                chara_pos_x = Width - tile_size;
            }
            if (chara_pos_y < 0) {
                chara_pos_y = 0;
            }
            if (chara_pos_y > Height - tile_size) {
                chara_pos_y = Height - tile_size;
            }

            if (moveW == true) {
                chara_pos_y -= 10;
            }
            if (moveA == true) {
                chara_pos_x -= 10;
            }
            if (moveS == true) {
                chara_pos_y += 10;
            }
            if (moveD == true) {
                chara_pos_x += 10;
            }
        }
    }
};

int main() {
    create_window(world_x * tile_size, world_y * tile_size);

    set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
    set_image_mode(RectMode::Corner);
    no_fill();
    set_outline_width(3.0);

    //캐릭터 초기 위치 찾기
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

    bool not_clicked = false;

    while (!is_window_closed()) {
        update_window();
        clear_background(255);

        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                int tile = world_map[y][x];
                draw_image(tiles[PLAIN], x * tile_size, y * tile_size, tile_size, tile_size);
            }
        }

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

        if (!MouseIsPressed)
        {
            not_clicked = true;
        }

        player.pos_update();
        player.draw_chara();
    }

    return 0;
}