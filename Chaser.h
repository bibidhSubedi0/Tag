#ifndef chaser_h
#define chaser_h

#include <vector>
#include "Player.h"

struct bullet
{
    int posx;
    int posy;
    Vector2 vel;
    Vector2 dir;

    bullet(int posx, int posy, Vector2 vel, Vector2 dir)
    {
        this->posx = posx;
        this->posy = posy;
        this->vel = vel;
        this->dir = dir;
    }
};

class Chaser : public Player
{
public:
    int bullets;
    std::vector<bullet> allBullets;

    Chaser(Vector2 current_velocity,
           float max_velocity,
           Vector2 currDirection,
           Vector2 position,
           Vector2 dimention, Color colour);
    void shoot_Bullets();
    void moveBullets();
};

#endif // chaser_h
