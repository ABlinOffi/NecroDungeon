#include "Tile.h"

Tile::Tile(sf::Vector2f _pos, float _size, sf::Color _color)
{
	this->pos = _pos;
	this->size = _size;

	shape.setFillColor(_color);
	shape.setSize(sf::Vector2f(size, size));
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(-1);
	shape.setOrigin(sf::Vector2f(size / 2, size / 2));
	shape.setPosition(_pos);
}

Tile::~Tile()
{
	
}

void Tile::Draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}