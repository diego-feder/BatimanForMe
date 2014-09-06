#define ALLEGRO_STATICLINK

#include"Game.h"
#include"stdafx.h"

void* azul(void* p);

int main()
{
    //pthread_t T1;
    //pthread_create(&T1, NULL, azul, NULL);
    Game objGame;
    objGame.execute();

    return 0;
}
END_OF_MAIN()

/*void* azul(void* p)
{
    allegro_message("azul");
}*/

