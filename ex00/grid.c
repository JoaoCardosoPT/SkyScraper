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
    if (i == 1)
        grid[0][j] = 4;
    else if (i == 1)
        grid[3][j] = 4;
    else if (i == 2)
        grid[j][0] = 4;
    else 
        grid[j][3] = 4;
}

void assing(int grid[4][4], int i, int j, int arr[4][4])
{
    if (arr[i][j] == 1)
       clue_1(grid, i, j); 
    else if (arr[i][j] == 4)
       grid_assing(grid, j, i < 2, i % 2); 
}

void start_grid(int grid[4][4], int arr[4][4])
{
    int i = 0;
    while (i < 4)
    {
            int j = 0; 
            while(j < 4)
            {
                // if the clue is 1 or 4 
                // if it is 3 or 2 dont do nothing 
                if(arr[i][j] == 4  || arr[i][j] == 1)
                    assing(grid, i, j, arr);
            }
    }
}
