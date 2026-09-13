#include "include.h"
#include <unistd.h>

int main(int argc, char **argv)
{
    int grid[4][4];
    int clu[4][4];
    
    if (argc != 2 || !valid_input(argv[1]))
        write(1, "Errro", 1);
    
     save_clues(argv[1], clu);
     clear_grid(grid);
     start_grid(grid, clu);
     printgrid(grid);

    return (0);
}
