#pragma once
#include <raylib.h>
//#include <vector>
//je ne comprend pas pourquoi #include <vector> ne marche pas

class Spaceship {
    private:
    int PosX;
    int PosY;
    int Velocity;

    public:
    Spaceship(int StartX, int StartY);
    void Draw();
    void Move();
};

class Asteroid {
    private:
    int PosX;
    int PosY;
    int CenterX;
    int CenterY;
    float Radius;
    int VelocityX;
    int VelocityY;

    public:
    Asteroid(int StartX, int StartY);
    void Draw();
    void Move();
};

class Saucer {
    private:
    int PosX;
    int PosY;
};