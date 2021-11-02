#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex) :
worldPos(pos),
texture(tex)
{
}

Prop::~Prop()
{
    UnloadTexture(texture);
}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPos {Vector2Subtract(worldPos, knightPos)};
    DrawTextureEx(texture, screenPos, 0, scale, WHITE);
}

Rectangle Prop::GetCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos {Vector2Subtract(worldPos, knightPos)};
    return Rectangle {
        screenPos.x,
        screenPos.y,
        static_cast<float>(texture.width) * scale,
        static_cast<float>(texture.height) * scale
    };
}