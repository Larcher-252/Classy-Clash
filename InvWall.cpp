#include "InvWall.h"
#include "raymath.h"

InvWall::InvWall()
{
    int i = 0;
    // 1 island
    wallsArray[i] = {505.0f, 300.0f, 2570.f, 10.f};
    wallsArray[i++] = {505.0f, 300.0f, 10.f, 330.f};
    wallsArray[i++] = {505.0f, 630.0f, 175.f, 10.f};
    wallsArray[i++] = {850.0f, 630.0f, 900.f, 10.f};
    wallsArray[i++] = {2005.0f, 630.0f, 785.f, 10.f};
    wallsArray[i++] = {2975.0f, 630.0f, 85.f, 10.f};
    wallsArray[i++] = {3060.0f, 300.0f, 10.f, 340.f};
    // bridges 1-2 island
    wallsArray[i++] = {670.0f, 630.0f, 10.f, 466.f};
    wallsArray[i++] = {850.0f, 630.0f, 10.f, 466.f};
    wallsArray[i++] = {1730.0f, 630.0f, 10.f, 375.f};
    wallsArray[i++] = {2000.0f, 630.0f, 10.f, 375.f};
    wallsArray[i++] = {2780.0f, 630.0f, 10.f, 450.f};
    wallsArray[i++] = {2975.0f, 630.0f, 10.f, 450.f};
    
    // middle islands
    // left island
    wallsArray[i++] = {610.0f, 1090.0f, 70.f, 10.f};
    wallsArray[i++] = {860.0f, 1090.0f, 70.f, 10.f};
    wallsArray[i++] = {610.0f, 1090.0f, 10.f, 700.f};
    wallsArray[i++] = {610.0f, 1780.0f, 70.f, 10.f};
    wallsArray[i++] = {860.0f, 1780.0f, 70.f, 10.f};
    wallsArray[i++] = {930.0f, 1090.0f, 10.f, 180.f};
    wallsArray[i++] = {930.0f, 1270.0f, 390.f, 10.f};
    wallsArray[i++] = {1320.0f, 1270.0f, 10.f, 75.f};
    wallsArray[i++] = {1320.0f, 1500.0f, 10.f, 100.f};
    wallsArray[i++] = {930.0f, 1600.0f, 390.f, 10.f};
    wallsArray[i++] = {930.0f, 1600.0f, 10.f, 200.f};
    // middle island
    wallsArray[i++] = {1470.0f, 1000.0f, 10.f, 350.f};
    wallsArray[i++] = {1470.0f, 1000.0f, 270.f, 10.f};
    wallsArray[i++] = {2010.0f, 1000.0f, 280.f, 10.f};
    wallsArray[i++] = {2290.0f, 1000.0f, 10.f, 330.f};
    wallsArray[i++] = {2290.0f, 1500.0f, 10.f, 380.f};
    wallsArray[i++] = {1470.0f, 1500.0f, 10.f, 380.f};
    wallsArray[i++] = {2000.0f, 1880.0f, 300.f, 10.f};
    wallsArray[i++] = {1470.0f, 1880.0f, 300.f, 10.f};
    // right island
    wallsArray[i++] = {2730.0f, 1080.0f, 55.f, 10.f};
    wallsArray[i++] = {2730.0f, 1080.0f, 10.f, 200.f};
    wallsArray[i++] = {2530.0f, 1280.0f, 210.f, 10.f};
    wallsArray[i++] = {2520.0f, 1280.0f, 10.f, 50.f};
    wallsArray[i++] = {2520.0f, 1500.0f, 10.f, 90.f};
    wallsArray[i++] = {2520.0f, 1590.0f, 210.f, 10.f};
    wallsArray[i++] = {2730.0f, 1590.0f, 10.f, 200.f};
    wallsArray[i++] = {2730.0f, 1790.0f, 55.f, 10.f};
    wallsArray[i++] = {2975.0f, 1790.0f, 55.f, 10.f};
    wallsArray[i++] = {2975.0f, 1080.0f, 55.f, 10.f};
    wallsArray[i++] = {3030.0f, 1080.0f, 10.f, 720.f};
    // middle bridges
    wallsArray[i++] = {1320.0f, 1345.0f, 150.f, 10.f};
    wallsArray[i++] = {1320.0f, 1500.0f, 150.f, 10.f};
    wallsArray[i++] = {2290.0f, 1320.0f, 230.f, 10.f};
    wallsArray[i++] = {2290.0f, 1500.0f, 230.f, 10.f};
    
    //Third island
    wallsArray[i++] = {610.0f, 2340.0f, 80.f, 10.f};
    wallsArray[i++] = {860.0f, 2340.0f, 70.f, 10.f};
    wallsArray[i++] = {610.0f, 2340.0f, 10.f, 600.f};
    wallsArray[i++] = {610.0f, 2940.0f, 2450.f, 10.f};
    wallsArray[i++] = {3060.f, 2340.0f, 10.f, 600.f};
    wallsArray[i++] = {2980.f, 2340.0f, 80.f, 10.f};
    wallsArray[i++] = {2700.f, 2340.0f, 80.f, 10.f};
    wallsArray[i++] = {2700.f, 2340.0f, 10.f, 200.f};
    wallsArray[i++] = {2075.f, 2540.0f, 620.f, 10.f};
    wallsArray[i++] = {2075.f, 2340.0f, 10.f, 200.f};
    wallsArray[i++] = {2015.f, 2340.0f, 60.f, 10.f};
    wallsArray[i++] = {1665.f, 2340.0f, 105.f, 10.f};
    wallsArray[i++] = {1665.f, 2340.0f, 10.f, 200.f};
    wallsArray[i++] = {925.f, 2540.0f, 750.f, 10.f};
    wallsArray[i++] = {925.f, 2340.0f, 10.f, 200.f};
    // 2-3 island bridges
    wallsArray[i++] = {680.0f, 1780.0f, 10.f, 560.f};
    wallsArray[i++] = {860.0f, 1780.0f, 10.f, 560.f};
    wallsArray[i++] = {2000.0f, 1880.0f, 10.f, 460.f};
    wallsArray[i++] = {1770.0f, 1880.0f, 10.f, 460.f};
    wallsArray[i++] = {2780.0f, 1790.0f, 10.f, 560.f};
    wallsArray[i++] = {2975.0f, 1790.0f, 10.f, 560.f};
}

Rectangle InvWall::getCollisionRec(Vector2 knightPos, int index)
{
    Vector2 screenPos {Vector2Subtract({wallsArray[index].x, wallsArray[index].y}, knightPos)};
    return Rectangle {
        screenPos.x,
        screenPos.y,
        wallsArray[index].width,
        wallsArray[index].height
    };
}