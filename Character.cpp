#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth),
                                                    windowHeight(winHeight)
{
    // Textures
    idle = LoadTexture("characters/knight_idle_spritesheet.png");
    run = LoadTexture("characters/knight_run_spritesheet.png");
    texture = idle;
    weapon = LoadTexture("characters/weapon_sword.png");

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
    if (!getAlive())
        return;

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

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (toTheRight)
    {
        origin = {0.f, static_cast<float>(weapon.height) * scale};
        offset = {35.f, 55.f};
        IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? rotation = 35.f : rotation = 0.f;

        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - static_cast<float>(weapon.height) * scale,
            static_cast<float>(weapon.width) * scale,
            static_cast<float>(weapon.height) * scale};
    }
    else
    {
        origin = {static_cast<float>(weapon.width) * scale, static_cast<float>(weapon.height) * scale};
        offset = {25.f, 55.f};
        IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? rotation = -35.f : rotation = 0.f;

        weaponCollisionRec = {
            getScreenPos().x + offset.x - static_cast<float>(weapon.width) * scale,
            getScreenPos().y + offset.y - static_cast<float>(weapon.height) * scale,
            static_cast<float>(weapon.width) * scale,
            static_cast<float>(weapon.height) * scale};
    }
    Rectangle source{0.0f, 0.0f, static_cast<float>(weapon.width) * (toTheRight ? 1.0f : -1.0f), static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, static_cast<float>(weapon.width) * scale, static_cast<float>(weapon.height) * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

    DrawRectangleLines(
        weaponCollisionRec.x,
        weaponCollisionRec.y,
        weaponCollisionRec.width,
        weaponCollisionRec.height,
        RED);
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - static_cast<float>(texture.width) / static_cast<float>(frameCount) * scale * 0.5f,
        static_cast<float>(windowHeight) / 2.0f - static_cast<float>(texture.height) * scale * 0.5f};
}

void Character::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0) setAlive(false);
}