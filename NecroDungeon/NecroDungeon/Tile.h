#pragma once

#include "Definitions.h"

class Tile
{
public:
	Tile() = default;
	Tile(sf::Vector2i _pos, float _size, sf::Color _color);
	~Tile();

	int fScore;

	virtual void Draw(sf::RenderWindow& _window);
	bool operator==(Tile);

	const sf::Vector2i& GetPos();

protected:
	sf::Vector2i pos;
	float size;
	sf::RectangleShape shape;

};