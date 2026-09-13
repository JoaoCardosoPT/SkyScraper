#ifndef RUSH01_H
#define RUSH01_H

void save_clues(char *str, int clues[4][4]);
int  valid_input(char *str);

void clear_grid(int grid[4][4]);
void printgrid(int grid[4][4]);
void start_grid(int grid[4][4], int clu[4][4]);

int can_place(int grid[4][4], int row, int col, int value);
int count_visible(int line[4]);
int	check_column(int grid[4][4], int clues[4][4], int col);
int	check_all_clues(int grid[4][4], int clues[4][4]);
int	solve_grid(int grid[4][4], int clues[4][4], int position);

#endif
