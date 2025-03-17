#include "InputManager.h"
#include "../src/Map.h"

InputManager::InputManager()
{
}

InputManager::InputManager(InputManager& _cpy)
{
}

InputManager::~InputManager()
{
}

void InputManager::LeftClick(sf::Event& _event, sf::RenderWindow& _window)
{
	if (_event.type == _event.MouseButtonReleased && _event.mouseButton.button == sf::Mouse::Left)
	{
		std::cout << "\nx = " << sf::Mouse::getPosition(_window).x
			<< "\ny = " << sf::Mouse::getPosition(_window).y;
	}
}

void InputManager::LeftClick(sf::Event& _event, sf::RenderWindow& _window, Map* _map)
{
	if (_event.type == _event.MouseButtonReleased && _event.mouseButton.button == sf::Mouse::Left)
	{
		_map->TileClicked(sf::Mouse::getPosition(_window));
	}
}
