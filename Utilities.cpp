#include"Utilities.h"

void movePlayer(Chaser &chs,Runner &run)
{
    if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP))
    {
        chs.currDirection = {1, -1};
        chs.movePlayer();
    }
    else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN))
    {
        chs.currDirection = {1, 1};
        chs.movePlayer();
    }
    else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP))
    {
        chs.currDirection = {-1, -1};
        chs.movePlayer();
    }
    else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN))
    {
        chs.currDirection = {-1, 1};
        chs.movePlayer();
    }

    else if (IsKeyDown(KEY_RIGHT))
    {
        chs.currDirection.x = 1;
        chs.currDirection.y = 0;
        chs.movePlayer();
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        chs.currDirection.x = -1;
        chs.currDirection.y = 0;
        chs.movePlayer();
    }
    else if (IsKeyDown(KEY_UP))
    {
        chs.currDirection.y = -1;
        chs.currDirection.x = 0;
        chs.movePlayer();
    }

    else if (IsKeyDown(KEY_DOWN))
    {
        chs.currDirection.y = 1;
        chs.currDirection.x = 0;
        chs.movePlayer();
    }
    else{}




    if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W))
    {
        run.currDirection = {1, -1};
        run.movePlayer();
    }
    else if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S))
    {
        run.currDirection = {1, 1};
        run.movePlayer();
    }
    else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W))
    {
        run.currDirection = {-1, -1};
        run.movePlayer();
    }
    else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S))
    {
        run.currDirection = {-1, 1};
        run.movePlayer();
    }

    else if (IsKeyDown(KEY_D))
    {
        run.currDirection.x = 1;
        run.currDirection.y = 0;
        run.movePlayer();
    }
    else if (IsKeyDown(KEY_A))
    {
        run.currDirection.x = -1;
        run.currDirection.y = 0;
        run.movePlayer();
    }
    else if (IsKeyDown(KEY_W))
    {
        run.currDirection.y = -1;
        run.currDirection.x = 0;
        run.movePlayer();
    }

    else if (IsKeyDown(KEY_S))
    {
        run.currDirection.y = 1;
        run.currDirection.x = 0;
        run.movePlayer();
    }
    else{}
}