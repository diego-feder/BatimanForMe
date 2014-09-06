#pragma once

#include "Boss.h"

Boss::Boss(int h, int atk, int dmg, int x, int y) :
    Character(h, atk, dmg, x, y),
    Thread()
{
    //São atribuidos valores inicias para esses atributos.

    shootAvailable = true;
    movingBackwards = true;
    sliding = false;
    attacking = false;
    dir = false;
    r1 = 0;
    r2 = 0;
    i = 0;
    indx = 0;
    spriteIndex = 0;
    X = 740;
    Y = 220;
    velX = -5;

    //Carregamento de sprites.
    loadSprites("sprites/boss/boss%d.bmp", 8, &spriteWalk);
    createMasks(&spriteWalk, &maskVector, &rotatedMaskVector);

    loadSprites("sprites/boss/bossSlide%d.bmp", 6, &spriteSlide);
    createMasks(&spriteSlide, &maskSpriteSlide, &rotatedMaskSpriteSlide);

    portrait = load_bitmap("sprites/boss/portrait.bmp", 0);
    if(!portrait)
    {
        allegro_message("Unable to load image Boss Portrait Bitmap.");
    }

    loadSprites("sprites/boss/healthbar%d.bmp", 16, &healthbar);

}

Boss::~Boss()
{

}

//Metodo que permite anexar um Jogador ao Boss.
//Uma maneira de fazer os objetos se conhecerem.
void Boss::attachPlayer(Player* pP)
{
    pAttachedPlayer = pP;
}

//Metodo que permite anexar um Timer ao Boss.
//Uma maneira de fazer os objetos se conhecerem.
void Boss::attachTimer(Timer* pT)
{
    pAttachedTimer = pT;
}

//Metodo que retorna o estado do Boss em relação a sua direçao.
//Usado em outras classes.
bool Boss::isMovingBackwards() const
{
    return movingBackwards;
}


//Funcao de movimento/ataque 1, rolar.
void Boss::roll()
{
    if (pAttachedPlayer->getX() <= this->X)
    {
        movingBackwards = true;
        velX--;
        if (velX < -22)
            velX = -22;
    }

    else if (pAttachedPlayer->getX() > this->X)
    {

        movingBackwards = false;
        velX++;
        if (velX > 22)
            velX = 22;
    }

    X += velX;
    spriteIndex++;

    if (spriteIndex > 7)
    {
        spriteIndex = 2;
    }
}

//Funcao de movimento/ataque 2. Deslizar
void Boss::slide()
{

    indx++;

    if (indx > 1)
    {
        spriteIndex++;
        indx = 0;
    }
    if (dir)
    {
        movingBackwards = false;
        velX = 10;
    }
    else
    {
        movingBackwards = true;
        velX = -10;
    }

    X += velX;
    offsetX = X;

    if (spriteIndex > 5)
    {
        sliding = false;
        spriteIndex = 0;
    }
}

//Thread de ataque, onde o Boss lança um projétil randomicamente.
DWORD Boss::threadMemberFunction()
{

    r2 = rand() % 100 + 1;
    if ((r2 > 21 && r2 < 25))
    {
        attack();
    }
}

//Método de movimento Geralm que instancia e organiza os outrso métodos.
void Boss::move()
{
    executeShot();

    if (pAttachedTimer->getDeltaT() < 1.2)
    {
            spriteIndex = 0;
    }
    else
    {
        if(health > 6)
        {
            roll();
        }
        else if (health  > 0 && health <= 6)
        {
            if (!sliding)
            {
                r1 = rand() % 100 + 1;

                if (pAttachedPlayer->getX() > this->X)
                {
                    movingBackwards = false;
                }
                else
                {
                    movingBackwards = true;
                }
            }
            if ((r1 > 0 && r1 < 5))
            {
                if (!sliding)
                {
                    if (pAttachedPlayer->getX() > this->X)
                    {
                        dir = true;
                    }
                    else
                    {
                        dir = false;
                    }
                }
                sliding = true;
                slide();


            }

            if (!attacking && !sliding)
            {
                threadMemberFunction();
            }
        }
        else
        {
            spriteIndex = 0;
        }
    }

    offsetX = X;
    maskSelector();
}

