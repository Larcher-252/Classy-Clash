#ifndef INV_WALL_H
#define INV_WALL_H

#include "raylib.h"

class InvWall
{
public:
    InvWall(Rectangle rec);
    Rectangle getCollisionRec() const { return collisionRec; };

private:
    Rectangle collisionRec;
};

#endif