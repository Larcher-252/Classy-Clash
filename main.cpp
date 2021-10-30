#include "raylib.h"
#include "raymath.h"

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

    // Hero params
    Vector2 direction {0.0f, 0.0f};
    const float speed {10};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        direction.x = 0;
        direction.y = 0;
        if (IsKeyDown(KEY_A)) direction.x -= 1;
        if (IsKeyDown(KEY_D)) direction.x += 1;
        if (IsKeyDown(KEY_W)) direction.y -= 1;
        if (IsKeyDown(KEY_S)) direction.y += 1;

        if (Vector2Length(direction) != 0.0f)
        {
            direction = Vector2Normalize(direction);
            direction = Vector2Scale(direction, speed);
            myBG.pos = Vector2Subtract(myBG.pos, direction);
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(myBG.texure, myBG.pos, myBG.rotation, myBG.scale, WHITE);
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}