#pragma once
#include <vector>
#include <raylib.h>

class Grid 
{
    public:
        Grid (int width, int height, int SizeOfCell)
        : rows(height/SizeOfCell), columns(width/SizeOfCell), SizeOfCell(SizeOfCell), cells(rows, std::vector<int>(columns, 0)) {};

        void Draw();//draw
        void SetValue(int row, int column, int value);//set a value to the grid
        int GetValue(int row, int column);//get the value of said grid
        bool InBoundOrNot(int row, int column);//is there a pixel in bound to be the neighbor
        int GetTheRows() {return rows;}//get the row(s) of the neighbor(s)
        int GetTheColumns() {return columns;}//get the column(s) of the neighbor(s)
        void FillingRandomPlaces();//set the random places to start

    private:
        int rows;
        int columns;
        int SizeOfCell;
        std::vector<std::vector<int>> cells;
};

class Simulation {
    public:
        Simulation(int width, int height, int SizeOfCell)
        : grid(width, height, SizeOfCell), temporaryGrid(width, height, SizeOfCell) {grid.FillingRandomPlaces();};

        void Draw();//draw
        void SetValue(int row, int column, int value);//set the values of the pixels of the grid
        int HowManyLivingNeighborsFinder(int row, int column);//find the number of living neighbor(s) next to the pixels
        void Update();//updating the states and everything else

    private:
        Grid grid;
        Grid temporaryGrid;
};