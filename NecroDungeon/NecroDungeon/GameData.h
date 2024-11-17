#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class GameData
{
public:
    static GameData& instance();

    sf::RenderWindow window;
    sf::Event event;
    
    void UpdateTime();
    const float GetDeltaTime();

protected:

private:
    GameData();
    GameData(GameData&) = delete;
    void operator=(const GameData&) = delete;
    ~GameData();

    //static GameData* gameData;
    sf::Clock clock;
    float dt;
};
