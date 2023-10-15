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
    assert(true);
/*  Post-conditon:
    If row and column are within the bounds defined by NO_OF_ROWS and NO_OF_COLUMNS, return the coordinate value in enum Cell
    If row and column are outside the bounds, return Dead */

    if(row >= 0 && row < NO_OF_ROWS && column >= 0 && column < NO_OF_COLUMNS) // within the bounds
    {
        if (universe [row][column] == LIVE)
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
    ifstream file (filename);  // Open File     
        if (file.fail())
        {
            cerr << "Error: File "<< filename << " could not be opened." << endl;
            return false;
        }    
        else
        {
            char cell;
            int i,j;

            for (i = 0; i < NO_OF_ROWS; ++i)
            {
                for (j = 0; j < NO_OF_COLUMNS; ++j)  
                {
                    file >> cell;
                    if (cell == LIVE)
                    universe[i][j] = Live;
                    else
                    universe[i][j] = Dead;                
                }
            }

            cout << "File " << filename << " has been opened successfully." << endl; 
            return true;
        }   
}

void show_universe (Cell universe [NO_OF_ROWS][NO_OF_COLUMNS])
{
//  Pre-condition:
    assert(true);
/*  Post-conditon:
    Print all cell values in the 2-dimension universe char by char*/
    
    int i,j;
    for (i = 0; i < NO_OF_ROWS; ++i)
    {
        for (j = 0; j < NO_OF_COLUMNS; ++j)  
        {
            if (j = NO_OF_COLUMNS-1) // The end of a row and outprint will jump to the next row
            {
                if (universe[i][j] == LIVE)
                    cout << LIVE << endl; 
                else
                    cout << DEAD << endl;               
            }
            else
            {
                if (universe[i][j] == LIVE)
                    cout << LIVE; 
                else
                    cout << DEAD; 
            }               
        }
    }
}

// Part 3: the next generation
void next_generation (Cell now [NO_OF_ROWS][NO_OF_COLUMNS], Cell next [NO_OF_ROWS][NO_OF_COLUMNS])
{
//  Pre-condition:
    assert(true);
/*  Post-conditon:
    Compute all the cell values after one transition of a universe */

    int i,j,k,l; // i,j: coordinate of a cell now, k,l: values used to compute coordinate of neighbout cells
    for (i = 0; i < NO_OF_ROWS; ++i)
    {
        for (j = 0; j < NO_OF_COLUMNS; ++j)  
        {
            int live_neighbour_cells = 0;
            for (k = 0; k < NO_OF_ROWS; ++k)
            {
                for (l = 0; l < NO_OF_ROWS; ++l)
                {
                    if(k != 0 || l !=0 ) // exclude the cell now
                    {
                        Cell neighbour_cell = cell_at(now, i+k, j+l); // value of a neighbour cell
                        if(neighbour_cell == Live) 
                        live_neighbour_cells++;
                    }
                }
            }

            if (now[i][j] == Live)
            {
                if(live_neighbour_cells  < 2 || live_neighbour_cells > 3) // Rule #1,3
                    next[i][j] = Dead;
                else 
                    next[i][j] = Live; // Rule #2
            }
            else
            {
                if(live_neighbour_cells == 3) // Rule #4 
                    next[i][j] = Live;
                else
                    next[i][j] = Dead;
            }
        }
    }
}

#ifndef TESTING
int main ()
{
//  Pre-condition:
    assert(true);
/*  Post-conditon:
    Enter the filename, and the result of the cell universe after one transition will be printed*/

    Cell now[NO_OF_ROWS][NO_OF_COLUMNS];
    Cell next[NO_OF_ROWS][NO_OF_COLUMNS];
    string filename;
    cout << "Enter the filename of the universe: ";
    cin >> filename;

    if(read_universe_file(filename, now) == false)
    return 1;

    next_generation(now,next);
    show_universe(next);

    return 0;
}
#endif
