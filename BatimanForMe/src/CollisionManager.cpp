#include "CollisionManager.h"

/*Classe que gerencia a verificação das colisões do jogo*/

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{

}

/*Função que verifica se o player está colidindo com uma instânicia
da classe DamageAbleEntity em uma posição deslocada (dx,dy) que está entre (X,Y)
e (destX,destY)

Parâmetros de entrada:

 pPlayer: Ponteiro para o Player sobre o qual se quer fazer a verificação
 pEnitty: Ponteiro para a DamageAbleEntity sobre a qual se quer fazer a verificação
 dx: deslocamento dx partindo da origem do player
 dy: deslocamento dy partindo da origem do player;

Retorno: Em caso de colisão retorna true

*/

bool CollisionManager::collisionCheckPlayerDamageAbleEntity(Player* pPlayer, DamageAbleEntity* pEntity, int dx, int dy)
{
    playerMask = pPlayer->getActualMask();
    entityMask = pEntity->getActualMask();

    return check_pmask_collision(playerMask, entityMask, pPlayer->getX()+dx+pAttachedScenario->getX(),pPlayer->getY()+dy,pEntity->getOffsetX(),pEntity->getY());
}

/*Função que percorre a lista parametrizada com DamageAbleEntity e para cada
instância presente na lista chama o método collisionCheckPlayerDamageAbleEntity()
para um determinado (dx,dy). Caso haja colisão, transfere à variável dmg o valor
do dano causado pelo objeto em caso de toque.

Parâmetros de entrada:

 dx: deslocamento dx partindo da origem do player;
 dy: deslocamento dy partindo da origem do player;
 dmg: ponteiro para int que receberá, caso exista colisão, o valor do dano
 causado ao toque.

Retorno: Caso exista alguma instância dentro da lista colidindo com player o retorno
é true;
*/

bool CollisionManager::collisionCheckPlayerDamageAbleEntities(int dx, int dy,int* dmg)
{
    int index;
    bool result;

    //Percorre a lista até ela acabar ou até que alguma colisão seja encontrada

    for(index = 0, result = false; (index < pAttachedScenario->getDamageAbleEntityList()->getListSize()) && !result; index++)
    {
        result = collisionCheckPlayerDamageAbleEntity(pAttachedScenario->getAttachedPlayer(), (*(pAttachedScenario->getDamageAbleEntityList()))[index],dx,dy);
    }

    //Transmite à dmg o valor da variavel damage do objeto

    if(result)
    {
       *dmg =  (*(pAttachedScenario->getDamageAbleEntityList()))[index-1]->getDamage();
    }

    return result;
}

/*Função que tenta deslocar o personagem até seu destino (destX,destY)
verificando colisões a priori com o mapa e fazendo chamadas para verificar colisões
com as entidades que podem causar danos

O funcionamento geral é o seguinte: o personagem quando se move indica que
sua futura posição, que caso não haja colisão será (destX,destY). Essa função
verifica a distância do ponto de origem até o destino e anda incrementalmente.

Caso exista colisão com o mapa a rotina trata essa colisão tentando verificar
se há possibilidade de andar em uma só direção ou se as duas direçoes estão bloqueadas.

Existindo colisão final, ou seja, se houver um ponto no caminho
entre (X,Y) - (destX,destY) em que o personagem não consegue andar em nenhuma direção
(que avance rumo ao destino), o laço será interrompido.

Caso o personagem consiga andar até o ponto incremental então será necessário fazer a
verificação de colisão com entidades. Ocorrência de colisão significa
interrupção do laço (e tomar as providências de danificar o personagem),
não existência de colisão prossegue o laço.

Se no meio do caminhão o laço não for interrompido (seja por colisão com mapa, seja
 por colisão com entidades, então o laço acaba no ponto final.


Parâmetros de entrada:

 pPlayer: ponteiro para a instância de Player sobre a qual a verificação ocorrerá

Retorno: Sem retorno
*/

