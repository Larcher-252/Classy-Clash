#include "raylib.h"
#include "raymath.h"

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

// Update texture frames
AnimData animUpdate(AnimData data, float deltaTime)
{
    data.runTime += deltaTime;
    if (data.runTime >= data.updTime)
    {
        data.runTime = 0.0f;
        if (data.frame++ > data.maxFrame)
        {
            data.frame = 0;
        }
        data.source.x = data.frame * data.source.width;
    }
    return data;
}

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPosition(int width, int height);
    void tick(float deltaTime);

private:
    // Texture variables
    Texture2D texture;
    Texture2D idle;
    Texture2D run;

    // Position params
    Vector2 screenPos;
    Vector2 worldPos;

    // Frames variables
    Rectangle rec;
    float runTime{0.0f};
    float updTime{1.0f / 12.0f};
    int frame{0};
    int maxFrame{5};

    // Moving variables
    const float speed{10};
    Vector2 direction{0.0f, 0.0f};
};

void Character::setScreenPosition(int width, int height)
{
    screenPos = {
        (float)width / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)height / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}

void Character::tick(float deltaTime)
{
    // Update direction
    direction.x = 0;
    direction.y = 0;
    if (IsKeyDown(KEY_A))
        direction.x -= 1;
    if (IsKeyDown(KEY_D))
        direction.x += 1;
    if (IsKeyDown(KEY_W))
        direction.y -= 1;
    if (IsKeyDown(KEY_S))
        direction.y += 1;
    
    // Update texture and position
    if (Vector2Length(direction) != 0.0f)
    {
        texture = run;
        direction = Vector2Normalize(direction);
        direction = Vector2Scale(direction, speed);
        worldPos = Vector2Subtract(worldPos, direction);
    }
    else
        texture = idle;
    
    // Update left right rotate
    if ((IsKeyPressed(KEY_A) && (rec.width > 0)) || (IsKeyPressed(KEY_D) && (rec.width < 0)))
    rec.width *= -1;

    // Update frames
    runTime += deltaTime;
    if (runTime >= updTime)
    {
        runTime = 0.0f;
        if (frame++ > maxFrame)
        {
            frame = 0;
        }
        rec.x = frame * rec.width;
    }
}

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
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    const float speed{10};
    Vector2 direction{0.0f, 0.0f};
    TextureData knightText;
    knightText.texture = knight_idle;
    knightText.scale = 5.0f;
    AnimData knightAnim;
    knightAnim.source.width = knight_idle.width / (knightAnim.maxFrame + 1);
    knightAnim.source.height = knight_idle.height;
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
        if (IsKeyDown(KEY_A))
            direction.x -= 1;
        if (IsKeyDown(KEY_D))
            direction.x += 1;
        if (IsKeyDown(KEY_W))
            direction.y -= 1;
        if (IsKeyDown(KEY_S))
            direction.y += 1;

        if (Vector2Length(direction) != 0.0f)
        {
            knightText.texture = knight_run;
            direction = Vector2Normalize(direction);
            direction = Vector2Scale(direction, speed);
            myBG.pos = Vector2Subtract(myBG.pos, direction);
        }
        else
            knightText.texture = knight_idle;

        if (IsKeyPressed(KEY_A) && (knightAnim.source.width > 0))
            knightAnim.source.width *= -1;
        if (IsKeyPressed(KEY_D) && (knightAnim.source.width < 0))
            knightAnim.source.width *= -1;

        knightAnim = animUpdate(knightAnim, GetFrameTime());

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(myBG.texture, myBG.pos, myBG.rotation, myBG.scale, WHITE);
        DrawTexturePro(knightText.texture, knightAnim.source, knightAnim.dest, knightAnim.origin, knightText.rotation, WHITE);
        EndDrawing();
    }
    UnloadTexture(map);
    UnloadTexture(knight_idle);
    CloseWindow();
}