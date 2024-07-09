#ifndef test_h
#define test_h

#include <string>
#include <raylib.h>

class Player
{
public:
    Vector2 current_velocity;
    float max_velocity;
    Vector2 currDirection;
    Vector2 position;
    Vector2 dimention;
    Color colour;

    Player();
    Player(Vector2 current_velocity,
           float max_velocity,
           Vector2 currDirection,
           Vector2 position,
           Vector2 dimention, Color colour);
    ~Player();
    void drawPlayer();
    void movePlayer();
};

#endif // PERSON_H
