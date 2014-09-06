#pragma once

#include "BaseScenario.h"

class BaseScenario;
class Player;

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

	bool collisionCheckPlayerDamageAbleEntity(Player* pPlayer, DamageAbleEntity* pEntity, int dx, int dy);
	bool collisionCheckPlayerDamageAbleEntities(int dx, int dy, int* dmg);
	void collisionCheckPlayerMap(Player* pPlayer);
	bool collisionCheckShotCharacter(Shot* pShot,Character* pCharacter);
	void collisionCheckShotCharacters();
	bool collisionCheckEnemyShotPlayer(Shot* pShot,Player* pPlayer);

	void attachScenario(BaseScenario* pScenario);

    struct PMASK* shotMask;
    struct PMASK* characterMask;
    struct PMASK* playerMask;
    struct PMASK* mapMask;
    struct PMASK* entityMask;

private:

	BaseScenario* pAttachedScenario;

};

