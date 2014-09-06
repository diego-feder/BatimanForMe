#include"stdafx.h"

#include"Player.h"


Player::Player(int s, int h, int atk, int dmg, int x, int y, int vx, int vy): Character(h,atk,dmg,x,y)
{
    score = s;

    spriteIndex = 0;
    jumpSpriteIndex = 1;
    crouchSpriteIndex = 1;

    //health = 5;

    movingBackwards = false;
    leftScreenLimit = false;
    onSolidGround = false;
    takingShot = false;
    crouching = false;
    invulnerable = false;
    takingDamage = false;
    shootAvailable = true;

    collisionTime = 0.0;

    velocityX = vx;
    velocityY = vy;

    destX = x;
    destY = y;



    if(!newGame())
    {
        loadPlayer();
    }

    loadName();
    loadSprites("sprites/batman/batman%d.bmp", 17, &spriteVector);
    createMasks("sprites/batman/batman%d_collidable.bmp", 17, &maskVector, &rotatedMaskVector);

    loadSprites("sprites/batman/batmanjumping%d.bmp",5, &jumpSprites);
    createMasks(&jumpSprites, &jumpSpritesMask, &rotatedJumpSpritesMask);

    loadSprites("sprites/batman/batmancrouch%d.bmp",3, &crouchSprites);
    createMasks(&crouchSprites, &crouchSpritesMask, &rotatedCrouchSpritesMask);

    portrait = load_bitmap("sprites/batman/portrait.bmp", 0);
    if(!portrait)
    {
        allegro_message("Unable to load image Boss Portrait Bitmap.");
    }

    loadSprites("sprites/batman/healthbar%d.bmp", 6, &healthbar);

}

Player::~Player()
{
    pAttachedRanking->readFile();
    pAttachedRanking->includeScore(score, name);
    pAttachedRanking->reverseSortFile();
    pAttachedRanking->writeFile();

    savePlayer();
}


void Player::savePlayer()
{
    ofstream myfile ("bin/player.bin", ios::trunc);
    if (myfile.is_open())
    {
        myfile << X << endl;
        myfile << score << endl;
        myfile << health << endl;
        myfile.close();
    }
}

void Player::loadPlayer()
{
    string str;
    ifstream myfile("bin/player.bin");
    if(myfile.is_open())
    {
        getline(myfile, str);
        destX = atoi(str.c_str());
        getline(myfile, str);
        score = atoi(str.c_str());
        getline(myfile, str);
        health = atoi(str.c_str());
    }
    myfile.close();
}

void Player::loadName()
{
    ifstream myfile("files/player.txt", std::ifstream::in);
    if(myfile.is_open())
    {
        getline(myfile, name);
        if(name == "" || name == "/n")
        {
            name = "Batiman";
        }
        myfile.close();
    }
    else
    {
        ofstream file("files/player.txt");
        if(file.is_open())
        {
            name = "Batiman";
            file << "Batiman";
            file.close();
        }
        else
        {
            allegro_message("Unable to read and crate file");
        }
    }
}


int Player::getSpriteIndex() const
{
    return spriteIndex;
}

int Player::getJumpSpriteIndex() const
{
    return jumpSpriteIndex;
}

vector<struct PMASK*>* Player::getJumpSpritesMask()
{
    return &jumpSpritesMask;
}
vector<struct PMASK*>* Player::getRotatedJumpSpritesMask()
{
    return &rotatedJumpSpritesMask;
}

int Player::getVelocityX() const
{
	return velocityX;
}
void Player::setVelocityX(int velocity)
{
    velocityX = velocity;
}

int Player::getVelocityY() const
{
    return velocityY;
}
void Player::setVelocityY(int velocity)
{
    velocityY = velocity;
}

int Player::getScore()
{
    return Player::score;
}

void Player::setScore(int value)
{
    score = value;
}

const int Player::getHealth() const
{
    return health;
}

void Player::decreaseHealth()
{
    health--;
}

 void Player::increaseScore(const int points)
 {
     score += points;
 }

Shot* Player::getBatarang() const
{
    return pBatarang;
}

void Player::attachScenario(BaseScenario* pSc)
{
    pScenarioAttached = pSc;
}

