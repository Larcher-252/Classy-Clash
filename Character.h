#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    // Constructor and destructor
    Character(int windowWidth, int windowHeight);
    ~Character();
    // Override tick for character
    virtual void tick(float deltaTime) override;
    // Ovveride screen pos for character
    virtual Vector2 getScreenPos() override;
    // Returns weapon collision rec
    Rectangle getWeaponCollisionRec() {return weaponCollisionRec;}

private:
    // Window params for character screen pos
    int windowWidth;
    int windowHeight;
    // Weapon
    Texture2D weapon{};
    Rectangle weaponCollisionRec{};
    float weaponScale{};
    void drawWeapon();
};

#endif