void CollisionManager::collisionCheckPlayerMap(Player* pPlayer)
{
    //A máscara atual do personagem e a máscara do mapa são carregadas

    playerMask = pPlayer->getActualMask();
    mapMask =  pAttachedScenario->getMaskVector()->at(0);

    //Variável que armazena o valor da verificação se existiu colisão
    bool collided;

    //O módulo da distância entre o ponto de origem (X,Y) até o destino (destX,destY)
    //em cada componente é calculado

    int distanceX = sqrt((pPlayer->getX()-pPlayer->getDestX())*(pPlayer->getX()-pPlayer->getDestX()));
    int distanceY = sqrt((pPlayer->getY()-pPlayer->getDestY())*(pPlayer->getY()-pPlayer->getDestY()));

    //Variáveis utilizadas para representar o deslocamento incremental
    int dx;
    int dy;
    //Variável que armazena, caso exista, o dano que será recebido pelo personagem
    int dmg;

    dx = 0;
    dy = 0;

    //Variáveis que representam a direção do deslocamento em X e Y do personagem
    int signaly = 1;
    int signalx = 1;

    //As direções em X e Y são calculadas
    if(pPlayer->getVelocityX() < 0)
    {
        signalx = -1;
    }

    if(pPlayer->getVelocityY()<0)
    {
        signaly = -1;
    }

    //Variáveis que indicam em que direção o deslocamento está acontecendo e
    //se está acontecendo
    bool runx = true;
    bool runy = true;
    bool run = true;


    /*No começo do laço de cada incrimento é feita uma verificação se o ponto desejado
    já foi alcançado e se o deslocamento em alguma direção já foi alcançado. No primeiro
    caso o laço é finalizado (por motivos óbvios). No segundo a direção cujo deslocamento
    desejado foi alcançado será desabilitada, ou seja, o personagem não mais andará em
    tal direção.

    Posteriormente as variáveis de deslocamento cujas direções estiverem habilitadas
    receberão incremento. Uma colisão com o mapa será verificada no ponto (X+dx, Y+dy).

        Caso não exista colisão no novo ponto, realiza-se uma verificação se não existe
        colisão com alguma entidade.

            Caso exista colisão com a entidade o laço é quebrado
            Caso contrário o laço proseegue

        Caso exista colisão no novo ponto o ponto é decrementado a fim de verificar
        qual é a direção que está impossibilitada de ser incrementado

            Anda só por X e verifica se houve colisão

                Em caso afirmativo volta para o ponto anterior, se desloca por Y
                e verifica colisão

                    Em caso afirmativo, essa é uma colisão final e o personagem não
                    se desloca

                        Em caso negativo verifica se houve colisão com entidades

                    Em caso negativo, desabilita a direção X e se desloca só por Y

                Em caso negativo desabilita a direção Y e se desloca só por X
        */

        while(run)
        {

            //Verifica se os deslocamento em cada uma das direções
            //já atingiu seu destino
            if(sqrt(dx*dx) >= distanceX) runx = false;
            if(sqrt(dy*dy) >= distanceY) runy = false;

            //Caso as duas direções estejam desabilitadas o laço
            //deve ser encerrado;
            if(!runx && !runy)
            {
                run = false;
                break;
            }

            //Incrementa as direções que estejam habilitadas
            if(runx) dx += 1*signalx;
            if(runy) dy += 1*signaly;

            //Verifica se há colisão no novo ponto
            collided = check_pmask_collision(playerMask, mapMask, pAttachedScenario->getX() + pPlayer->getX()+dx,pPlayer->getY()+dy,0,SCREEN_H - mapMask->h);
            if(collided)
            {
                //Caso haja colisão e as duas direções estão habilitadas
                if((runx&&runy))
                {
                    //Volta à o ponto anterior e anda apenas por Y
                    dx -= 1*signalx;
                    dy -= 1*signaly;
                    dy += 1*signaly;
                    collided = check_pmask_collision(playerMask, mapMask, pAttachedScenario->getX() + pPlayer->getX()+dx,pPlayer->getY()+dy,0,SCREEN_H - mapMask->h);
                    if(collided)
                    {
                        //Caso andar só por Y cause colisão, volta ao ponto anterior
                        //e anda só por X
                        dy -= 1*signaly;
                        dx += 1*signalx;
                        collided = check_pmask_collision(playerMask, mapMask, pAttachedScenario->getX() + pPlayer->getX()+dx,pPlayer->getY()+dy,0,SCREEN_H - mapMask->h);
                        if(collided)
                        {
                            //Caso andar só por X também cause colisão,é impossível
                            //se deslocar, volta ao ponto anterior e o laço é encerrado
                            dx -= 1*signalx;
                            run = false;
                            break;
                        }
                        else
                        {
                            //Caso andar só por X não cause colisão,então X está livre
                            //e Y deve ser desabilitado, além disso o personagem está
                            //pisando em algo sólido.
                            runy = false;
                            pPlayer->enableJumpEvent();
                            pPlayer->enableSolidGroundEvent();
                            //Verificar se existe colisão com entidades é necessário
                            if(collisionCheckPlayerDamageAbleEntities(dx,dy, &dmg) && !pPlayer->isInvulnerable())
                            {
                                //Caso ache colisão com alguma entidade
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
                        //Caso andar só por Y não cause colisão, então desabilita
                        //o eixo X
                        runx = false;

                        //Verifica se há colisão com alguma entidade
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
                    //Caso apenas uma das direções esteja habilitada não há como testar
                    //outro caminho, então existe uma colisão final

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
            //Caso não exista colisão no ponto incremental.

            //Faz-se necessário verificar colisão com entidades
           if(collisionCheckPlayerDamageAbleEntities(dx, dy, &dmg) && !pPlayer->isInvulnerable())
           {
                dx -= 1*signalx;
                dy -= 1*signaly;
                pPlayer->enableTakingDamage(dmg);
                break;
           }
        }

}

    //Coloca o personagem no ponto sem colisão mais próximo
    //do ponto de destino que está no caminho para este.
    pPlayer->setDestX(pPlayer->getX() + dx);
    pPlayer->setDestY(pPlayer->getY() + dy);

    pPlayer->setX(pPlayer->getDestX());
    pPlayer->setY(pPlayer->getDestY());

}

/*Função que verifica se existe colisão entre um projétil de Player e
um Character específico

Parâmetros de entrada:

 pShot: ponteiro para o projétil
 pCharacter: ponteiro para o Character;

Retorno: retorna true em caso de colisão
*/


bool CollisionManager::collisionCheckShotCharacter(Shot* pShot,Character* pCharacter)
{
    shotMask = pShot->getActualMask();

    characterMask = pCharacter->getActualMask();

    return check_pmask_collision(shotMask, characterMask, pShot->getX(),pShot->getY(),pCharacter->getX(),pCharacter->getY());
}


/*Percorre a lista de Characters associada à fase atual, verificando
se existe colisão entre algum dos Characters e um projétil do Player.
Em caso afirmativo toma as ações necessárias

Parâmetros de entrada:

 pShot: ponteiro para o projétil
 pCharacter: ponteiro para o Character;

Retorno: sem retorno
*/

void CollisionManager::collisionCheckShotCharacters()
{
    int index;
    bool result;

        //Persiste no laço até que alguma colisão seja verificado afirmativa
        //ou se atingir o final da lista
        for(index = 0, result = false; index < pAttachedScenario->getCharacterList()->size();index++)
        {
            //Verifica se existe colisão
            result = collisionCheckShotCharacter(pAttachedScenario->getAttachedPlayer()->getBatarang(),pAttachedScenario->getCharacterList()->at(index));
            if(result)
            {
                //Caso exista colisão remove uma vida do personagem atingido
                (*(pAttachedScenario->getCharacterList()->at(index)))--;

                //Habilita o uso de novos projéteis pelo jogador
                pAttachedScenario->getAttachedPlayer()->enableShootAvailable();
                pAttachedScenario->getAttachedPlayer()->increaseScore((pAttachedScenario->getCharacterList()->at(index)->getHealth() + 1)*10);


                if(pAttachedScenario->getCharacterList()->at(index)->getHealth() <= 0)
                {
                    //Caso a vida do personagem atingido atinja 0 aumenta a pontuação do jogador
                    //proporcionalmente à o dano causado pelo personagem
                    //pAttachedScenario->getAttachedPlayer()->increaseScore(pAttachedScenario->getCharacterList()->at(index)->getHealth());

                    //Remove o personagem da lista parametrizada com DamageAbleEntity e da lista de Characters
                    pAttachedScenario->getDamageAbleEntityList()->remove(pAttachedScenario->getCharacterList()->at(index));
                    pAttachedScenario->getCharacterList()->excludeCharacter(index);

                }
            break;
            }
        }

}

/*Verifica se algum projétil inimigo atingiu o jogador

Parâmetros de entrada:

 pShot: ponteiro para o projétil
 pPlayer: ponteiro para o jogador;

Retorno: afirmativo caso o projétil atinja o jogador
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

/*Anexa uma fase ao gerenciador de colisões e também invoca o método
dessa para anexar o gerenciador de colisões nela.

Parâmetros de entrada:

 pSc: ponteiro para a fase a ser anexada

Retorno: sem retorno
*/


void CollisionManager::attachScenario(BaseScenario* pSc)
{
    pAttachedScenario = pSc;
    pAttachedScenario->attachCollisionManager(this);
}




