#pragma once

#include "../Definitions.h"

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

};

static class PathFinding
{
public:
	static std::vector<Tile*>* GetPath(std::vector<std::vector<Tile*>>& _map, Tile& _start, Tile& _end);
	static std::vector<Tile*>* GetMoveArea(std::vector<std::vector<Tile*>>& _map, Tile& _start, int _moves);

private:
	static std::vector<Tile*>* ReconstructPath(std::map<Tile*, Tile*>& _cameFrom, Tile& _current);
	static int Dist(Tile& _start, Tile& _end);
	static std::vector<Tile*>* GetNeighbourAtPos(std::vector<std::vector<Tile*>>& _map, int _currentX, int _currentY);

};