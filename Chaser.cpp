#include "Chaser.h"
#include <iostream>

Chaser::Chaser(Vector2 current_velocity,
               float max_velocity,
               Vector2 currDirection,
               Vector2 position,
               Vector2 dimention,
               Color colour) : Player(current_velocity, max_velocity, currDirection, position, dimention, colour)
{
    this->bullets = 10;
    this->allBullets = {{}};
}

void Chaser::shoot_Bullets()
{
    bullet b(position.x+dimention.x/2, position.y+dimention.y/2, {20,20}, currDirection);
    allBullets.push_back(b);
}

void Chaser::moveBullets()
{
    for(int i=0;i<allBullets.size();i++)
    {
        if((allBullets[i].posx > GetScreenWidth() || allBullets[i].posy > GetScreenHeight()||allBullets[i].posx+5 < 0 || allBullets[i].posy+5 < 0))
        {
            allBullets.erase(allBullets.begin()+i);
        }

        allBullets[i].posx+=allBullets[i].vel.x * allBullets[i].dir.x;
        allBullets[i].posy+=allBullets[i].vel.y * allBullets[i].dir.y;
        DrawCircle(allBullets[i].posx,allBullets[i].posy,5,WHITE);
    }
}