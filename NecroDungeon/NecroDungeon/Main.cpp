#include "GameData.h"
#include "Map.h"

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
}

void GameData::Update()
{
    UpdateTime();
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        //PathFinding::GetMoveArea(map->GetMap(), )
}

void GameData::Draw()
{
    window.clear();
    map->Draw(window);
    window.display();
}

int main()
{
    GameData& gameData = GameData::instance();
    gameData.Init();

    while (gameData.window.isOpen())
    {
        
        
        while (gameData.window.pollEvent(gameData.event))
        {
            if (gameData.event.type == sf::Event::Closed)
                gameData.window.close();
        }
        gameData.Update();
        gameData.Draw();
    }

    return 0;
}