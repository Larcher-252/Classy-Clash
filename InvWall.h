#ifndef INV_WALL_H
#define INV_WALL_H

#include "raylib.h"

class InvWall
{
public:
    // Construct that add all walls in wallsArray
    InvWall();
    // Get collision rec of a certain wall
    Rectangle getCollisionRec(Vector2 knightPos, int index);

private:
    // Array of walls
    Rectangle wallsArray[68];
};

#endif