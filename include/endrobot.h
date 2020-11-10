#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "user_data.h"

class Game;
class b2Body;

namespace sf
{
    class RenderWindow;
}

class Endrobot
{
public:
    explicit Endrobot(Game& game);
    void Init();
    void Update(float dt);
    void Render(sf::RenderWindow& window);

private:
    Game& game_;
    b2Body* body_ = nullptr;
    const float scale_ = 3.0f;
    sf::Sprite sprite_;
    inline static bool isTextureLoaded_;
    inline static sf::Texture endrobotTexture_;
    const sf::Vector2f originPos = sf::Vector2f(1.0f, 3.0f);
    UserData endrobotUserData_ = { UserDataType::ENDROBOT };
};