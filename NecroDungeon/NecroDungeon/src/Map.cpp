#include "Map.h"
#include "Tile.h"

Map::Map(float _height, float _width, float _tileSize)
{
	this->height = _height / _tileSize;
	this->width = _width / _tileSize;

	for (int i = 0; i < height; ++i)
	{
		std::vector<Tile*> tempArray;

		for (int j = 0; j < width; ++j)
		{
			Tile* tempTile = new Tile(sf::Vector2i(i * _tileSize + _tileSize / 2, j * _tileSize + _tileSize / 2), _tileSize, sf::Color::Green);
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

void Map::TileClicked(sf::Vector2i _mousePos)
{
	Tile** clickedTile = nullptr;

	CleanMap();
	for (int i = 0; i < tileArray.size(); ++i)
	{
		for (int j = 0; j < tileArray[i].size(); ++j)
		{
			if (tileArray[i][j]->IsCursorInside(_mousePos))
			{
				clickedTile = &tileArray[i][j];
			}
		}
	}

	if (clickedTile != nullptr)
	{
		//TODO : Flag the tile to know if we can do something with it
		std::vector<Tile*>* temp = PathFinding::GetMoveArea(tileArray, **clickedTile, 5);
		SetToWalkable(*temp);
		delete(temp);
		(*clickedTile)->SetColor(sf::Color::Red);
		clickedTile = nullptr;
		delete(clickedTile);
	}
}

void Map::CleanMap()
{
	for (int i = 0; i < tileArray.size(); ++i)
	{
		for (int j = 0; j < tileArray[i].size(); ++j)
		{
			tileArray[i][j]->SetColor(sf::Color::Green);
		}
	}
}

void Map::SetToWalkable(std::vector<Tile*>& _tiles)
{
	for (int i = 0; i < _tiles.size(); ++i)
	{
		_tiles[i]->SetColor(sf::Color::Blue);
	}
}
