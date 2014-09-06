#include "CollisionManager.h"

/*Classe que gerencia a verifica��o das colis�es do jogo*/

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{

}

/*Fun��o que verifica se o player est� colidindo com uma inst�nicia
da classe DamageAbleEntity em uma posi��o deslocada (dx,dy) que est� entre (X,Y)
e (destX,destY)

Par�metros de entrada:

 pPlayer: Ponteiro para o Player sobre o qual se quer fazer a verifica��o
 pEnitty: Ponteiro para a DamageAbleEntity sobre a qual se quer fazer a verifica��o
 dx: deslocamento dx partindo da origem do player
 dy: deslocamento dy partindo da origem do player;

Retorno: Em caso de colis�o retorna true

*/

bool CollisionManager::collisionCheckPlayerDamageAbleEntity(Player* pPlayer, DamageAbleEntity* pEntity, int dx, int dy)
{
    playerMask = pPlayer->getActualMask();
    entityMask = pEntity->getActualMask();

    return check_pmask_collision(playerMask, entityMask, pPlayer->getX()+dx+pAttachedScenario->getX(),pPlayer->getY()+dy,pEntity->getOffsetX(),pEntity->getY());
}

/*Fun��o que percorre a lista parametrizada com DamageAbleEntity e para cada
inst�ncia presente na lista chama o m�todo collisionCheckPlayerDamageAbleEntity()
para um determinado (dx,dy). Caso haja colis�o, transfere � vari�vel dmg o valor
do dano causado pelo objeto em caso de toque.

Par�metros de entrada:

 dx: deslocamento dx partindo da origem do player;
 dy: deslocamento dy partindo da origem do player;
 dmg: ponteiro para int que receber�, caso exista colis�o, o valor do dano
 causado ao toque.

Retorno: Caso exista alguma inst�ncia dentro da lista colidindo com player o retorno
� true;
*/

bool CollisionManager::collisionCheckPlayerDamageAbleEntities(int dx, int dy,int* dmg)
{
    int index;
    bool result;

    //Percorre a lista at� ela acabar ou at� que alguma colis�o seja encontrada

    for(index = 0, result = false; (index < pAttachedScenario->getDamageAbleEntityList()->getListSize()) && !result; index++)
    {
        result = collisionCheckPlayerDamageAbleEntity(pAttachedScenario->getAttachedPlayer(), (*(pAttachedScenario->getDamageAbleEntityList()))[index],dx,dy);
    }

    //Transmite � dmg o valor da variavel damage do objeto

    if(result)
    {
       *dmg =  (*(pAttachedScenario->getDamageAbleEntityList()))[index-1]->getDamage();
    }

    return result;
}

/*Fun��o que tenta deslocar o personagem at� seu destino (destX,destY)
verificando colis�es a priori com o mapa e fazendo chamadas para verificar colis�es
com as entidades que podem causar danos

O funcionamento geral � o seguinte: o personagem quando se move indica que
sua futura posi��o, que caso n�o haja colis�o ser� (destX,destY). Essa fun��o
verifica a dist�ncia do ponto de origem at� o destino e anda incrementalmente.

Caso exista colis�o com o mapa a rotina trata essa colis�o tentando verificar
se h� possibilidade de andar em uma s� dire��o ou se as duas dire�oes est�o bloqueadas.

Existindo colis�o final, ou seja, se houver um ponto no caminho
entre (X,Y) - (destX,destY) em que o personagem n�o consegue andar em nenhuma dire��o
(que avance rumo ao destino), o la�o ser� interrompido.

Caso o personagem consiga andar at� o ponto incremental ent�o ser� necess�rio fazer a
verifica��o de colis�o com entidades. Ocorr�ncia de colis�o significa
interrup��o do la�o (e tomar as provid�ncias de danificar o personagem),
n�o exist�ncia de colis�o prossegue o la�o.

Se no meio do caminh�o o la�o n�o for interrompido (seja por colis�o com mapa, seja
 por colis�o com entidades, ent�o o la�o acaba no ponto final.


Par�metros de entrada:

 pPlayer: ponteiro para a inst�ncia de Player sobre a qual a verifica��o ocorrer�

Retorno: Sem retorno
*/

