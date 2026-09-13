int can_place(int grid[4][4], int row, int col, int value)
{
    int x;
    
    x = 0;
    while (x < 4)
    {
        if(grid[row][x] == value)
            return (0);
        if(grid[x][col] == value)
            return (0);
        x++;
    }
    return (1);
}
int count_visible(int line[4])
{
    int x;
    int highest;
    int visible;

    x = 0;
    highest = 0;
    visible = 0;

    while (x < 4)
    {
        if (line[x] > highest)
        {
            highest = line[x];
            visible++;
        }
        x++;
    }
    return (visible);
}

int solve_grid(int grid[4][4], int clues[4][4], int position)
{
    int row;
    int col;
    int value;

    if (position == 16)
        return();
}

