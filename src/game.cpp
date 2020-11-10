#include "game.h"

#include <iostream>


#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Audio.hpp"

Game::Game() : player_(*this), platform_(*this), endrobot_(*this), contactListener_(*this)
{
    
}

void Game::Init()
{

    world_.SetContactListener(&contactListener_);

    window_.create(sf::VideoMode(1280, 720),
        "SAE Platformer");
    window_.setVerticalSyncEnabled(true);
    //window_.setFramerateLimit(10);
    if(!wall_.loadFromFile("data/sprites/background.png"))
    {
        std::cerr << "Could not load texture!\n";
    }
    sprite_.setTexture(wall_);
    sprite_.setOrigin(wall_.getSize().x / 2.0f, wall_.getSize().y / 2.0f);
    sprite_.setScale(1.5, 1.5);

    player_.Init();
    platform_.Init();
    platform_.Init2();
    platform_.Init3();
    platform_.Init4();
    platform_.Init5();
    platform_.Init6();
    endrobot_.Init();

}

void Game::Loop()
{
    sf::Clock gameClock_;
    while(window_.isOpen())
    {

        auto dt = gameClock_.restart();
        sf::Event event;
        while (window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window_.close();
                return;
            }
            if(event.type == sf::Event::Resized)
            {
                auto view = window_.getView();
                view.setSize(event.size.width, event.size.height);
                window_.setView(view);
            }
        }

        fixedTimer_ += dt.asSeconds();
        while(fixedTimer_ > fixedTimestep_)
        {
            world_.Step(fixedTimestep_, 8, 3);
            fixedTimer_ -= fixedTimestep_;
        }

        player_.Update(dt.asSeconds());
        //Window view follows the player character
        auto view = window_.getView();
        view.setCenter(player_.GetPosition());
        window_.setView(view);


        window_.clear(sf::Color::Black);
        const auto windowsSize = window_.getSize();
        sprite_.setPosition(windowsSize.x/2.0f, windowsSize.y/2.0f);
        window_.draw(sprite_);

        player_.Render(window_);
        platform_.Render(window_);
        endrobot_.Render(window_);

        window_.display();
    }
}

b2Body* Game::CreateBody(const b2BodyDef& bodyDef)
{
    return world_.CreateBody(&bodyDef);
}

void Game::BeginContact(UserDataType userData, UserDataType userData1)
{
    if((userData == UserDataType::PLATFORM && userData1 == UserDataType::PLAYER_FOOT) ||
        (userData1 == UserDataType::PLATFORM && userData == UserDataType::PLAYER_FOOT)
        )
    {
        player_.BeginContactGround();
    }
   
    if ((userData == UserDataType::PLAYER_BOX && userData1 == UserDataType::ENDROBOT) ||
        (userData1 == UserDataType::PLAYER_BOX && userData == UserDataType::ENDROBOT))
    {
        std::cout << " You successfully reacher Robot Daddy !!! You win !!! \n";

        window_.close();
    }
}

void Game::EndContact(UserDataType userData, UserDataType userData1)
{
    if ((userData == UserDataType::PLATFORM && userData1 == UserDataType::PLAYER_FOOT) ||
        (userData1 == UserDataType::PLATFORM && userData == UserDataType::PLAYER_FOOT))
    {
        player_.EndContactGround();
    }
}

//void Game::Victory(UserDataType playerBoxData, UserDataType endrobotUserData_)
//{
//    if ((playerBoxData == UserDataType::PLAYER_BOX && endrobotUserData_ == UserDataType::ENDROBOT) ||
//        (endrobotUserData_ == UserDataType::PLAYER_BOX && playerBoxData == UserDataType::ENDROBOT))
//    {
//        player_.Winthegame();
//    }
//
//