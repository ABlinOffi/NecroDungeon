#include "CombatManager.h"

CombatManager::CombatManager()
{
}

CombatManager::CombatManager(CombatManager& _cpy)
{
}

CombatManager::~CombatManager()
{
}

bool CombatManager::IsInRange(sf::Vector2f _enemyPos, sf::Vector2f _allyPos, int _range)
{
	//Check if pos of enemy is in range of pos ally
	return false;
}

bool CombatManager::HasAttacked(int _attackLeft)
{
	//Check if the unit is eligible for attack
	return false;
}

void CombatManager::ResolveAttack()
{
	//Compute damage and dish it out on target
	//Apply other effect if any
}
