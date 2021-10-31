#include "raylib.h"

class Character
{
public:
    Character();
    Vector2 getWorldPos() {return worldPos;}
    void setScreenPos(int width, int height);
    void tick(float deltaTime);

private:
    // Texture variables
    Texture2D texture {};
    Texture2D idle {};
    Texture2D run {};

    // Position params
    Vector2 worldPos {};
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