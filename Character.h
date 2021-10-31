#include "raylib.h"

class Character
{
public:
    Character(int windowWidth, int windowHeight);
    Vector2 getWorldPos() {return worldPos;}
    void tick(float deltaTime);
    void undoMovement();
    Rectangle GetCollisionRec();

private:
    // Texture variables
    Texture2D texture {};
    Texture2D idle {};
    Texture2D run {};

    // Position params
    Vector2 worldPos {};
    Vector2 lastWorldPos {};
    float scale {};

    // Frames variables
    Rectangle rec {};
    Rectangle screen {};
    float runTime {};
    float updTime {};
    int frame {};
    int maxFrame {};

    // Moving variables
    float speed {};
    Vector2 direction {};
};