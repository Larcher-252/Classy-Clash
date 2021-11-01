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
    maxFrame = 5;

    rec = {
        0.0f,
        0.0f,
        static_cast<float>(texture.width) / static_cast<float>(maxFrame + 1),
        static_cast<float>(texture.height)};

    // Initialize dest for draw
    screen = {
        0.0f,
        0.0f,
        rec.width * scale,
        rec.height * scale};

    // Speed params
    speed = 3.5f;
    direction = {0.0f, 0.0f};
}

void Enemy::tick(float deltaTime)
{
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), {screen.x, screen.y});
    toTarget = Vector2Normalize(toTarget);
    toTarget = Vector2Scale(toTarget, speed);
    worldPos = Vector2Add(worldPos, toTarget);

    Vector2 screenPos = Vector2Subtract(worldPos ,target->getWorldPos());
    screen.x = screenPos.x;
    screen.y = screenPos.y;

    BaseCharacter::tick(deltaTime);
}