#pragma once

#include "stdafx.h"




class SoundManager {
private:
    SAMPLE* themeSound;
    vector<MIDI*> effectsSounds;

    int themeVolume;
    int effectsVolume;

public:
	SoundManager();
	~SoundManager();

    void loadTheme(const char* nameBase);
    void loadEffect(const char* nameBase);

    void loadConfigurations();

    void stopTheme();

    void playTheme();
    void playEffect(const int position);
};

