#pragma once

#include "../Definitions.h"

class Map;
class Tile;

class InputManager
{
public:
	InputManager();
	InputManager(InputManager& _cpy);
	~InputManager();

	Tile& GetTileAtCursor(Map* _map);

private:


};