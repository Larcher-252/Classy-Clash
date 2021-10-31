#include "raylib.h"

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPosition(int width, int height);
    void tick(float deltaTime);

private:
    // Texture variables
    Texture2D texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D const idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D const run = LoadTexture("characters/knight_run_spritesheet.png");

    // Position params
    Vector2 screenPos;
    Vector2 worldPos;

    // Frames variables
    Rectangle rec {
        0.0f,
        0.0f,
        (float)texture.width / 6.0f,
        (float)texture.height
    };
    float runTime{0.0f};
    float updTime{1.0f / 12.0f};
    int frame{0};
    int maxFrame{5};

    // Moving variables
    const float speed{10};
    Vector2 direction{0.0f, 0.0f};
};