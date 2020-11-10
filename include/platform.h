#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

#include "user_data.h"

namespace sf {
    class RenderWindow;
}

class b2Body;
class Game;

class Platform
{
public:
    explicit Platform(Game& game);
    void Init();
    void Init2();
    void Init3();
    void Init4();
    void Init5();
    void Init6();
    void Update(float dt);
    void Render(sf::RenderWindow& window);
    //std::vector<Platform> platforms_;//

private:
    Game& game_;
    b2Body* body_ = nullptr;
    const float scale_ = 3.0f;
    const sf::Vector2u borderMarginForm_ = sf::Vector2u(30, 80);
    sf::Sprite sprite_;
    sf::Sprite sprite2_;
    sf::Sprite sprite3_;
    sf::Sprite sprite4_;
    sf::Sprite sprite5_;
    sf::Sprite sprite6_;
    inline static bool isTextureLoaded_;
    inline static sf::Texture platformTexture_;
    const sf::Vector2f originPos = sf::Vector2f(1.0f, 3.0f);
    UserData platformUserData_ = { UserDataType::PLATFORM };
};
