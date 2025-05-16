#include "classes.h"
#include <raylib.h>
#include <vector>
#include <algorithm>

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.

SquareTemp::SquareTemp(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(10), Height(20), Angle(DEG2RAD), Velocity(5), SquareTempColor(BLUE) {}
void SquareTemp::Draw() {
    DrawRectangle(PosX, PosY, Width, Height, SquareTempColor);
}

int main(void) {

    //window size and name definition
    int ScreenHeight = 500;
    int ScreenWidth = 800;
    const char* ScreenName = "Asteroid";

    int FPS = 1; //subject to changes

    Color BACKGROUND = {0, 0, 0, 255}; //basically black, 'cause space is black

    InitWindow(ScreenWidth, ScreenHeight, ScreenName);
    SetTargetFPS(FPS);
    SquareTemp squaretemp(50, 90);

    while (!WindowShouldClose()) {
        BeginDrawing();
        squaretemp.Draw();
        ClearBackground(BACKGROUND);
        EndDrawing();
    }

    CloseWindow();

    // Example:
    // Engine eng = Engine();
    // eng.start();
}