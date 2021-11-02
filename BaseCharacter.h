#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"

// Abstractr class for characters
class BaseCharacter
{
public:
    BaseCharacter();  // Constructor
    ~BaseCharacter(); // Destructor
    // Rectangle getters
    Rectangle getScreenRec();
    Rectangle getSourceRec();
    // Undo last character movement
    void undoMovement() { worldPos = lastWorldPos; }
    // Function that is used every frame
    virtual void tick(float deltaTime);
    // Return world position
    Vector2 getWorldPos() const { return worldPos; }
    // Pure virtual function that make class abstract
    virtual Vector2 getScreenPos() = 0;

    // Health and damage
    bool getAlive() const       { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }
    float getHealth() const     { return health; }
    float getDamValue() const   { return damagePerSec; }
    void takeDamage(float damage);

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

    // Health and damage
    bool alive{true};
    float health{};
    float damagePerSec{};
};

#endif