void Player::attachRanking(Ranking* pR)
{
    pAttachedRanking = pR;
}

void Player::attack()
{
    //AINDA NAO LISTANDO ATTACK!
    executeShot();
}

void Player::enableJumpEvent()
{
    jumping = false;
}

void Player::disableJumpEvent()
{
    jumping = true;
}

void Player::enableSolidGroundEvent()
{
    onSolidGround = true;
}


void Player::disableSolidGroundEvent()
{
    onSolidGround = false;
}

void Player::enableShootAvailable()
{
    shootAvailable = true;
}

void Player::enableInvulnerable()
{
    invulnerable = true;
}

void Player::disableInvulnerable()
{
    invulnerable = false;
}

bool Player::isJumping() const
{
    return jumping;
}

bool Player::isCrouching() const
{
    return crouching;
}


bool Player::isOnSolidGround() const
{
    return onSolidGround;
}

bool Player::isMovingBackwards() const
{
    return movingBackwards;
}

bool Player::isBatarangAvailable() const
{
    return shootAvailable;
}

bool Player::isInvulnerable() const
{
    return invulnerable;
}

bool Player::isTakingDamage() const
{
    return takingDamage;
}

void Player::executeJump()
{
    if (onSolidGround /*&& !takingDamage*/)
    {
        enableJumpEvent();
        velocityY = SPEED_PLAYER_Y;

        if (key[KEY_SPACE])
        {
            disableJumpEvent();
            velocityY = -SPEED_PLAYER_Y;       // VELOCIDADE INICIAL DO PULO em stdafx.h
            //Y = Y + velocityY; // FORÇA UM PRIMEIRO PULO
            disableSolidGroundEvent(); //foi feito pois ainda não tem verificador de colisão com o chao

            (!velocityX) ? (jumpSpriteIndex = 1) : (jumpSpriteIndex = 4);
            //if(jumpSpriteIndex == 1);
            if (this->X >= SCREEN_W/2 - 100 && key[KEY_D])
            {
                jumpSpriteIndex = 4;
            }
        }
    }
    else
    {
            velocityY =  velocityY + GRAVITY;
            if (velocityY > 0)
            {
                jumpSpriteIndex = 3;
            }
            destX += velocityX;

                //Y = Y + velocityY;
                /*if (velocityY > SPEED_PLAYER_Y) //ESTABELECE UM MAXIMO NA VELOCIDADE DE DECIDA
                    velocityY = SPEED_PLAYER_Y;*/

                /*if (Y >= 300) // ALTERAR ESTE IF PARA CHAMAR FUNCAO DE COLISAO  *if (COLIDE COM O CHAO)*
                {
                    if(jumping)
                    {
                        velocityX = 0;
                        enableJumpEvent();
                    }
                    Y = Y - velocityY;
                    isOnSolidGround = true;
                }*/
    }
    destY = Y + velocityY;
}

void Player::executeDamage()
{

    if(takingDamage)
    {
        if(collisionTime < 0.00000001)
        {
            X = pScenarioAttached->getPlayerStartX();
            Y = pScenarioAttached->getPlayerStartY();
            destX = X;
            destY = Y;
            pScenarioAttached->setX(0);
            for(int i = 0 ; i < damageToTake; i++)
            {
                this->operator--();
            }
            enableInvulnerable();
            collisionTime = pScenarioAttached->getAttachedTimer()->getDeltaT();
        }
        else if((pScenarioAttached->getAttachedTimer()->getDeltaT() - collisionTime) >= 2 /*collisionCounter >= 50*/)
        {
            takingDamage = false;
            disableInvulnerable();
            collisionTime = 0.0;
        }

    }
}

