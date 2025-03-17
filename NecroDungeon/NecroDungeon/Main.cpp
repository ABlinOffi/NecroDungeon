#include "GameData.h"
#include "src/Map.h"
#include "managers/InputManager.h"

//GameData class
///////////////////////////////////////////////////////////////////////////////////
GameData::GameData()
{
}

GameData& GameData::instance()
{
    static GameData gameData;
    return gameData;
}

GameData::~GameData()
{
    delete(map);
    map = nullptr;
}

void GameData::UpdateTime()
{
    dt = clock.getElapsedTime().asSeconds();
    clock.restart();
}

const float GameData::GetDeltaTime()
{
    return dt;
}
///////////////////////////////////////////////////////////////////////////////////
//Game Loop
///////////////////////////////////////////////////////////////////////////////////
void GameData::Init()
{
    window.create(sf::VideoMode(1080, 720), "Necromancer's Dungeon");
    map = new Map(1080, 720, 40);
    inputs = new InputManager();
}

void GameData::Update()
{
    UpdateTime();
}

void GameData::Draw()
{
    window.clear();
    map->Draw(window);
    window.display();
}

void GameData::UpdateEvent()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        inputs->LeftClick(event, window, map);
    }
}

int main()
{
    GameData& gameData = GameData::instance();
    gameData.Init();

    while (gameData.window.isOpen())
    {
        gameData.UpdateEvent();
        gameData.Update();
        gameData.Draw();
    }

    return 0;
}