#include "raylib.h"
#include "raymath.h"
#include "Character.h"

struct TextureData
{
    Texture2D texture{};
    Vector2 pos{0.0f, 0.0f};
    float rotation{0.0f};
    float scale{1.0f};
};

struct AnimData
{
    Rectangle source{0.0f, 0.0f, 0.0f, 0.0f};
    Rectangle dest{0.0f, 0.0f, 0.0f, 0.0f};
    Vector2 origin{0.0f, 0.0f};
    float runTime{0.0f};
    float updTime{1.0f / 12.0f};
    int frame{0};
    int maxFrame{5};
};

int main()
{
    // Window params
    const int windowRes[]{384, 384};
    const char title[]{"Classy Clash"};
    InitWindow(windowRes[0], windowRes[1], title);

    // Background map
    Texture2D map = LoadTexture("nature_tileset/1Level.png");
    TextureData myBG;
    myBG.texture = map;
    myBG.scale = 4.0f;

    // Knight params
    Character knight;
    knight.setScreenPos(windowRes[0], windowRes[1]);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        myBG.pos = Vector2Scale(knight.getWorldPos(), -1.0f);

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(myBG.texture, myBG.pos, myBG.rotation, myBG.scale, WHITE);
        knight.tick(GetFrameTime());
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}