void Player::executeWalk()
{

    if(onSolidGround)
    {
        velocityX = 0;

        if(key[KEY_D])
        {

            spriteIndex++;
            movingBackwards = false;
            velocityX = SPEED_PLAYER_X;
            destX += velocityX;
            if (spriteIndex >= 17)
                spriteIndex = 9;


        }

        else if(key[KEY_A])
        {
            movingBackwards = true;
            spriteIndex++;
            velocityX = (-1)*SPEED_PLAYER_X;
            destX += velocityX;
            if (spriteIndex >= 17)
                spriteIndex = 9;

        }

        if (!key[KEY_D] && !key[KEY_A])
        {
                spriteIndex = 0;
                velocityX = 0;
        }

    }


    //FAZER BOUNDRIES DO MAPA.
    /*if (this->X <= 0)
    {
        //X += SPEED_PLAYER_X;
        destX = 0;
    }

    if (this->X >= 820)
    {
        //X -= SPEED_PLAYER_X;
        destX = 820;
    }*/

}

void Player::executeShot()
{
    if (shootAvailable)
    {
        if(key[KEY_ENTER] && !isCrouching())
        {
            shootAvailable = false;
            if (isMovingBackwards())
            {
                pBatarang = new Shot(0,-SHOT_SPEED,1,this->X, this->Y + SHOT_Y);
            }
            else
            {
                if (velocityX > 0)
                {
                    pBatarang = new Shot(0,SHOT_SPEED, 1,this->X + SHOT_X + 50, this->Y + SHOT_Y);
                }
                else
                {
                    pBatarang = new Shot(0,SHOT_SPEED, 1,this->X + SHOT_X, this->Y + SHOT_Y);
                }
            }
        }
    }
    else
    {
        pBatarang->move();

        if (pBatarang->getX() < 0 || pBatarang->getX() > 900)
        {
            shootAvailable = true;
            pBatarang->deleteShot();
        }
    }
}

void Player::executeCrouch()
{
    crouching = false;
    if (isOnSolidGround() && !(key[KEY_D] || key[KEY_A]))
    {
        if (key[KEY_S])
        {
            crouchSpriteIndex = 2;
            crouching = true;
        }
    }
}

void Player::move()
{
    executeDamage();
    executeWalk();
    executeJump();
    executeCrouch();
    maskSelector();
}


void Player::print(BITMAP* pWhereToPrint)
{
    if(isJumping())
    {
        if (!isMovingBackwards())
        {
            draw_sprite(pWhereToPrint, jumpSprites[jumpSpriteIndex], X, Y);
        }
        else
        {
            draw_sprite_h_flip(pWhereToPrint, jumpSprites[jumpSpriteIndex],X, Y);
        }
    }
    else if(isCrouching())
    {
        if (!isMovingBackwards())
        {
            draw_sprite(pWhereToPrint, crouchSprites[crouchSpriteIndex], X, Y);
        }
        else
        {
            draw_sprite_h_flip(pWhereToPrint, crouchSprites[crouchSpriteIndex], X, Y);
        }
    }
    else
    {
        if (!isMovingBackwards())
        {
            draw_sprite(pWhereToPrint, spriteVector[spriteIndex], X, Y);
        }
        else
        {
            draw_sprite_h_flip(pWhereToPrint, spriteVector[spriteIndex], X, Y);
        }
    }

    draw_sprite(pWhereToPrint, healthbar[health], HEALTHBAR_X, HEALTHBAR_Y);
    draw_sprite(pWhereToPrint, portrait, 0, 0);

    textprintf_ex(pWhereToPrint, font, 100, 55, makecol(255,255,255), -1, "SCORE: %d", this->score);

    if (!shootAvailable)
    {
        pBatarang->print(pWhereToPrint);
    }

}

void Player::operator--()
{
    decreaseHealth();
}

void Player::maskSelector()
{
    if(isJumping())
    {
        if (!isMovingBackwards())
        {
            actualMask = jumpSpritesMask[jumpSpriteIndex];
        }
        else
        {
            actualMask = rotatedJumpSpritesMask[jumpSpriteIndex];
        }
    }
    else if(isCrouching())
    {
        if (!isMovingBackwards())
        {
            actualMask = crouchSpritesMask[crouchSpriteIndex];
        }
        else
        {
            actualMask = rotatedCrouchSpritesMask[crouchSpriteIndex];
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
            actualMask = rotatedMaskVector[spriteIndex];
        }
    }
}



void Player::enableTakingDamage(const int dmg)
{
    takingDamage = true;
    damageToTake = dmg;
}
