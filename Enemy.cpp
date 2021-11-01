#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex)
{
    worldPos = pos;
    texture = idle_tex;
    idle = idle_tex;
    run = run_tex;

    // Draw params
    scale = 4.0f;

    // Frames params
    runTime = 0.0f;
    updTime = 1.0f / 12.0f;
    frame = 0;
    frameCount = 6;

    // Speed params
    speed = 3.5f;
    velocity = {0.0f, 0.0f};
}

void Enemy::tick(float deltaTime)
{
    if (!getAlive()) return;
    
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if (Vector2Length(velocity) <= radius) velocity = {};
    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(GetCollisionRec(), target->GetCollisionRec()))
        target->takeDamage(damagePerSec * deltaTime);
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}