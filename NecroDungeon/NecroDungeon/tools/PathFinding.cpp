#include "PathFinding.h"
#include "../src/Tile.h"

//Sorted Queue for the Pathfinding
/////////////////////////////////////////////////////////////////////////
MySortedList::MySortedList()
{

}

MySortedList::MySortedList(MySortedList& _cpy)
{
	tiles.clear();
	for (int i = 0; i < _cpy.Count(); ++i)
	{
		tiles.push_back(&_cpy.Dequeue());
	}
}

MySortedList::~MySortedList()
{
	for (int i = 0; i < tiles.size(); ++i)
	{
		tiles[i] = nullptr;
	}
}

bool SortByFCost(Tile* _tile1, Tile* _tile2)
{
	return _tile1->fScore < _tile2->fScore;
}

void MySortedList::AddTile(Tile& _tile)
{
	tiles.push_back(&_tile);
	std::sort(tiles.begin(), tiles.end(), SortByFCost);
}

int MySortedList::Count()
{
	return tiles.size();
}

Tile& MySortedList::Dequeue()
{
	Tile& ret = *tiles[0];
	tiles.erase(tiles.begin());
	return ret;
}

bool MySortedList::Contains(Tile& _tile)
{
	for (int i = 0; i < tiles.size(); ++i)
	{
		if (*tiles[i] == _tile)
			return true;
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////
//Pathfinding algorithms and methods
/////////////////////////////////////////////////////////////////////////
std::vector<Tile*>* PathFinding::GetPath(std::vector<std::vector<Tile*>>& _map, Tile& _start, Tile& _end)
{
	// TODO: insert return statement here
	std::vector<Tile*> trash;
	return &trash;
}

std::vector<Tile*>* PathFinding::GetMoveArea(std::vector<std::vector<Tile*>>& _map, Tile& _start, int _moves)
{
	//The list we will be iterating on
        std::vector<Tile*> openSet;
        //The list of next tiles to iterate on
        std::vector<Tile*> nextSet;
        //The list of all the tiles reachable with our move
        std::vector<Tile*>* closedSet = new std::vector<Tile*>;
        //The "timeout" list of tiles that have a cost
        //std::vector<Tile*> costSet;

		openSet.push_back(&_start);

        int movesLeft = _moves;
        do
        {
            for (int i = 0; i < openSet.size(); ++i)
            {
                std::vector<Tile*>* neighbours;

                neighbours = GetNeighbourAtPos(_map, openSet[i]->GetPos().x, openSet[i]->GetPos().y);

                for (int j = 0; j < neighbours->size(); ++j)
                {
                    //TODO add branch for obstacles or tile cost
                    {
                        nextSet.push_back(neighbours->at(j));
                    }
                }

				closedSet->push_back(openSet[i]);
				delete(neighbours);
            }
			openSet.clear();
            openSet = nextSet;
            nextSet.clear();

            movesLeft--;
        }while (movesLeft >= 0);

        return closedSet;
}

std::vector<Tile*>* PathFinding::ReconstructPath(std::map<Tile*, Tile*>& _cameFrom, Tile& _current)
{
	// TODO: insert return statement here
	std::vector<Tile*> trash;
	return &trash;
}

int PathFinding::Dist(Tile& _start, Tile& _end)
{
	return 0;
}

std::vector<Tile*>* PathFinding::GetNeighbourAtPos(std::vector<std::vector<Tile*>>& _map, int _currentX, int _currentY)
{
	std::vector<Tile*>* neighbours = new std::vector<Tile*>;
	int idX = _currentX / TILE_SIZE;
	int idY = _currentY / TILE_SIZE;
	////////////////////////////////////////////////////////////
	///List of the neighbouring tiles of the current tile
	if (idX > 0)
	{
		neighbours->push_back(_map[idX - 1][idY]);
	}

	if (idX < _map.size() - 1)
	{
		neighbours->push_back(_map[idX + 1][idY]);
	}

	if (idY > 0)
	{
		neighbours->push_back(_map[idX][idY - 1]);
	}

	if (idY < _map[0].size() - 1)
	{
		neighbours->push_back(_map[idX][idY + 1]);
	}
	////////////////////////////////////////////////////////////

	return neighbours;
}

/////////////////////////////////////////////////////////////////////////