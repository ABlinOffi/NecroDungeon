#pragma once

#include "Definitions.h"

class Tile;

class MySortedList
{
public:
	MySortedList();
	MySortedList(MySortedList& _cpy);
	~MySortedList();

	void AddTile(Tile& _tile);
	int Count();
	Tile& Dequeue();
	bool Contains(Tile& _tile);

private:
	std::vector<Tile*> tiles;

	//bool SortByFCost(Tile _tile1, Tile _tile2);
};

static class PathFinding
{
public:
	std::vector<Tile*>& GetPath(std::vector<std::vector<Tile*>>& _map, Tile& _start, Tile& _end);
	std::vector<Tile*>& GetMoveArea(std::vector<std::vector<Tile*>>& _map, Tile& _start, int _moves);

private:
	std::vector<Tile*>& ReconstructPath(std::map<Tile*, Tile*>& _cameFrom, Tile& _current);
	int Dist(Tile& _start, Tile& _end);
	std::vector<Tile*>& GetNeighbourAtPos(std::vector<std::vector<Tile*>>& _map, int _currentX, int _currentY);

};