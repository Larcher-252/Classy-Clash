#include "raylib.h"
#include "raymath.h"

struct TextureData
{
    Texture2D texture {};
    Vector2 pos {0.0f, 0.0f};
    float rotation {0.0f};
    float scale {1.0f};
};

struct AnimData
{
    Rectangle source {0.0f, 0.0f, 0.0f, 0.0f};
    Rectangle dest {0.0f, 0.0f, 0.0f, 0.0f};
    const Vector2 origin {0.0f, 0.0f};
    int frame {0};
    int const maxFrame {5};
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
    myBG.texture = map;
    myBG.scale = 4.0f;

    // Knight params
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 direction {0.0f, 0.0f};
    const float speed {10};
    TextureData knightText;
    knightText.texture = knight;
    knightText.scale = 4.0f;
    AnimData knightAnim;
    knightAnim.source.width = knight.width / (knightAnim.maxFrame + 1);
    knightAnim.source.height = knight.height;
    knightAnim.source.x = knightAnim.source.width * knightAnim.frame;
    knightAnim.dest.width = knightAnim.source.width * knightText.scale;
    knightAnim.dest.height = knightAnim.source.height * knightText.scale;
    knightAnim.dest.x = windowRes[0] / 2 - knightAnim.dest.width / 2;
    knightAnim.dest.y = windowRes[1] / 2 - knightAnim.dest.height / 2;

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
        DrawTextureEx(myBG.texture, myBG.pos, myBG.rotation, myBG.scale, WHITE);
        DrawTexturePro(knightText.texture, knightAnim.source, knightAnim.dest, knightAnim.origin, knightText.rotation, WHITE);
        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(knight);
    CloseWindow();
}