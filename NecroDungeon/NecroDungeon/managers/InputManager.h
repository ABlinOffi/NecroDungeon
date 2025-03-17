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

	void LeftClick(sf::Event& _event, sf::RenderWindow& _window);
	void LeftClick(sf::Event& _event, sf::RenderWindow& _window, Map* _map);

private:


};