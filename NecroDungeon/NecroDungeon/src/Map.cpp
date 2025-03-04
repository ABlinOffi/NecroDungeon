#include "Map.h"
#include "Tile.h"

Map::Map(float _height, float _width, float _tileSize)
{
	this->height = _height/_tileSize;
	this->width = _width/_tileSize;

	for (int i = 0; i < height; ++i)
	{
		std::vector<Tile*> tempArray;

		for (int j = 0; j < width; ++j)
		{
			Tile* tempTile = new Tile(sf::Vector2i(i * _tileSize + _tileSize/2, j * _tileSize + _tileSize/2), _tileSize, sf::Color::Green);
			tempArray.push_back(tempTile);
		}

		tileArray.push_back(tempArray);
	}
}

Map::~Map()
{

}

void Map::Draw(sf::RenderWindow& _window)
{
	for (int i = 0; i < this->height; ++i)
	{
		for (int j = 0; j < this->width; ++j)
		{
			tileArray[i][j]->Draw(_window);
		}
	}
}

std::vector<std::vector<Tile*>>& Map::GetMap()
{
	return tileArray;
}

Tile& Map::GetTile(int _x, int _y)
{
	return *tileArray[_y][_x];
}
