//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------

#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class SoundEffect {
public:
    SoundEffect(const string& filename);
    SoundBuffer buffer;
    Sound       sound;
    void        play();
};
#endif