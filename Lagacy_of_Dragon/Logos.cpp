#include "Logos.h"
#include <doodle\doodle.hpp>
using namespace doodle;

void Logos::digipen_logo() {
	clear_background(255);
	push_settings();
	set_image_mode(RectMode::Center);
	apply_scale(0.7);
	draw_image(DigipenLogo, digipen_width, digipen_height);
	pop_settings();
}

void Logos::team_logo() {
	clear_background(255);
	push_settings();
	apply_scale(0.3);
	set_image_mode(RectMode::Center);
	draw_image(TeamLogo, teamlogo_width, teamlogo_height);
	pop_settings();
}


