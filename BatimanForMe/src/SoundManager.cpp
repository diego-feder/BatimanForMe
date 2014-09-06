#include "SoundManager.h"

SoundManager::SoundManager()
{
   loadConfigurations();
}

SoundManager::~SoundManager()
{
    destroy_sample(themeSound);
}


void SoundManager::loadTheme(const char* nameBase)
{
     themeSound = load_sample(nameBase);
     if(!themeSound)
     {
        allegro_message("Unable to load the Theme Sample");
     }
}
void SoundManager::loadEffect(const char* nameBase)
{
    effectsSounds.push_back(load_midi(nameBase));
}

void SoundManager::loadConfigurations()
{
    string pAux;
    ifstream myfile("files/settings.txt");
    if(myfile.is_open())
    {
        getline(myfile,pAux);
        effectsVolume =  atoi(pAux.c_str());
        getline(myfile,pAux);
        themeVolume = atoi(pAux.c_str());
        myfile.close();

        themeVolume = (themeVolume*255)/100;
        effectsVolume = (effectsVolume*255)/100;

        set_volume(255, effectsVolume);
    }
    else
    {
        ofstream file("files/settings.txt");
        if(file.is_open())
        {
            file << 100 << endl << 100;
            themeVolume = 255;
            effectsVolume = 255;
            file.close();
        }
        else
        {
            allegro_message("Unable to read and create settings");
        }

    }
}

void SoundManager::playTheme()
{
    play_sample(themeSound, themeVolume, 126, 1000, 1);
}

void SoundManager::stopTheme()
{
    stop_sample(themeSound);
}
void SoundManager::playEffect(const int position)
{

}
