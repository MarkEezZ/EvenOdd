#pragma once
#include <iostream>
#include <windows.h>

void wait(double seconds);
void Rules();
void askRules();
void fieldOutput(int** gameField, int fieldSize);
void memoryCleaning(int** gameField, int fieldSize);
int declarationFunc(int** gameField, int fieldSize, int x, int y);
int calculationFunc(int** gameField, int fieldSize);