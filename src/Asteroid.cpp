#include "classes.h"
#include <raylib.h>
// #include <vector>
// #include <algorithm>
//je ne recois que des messages d'erreurs qui disent qu'il y a une erreur dans mon #include <vector> ainsis que mon #include <algorithme>

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.

Spaceship::Spaceship(int StartX, int StartY) : PosX(StartX), PosY(StartY), Velocity(5) {}
Asteroid::Asteroid(int StartX, int StartY) : PosX(StartX), PosY(StartY), CenterX(GetRandomValue(0, 800)), CenterY(GetRandomValue(0, 500)), Radius(GetRandomValue(10, 50)), VelocityX(100), VelocityY(100) {}
/*std::vector<Asteroid> asteroids;*/ // evidement, ca ne marche pas


void Spaceship::Draw() {
    DrawTriangle({100, 10}, {10, 100}, {100, 100}, BLUE);
}

void Asteroid::Draw() {
    DrawCircle(CenterX, CenterY, Radius, GRAY);
}

void Spaceship::Move() {
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        PosY -= Velocity;
        if (PosY < 0) {
            PosY = 500;
        }
        if (PosX>500) {
            PosY = 0;
        }
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
    Asteroid asteroid1(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid2(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid3(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid4(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid5(GetRandomValue(0, 800), GetRandomValue(0, 500));
    Asteroid asteroid6(GetRandomValue(0, 800), GetRandomValue(0, 500));

    //spawn asteroids (my best guess is that it will not work due to the #include <vector>) lignes 66 a 70 == je l'avais prédits
    /*for (int i = 0; i < 6; i++) {
        int SpawnPosX = GetRandomValue(0, 800);
        int SpawnPosY = GetRandomValue(0, 500);
        asteroids.push_back(Asteroid(SpawnPosX, SpawnPosY));
    }*/

    while (!WindowShouldClose()) {
        BeginDrawing();
        spaceship.Draw();
        spaceship.Move();
        //lignes 85 a 87 == essay avec vecteur, mais erreur, encore
/*      for (Asteroid& asteroid : asteroids) {
            asteroid.Draw();
        }*/
        
        //je vais y aller a la methode longue
        asteroid1.Draw();
        asteroid2.Draw();
        asteroid3.Draw();
        asteroid4.Draw();
        asteroid5.Draw();
        asteroid6.Draw();
        asteroid1.Move();
        asteroid2.Move();
        asteroid3.Move();
        asteroid4.Move();
        asteroid5.Move();
        asteroid6.Move();

        ClearBackground(BACKGROUND);
        EndDrawing();
    }

    CloseWindow();

    // Example:
    // Engine eng = Engine();
    // eng.start();
}