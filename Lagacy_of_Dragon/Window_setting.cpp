//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
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
