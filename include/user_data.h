#pragma once

enum class UserDataType
{
    PLAYER_BOX,
    PLAYER_FOOT,
    PLATFORM,
    ENDROBOT,
    NONE
};

struct UserData
{
    UserDataType userData = UserDataType::NONE;
};