#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    // Constructor
    Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex);
    // Override tick
    virtual void tick(float deltaTime, bool damaged) override;
    // Set target that is knight
    void setTarget(Character *knight) { target = knight; }
    // Override screenPos getter
    virtual Vector2 getScreenPos() override;

private:
    // Battle params
    Character *target{};
    float attackRadius{25.f};
    float visibilityRange{550.f};
};

#endif