void CollisionManager::collisionCheckPlayerMap(Player* pPlayer)
{
    //A m�scara atual do personagem e a m�scara do mapa s�o carregadas

    playerMask = pPlayer->getActualMask();
    mapMask =  pAttachedScenario->getMaskVector()->at(0);

    //Vari�vel que armazena o valor da verifica��o se existiu colis�o
    bool collided;

    //O m�dulo da dist�ncia entre o ponto de origem (X,Y) at� o destino (destX,destY)
    //em cada componente � calculado

    int distanceX = sqrt((pPlayer->getX()-pPlayer->getDestX())*(pPlayer->getX()-pPlayer->getDestX()));
    int distanceY = sqrt((pPlayer->getY()-pPlayer->getDestY())*(pPlayer->getY()-pPlayer->getDestY()));

    //Vari�veis utilizadas para representar o deslocamento incremental
    int dx;
    int dy;
    //Vari�vel que armazena, caso exista, o dano que ser� recebido pelo personagem
    int dmg;

    dx = 0;
    dy = 0;

    //Vari�veis que representam a dire��o do deslocamento em X e Y do personagem
    int signaly = 1;
    int signalx = 1;

    //As dire��es em X e Y s�o calculadas
    if(pPlayer->getVelocityX() < 0)
    {
        signalx = -1;
    }

    if(pPlayer->getVelocityY()<0)
    {
        signaly = -1;
    }

    //Vari�veis que indicam em que dire��o o deslocamento est� acontecendo e
    //se est� acontecendo
    bool runx = true;
    bool runy = true;
    bool run = true;


    /*No come�o do la�o de cada incrimento � feita uma verifica��o se o ponto desejado
    j� foi alcan�ado e se o deslocamento em alguma dire��o j� foi alcan�ado. No primeiro
    caso o la�o � finalizado (por motivos �bvios). No segundo a dire��o cujo deslocamento
    desejado foi alcan�ado ser� desabilitada, ou seja, o personagem n�o mais andar� em
    tal dire��o.

    Posteriormente as vari�veis de deslocamento cujas dire��es estiverem habilitadas
    receber�o incremento. Uma colis�o com o mapa ser� verificada no ponto (X+dx, Y+dy).

        Caso n�o exista colis�o no novo ponto, realiza-se uma verifica��o se n�o existe
        colis�o com alguma entidade.

            Caso exista colis�o com a entidade o la�o � quebrado
            Caso contr�rio o la�o proseegue

        Caso exista colis�o no novo ponto o ponto � decrementado a fim de verificar
        qual � a dire��o que est� impossibilitada de ser incrementado

            Anda s� por X e verifica se houve colis�o

                Em caso afirmativo volta para o ponto anterior, se desloca por Y
                e verifica colis�o

                    Em caso afirmativo, essa � uma colis�o final e o personagem n�o
                    se desloca

                        Em caso negativo verifica se houve colis�o com entidades

                    Em caso negativo, desabilita a dire��o X e se desloca s� por Y

                Em caso negativo desabilita a dire��o Y e se desloca s� por X
        */

        while(run)
        {

            //Verifica se os deslocamento em cada uma das dire��es
            //j� atingiu seu destino
            if(sqrt(dx*dx) >= distanceX) runx = false;
            if(sqrt(dy*dy) >= distanceY) runy = false;

            //Caso as duas dire��es estejam desabilitadas o la�o
            //deve ser encerrado;
            if(!runx && !runy)
            {
                run = false;
                break;
            }

            //Incrementa as dire��es que estejam habilitadas
            if(runx) dx += 1*signalx;
            if(runy) dy += 1*signaly;

            //Verifica se h� colis�o no novo ponto
            collided = check_pmask_collision(playerMask, mapMask, pAttachedScenario->getX() + pPlayer->getX()+dx,pPlayer->getY()+dy,0,SCREEN_H - mapMask->h);
            if(collided)
            {
                //Caso haja colis�o e as duas dire��es est�o habilitadas
                if((runx&&runy))
                {
                    //Volta � o ponto anterior e anda apenas por Y
                    dx -= 1*signalx;
                    dy -= 1*signaly;
                    dy += 1*signaly;
                    collided = check_pmask_collision(playerMask, mapMask, pAttachedScenario->getX() + pPlayer->getX()+dx,pPlayer->getY()+dy,0,SCREEN_H - mapMask->h);
                    if(collided)
                    {
                        //Caso andar s� por Y cause colis�o, volta ao ponto anterior
                        //e anda s� por X
                        dy -= 1*signaly;
                        dx += 1*signalx;
                        collided = check_pmask_collision(playerMask, mapMask, pAttachedScenario->getX() + pPlayer->getX()+dx,pPlayer->getY()+dy,0,SCREEN_H - mapMask->h);
                        if(collided)
                        {
                            //Caso andar s� por X tamb�m cause colis�o,� imposs�vel
                            //se deslocar, volta ao ponto anterior e o la�o � encerrado
                            dx -= 1*signalx;
                            run = false;
                            break;
                        }
                        else
                        {
                            //Caso andar s� por X n�o cause colis�o,ent�o X est� livre
                            //e Y deve ser desabilitado, al�m disso o personagem est�
                            //pisando em algo s�lido.
                            runy = false;
                            pPlayer->enableJumpEvent();
                            pPlayer->enableSolidGroundEvent();
                            //Verificar se existe colis�o com entidades � necess�rio
                            if(collisionCheckPlayerDamageAbleEntities(dx,dy, &dmg) && !pPlayer->isInvulnerable())
                            {
                                //Caso ache colis�o com alguma entidade
                                //o dano de tal entidade deve ser transmitido ao player
                                //e o personagem deve ir ao ponto anterior
                                dy -= 1*signaly;
                                pPlayer->enableTakingDamage(dmg);
                                break;
                            }
                        }
                    }
                    else
                    {
                        //Caso andar s� por Y n�o cause colis�o, ent�o desabilita
                        //o eixo X
                        runx = false;

                        //Verifica se h� colis�o com alguma entidade
                        if(collisionCheckPlayerDamageAbleEntities(dx,dy,&dmg) && !pPlayer->isInvulnerable())
                        {
                             dx -= 1*signalx;
                             pPlayer->enableTakingDamage(dmg);
                             break;
                        }

                    }
                }
                else
                {
                    //Caso apenas uma das dire��es esteja habilitada n�o h� como testar
                    //outro caminho, ent�o existe uma colis�o final

                    if(runy && !runx)
                    {
                        dy -= 1*signaly;
                        runy = false;
                        pPlayer->enableJumpEvent();
                        pPlayer->enableSolidGroundEvent();
                        if(collisionCheckPlayerDamageAbleEntities(dx,dy,&dmg))
                        {
                             pPlayer->enableTakingDamage(dmg);
                             break;
                        }
                    }
                    else if(runx && !runy)
                    {
                        dx -= 1*signalx;
                        runx = false;
                    }
                    break;
                }

        }
        else
        {
            //Caso n�o exista colis�o no ponto incremental.

            //Faz-se necess�rio verificar colis�o com entidades
           if(collisionCheckPlayerDamageAbleEntities(dx, dy, &dmg) && !pPlayer->isInvulnerable())
           {
                dx -= 1*signalx;
                dy -= 1*signaly;
                pPlayer->enableTakingDamage(dmg);
                break;
           }
        }

}

    //Coloca o personagem no ponto sem colis�o mais pr�ximo
    //do ponto de destino que est� no caminho para este.
    pPlayer->setDestX(pPlayer->getX() + dx);
    pPlayer->setDestY(pPlayer->getY() + dy);

    pPlayer->setX(pPlayer->getDestX());
    pPlayer->setY(pPlayer->getDestY());

}

