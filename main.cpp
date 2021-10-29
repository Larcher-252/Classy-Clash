#include "raylib.h"

struct TextureData
{
    Texture2D texure {};
    Vector2 pos {0.0f, 0.0f};
    float rotation {0.0f};
    float scale {1.0f};
};

int main ()
{
    // Window params
    const int windowRes[] {384, 384};
    const char title[] {"Classy Clash"};
    InitWindow(windowRes[0], windowRes[1], title);

    // Background map
    Texture2D map = LoadTexture("nature_tileset/1Level.png");
    TextureData myBG;
    myBG.texure = map;
    myBG.scale = 4.0f;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(myBG.texure, myBG.pos, myBG.rotation, myBG.scale, WHITE);
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}