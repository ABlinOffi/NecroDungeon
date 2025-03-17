#pragma once

#include "../Definitions.h"

class Tile;

class Map
{
public:
	Map(float _height, float _width, float _tileSize);
	~Map();

	void Draw(sf::RenderWindow& _window);

	std::vector<std::vector<Tile*>>& GetMap();
	Tile& GetTile(int _x, int _y);
	void TileClicked(sf::Vector2i _mousePos);
	void CleanMap();
	void SetToWalkable(std::vector<Tile*>& _tiles);

private:
	std::vector<std::vector<Tile*>> tileArray;
	float height;
	float width;

};