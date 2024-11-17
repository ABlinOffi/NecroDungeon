#pragma once

#include "Definitions.h"

class Tile
{
public:
	Tile() = default;
	Tile(sf::Vector2f _pos, float _size, sf::Color _color);
	~Tile();
	virtual void Draw(sf::RenderWindow& _window);

protected:
	sf::Vector2f pos;
	float size;
	sf::RectangleShape shape;

};