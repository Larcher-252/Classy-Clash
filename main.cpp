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

    InvWall walls[] {
        // 1 island
        InvWall {{505.0f, 300.0f, 2570.f, 10.f}},
        InvWall {{505.0f, 300.0f, 10.f, 330.f}},
        InvWall {{505.0f, 630.0f, 175.f, 10.f}},
        InvWall {{850.0f, 630.0f, 900.f, 10.f}},
        InvWall {{2005.0f, 630.0f, 785.f, 10.f}},
        InvWall {{2975.0f, 630.0f, 85.f, 10.f}},
        InvWall {{3060.0f, 300.0f, 10.f, 340.f}},
        // bridges 1-2 island
        InvWall {{670.0f, 630.0f, 10.f, 466.f}},
        InvWall {{850.0f, 630.0f, 10.f, 466.f}},
        InvWall {{1730.0f, 630.0f, 10.f, 375.f}},
        InvWall {{2000.0f, 630.0f, 10.f, 375.f}},
        InvWall {{2780.0f, 630.0f, 10.f, 450.f}},
        InvWall {{2975.0f, 630.0f, 10.f, 450.f}},

        // middle islands
        // left island
        InvWall {{610.0f, 1090.0f, 70.f, 10.f}},
        InvWall {{860.0f, 1090.0f, 70.f, 10.f}},
        InvWall {{610.0f, 1090.0f, 10.f, 700.f}},
        InvWall {{610.0f, 1780.0f, 70.f, 10.f}},
        InvWall {{860.0f, 1780.0f, 70.f, 10.f}},
        InvWall {{930.0f, 1090.0f, 10.f, 180.f}},
        InvWall {{930.0f, 1270.0f, 390.f, 10.f}},
        InvWall {{1320.0f, 1270.0f, 10.f, 75.f}},
        InvWall {{1320.0f, 1500.0f, 10.f, 100.f}},
        InvWall {{930.0f, 1600.0f, 390.f, 10.f}},
        InvWall {{930.0f, 1600.0f, 10.f, 200.f}},
        // middle island
        InvWall {{1470.0f, 1000.0f, 10.f, 350.f}},
        InvWall {{1470.0f, 1000.0f, 270.f, 10.f}},
        InvWall {{2010.0f, 1000.0f, 280.f, 10.f}},
        InvWall {{2290.0f, 1000.0f, 10.f, 330.f}},
        InvWall {{2290.0f, 1500.0f, 10.f, 380.f}},
        InvWall {{1470.0f, 1500.0f, 10.f, 380.f}},
        InvWall {{2000.0f, 1880.0f, 300.f, 10.f}},
        InvWall {{1470.0f, 1880.0f, 300.f, 10.f}},
        // right island
        InvWall {{2730.0f, 1080.0f, 55.f, 10.f}},
        InvWall {{2730.0f, 1080.0f, 10.f, 200.f}},
        InvWall {{2530.0f, 1280.0f, 210.f, 10.f}},
        InvWall {{2520.0f, 1280.0f, 10.f, 50.f}},
        InvWall {{2520.0f, 1500.0f, 10.f, 90.f}},
        InvWall {{2520.0f, 1590.0f, 210.f, 10.f}},
        InvWall {{2730.0f, 1590.0f, 10.f, 200.f}},
        InvWall {{2730.0f, 1790.0f, 55.f, 10.f}},
        InvWall {{2975.0f, 1790.0f, 55.f, 10.f}},
        InvWall {{2975.0f, 1080.0f, 55.f, 10.f}},
        InvWall {{3030.0f, 1080.0f, 10.f, 720.f}},
        // middle bridges
        InvWall {{1320.0f, 1345.0f, 150.f, 10.f}},
        InvWall {{1320.0f, 1500.0f, 150.f, 10.f}},
        InvWall {{2290.0f, 1320.0f, 230.f, 10.f}},
        InvWall {{2290.0f, 1500.0f, 230.f, 10.f}},

        //Third island
        InvWall {{610.0f, 2340.0f, 80.f, 10.f}},
        InvWall {{860.0f, 2340.0f, 70.f, 10.f}},
        InvWall {{610.0f, 2340.0f, 10.f, 600.f}},
        InvWall {{610.0f, 2940.0f, 2450.f, 10.f}},
        InvWall {{3060.f, 2340.0f, 10.f, 600.f}},
        InvWall {{2980.f, 2340.0f, 80.f, 10.f}},
        InvWall {{2700.f, 2340.0f, 80.f, 10.f}},
        InvWall {{2700.f, 2340.0f, 10.f, 200.f}},
        InvWall {{2075.f, 2540.0f, 620.f, 10.f}},
        InvWall {{2075.f, 2340.0f, 10.f, 200.f}},
        InvWall {{2015.f, 2340.0f, 60.f, 10.f}},
        InvWall {{1665.f, 2340.0f, 105.f, 10.f}},
        InvWall {{1665.f, 2340.0f, 10.f, 200.f}},
        InvWall {{925.f, 2540.0f, 750.f, 10.f}},
        InvWall {{925.f, 2340.0f, 10.f, 200.f}},
        // 2-3 island bridges
        InvWall {{680.0f, 1780.0f, 10.f, 560.f}},
        InvWall {{860.0f, 1780.0f, 10.f, 560.f}},
        InvWall {{2000.0f, 1880.0f, 10.f, 460.f}},
        InvWall {{1770.0f, 1880.0f, 10.f, 460.f}},
        InvWall {{2780.0f, 1790.0f, 10.f, 560.f}},
        InvWall {{2975.0f, 1790.0f, 10.f, 560.f}},
    };

    SetTargetFPS(60);
    while (true)
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
            DrawText(lastEnemies.c_str(), windowRes[0] - 250.f, 45.f, 40, BLACK);

            std::string position = "x: ";
            position.append(std::to_string(knight.getWorldPos().x), 0, 5);
            position += "\ny: ";
            position.append(std::to_string(knight.getWorldPos().y), 0, 5);
            DrawText(position.c_str(), windowRes[0] / 2.2f, 600.f, 40, BLACK);
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

        for (auto wall : walls)
        {
            wall.getCollisionRec(knight.getWorldPos()).x;
            DrawRectangleLines(
                static_cast<int>(wall.getCollisionRec(knight.getWorldPos()).x), 
                static_cast<int>(wall.getCollisionRec(knight.getWorldPos()).y),
                static_cast<int>(wall.getCollisionRec(knight.getWorldPos()).width),
                static_cast<int>(wall.getCollisionRec(knight.getWorldPos()).height),
                RED);
            if (CheckCollisionRecs(knight.getScreenRec(), wall.getCollisionRec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}