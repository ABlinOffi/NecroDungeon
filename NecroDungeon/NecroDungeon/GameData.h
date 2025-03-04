#pragma once

#include "Definitions.h"

class Map;
class InputManager;

class GameData
{
public:
    static GameData& instance();

    sf::RenderWindow window;
    sf::Event event;
    
    void UpdateTime();
    const float GetDeltaTime();

    void Init();
    void Update();
    void Draw();

private:
    GameData();
    GameData(GameData&) = delete;
    void operator=(const GameData&) = delete;
    ~GameData();

    Map* map;
    sf::Clock clock;
    float dt;
};
