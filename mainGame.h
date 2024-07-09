#ifndef maingame_h
#define maingame_h

#include <iostream>
#include <raylib.h>
#include <vector>
#include "Chaser.h"
#include "Runner.h"
#include "Utilities.h"
#include <string>

using std::cin, std::cout, std::vector, std::string, std::endl;


const int TargetFPS = 100;
const float deltaTime = 0.01;
const string Title = "Tag";


int MainGameLoop();
int GameOverLoop();
void handelCollision(Chaser &chs, Runner &run);

#endif // PERSON_H
