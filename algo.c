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


int	count_visible_reverse(int line[4])
{
	int	x;
	int	highest;
	int	visible;

	x = 3;
	highest = 0;
	visible = 0;
	while (x >= 0)
	{
		if (line[x] > highest)
		{
			highest = line[x];
			visible++;
		}
		x--;
	}
	return (visible);
}

int checkrow(int grid[4][4], int clues[4][4], int row)
{
    int line[4];
    int x;

    x = 0;
    while(x < 4)
    {
        line[x] = grid[row][x];
        x++;
    }
    if(count_visible(line) != clues[2][row])
        return(0);
	if (count_visible_reverse(line) != clues[3][row])
		return (0);
    return(1);
}

int	check_column(int grid[4][4], int clues[4][4], int col)
{
	int	column[4];
	int	x;

	x = 0;
	while (x < 4)
	{
		column[x] = grid[x][col];
		x++;
	}
	if (count_visible(column) != clues[0][col])
		return (0);
	if (count_visible_reverse(column) != clues[1][col])
		return (0);
	return (1);
}

int	check_all_clues(int grid[4][4], int clues[4][4])
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if (!checkrow(grid, clues, index))
			return (0);
		if (!check_column(grid, clues, index))
			return (0);
		index++;
	}
	return (1);
}

int	solve_grid(int grid[4][4], int clues[4][4], int position)
{
	int	row;
	int	col;
	int	value;

	if (position == 16)
		return (check_all_clues(grid, clues));
	row = position / 4;
	col = position % 4;
	if (grid[row][col] != 0)
		return (solve_grid(grid, clues, position + 1));
	value = 1;
	while (value <= 4)
	{
		if (can_place(grid, row, col, value))
		{
			grid[row][col] = value;
			if (solve_grid(grid, clues, position + 1))
				return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
