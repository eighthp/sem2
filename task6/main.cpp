#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>
#include <Ship.hpp>
int main()
{
    ag::Game game(1000, 600, "Game!!!");
    if(!game.Setup(10))
        return -1;

    game.LifeCycle();

    return 0;
}