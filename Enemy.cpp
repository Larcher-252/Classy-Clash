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

    // Health and damage
    damagePerSec = 30.f;
    health = 100;
}

void Enemy::tick(float deltaTime)
{
    // if dead then exit tick
    if (!getAlive())
        return;

    // Get vector to knight
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());

    // If knight is too far then stop stalking
    // and if monster is close enough to attack
    if ((Vector2Length(velocity) > visibilityRange) || (Vector2Length(velocity) <= attackRadius))
        velocity = {};

    BaseCharacter::tick(deltaTime);

    // If close enough then damage the knight
    if (CheckCollisionRecs(getScreenRec(), target->getScreenRec()))
        target->takeDamage(damagePerSec * deltaTime);
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}