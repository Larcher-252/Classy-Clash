#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::tick(float deltaTime)
{
    // Backup
    lastWorldPos = worldPos;

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

    // Draw character
    DrawTexturePro(texture, rec, screen, Vector2 {}, 0.0f, WHITE);
}