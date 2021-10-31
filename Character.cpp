#include "Character.h"
#include "raymath.h"

void Character::setScreenPosition(int width, int height)
{
    screenPos = {
        (float)width / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)height / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float deltaTime)
{
    // Update direction
    direction.x = 0;
    direction.y = 0;
    if (IsKeyDown(KEY_A))
        direction.x -= 1;
    if (IsKeyDown(KEY_D))
        direction.x += 1;
    if (IsKeyDown(KEY_W))
        direction.y -= 1;
    if (IsKeyDown(KEY_S))
        direction.y += 1;

    // Update texture and position
    if (Vector2Length(direction) != 0.0f)
    {
        texture = run;
        direction = Vector2Normalize(direction);
        direction = Vector2Scale(direction, speed);
        worldPos = Vector2Add(worldPos, direction);
        // Update left right rotate
        if ((IsKeyPressed(KEY_A) && (rec.width > 0)) || (IsKeyPressed(KEY_D) && (rec.width < 0)))
            rec.width *= -1;
    }
    else
        texture = idle;

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
    Rectangle dest {
        screenPos.x,
        screenPos.y,
        (float)texture.width / 6.0f * 4.0f,
        (float)texture.height * 4.0f
    };
    DrawTexturePro(texture, rec, dest, Vector2 {}, 0.0f, WHITE);
}