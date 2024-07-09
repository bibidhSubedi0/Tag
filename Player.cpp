#include "Player.h"
#include <iostream>


// Default constructor

Player::Player(Vector2 current_velocity,
               float max_velocity,
               Vector2 currDirection,
               Vector2 position,
               Vector2 dimention,
               Color colour)
{
    this->currDirection = currDirection;
    this->current_velocity = current_velocity;
    this->position = position;
    this->max_velocity = max_velocity;
    this->dimention = dimention;
    this->colour = colour;
}

Player::~Player(){}

void Player::drawPlayer()
{
    DrawRectangle(position.x, position.y, dimention.x, dimention.y, colour);
}
void Player::movePlayer()
{
    position.x+= current_velocity.x*currDirection.x;
    position.y+= current_velocity.y*currDirection.y;
}
