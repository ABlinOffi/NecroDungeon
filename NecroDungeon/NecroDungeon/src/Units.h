#pragma once

#include "../Definitions.h"

enum class UnitStat
{
	CURRENTHEALTH,
	MAXHEALTH,
	ATTACK,
	MOVEMENT,
	RANGE,
	ENUMSIZE
};

class Unit
{
public:
	Unit(int _maxHealth, int _attack, int _movement, int _range);
	Unit(Unit& _cpy);
	~Unit();

	std::string GetName();
	float GetStat(UnitStat _stat);
	void ApplyDamage(float _dmg);

protected:
	std::string name;
	std::vector<float> stats;
	bool isAlive = true;

};
