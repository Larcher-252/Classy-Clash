#include "Character.h"
#include "raymath.h"

Character::Character()
{
    // Textures
    idle = LoadTexture("characters/knight_idle_spritesheet.png");
    run = LoadTexture("characters/knight_run_spritesheet.png");
    texture = idle;

    // Draw params
    scale = 4.0f;

    // Initialize rec for frames
    rec = {
        0.0f,
        0.0f,
        (float)texture.width / (float)(maxFrame + 1),
        (float)texture.height
    };
    
    // Initialize dest for draw
    screen = {
    0.0f,
    0.0f,
    rec.width * scale,
    rec.height * scale
    };

    // Frames params
    runTime = 0.0f;
    updTime = 1.0f / 12.0f;
    frame = 0;
    maxFrame = 5;

    // Speed params
    speed = 10;
    direction = {0.0f, 0.0f};
}

void Character::setScreenPos(int width, int height)
{
    screen.x = (float)width / 2.0f - 0.5f * screen.width;
    screen.y = (float)height / 2.0f - 0.5f * screen.height;
}

void Character::tick(float deltaTime)
{
    // Backup
    lastWorldPos = worldPos;

    // Update direction
    direction.x = 0;
    direction.y = 0;
    if (IsKeyDown(KEY_A)) direction.x -= 1;
    if (IsKeyDown(KEY_D)) direction.x += 1;
    if (IsKeyDown(KEY_W)) direction.y -= 1;
    if (IsKeyDown(KEY_S)) direction.y += 1;

    // Update texture and position
    if (Vector2Length(direction) != 0.0f)
    {
        texture = run;
        direction = Vector2Normalize(direction);
        direction = Vector2Scale(direction, speed);
        worldPos = Vector2Add(worldPos, direction);
        // Update left right rotate
        if ((IsKeyPressed(KEY_A) && (rec.width > 0)) || (IsKeyPressed(KEY_D) && (rec.width < 0))) rec.width *= -1;
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

    DrawTexturePro(texture, rec, screen, Vector2 {}, 0.0f, WHITE);
}

void Character::undoMovement() {worldPos = lastWorldPos;}