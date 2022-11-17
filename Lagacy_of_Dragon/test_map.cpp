#include<iostream>
#include<doodle/doodle.hpp>

#include "test_map.h"

using namespace doodle;


extern int center_map_x, center_map_y;

const Image full_map{"map/wp4649492.jpg" };

void basic_map() {

	push_settings();

	int bridge_x = center_map_x;
	int bridge_y = center_map_y;

	apply_scale(3);
	apply_translate(-300 + 100, -300 + 100);
	draw_image(full_map, bridge_x, bridge_y);

	pop_settings();
}
