#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter
{
    public:
    Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
    void tick(float deltaTime, Vector2 knightPos);

    private:
};

#endif