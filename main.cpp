#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>
#include "InvWall.h"

struct TextureData
{
    Texture2D texture{};
    Vector2 pos{0.0f, 0.0f};
    float rotation{0.0f};
    float scale{1.0f};
};

int main()
{
    // Window params
    const int windowRes[]{1280, 720};
    const char title[]{"Classy Clash"};
    InitWindow(windowRes[0], windowRes[1], title);

    // Background map
    Texture2D map = LoadTexture("nature_tileset/1Level.png");
    TextureData myBG;
    myBG.texture = map;
    myBG.scale = 3.0f;

    // Knight params
    Character knight{windowRes[0], windowRes[1]};

    // Enemy initialize
    // Goblins
    Enemy goblin_1{{800.0f, 2650.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_2{{900.0f, 2450.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_3{{1000.0f, 2500.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_4{{1200.0f, 2450.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_5{{1400.0f, 2550.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_6{{1600.0f, 2600.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_7{{1800.0f, 2550.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_8{{2000.0f, 2600.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_9{{2400.0f, 2650.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_10{{2600.0f, 2000.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_11{{895.0f, 1457.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_12{{700.0f, 1600.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_13{{900.0f, 1550.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_14{{750.0f, 1490.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_15{{2500.0f, 1157.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_16{{2450.0f, 1300.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_17{{2600.0f, 1250.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy goblin_18{{2500.0f, 1490.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    // Slimes
    Enemy slime_1{{1800.0f, 1450.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_2{{1700.0f, 1500.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_3{{1600.0f, 1600.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_4{{1900.0f, 1700.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_5{{1600.0f, 1670.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_6{{1750.0f, 1560.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_7{{1800.0f, 350.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_8{{1700.0f, 400.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_9{{1600.0f, 550.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_10{{1900.0f, 350.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_11{{1600.0f, 500.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy slime_12{{1750.0f, 460.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};

    Enemy* arrEnemies[] {
        &goblin_1,
        &goblin_2,
        &goblin_3,
        &goblin_4,
        &goblin_5,
        &goblin_6,
        &goblin_7,
        &goblin_8,
        &goblin_9,
        &goblin_10,
        &goblin_11,
        &goblin_12,
        &goblin_13,
        &goblin_14,
        &goblin_15,
        &goblin_16,
        &goblin_17,
        &goblin_18,
        &slime_1,
        &slime_2,
        &slime_3,
        &slime_4,
        &slime_5,
        &slime_6,
        &slime_7,
        &slime_8,
        &slime_9,
        &slime_10,
        &slime_11,
        &slime_12
    };

    // Give target to all Enemies
    for (auto enem : arrEnemies)
        enem->setTarget(&knight);

    // Initialize props
    Prop log1{{870.0f, 1500.0f}, LoadTexture("nature_tileset/Log.png")};
    Prop log2{{1200.0f, 2650.0f}, LoadTexture("nature_tileset/Log.png")};
    Prop rock1{{1890.0f, 1450.0f}, LoadTexture("nature_tileset/Rock.png")};
    Prop rock2{{2500.0f, 2800.0f}, LoadTexture("nature_tileset/Rock.png")};
    // Array of ptr to all props
    Prop *props[]{
        &rock1,
        &rock2,
        &log1,
        &log2};

    // Initialize invisible walls
    InvWall walls;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Update map pos on screen
        myBG.pos = Vector2Scale(knight.getWorldPos(), -1.0f);

        // Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // Draw map
        DrawTextureEx(myBG.texture, myBG.pos, myBG.rotation, myBG.scale, WHITE);

        // Draw props
        for (auto prop : props)
            prop->Render(knight.getWorldPos());

        // Draw goblin
        int enemyCount = 0;
        for (auto enem : arrEnemies)
            if (enem->getAlive())
                enemyCount++;

        // Draw HP and Enemies or Game Over
        if (enemyCount > 0)
        {
            if (knight.getAlive())
            {
                std::string HP = "HP: ";
                HP.append(std::to_string(knight.getHealth()), 0, 5);
                DrawText(HP.c_str(), 55.f, 45.f, 40, RED);

                std::string lastEnemies = "Enemies: ";
                lastEnemies.append(std::to_string(enemyCount));
                DrawText(lastEnemies.c_str(), windowRes[0] - 250.f, 45.f, 40, RED);
            }
            else
            {
                DrawText("Game Over!", windowRes[0] / 2 - 240, windowRes[1] / 2 - 40, 80, RED);
                EndDrawing();
                continue;
            }
        }
        // Draw Win text
        else
        {
            DrawText("You win!", windowRes[0] / 2 - 160, windowRes[1] / 2 - 40, 80, GREEN);
            EndDrawing();
            continue;
        }

        // Draw enemies
        for (auto enem : arrEnemies)
            enem->tick(GetFrameTime(), false);

        // Draw knight
        knight.tick(GetFrameTime(), false);

        // Map bounds check
        if ((knight.getWorldPos().x < 0) || (knight.getWorldPos().x + windowRes[0] > myBG.texture.width * myBG.scale) ||
            (knight.getWorldPos().y < 0) || (knight.getWorldPos().y + windowRes[1] > myBG.texture.height * myBG.scale))
            knight.undoMovement();

        // Check props collision
        for (auto prop : props)
            if (CheckCollisionRecs(knight.getScreenRec(), prop->GetCollisionRec(knight.getWorldPos())))
                knight.undoMovement();

        // Knight attack check
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            for (auto enem : arrEnemies)
                if (CheckCollisionRecs(knight.getWeaponCollisionRec(), enem->getScreenRec()))
                    enem->takeDamage(knight.getDamValue());

        for (int i = 0; i < 69; i++)
            if (CheckCollisionRecs(knight.getScreenRec(), walls.getCollisionRec(knight.getWorldPos(), i)))
                knight.undoMovement();

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}