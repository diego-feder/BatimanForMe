#include "Transitions.h"

Transitions::Transitions()
{

    index = 0;

    char spriteString[40];

    for(int i = 0; i < 3; i++)
    {
        sprintf(spriteString,"img/transition%d.bmp", i);
        transition[i] = load_bitmap(spriteString, 0);
        if(!transition[i])
        {
            allegro_message("Unable to load sprite Bitmap.");
        }
    }
}

Transitions::~Transitions()
{

}


void Transitions::print(BITMAP* pWhereToPrint)
{
    blit(transition[index], pWhereToPrint, 0,0,0,0,transition[index]->w, transition[index]->h);
}

void Transitions::screenWait()
{
    while(!key[KEY_ENTER])
    {
        print(screen);
        rest(100);
    }
}

void Transitions::execute()
{
    while(!key[KEY_ENTER])
    {
        screenWait();
    }
    index++;

    if (index > 3)
    {
        index = 0;
    }
}


