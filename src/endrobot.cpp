#define _USE_MATH_DEFINES
#include "endrobot.h"
#include "game.h"
#include <box2d/box2d.h>
#include <cmath>


Endrobot::Endrobot(Game& game) : game_(game)
{
    isTextureLoaded_ = false;
}

void Endrobot::Init()
{
    if (!isTextureLoaded_)
    {
        endrobotTexture_.loadFromFile("data/sprites/Endrobot.png");
        isTextureLoaded_ = true;
    }

    sprite_.setTexture(endrobotTexture_);
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(5, -5);

    sprite_.setPosition(
        5 * game_.pixelToMeter,
        -5 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = endrobotTexture_.getSize();
    sprite_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite_.setScale(scale_, scale_);

    b2Vec2 boxSize;
    boxSize.Set(
        textureSize.x / game_.pixelToMeter / 4.0f * scale_,
        textureSize.y / game_.pixelToMeter / 4.0f * scale_
    );

    b2PolygonShape endrobotShape;
    endrobotShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef endrobotFixtureDef;
    endrobotFixtureDef.isSensor = true;
    endrobotFixtureDef.userData = &endrobotUserData_;
    endrobotFixtureDef.shape = &endrobotShape;
    body_->CreateFixture(&endrobotFixtureDef);
}

void Endrobot::Update(float dt)
{
}

void Endrobot::Render(sf::RenderWindow& window)
{
    window.draw(sprite_);
}

