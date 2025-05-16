#pragma once
#include <raylib.h>
#include <vector>

class SquareTemp {
    private:
    int PosX;
    int PosY;
    int Width;
    int Height;
    float Angle;
    int Velocity;
    Color SquareTempColor;

    public:
    SquareTemp(int StartX, int StartY);
    void Draw();
};