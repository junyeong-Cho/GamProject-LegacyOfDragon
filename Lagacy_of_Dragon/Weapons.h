#pragma once

class Weapons {
	int x = 0;
	int y = 0;
	int size = 0;
	int damage = 0;
	int range = 0;

	Weapons(float _x, float _y, int _health, int _deal, float _speed, int _enemysize, unsigned int _color, int _type)
	{
		x = _x;
		y = _y;
		health = _health;
		deal = _deal;
		speed = _speed;
		enemysize = _enemysize;
		color = _color;
		type = _type;
	}
};