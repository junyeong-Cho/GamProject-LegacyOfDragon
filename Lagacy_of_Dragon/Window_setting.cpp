#include "Map_setting.h"
#include "Player.h"
#include "Window_setting.h"

 void Window_setting::setting() {
 create_window(world_x* tile_size, world_y* tile_size);
 set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
 set_image_mode(RectMode::Corner);
 no_fill();
 set_outline_width(3.0);
}