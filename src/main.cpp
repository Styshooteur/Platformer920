
#include "game.h"
#include "SFML/Main.hpp"
#include "iostream"
#include "SFML/Audio.hpp"


int main(int argc, char** argv)
{
    Game game;
    sf::Music music;
    
    if (!music.openFromFile("data/sound/Final_Music.ogg"))
    {
        std::cout << " Music could not be loaded ! \n";
    }
    music.setVolume(10);
    music.play();
    game.Init();
    game.Loop();
    return EXIT_SUCCESS;
}