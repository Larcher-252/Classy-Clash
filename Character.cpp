#include "Character.h"
#include "raymath.h"

Character::Character(int windowWidth, int windowHeight)
{
    // Textures
    idle = LoadTexture("characters/knight_idle_spritesheet.png");
    run = LoadTexture("characters/knight_run_spritesheet.png");
    texture = idle;

    // Draw params
    scale = 4.0f;

    // Frames params
    runTime = 0.0f;
    updTime = 1.0f / 12.0f;
    frame = 0;
    maxFrame = 5;

    // Initialize rec for frames
    rec = {
        0.0f,
        0.0f,
        static_cast<float>(texture.width) / static_cast<float>(maxFrame + 1),
        static_cast<float>(texture.height)
    };
    
    // Initialize dest for draw
    screen = {
    static_cast<float>(windowWidth) / 2.0f - 0.5f * static_cast<float>(rec.width) * scale,
    static_cast<float>(windowHeight) / 2.0f - 0.5f * static_cast<float>(rec.height) * scale,
    rec.width * scale,
    rec.height * scale
    };

    // Speed params
    speed = 10;
    direction = {0.0f, 0.0f};
}

void Character::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);

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
        if (((direction.x < 0) && (rec.width > 0)) || ((direction.x > 0) && (rec.width < 0))) rec.width *= -1;
    }
    else
        texture = idle;
}