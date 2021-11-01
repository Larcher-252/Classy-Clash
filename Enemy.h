#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
    virtual void tick(float deltaTime) override;
    void setTarget(Character* knight) {target = knight;}

private:
    Character* target {};
};

#endif