//Método de inicialização do ataque para executar o tiro / lançamento de projétil
void Boss::attack()
{
    attacking = true;
    spriteIndex = 0;
    executeShot();
}


//Execução do Tiro, cria um tiro da classe Shot dinamicamente, e deleta se o tiro passar da fronteira da tela.
void Boss::executeShot()
{
    if (attacking)
    {
        if (shootAvailable)
        {
            shootAvailable = false;

            if (isMovingBackwards())
            {
                pClayShot = new Shot(1, -SHOT_SPEED + 10, this->attackPower,this->X, this->Y + SHOT_Y + 10);
            }
            else
            {
                pClayShot = new Shot(1, SHOT_SPEED - 10, this->attackPower,this->X, this->Y + SHOT_Y + 10);
            }

        }
        else
        {
            pClayShot->move();

            if (pClayShot->getX() < 0 || pClayShot->getX() > 900 || pAttachedScenario->askCollisionCheckEnemyShotPlayer(pClayShot, pAttachedPlayer))
            {
                shootAvailable = true;
                attacking = false;
                pClayShot->deleteShot();
            }
        }
    }

}

// Método de impressão.
void Boss::print(BITMAP* pWhereToPrint)
{
    if (sliding == true)
    {
        if (!isMovingBackwards())
        {
            draw_sprite(pWhereToPrint, spriteSlide[spriteIndex], this->X, this->Y);
        }
        else
        {
            draw_sprite_h_flip(pWhereToPrint, spriteSlide[spriteIndex], this->X, this->Y);
        }
    }
    else if (attacking == true)
    {
        if (!isMovingBackwards())
        {
            draw_sprite(pWhereToPrint, spriteWalk[spriteIndex], this->X, this->Y);
        }
        else
        {
            draw_sprite_h_flip(pWhereToPrint, spriteWalk[spriteIndex], this->X, this->Y);
        }
    }
    else
    {
        if (!isMovingBackwards())
        {
            draw_sprite(pWhereToPrint, spriteWalk[spriteIndex], this->X, this->Y);
        }
        else
        {
            draw_sprite_h_flip(pWhereToPrint, spriteWalk[spriteIndex], this->X, this->Y);
        }
    }

    textprintf_ex(pWhereToPrint, font, 240, 80, makecol(255,255,255), -1, "X: %d", X);
    draw_sprite(pWhereToPrint, healthbar[health], HEALTHBAR_X + 575, HEALTHBAR_Y);
    draw_sprite(pWhereToPrint, portrait, 820, 0);
    if (!shootAvailable)
    {
        pClayShot->print(pWhereToPrint);
    }

}

// Decrementa a vida do Boss.
void Boss::decreaseHealth()
{
    if (health > 0)
    {
        health--;
    }
}

const int Boss::getHealth() const
{
    return health;
}

void Boss::setHealth(const int value)
{
    health = value;
}

//Método que verifica qual a mascara atual do Boss. Isso é utilizado para a colisão.
void Boss::maskSelector()
{
    if (sliding == true)
    {
        if (!isMovingBackwards())
        {
            actualMask = maskSpriteSlide[spriteIndex];
        }
        else
        {
            actualMask = rotatedMaskSpriteSlide[spriteIndex];
        }
    }
    else if (attacking == true)
    {
        if (!isMovingBackwards())
        {
            actualMask = maskVector[spriteIndex];
        }
        else
        {
            actualMask =  rotatedMaskVector[spriteIndex];
        }
    }
    else
    {
        if (!isMovingBackwards())
        {
            actualMask = maskVector[spriteIndex];
        }
        else
        {
            actualMask =  rotatedMaskVector[spriteIndex];
        }
    }

}

//Metodo que permite anexar um Scenario ao Boss.
//Uma maneira de fazer os objetos se conhecerem.
void Boss::attachScenario(BaseScenario* pScenario)
{
    pAttachedScenario = pScenario;
}
