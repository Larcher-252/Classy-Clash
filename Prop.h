#ifndef PROP_H
#define PROP_H

#include "raylib.h"

class Prop
{
public:
    // Constructor
    Prop(Vector2 pos, Texture2D texture);
    // Destructor
    ~Prop();
    // Draw prop
    void Render(Vector2 knightPos);
    // Get prop collision
    Rectangle GetCollisionRec(Vector2 knightPos);

private:
    Vector2 worldPos{};
    Texture2D texture{};
    float scale{3.0f};
};

#endif