/*Fun��o que verifica se existe colis�o entre um proj�til de Player e
um Character espec�fico

Par�metros de entrada:

 pShot: ponteiro para o proj�til
 pCharacter: ponteiro para o Character;

Retorno: retorna true em caso de colis�o
*/


bool CollisionManager::collisionCheckShotCharacter(Shot* pShot,Character* pCharacter)
{
    shotMask = pShot->getActualMask();

    characterMask = pCharacter->getActualMask();

    return check_pmask_collision(shotMask, characterMask, pShot->getX(),pShot->getY(),pCharacter->getX(),pCharacter->getY());
}


/*Percorre a lista de Characters associada � fase atual, verificando
se existe colis�o entre algum dos Characters e um proj�til do Player.
Em caso afirmativo toma as a��es necess�rias

Par�metros de entrada:

 pShot: ponteiro para o proj�til
 pCharacter: ponteiro para o Character;

Retorno: sem retorno
*/

void CollisionManager::collisionCheckShotCharacters()
{
    int index;
    bool result;

        //Persiste no la�o at� que alguma colis�o seja verificado afirmativa
        //ou se atingir o final da lista
        for(index = 0, result = false; index < pAttachedScenario->getCharacterList()->size();index++)
        {
            //Verifica se existe colis�o
            result = collisionCheckShotCharacter(pAttachedScenario->getAttachedPlayer()->getBatarang(),pAttachedScenario->getCharacterList()->at(index));
            if(result)
            {
                //Caso exista colis�o remove uma vida do personagem atingido
                (*(pAttachedScenario->getCharacterList()->at(index)))--;

                //Habilita o uso de novos proj�teis pelo jogador
                pAttachedScenario->getAttachedPlayer()->enableShootAvailable();
                pAttachedScenario->getAttachedPlayer()->increaseScore((pAttachedScenario->getCharacterList()->at(index)->getHealth() + 1)*10);


                if(pAttachedScenario->getCharacterList()->at(index)->getHealth() <= 0)
                {
                    //Caso a vida do personagem atingido atinja 0 aumenta a pontua��o do jogador
                    //proporcionalmente � o dano causado pelo personagem
                    //pAttachedScenario->getAttachedPlayer()->increaseScore(pAttachedScenario->getCharacterList()->at(index)->getHealth());

                    //Remove o personagem da lista parametrizada com DamageAbleEntity e da lista de Characters
                    pAttachedScenario->getDamageAbleEntityList()->remove(pAttachedScenario->getCharacterList()->at(index));
                    pAttachedScenario->getCharacterList()->excludeCharacter(index);

                }
            break;
            }
        }

}

/*Verifica se algum proj�til inimigo atingiu o jogador

Par�metros de entrada:

 pShot: ponteiro para o proj�til
 pPlayer: ponteiro para o jogador;

Retorno: afirmativo caso o proj�til atinja o jogador
*/



bool CollisionManager::collisionCheckEnemyShotPlayer(Shot* pShot,Player* pPlayer)
{
    shotMask = pShot->getActualMask();
    playerMask = pPlayer->getActualMask();

    if((check_pmask_collision(shotMask, playerMask, pShot->getX(),pShot->getY(),pPlayer->getX(),pPlayer->getY()))&&!pPlayer->isInvulnerable())
    {
        pPlayer->enableTakingDamage(pShot->getDamage());
    }

}

/*Anexa uma fase ao gerenciador de colis�es e tamb�m invoca o m�todo
dessa para anexar o gerenciador de colis�es nela.

Par�metros de entrada:

 pSc: ponteiro para a fase a ser anexada

Retorno: sem retorno
*/


void CollisionManager::attachScenario(BaseScenario* pSc)
{
    pAttachedScenario = pSc;
    pAttachedScenario->attachCollisionManager(this);
}




