#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos()       { return worldPos; }
    void undoMovement()         { worldPos = lastWorldPos; }
    Rectangle GetCollisionRec() { return screen; }

protected:
    // Texture variables
    Texture2D texture{};
    Texture2D idle{};
    Texture2D run{};

    // Position params
    Vector2 worldPos{};
    Vector2 lastWorldPos{};
    float scale{};

    // Frames variables
    Rectangle rec{};
    Rectangle screen{};
    float runTime{};
    float updTime{};
    int frame{};
    int maxFrame{};

    // Moving variables
    float speed{};
    Vector2 direction{};
};

#endif