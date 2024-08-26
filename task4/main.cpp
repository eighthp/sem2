#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Triangle.hpp>
#include <Rectangle.hpp>
#include <Line.hpp>
#include <Game.hpp>

int main()
{
    ag::Game game(1920, 1080, "Game!!!");
    game.Setup(5);
	game.LifeCycle();


	return 0;
}