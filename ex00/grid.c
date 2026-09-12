// criamos a grid
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
                grid[x][constant] = 4 - x;
        }
        else 
        {
            if (cres_or_decre == 0)
                grid[constant][x] = x + 1;
            else
                grid[x][constant] = 4 - x;
        }
        x++;
    }
}

// pistas
// i = lado
// j = Coluna ou linha
// se so conseguimos ver um predio entao o primeiro numero e o 4
void clue_1(int grid[4][4], int i, int j)
{
    if (i == 1)
        grid[0][j] = 4;
    else if (i == 1)
        grid[3][j] = 4;
    else if (i == 2)
        grid[j][0] = 4;
    else if (i == 3)
        grid[j][3] = 4;
}

// arr guarda as pistas
void assing(int grid[4][4], int i, int j, int arr[4][4])
{
    if (arr[i][i] == 1)
       clue_1(grid, i, j); 
    else if (arr[i][i] == 4)
       clue_1(); 
}


