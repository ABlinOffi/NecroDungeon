#include "Tile.h"

Tile::Tile(sf::Vector2i _pos, float _size, sf::Color _color)
{
	this->pos = _pos;
	this->size = _size;

	shape.setFillColor(_color);
	shape.setSize(sf::Vector2f(size, size));
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(-1);
	shape.setOrigin(sf::Vector2f(size / 2, size / 2));
	shape.setPosition(sf::Vector2f(_pos.x, _pos.y));
}

Tile::~Tile()
{
	
}

void Tile::Draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}

bool Tile::operator==(Tile _tile)
{
	if (pos.x != _tile.pos.x || pos.y != _tile.pos.y)
	{
		return false;
	}
	return true;
}

const sf::Vector2i& Tile::GetPos()
{
	return pos;
}

void Tile::SetColor(sf::Color _color)
{
	shape.setFillColor(_color);
}
