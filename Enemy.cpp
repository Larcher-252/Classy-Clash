#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_tex, Texture2D run_tex) :
worldPos(pos),
texture(idle_tex),
idle(idle_tex),
run(run_tex)
{
    rec = {
        0.0f,
        0.0f,
        static_cast<float>(texture.width) / static_cast<float>(maxFrame + 1),
        static_cast<float>(texture.height)
    };
}

void Enemy::tick(float deltaTime)
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

    DrawTexturePro(texture, rec, screen, Vector2 {}, 0.0f, WHITE);
}

void Enemy::undoMovement() {worldPos = lastWorldPos;}

Rectangle Enemy::GetCollisionRec() {return screen;}