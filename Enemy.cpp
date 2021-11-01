#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex) : worldPos(pos),
                                                                   texture(idle_tex),
                                                                   idle(idle_tex),
                                                                   run(run_tex)
{
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
    speed = 10;
    direction = {0.0f, 0.0f};
}

void Enemy::tick(float deltaTime, Vector2 knightPos)
{
    // Backup
    lastWorldPos = worldPos;

    // Update frames
    runTime += deltaTime;
    if (runTime >= updTime)
    {
        runTime = 0.0f;
        if (frame++ > maxFrame)
        {
            frame = 0;
        }
        rec.x = frame * rec.width;
    }

    Vector2 screenPos {Vector2Subtract(worldPos, knightPos)};
    screen.x = screenPos.x;
    screen.y = screenPos.y;

    DrawTexturePro(texture, rec, screen, Vector2 {}, 0.0f, WHITE);
}

void Enemy::undoMovement() { worldPos = lastWorldPos; }

Rectangle Enemy::GetCollisionRec() { return screen; }