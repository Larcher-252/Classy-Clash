#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

BaseCharacter::~BaseCharacter()
{
    // Unload all class textures
    UnloadTexture(idle);
    UnloadTexture(run);
    UnloadTexture(texture);
}

void BaseCharacter::tick(float deltaTime, bool damaged)
{
    // Backup
    lastWorldPos = worldPos;

    // Update frames
    runTime += deltaTime;
    if (runTime >= updTime)
    {
        runTime = 0.0f;
        if (frame++ == frameCount)
        {
            frame = 0;
        }
    }

    // Update texture and position
    if (Vector2Length(velocity) != 0.0f)
    {
        texture = run;
        velocity = Vector2Normalize(velocity);
        velocity = Vector2Scale(velocity, speed);
        worldPos = Vector2Add(worldPos, velocity);
        // Update left right rotate
        if (velocity.x > 0)
            toTheRight = true;
        if (velocity.x < 0)
            toTheRight = false;
    }
    else
        texture = idle;

    // Draw character
    Color ch_color;
    damaged ? ch_color = RED : ch_color = WHITE;
    DrawTexturePro(texture, getSourceRec(), getScreenRec(), Vector2{}, 0.0f, ch_color);
}

Rectangle BaseCharacter::getScreenRec()
{
    Rectangle rec{
        getScreenPos().x,
        getScreenPos().y,
        static_cast<float>(texture.width) / static_cast<float>(frameCount) * scale,
        static_cast<float>(texture.height) * scale};
    return rec;
}

Rectangle BaseCharacter::getSourceRec()
{
    Rectangle rec{
        static_cast<float>(texture.width) / static_cast<float>(frameCount) * static_cast<float>(frame),
        0.0f,
        static_cast<float>(texture.width) / static_cast<float>(frameCount) * (toTheRight ? 1.0f : -1.0f),
        static_cast<float>(texture.height)};
    return rec;
}

void BaseCharacter::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0.f)
    {
        health = 0.f;
        setAlive(false);
    }
}