#pragma once

#include "../Definitions.h"

class CombatManager
{
public:
	CombatManager();
	CombatManager(CombatManager& _cpy);
	~CombatManager();

	bool IsInRange(sf::Vector2f _enemyPos, sf::Vector2f _allyPos, int _range);
	bool HasAttacked(int _attackLeft);
	void ResolveAttack();

private:

};