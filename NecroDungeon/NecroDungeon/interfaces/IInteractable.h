#pragma once
#include "../Definitions.h"

class IInteractable
{
public:
	virtual bool IsCursorInside(sf::Vector2i _mousePos) = 0;

};