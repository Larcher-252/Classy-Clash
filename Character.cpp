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
    scale = 6.0f;
    weaponScale = 7.0f;

    // Frames params
    runTime = 0.0f;
    updTime = 1.0f / 12.0f;
    frame = 0;
    frameCount = 6;

    // Speed params
    speed = 10;
    velocity = {0.0f, 0.0f};

    // Health and damage
    health = 100;
    damagePerSec = 100.f;
}

Character::~Character()
{
    // all textures except weapon unload in parent class
    UnloadTexture(weapon);
}

void Character::tick(float deltaTime)
{
    // If dead then exit tick
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

    // Draw weapon
    drawWeapon();

    BaseCharacter::tick(deltaTime);
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - static_cast<float>(texture.width) / static_cast<float>(frameCount) * scale * 0.5f,
        static_cast<float>(windowHeight) / 2.0f - static_cast<float>(texture.height) * scale * 0.5f};
}

void Character::drawWeapon()
{
    Vector2 origin{};
    Vector2 offset{};
    float rotation{};

    if (toTheRight)
    {
        origin = {0.f, static_cast<float>(weapon.height) * weaponScale};
        offset = {getScreenRec().width / 1.5f, getScreenRec().height / 1.15f};
        IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? rotation = 25.f : rotation = 0.f;
    }
    else
    {
        origin = {static_cast<float>(weapon.width) * weaponScale, static_cast<float>(weapon.height) * weaponScale};
        offset = {getScreenRec().width / 3.f, getScreenRec().height / 1.15f};
        IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? rotation = -25.f : rotation = 0.f;
    }
    // Create source rec
    Rectangle source{0.0f, 0.0f, static_cast<float>(weapon.width) * (toTheRight ? 1.0f : -1.0f), static_cast<float>(weapon.height)};
    // Create screen rec
    weaponCollisionRec = {getScreenPos().x + offset.x, getScreenPos().y + offset.y, static_cast<float>(weapon.width) * weaponScale, static_cast<float>(weapon.height) * weaponScale};
    // Draw
    DrawTexturePro(weapon, source, weaponCollisionRec, origin, rotation, WHITE);

    // Create collision rec that the same that on screen
    weaponCollisionRec.x -= origin.x;
    weaponCollisionRec.y -= origin.y;
}