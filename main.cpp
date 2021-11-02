#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

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

    // Enemy params
    Enemy goblin{{200.0f, 200.0f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy badGoblin{{1000.0f, 200.0f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy *Enemies[]{
        &goblin,
        &badGoblin};

    for (auto ptr : Enemies)
    {
        ptr->setTarget(&knight);
    }

    Prop rock {{1000.0f, 1000.0f}, LoadTexture("nature_tileset/Log.png")};
    Prop *props[] {
        &rock
    };

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
        {
            prop->Render(knight.getWorldPos());
        }

        // Draw goblin
        int enemyCount = 0;
        for (auto ptr : Enemies)
        {
            if (ptr->getAlive()) enemyCount++;
        }

        // Draw HP or Game Over
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
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }

        // Draw goblin
        for (auto ptr : Enemies)
        {
            ptr->tick(GetFrameTime());
        }

        // Draw knight
        knight.tick(GetFrameTime());

        // Map bounds check
        if ((knight.getWorldPos().x < 0) || (knight.getWorldPos().x + windowRes[0] > myBG.texture.width * myBG.scale) ||
            (knight.getWorldPos().y < 0) || (knight.getWorldPos().y + windowRes[1] > myBG.texture.height * myBG.scale))
        {
            knight.undoMovement();
        }

        // Check props collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(knight.getScreenRec(), prop->GetCollisionRec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
        }

        // Knight attack check
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (auto ptr : Enemies)
            {
                if (CheckCollisionRecs(knight.getWeaponCollisionRec(), ptr->getScreenRec()))
                    ptr->takeDamage(knight.getDamValue());
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}