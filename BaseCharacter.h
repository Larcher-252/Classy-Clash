#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    // Rectangle getters
    Rectangle getScreenRec();
    Rectangle getSourceRec();
    Rectangle GetCollisionRec() { return getScreenRec(); }
    // Undo last character movement
    void undoMovement() { worldPos = lastWorldPos; }
    // Function that is used every frame
    virtual void tick(float deltaTime);
    // Return world position
    Vector2 getWorldPos() { return worldPos; }
    // Pure virtual function that make class abstract
    virtual Vector2 getScreenPos() = 0;

    bool getAlive() {return alive;}
    void setAlive(bool isAlive) {alive = isAlive;}

protected:
    // Texture variables
    Texture2D texture{};
    Texture2D idle{};
    Texture2D run{};

    // Position params
    Vector2 worldPos{};
    Vector2 lastWorldPos{};
    float scale{};
    bool toTheRight{};

    // Frames variables
    float runTime{};
    float updTime{};
    int frame{};
    int frameCount{};

    // Moving variables
    float speed{};
    Vector2 velocity{};

    bool alive{true};
};

#endif