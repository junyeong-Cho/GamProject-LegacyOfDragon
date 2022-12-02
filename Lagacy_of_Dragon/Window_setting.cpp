#include "Map_setting.h"
#include "Player.h"
#include "Window_setting.h"

 void Window_setting::setting() {
 create_window(1000, 1000);
 set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
 set_image_mode(RectMode::Corner);
 no_fill();
 set_outline_width(3.0);
}
