#pragma once

#include "../../Definitions.h"

enum class SkillType
{
	ACTIVE,
	PASSIVE
};

class Skill
{
public:
	bool IsSkillReady() { return currCooldown == 0; };
	float GetCurrCooldown() { return currCooldown; };
	void ReduceCooldown(float _dt) { currCooldown -= _dt; if (currCooldown < 0) currCooldown = 0; };

private:
	SkillType skillType;
	int cooldown;
	float currCooldown;

};

class Unit
{
public:

private:
	std::string name;
	int maxHealth;
	int currHealth;
	float attack;
	float defense;
	int attackModifier;
	int defenseModifier;
	std::vector<Skill> skills;

};
