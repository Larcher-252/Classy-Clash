#include "InvWall.h"
#include "raymath.h"

InvWall::InvWall(Rectangle rec) : worldRec(rec)
{
}

Rectangle InvWall::getCollisionRec(Vector2 knightPos)
{
    Vector2 screenPos {Vector2Subtract({worldRec.x, worldRec.y}, knightPos)};
    return Rectangle {
        screenPos.x,
        screenPos.y,
        worldRec.width,
        worldRec.height
    };
}