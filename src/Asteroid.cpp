#include "classes.h"
#include <raylib.h>
// #include <vector>
// #include <algorithm>
//je ne recois que des messages d'erreurs qui disent qu'il y a une erreur dans mon #include <vector> ainsis que mon #include <algorithme>

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.

Spaceship::Spaceship(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(25), Height(25), Velocity(5), RotateAngle(0.0f) {}
//some of the asteroids and saucers might be extremely slow as they will take a value that is probably too close to 0
Asteroid::Asteroid(int StartX, int StartY) : PosX(StartX), PosY(StartY), CenterX(GetRandomValue(0, 800)), CenterY(GetRandomValue(0, 500)), Radius(GetRandomValue(10, 50)), VelocityX(GetRandomValue(-100, 100)), VelocityY(GetRandomValue(-100, 100)) {}
Saucer::Saucer(int StartX, int StartY) : PosX(StartX), PosY(StartY), Width(GetRandomValue(10, 50)), Height(GetRandomValue(5,25)), VelocityX(GetRandomValue(-100, 100)), VelocityY(GetRandomValue(-100, 100)) {}
/*std::vector<Asteroid> asteroids;*/ // evidement, ca ne marche pas


void Spaceship::Draw() {
    //couldn't make the triangle move, so spaceship is square
    //DrawTriangle({30, 10}, {10, 30}, {30, 30}, BLUE);
    DrawRectangle(PosX, PosY, Width, Height, BLUE);
}

void Asteroid::Draw() {;
    DrawCircle(CenterX, CenterY, Radius, GRAY);
}


void Saucer::Draw() {
    DrawRectangle(PosX, PosY, Width, Height, PURPLE);//guess they are covenant since i made the saucers purple
}

//only go up, rotating was a pain, nothing worked because of bugged programm i guess
void Spaceship::Move() {
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        PosY -= Velocity;
        if (PosY < 0) {
            PosY = 500;
        }
        if (PosX > 500) {
            PosY = 0;
        };
    }
}

void Spaceship::HyperSpace() {
    if (IsKeyPressed(KEY_H)) {
        PosX = GetRandomValue(0, 800);
        PosY = GetRandomValue(0, 500);
    }
}

//they move!!!!!!
//after ~30min i did it
//they finally move!!!
void Asteroid::Move() {
    CenterX += VelocityX * GetFrameTime();
    CenterY += VelocityY * GetFrameTime();
    if (CenterY < 0) {
        CenterY = 500;
    }
    if (CenterY > 500) {
        CenterY = 0;
    }
    if (CenterX < 0) {
        CenterX = 800;
    }
    if (CenterX > 800) {
        CenterX = 0;
    }
}

void Saucer::Move() {
    PosX += VelocityX * GetFrameTime();
    PosY += VelocityY * GetFrameTime();
    if (PosY < 0) {
        PosY = 500;
    }
    if (PosY > 500) {
        PosY = 0;
    }
    if (PosX < 0) {
        PosX = 800;
    }
    if (PosX > 800) {
        PosX = 0;
    }
}

int main(void) {

    //window size and name definition
    int ScreenHeight = 500;
    int ScreenWidth = 800;
    const char* ScreenName = "Asteroid";

    int FPS = 60; //subject to changes

    Color BACKGROUND = {0, 0, 0, 255}; //basically black, 'cause space is black

    InitWindow(ScreenWidth, ScreenHeight, ScreenName);
    SetTargetFPS(FPS);

    Spaceship spaceship(100, 180);

    //so many asteroids!! i hate that vector is bugged
    //some of them will spawn in each other so seeing less than 10 is usual
    Asteroid asteroid1(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid2(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid3(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid4(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid5(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid6(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid7(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid8(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid9(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid10(GetRandomValue(0, 800), GetRandomValue(0, 500));

    //so many saucers!! i hate that vector is bugged
    //some of them will spawn in each other so seeing less than 10 is usual
    Saucer saucer1(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer2(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer3(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer4(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer5(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer6(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer7(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer8(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer9(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Saucer saucer10(GetRandomValue(0, 800), GetRandomValue(0, 500));

    //spawn asteroides avec un std::vector ne marche pas, car le programe est bugge

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        spaceship.Draw();
        spaceship.Move();
        spaceship.HyperSpace();

        //dessiner avec les vecteurs aussi ne marche pas, car je ne peut pas les spawn avec les vecteurs
        
        //draw the asteroids
        asteroid1.Draw();
        asteroid2.Draw();
        asteroid3.Draw();
        asteroid4.Draw();
        asteroid5.Draw();
        asteroid6.Draw();
        asteroid7.Draw();
        asteroid8.Draw();
        asteroid9.Draw();
        asteroid10.Draw();

        //move the asteroids
        asteroid1.Move();
        asteroid2.Move();
        asteroid3.Move();
        asteroid4.Move();
        asteroid5.Move();
        asteroid6.Move();
        asteroid7.Move();
        asteroid8.Move();
        asteroid9.Move();
        asteroid10.Move();


        //draw the saucers
        saucer1.Draw();
        saucer2.Draw();
        saucer3.Draw();
        saucer4.Draw();
        saucer5.Draw();
        saucer6.Draw();
        saucer7.Draw();
        saucer8.Draw();
        saucer9.Draw();
        saucer10.Draw();

        //move the saucers
        saucer1.Move();
        saucer2.Move();
        saucer3.Move();
        saucer4.Move();
        saucer5.Move();
        saucer6.Move();
        saucer7.Move();
        saucer8.Move();
        saucer9.Move();
        saucer10.Move();

        ClearBackground(BACKGROUND);
        EndDrawing();
    }

    CloseWindow();

    // Example:
    // Engine eng = Engine();
    // eng.start();
}