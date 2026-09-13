#include "include.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[4][4];

	if (argc != 2 || valid_input(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	save_clues(argv[1], clues);
	clear_grid(grid);
	start_grid(grid, clues);
	if (solve_grid(grid, clues, 0))
		printgrid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
