#include "raylib.h"
#include "GameHeaderFiles/mainGame.h"
#include <string.h>

struct gameInfo
{
    int totalRounds = 4;
    int round;
    string playerA;
    string playerB;
    float timeEachRound[4];
    string winner;
};

enum GameScreen
{
    HOME = 0,
    GAME,
    EXIT,
    GAME_OVER
};
bool gameOverToggled = 0;

int main()
{
    // Initialization
    const int screenWidth = GetMonitorWidth(0);
    const int screenHeight = GetMonitorHeight(0);

    InitWindow(screenWidth, screenHeight, "Tag");
    gameInfo gf;

    GameScreen currentScreen = HOME;

    // Main game loop
    while (!WindowShouldClose())
    {

        // Beginig of Game

        // Update
        switch (currentScreen)
        {
        case HOME:
        {
            if (IsKeyPressed(KEY_ENTER))
                currentScreen = GAME;
            if (IsKeyPressed(KEY_ESCAPE))
                currentScreen = EXIT;
        }
        break;
        case GAME:
        {
            // Game logic goes here
        }
        break;
        case EXIT:
        {
            CloseWindow();
            return 0;
        }
        }

        // Draw
        BeginDrawing();

        switch (currentScreen)
        {
        case HOME:
        {
            DrawText("HOME SCREEN", GetScreenWidth() / 2 - MeasureText("HOME SCREEN", 40) / 2, GetScreenHeight() / 2 - 40, 40, LIGHTGRAY);
            DrawText("Press ENTER to START", GetScreenWidth() / 2 - MeasureText("Press ENTER to START", 20) / 2, GetScreenHeight() / 2, 20, LIGHTGRAY);
            DrawText("Press BACK_SPACE to EXIT", GetScreenWidth() / 2 - MeasureText("Press BACK_SPACE to EXIT", 20) / 2, GetScreenHeight() / 2 + 40, 20, LIGHTGRAY);
        }
        break;
        case GAME:
        {
            MainGameLoop();

            currentScreen = HOME;
        }
        break;
        case EXIT:
        {
            // No drawing needed, handled in update section
        }
        break;
        }

        ClearBackground(RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
