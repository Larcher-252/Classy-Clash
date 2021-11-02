#ifndef INV_WALL_H
#define INV_WALL_H

#include "raylib.h"

class InvWall
{
public:
    InvWall(Rectangle rec);
    Rectangle getCollisionRec(Vector2 knightPos);

private:
    Rectangle worldRec;
};

#endif