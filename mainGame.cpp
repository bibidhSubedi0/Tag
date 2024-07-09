#include "mainGame.h"

int MainGameLoop()
{
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), Title.c_str());
    SetTargetFPS(TargetFPS);

    Chaser chs({10, 10}, 15, {1, -1}, {500, 500}, {50, 50}, RED);
    Runner run({8, 8}, 15, {1, 1}, {100, 100}, {50, 50}, BLUE);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Shoot Bullets
        if (IsKeyPressed(KEY_SPACE))
        {
            chs.shoot_Bullets();
        }
        chs.moveBullets();

        // Section 1 : Will Document Later
        // Criminal Code,but it works, so fuck off dont complain
        movePlayer(chs, run);

        // // Section 2 : Will document Later
        handelCollision(chs, run);

        // Section 3 : Will document  -> Collision With Each Other
        Rectangle chasing = {chs.position.x, chs.position.y, chs.dimention.x, chs.dimention.y};
        Rectangle running = {run.position.x, run.position.y, run.dimention.x, run.dimention.y};
        if (CheckCollisionRecs(chasing, running))
        {
            chs.current_velocity = {0, 0};
            run.current_velocity = {0, 0};
            while (!WindowShouldClose())
            {
                BeginDrawing();
                Rectangle GameOver = {GetMonitorWidth(0) / 4, GetMonitorHeight(0) / 4, 0.5 * GetMonitorWidth(0), 0.5 * GetMonitorHeight(0)};
                Color rectColor = {100, 50, 150, 10};
                DrawRectangleRec(GameOver, rectColor);
                EndDrawing();
            }
            return 0;
        }

        // Collistion with bullets
        for (int i = 0; i < chs.allBullets.size(); i++)
        {
            if (CheckCollisionCircleRec({(float)chs.allBullets[i].posx, (float)chs.allBullets[i].posx}, 5, running))
            {
                chs.current_velocity = {0, 0};
                run.current_velocity = {0, 0};
                while (!WindowShouldClose())
                {
                    BeginDrawing();
                    Rectangle GameOver = {GetMonitorWidth(0) / 4, GetMonitorHeight(0) / 4, 0.5 * GetMonitorWidth(0), 0.5 * GetMonitorHeight(0)};
                    Color rectColor = {100, 50, 150, 10};
                    DrawRectangleRec(GameOver, rectColor);
                    EndDrawing();
                }
                return 0;
            }
        }

        chs.drawPlayer();
        run.drawPlayer();
        ClearBackground(BLACK);
        EndDrawing();
    }

    return 0;
}

void handelCollision(Chaser &chs, Runner &run)
{
    if (chs.position.x > GetScreenWidth())
        chs.position.x = chs.dimention.x;
    if (chs.position.y > GetScreenHeight())
        chs.position.y = chs.dimention.y;
    if (chs.position.x < 0)
        chs.position.x = GetScreenWidth();
    if (chs.position.y < 0)
        chs.position.y = GetScreenHeight();
    if (run.position.x > GetScreenWidth())
        run.position.x = run.dimention.x;
    if (run.position.y > GetScreenHeight())
        run.position.y = run.dimention.y;
    if (run.position.x < 0)
        run.position.x = GetScreenWidth();
    if (run.position.y < 0)
        run.position.y = GetScreenHeight();
}
