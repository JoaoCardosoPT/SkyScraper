#include "include.h"
#include "unistd.h"

// Fill the grid 
#include <stdio.h>
void grid_assing(int grid[4][4], int constant, int roworcolum, int cres_or_decre)
{
    int x = 0;

    while(x < 4)
    {
        if( roworcolum == 0 )
        {
            if (cres_or_decre== 0)
                grid[constant][x] = x + 1;
            else
                grid[constant][x] = 4 - x;
        }
        else 
        {
            if (cres_or_decre == 0)
                grid[x][constant] = x + 1;
            else
                grid[x][constant] = 4 - x;
        }
        x++;
    }
}
// i = direction &&  j = Collum or row 
// Put the 4 in place where clue equals 1
void clue_1(int grid[4][4], int i, int j)
{
    if (i == 0)
        grid[0][j] = 4;
    else if (i == 1)
        grid[3][j] = 4;
    else if (i == 2)
        grid[j][0] = 4;
    else 
        grid[j][3] = 4;
}

void assing(int grid[4][4], int i, int j, int clu[4][4])
{
    if (clu[i][j] == 1)
       clue_1(grid, i, j); 
    else if (clu[i][j] == 4)
       grid_assing(grid, j, i < 2, i % 2); 
}

void clear_grid(int grid[4][4])
{
    int i; 
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0; 
        while (j < 4)
        {
           grid[i][j] = 0;
            j++;
        }
        i++;
    }
}
void start_grid(int grid[4][4], int clu[4][4])
{
    int i = 0;
    while (i < 4)
    {
            int j = 0; 
            while(j < 4)
            {
                // if the clue is 1 or 4 
                // if it is 3 or 2 dont do nothing 
                if(clu[i][j] == 4  || clu[i][j] == 1)
                    assing(grid, i, j, clu);
                j++;
            }
            i++;
    }
}

void printgrid(int grid[4][4])
{
    int i;
    int k;
    char number;
    
    i = 0;
    while (i < 4)
    {
        k = 0;
        while (k < 4)
        {
            number = grid[i][k] + '0';
            write(1, &number, 1);
            if (k < 3)
                write(1, " ", 1);
            k++;
        }
        write(1, "\n", 1);
        i++;
    }
}
