#include "GameData.h"

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
void Init()
{
    GameData::instance().window.create(sf::VideoMode(1080, 720), "Necromancer's Dungeon");
}

void Update(const float _dt)
{

}

void Draw(sf::RenderWindow& _window)
{
    _window.clear();
    _window.display();
}

int main()
{
    Init();
    GameData& gameData = GameData::instance();

    while (gameData.window.isOpen())
    {
        
        
        while (gameData.window.pollEvent(gameData.event))
        {
            if (gameData.event.type == sf::Event::Closed)
                gameData.window.close();
        }
        Update(gameData.GetDeltaTime());
        Draw(gameData.window);
    }

    return 0;
}