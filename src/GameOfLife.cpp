#include "TheClasses.h"
#include <raylib.h>
#include <vector>
//used a tutorial to help me because i had no idea where to start because raylib was not even launching until i figured it out
//the tutorial:  https://www.youtube.com/watch?v=daFYGrXq0aw&t=1772s

//Grid
void Grid::Draw() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++ ) {
            Color color = cells[row][column] ? Color{255, 86, 185, 255} /*Halo CE pink*/ : Color{55,55,55,255};//alive is pink, dead is grey
            DrawRectangle(column * SizeOfCell, row * SizeOfCell, SizeOfCell -1, SizeOfCell -1, color);//draw the cells
        }
    }
}

void Grid::SetValue(int row, int column, int value) {
    if (InBoundOrNot(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column) {
    if (InBoundOrNot(row, column)) {
        return cells[row][column];
    }
    return 0;
}

bool Grid::InBoundOrNot(int row, int column) {
    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    }
    return false;
}

//"Just Like The Simulations" -clones
void Simulation::Draw(){
    grid.Draw();
}

void Simulation::SetValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::HowManyLivingNeighborsFinder(int row, int column) {
    int LivingNeighbors = 0;

    std::vector<std::pair<int, int>> OffsetsFromNeighbor =
    {
        {-1, 0},    //up
        {1, 0},     //down
        {0, -1},    //left
        {0, 1},     //right
        {-1, -1},   //up-left
        {-1, 1},    //up-right
        {1, -1},    //down-left
        {11, 1},    //down-right
    };

    for (const auto& offset : OffsetsFromNeighbor) {
        int RowOfNeighbor = (row + offset.first + grid.GetTheRows()) % grid.GetTheRows();
        int ColumnOfNeighbor = (column + offset.second + grid.GetTheColumns()) % grid.GetTheColumns();
        LivingNeighbors += grid.GetValue(RowOfNeighbor, ColumnOfNeighbor);
    }
    return LivingNeighbors;//returns the number of living neighbor(s)
}

void Simulation::Update() {
    for (int row = 0; row < grid.GetTheRows(); row++) {
        for (int column = 0; column < grid.GetTheColumns(); column++) {
            int LivingNeighbors = HowManyLivingNeighborsFinder(row, column);
            int ValueOfTheCell = grid.GetValue(row, column);//what to do depending on the number of neighbor(s)

            if (ValueOfTheCell == 1) {//if cell is alive
                if (LivingNeighbors > 3 || LivingNeighbors < 2) {
                    temporaryGrid.SetValue(row, column, 0);//kill the cell
                }
                else {
                    temporaryGrid.SetValue(row, column, 1);
                }
            }
            else {//if cell is dead
                if (LivingNeighbors == 3) {
                    temporaryGrid.SetValue(row, column, 1);
                }
                else {
                    temporaryGrid.SetValue(row, column, 0);//kill the cell
                }
            }
        }
    }
    grid = temporaryGrid;
}

void Grid::FillingRandomPlaces() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int RandomNumberGenerator = GetRandomValue(0, 4);
            cells[row][column] = (RandomNumberGenerator == 4) ? 1 : 0;
        }
    }
}


//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
int main(void) {
    
    Color GREY = {34,34,34,255};//in beetween the cells lines (the grid)

    const int WidthOfTheScreen = 900;
    const int HeightOfTheScreen = 900;
    const int SizeOfTheCells = 5;
    int FramesPerSeconds = 10;


    InitWindow(WidthOfTheScreen, HeightOfTheScreen, "Game of Life");//gives the size and name
    SetTargetFPS(FramesPerSeconds);//sets the fps

    Grid grid(WidthOfTheScreen, HeightOfTheScreen, SizeOfTheCells);
    Simulation simulation(WidthOfTheScreen, HeightOfTheScreen, SizeOfTheCells);
    
    
    //logic loop
    while (!WindowShouldClose()) {
	  
    //updates
    simulation.Update();
    
    //draw
    BeginDrawing();//begin the drawing of everything
    ClearBackground(GRAY);//rest the canevas
    simulation.Draw();//draw
    EndDrawing();//stop thedrawing
    }

    //close
    CloseWindow();
}