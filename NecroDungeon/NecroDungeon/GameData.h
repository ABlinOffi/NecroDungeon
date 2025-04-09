#pragma once

#include "Definitions.h"

class Map;
class InputManager;
class CombatManager;

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

    void UpdateEvent();

private:
    GameData();
    GameData(GameData&) = delete;
    void operator=(const GameData&) = delete;
    ~GameData();

    Map* map;
    sf::Clock clock;
    float dt;
    InputManager* inputs;
    CombatManager* combatManager;
};
