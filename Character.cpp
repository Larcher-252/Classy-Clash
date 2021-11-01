#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)
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
    frameCount = 6;

    // Speed params
    speed = 10;
    velocity = {0.0f, 0.0f};
}

void Character::tick(float deltaTime)
{
    // Update velocity
    velocity = {};
    if (IsKeyDown(KEY_A))
        velocity.x -= 1;
    if (IsKeyDown(KEY_D))
        velocity.x += 1;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1;
    if (IsKeyDown(KEY_S))
        velocity.y += 1;

    BaseCharacter::tick(deltaTime);
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - static_cast<float>(texture.width) / static_cast<float>(frameCount) * scale * 0.5f,
        static_cast<float>(windowHeight) / 2.0f - static_cast<float>(texture.height) * scale * 0.5f};
}