//---------------------------------------------------------
// GAM100
// Author:	Junyeong Cho, Hyunwoo Yang, Chunho Park, Jaeyong Lee
//
// ﻿All content © 2022 DigiPen (USA) Corporation, all rights reserved.
//---------------------------------------------------------
#include "soundeffect.h"

SoundEffect::SoundEffect(const string& filename) {
    if (!buffer.loadFromFile(filename)) {
        cout << "Failed to load the music file: " << filename << endl;
    }
}

void SoundEffect::play() {
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(35);
}