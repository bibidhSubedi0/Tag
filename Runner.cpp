
#include"Runner.h"
#include<iostream>

Runner::Runner(Vector2 current_velocity,
                  float max_velocity,
                  Vector2 currDirection,
                  Vector2 position,
                  Vector2 dimention, Color colour):Player(current_velocity,max_velocity,currDirection,position,dimention,colour){
    this->shields=3;
}

void Runner::Activate_Shield()
{
    shields-=1;
}