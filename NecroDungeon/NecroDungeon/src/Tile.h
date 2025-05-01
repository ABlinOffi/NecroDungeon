#pragma once

#include "../Definitions.h"
#include "../interfaces/IInteractable.h"

class Unit;

class Tile : IInteractable
{
public:
	Tile() = default;
	Tile(sf::Vector2i _pos, float _size, sf::Color _color);
	~Tile();

	int fScore;

	virtual void Draw(sf::RenderWindow& _window);
	bool operator==(Tile);

	const sf::Vector2i& GetPos();
	void SetColor(sf::Color _color);
	void SetUnit(Unit* _unit);
	Unit* GetUnitOnTile();
	//interface methods
	bool IsCursorInside(sf::Vector2i _mousePos) override;

private:
	sf::Vector2i pos;
	float size;
	sf::RectangleShape shape;
	Unit* unit;

};