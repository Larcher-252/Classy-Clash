#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex) :
worldPos(pos),
textureProp(tex)
{
}

Prop::~Prop()
{
    UnloadTexture(textureProp);
}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPos {Vector2Subtract(worldPos, knightPos)};
    DrawTextureEx(textureProp, screenPos, 0, scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos {Vector2Subtract(worldPos, knightPos)};
    return Rectangle {
        screenPos.x,
        screenPos.y,
        static_cast<float>(textureProp.width) * scale,
        static_cast<float>(textureProp.height) * scale
    };
}