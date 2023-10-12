/*
Imperative Programming LAB team 8: Mandatory Assignment 6
Student Numbers and Names:
Kai Yuan, s1111236
Diana Smarandoiu, s1117913
*/

#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;


enum Cell {Dead=0, Live};                         // a cell is either Dead or Live (we use the fact that dead = 0 and live = 1)

const char DEAD             = '.' ;               // the presentation of a dead cell (both on file and screen)
const char LIVE             = '*' ;               // the presentation of a live cell (both on file and screen)
const int NO_OF_ROWS        = 40 ;                // the number of rows (height) of the universe (both on file and screen)
const int NO_OF_COLUMNS     = 60 ;                // the number of columns (width) of the universe (both on file and screen)

// Part 1: get cell in bounded universe
Cell cell_at (Cell universe [NO_OF_ROWS][NO_OF_COLUMNS], int row, int column)
{
//  Pre-condition:
    assert(universe [NO_OF_ROWS][NO_OF_COLUMNS] == LIVE || universe [NO_OF_ROWS][NO_OF_COLUMNS] == DEAD);
/*  Post-conditon:
    If row and column are within the bounds defined by NO_OF_ROWS and NO_OF_COLUMNS, return the coordinate value in enum Cell
    If row and column are outside the bounds, return Dead */

    if(row > 0 && row <= NO_OF_ROWS && column >0 && column <= NO_OF_COLUMNS) // within the bounds
    {
        if (universe [NO_OF_ROWS][NO_OF_COLUMNS] == LIVE)
            return Live;
        else
            return Dead;
    }  
    else // outside the bounds
        return Dead;
}

// Part 2: setting the scene
bool read_universe_file (string filename, Cell universe [NO_OF_ROWS][NO_OF_COLUMNS])
{
//  Pre-condition:
    assert(true);
/*  Post-conditon:
    If row and column are within the bounds defined by NO_OF_ROWS and NO_OF_COLUMNS, return the coordinate value in enum Cell
    If row and column are outside the bounds, return Dead */
    ifstream file (filename);
    if (!file.is_open())
        {
            file.open(filename);
            if (file.fail())
            {
                cerr << "Error: File "<< filename << " could not be opened." << endl;
                return false;
            }    
            else
                cout << "File " << filename << " has been opened successfully." << endl;            
        }

    char cell;
    int i,j;

    for (i = 0; i < NO_OF_ROWS; ++i)
    {
        for (j = 0; j < NO_OF_COLUMNS; ++i)  
        {
            file >> cell;
            if (cell == LIVE)
            universe[i][j] = Live;
            else
            universe[i][j] = Dead;                
        }
    }
    
}

void show_universe (Cell universe [NO_OF_ROWS][NO_OF_COLUMNS])
{
    int i,j;
    for (i = 0; i < NO_OF_ROWS; ++i)
    {
        for (j = 0; j < NO_OF_COLUMNS; ++i)  
        {
            if (universe[i][j] == LIVE)
            cout << LIVE; 
            else
            cout << DEAD;                
        }
    if (universe[i][j] == LIVE)
        cout << LIVE << endl; 
            else
        cout << DEAD << endl;  
    }
}

// Part 3: the next generation
void next_generation (Cell now [NO_OF_ROWS][NO_OF_COLUMNS], Cell next [NO_OF_ROWS][NO_OF_COLUMNS])
{
    // pre-conditions, post-conditions, implementation
}

#ifndef TESTING
int main ()
{
    // pre-conditions, post-conditions, implementation
    return 0;
}
#endif
