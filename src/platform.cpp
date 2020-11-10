#define _USE_MATH_DEFINES
#include "platform.h"
#include "game.h"
#include <box2d/box2d.h>
#include <cmath>

Platform::Platform(Game& game) : game_(game)
{
    isTextureLoaded_ = false;
}

void Platform::Init()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.png");
        isTextureLoaded_ = true;
    }
    sprite_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(originPos.x, originPos.y);

    sprite_.setPosition(
        originPos.x*game_.pixelToMeter, 
        originPos.y*game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite_.setScale(1, 1);
    
    b2Vec2 boxSize;
    boxSize.Set(
        325.0f/game_.pixelToMeter/2.0f,//*scale_,
        35.0f/game_.pixelToMeter/2.0f///*scale_
    );
  
    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y, b2Vec2(0, 0), 0);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}

void Platform::Init2()
{
    if (!isTextureLoaded_)
    {
    platformTexture_.loadFromFile("data/sprites/platform.png");
    isTextureLoaded_ = true;
    }

    sprite2_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(8, 10);

    sprite2_.setPosition(
       8 * game_.pixelToMeter,
       10 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite2_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite2_.setScale(1, 1);

    b2Vec2 boxSize;
    boxSize.Set(
        325.0f / game_.pixelToMeter / 2.0f,// * scale_,
        35.0f / game_.pixelToMeter / 2.0f// * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}

void Platform::Init3()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.png");
        isTextureLoaded_ = true;
    }

    sprite3_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(12, 8);

    sprite3_.setPosition(
        12 * game_.pixelToMeter,
        8 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite3_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite3_.setScale(1, 1);

    b2Vec2 boxSize;
    boxSize.Set(
        325.0f / game_.pixelToMeter / 2.0f,// * scale_,
        35.0f / game_.pixelToMeter / 2.0f// * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}

void Platform::Init4()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.png");
        isTextureLoaded_ = true;
    }

    sprite4_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(16, 5);
    bodyDef.angle = 90 * M_PI/180;

    sprite4_.setPosition(
        16 * game_.pixelToMeter,
        5 * game_.pixelToMeter);
    sprite4_.setRotation(90);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite4_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite4_.setScale(1, 1);

    b2Vec2 boxSize;
    boxSize.Set(
        325.0f / game_.pixelToMeter / 2.0f,// * scale_,
        35.0f / game_.pixelToMeter / 2.0f// * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}

void Platform::Init5()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.png");
        isTextureLoaded_ = true;
    }
    sprite5_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(12, 4);

    sprite5_.setPosition(
        12 * game_.pixelToMeter,
        4 * game_.pixelToMeter);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite5_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite5_.setScale(1, 1);

    b2Vec2 boxSize;
    boxSize.Set(
        325.0f / game_.pixelToMeter / 2.0f,// * scale_,
        35.0f / game_.pixelToMeter / 2.0f// * scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}

void Platform::Init6()
{
    if (!isTextureLoaded_)
    {
        platformTexture_.loadFromFile("data/sprites/platform.png");
        isTextureLoaded_ = true;
    }
    sprite6_.setTexture(platformTexture_);
    b2BodyDef bodyDef;
    bodyDef.position.Set(9, 1);
    bodyDef.angle = 30 * M_PI / 180;

    sprite6_.setPosition(
        9 * game_.pixelToMeter,
        1 * game_.pixelToMeter);
    sprite6_.setRotation(30);

    body_ = game_.CreateBody(bodyDef);


    const auto textureSize = platformTexture_.getSize();
    sprite6_.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite6_.setScale(1, 1);

    b2Vec2 boxSize;
    boxSize.Set(
        325.0f / game_.pixelToMeter / 2.0f,//*scale_,
        35.0f / game_.pixelToMeter / 2.0f///*scale_
    );

    b2PolygonShape platformShape;
    platformShape.SetAsBox(boxSize.x, boxSize.y, b2Vec2(0, 0), 0);
    b2FixtureDef platformFixtureDef;
    platformFixtureDef.userData = &platformUserData_;
    platformFixtureDef.shape = &platformShape;
    body_->CreateFixture(&platformFixtureDef);
}


void Platform::Update(float dt)
{
}

void Platform::Render(sf::RenderWindow& window)
{
    window.draw(sprite_);
    window.draw(sprite2_);
    window.draw(sprite3_);
    window.draw(sprite4_);
    window.draw(sprite5_);
    window.draw(sprite6_);
}
