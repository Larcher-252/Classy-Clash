#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

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
    const int windowRes[]{384, 384};
    const char title[]{"Classy Clash"};
    InitWindow(windowRes[0], windowRes[1], title);

    // Background map
    Texture2D map = LoadTexture("nature_tileset/1Level.png");
    TextureData myBG;
    myBG.texture = map;
    myBG.scale = 4.0f;

    // Knight params
    Character knight {windowRes[0], windowRes[1]};

    Prop props[] {
        Prop {{300.0f, 600.0f}, LoadTexture("nature_tileset/Rock.png")},
        Prop {{600.0f, 300.0f}, LoadTexture("nature_tileset/Rock.png")},
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        myBG.pos = Vector2Scale(knight.getWorldPos(), -1.0f);

        BeginDrawing();
        ClearBackground(WHITE);
        
        DrawTextureEx(myBG.texture, myBG.pos, myBG.rotation, myBG.scale, WHITE);

        // Draw props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }

        knight.tick(GetFrameTime());

        if ((knight.getWorldPos().x < 0) || (knight.getWorldPos().x + windowRes[0] > myBG.texture.width * myBG.scale) || 
        (knight.getWorldPos().y < 0) || (knight.getWorldPos().y + windowRes[0] > myBG.texture.height * myBG.scale))
        {
            knight.undoMovement();
        }

        for (auto prop : props)
        {
            if (CheckCollisionRecs(knight.GetCollisionRec(), prop.GetCollisionRec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}