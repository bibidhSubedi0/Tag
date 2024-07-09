#ifndef runner_h
#define runner_h

#include<vector>
#include"Player.h"

class Runner : public Player{
    public:
    int shields;

    Runner(Vector2 current_velocity,
                  float max_velocity,
                  Vector2 currDirection,
                  Vector2 position,
                  Vector2 dimention, Color colour);
    void Activate_Shield();
};

#endif //runner_h

