#include "Units.h"

Unit::Unit(int _maxHealth, int _attack, int _movement, int _range)
{
	stats.push_back(_maxHealth);
	stats.push_back(_maxHealth);
	stats.push_back(_attack);
	stats.push_back(_movement);
	stats.push_back(_range);
}

Unit::Unit(Unit& _cpy)
{
	name = _cpy.GetName();
	if (stats.size() < (int)UnitStat::ENUMSIZE)
	{
		stats.resize((int)UnitStat::ENUMSIZE);
	}

	for (int i = 0; i < (int)UnitStat::ENUMSIZE; ++i)
	{
		stats[(int)UnitStat::ENUMSIZE] = _cpy.GetStat((UnitStat)i);
	}
}

Unit::~Unit()
{
}

std::string Unit::GetName()
{
	return name;
}

float Unit::GetStat(UnitStat _stat)
{
	return stats[(int)_stat];
}

void Unit::ApplyDamage(float _dmg)
{
	stats[(int)UnitStat::CURRENTHEALTH] -= _dmg;
	if (stats[(int)UnitStat::CURRENTHEALTH] <= 0)
		isAlive = false;
};